#pragma once
#include "XSEngine.hpp"

class InputHandler
{
private:
	XSEngine *_game;
public:
	InputHandler(XSEngine *game);
	void handle();
};