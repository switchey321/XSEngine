#include "../Scene.hpp"

Scene* ScenesStack::getTopScene()
{
	if (!_stack.empty())
		return _stack.top();
}

bool ScenesStack::isPaused()
{
	return paused;
}

void ScenesStack::add(Scene* scene)
{
	_stack.push(scene);
}

void ScenesStack::pause()
{
	if (!isPaused() && !_stack.empty())
	{
		tempPauseScene = _stack.top();
		_stack.pop();
		paused = true;
	}

}

void ScenesStack::unpause()
{
	if (tempPauseScene)
		_stack.push(tempPauseScene);
	tempPauseScene = NULL;
	paused = false;
}


void ScenesStack::draw(BITMAP* bmp)
{
	if (!_stack.empty())
		_stack.top()->draw(bmp);
}

void ScenesStack::remove()
{
	if (!_stack.empty())
	{
		_stack.pop();
	}
}

void ScenesStack::update()
{
	if (!_stack.empty())
		_stack.top()->update();
}
