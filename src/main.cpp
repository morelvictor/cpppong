#include <iostream>

#include "App.hpp"

App *app;

int main() {
	app = new App();
	app->run();
	app->clean();
}