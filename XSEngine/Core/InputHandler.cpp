#include "../InputHandler.hpp"

InputHandler::InputHandler(XSEngine* game)
{
	_game = game;
}

void InputHandler::handle()
{
	if (key[KEY_ESC])
	{
		_game->close();
	}
	if (key[KEY_SPACE])
	{
		_game->getStack()->remove();
	}
	if (key[KEY_ENTER])
	{
		if (!_game->getStack()->isPaused())
			_game->getStack()->pause();
		else
			_game->getStack()->unpause();
	}
	rest(80);
}
