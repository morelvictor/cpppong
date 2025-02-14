#include "Button.hpp"
#include "Entity.hpp"
#include <string.h>

#include <iostream>


Button::Button(View *view, void (*on_clicked)(App *), char *label, int x, int y, int width, int height) : Entity(view, x, y, width, height) {
	this->on_clicked = on_clicked;
	this->label = (char *) malloc(strlen(label) + 1);
	strcpy(this->label, label);
}

void Button::handle_event(SDL_Event event) {
	if(event.type == SDL_MOUSEMOTION) {
		SDL_Point cursor = { event.motion.x, event.motion.y };
		SDL_Rect button = { (int) x, (int) y, (int) width, (int) height };
		selected = SDL_PointInRect(&cursor, &button);
	}

	if(selected) {
		if(event.type == SDL_MOUSEBUTTONDOWN) {
			if(event.button.button == SDL_BUTTON_LEFT) {
				on_clicked(view->get_app());
			}
		}
	}
}

void Button::update(double dt) {}

void Button::draw(SDL_Renderer * rend) {
    SDL_Rect rect = { (int) x, (int) y, (int) width, (int) height };

    SDL_Surface *surface = SDL_CreateRGBSurface(0, width, height, 32, 
                                                0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
    if (!surface) {
        SDL_Log("Error during creation of button's surface: %s", SDL_GetError());
        return;
    }

    Uint32 color = selected ? SDL_MapRGB(surface->format, 100, 100, 100)
                            : SDL_MapRGB(surface->format, 255, 255, 255);

    SDL_FillRect(surface, NULL, color);

    SDL_Color black = { 0, 0, 0 };
    SDL_Surface *text_surface = TTF_RenderText_Solid(view->get_app()->get_font(), label, black);
    
    if (!text_surface) {
        SDL_Log("Error during creation of text's surface: %s", TTF_GetError());
        SDL_FreeSurface(surface);
        return;
    }

    SDL_Rect text_rect;
    text_rect.x = (width - text_surface->w) / 2;
    text_rect.y = (height - text_surface->h) / 2;
    text_rect.w = text_surface->w;
    text_rect.h = text_surface->h;

    SDL_BlitSurface(text_surface, NULL, surface, &text_rect);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_FreeSurface(text_surface);

    if (!texture) {
        SDL_Log("Error during creation of the texture: %s", SDL_GetError());
        return;
    }

    SDL_RenderCopy(rend, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}

Button::~Button() {
}
