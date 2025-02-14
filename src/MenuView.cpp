#include "MenuView.hpp"

#include "GameView.hpp"

void on_click_play(App *app) {
	GameView *game_view = new GameView(app);
	app->set_view(game_view);
}

MenuView::MenuView(App *app) : View(app) {
	play_button = new Button(this, on_click_play, (char *) "Play", (app->get_width() - B_MENU_WIDTH) / 2, (app->get_height() - B_MENU_HEIGHT) / 2, B_MENU_WIDTH, B_MENU_HEIGHT); 
}

void MenuView::handle_event(SDL_Event event) {
	play_button->handle_event(event);
}

void MenuView::update(double dt) {
	play_button->update(dt);
}

void MenuView::paint(SDL_Renderer * rend) {
	play_button->draw(rend);
}

MenuView::~MenuView() {
}