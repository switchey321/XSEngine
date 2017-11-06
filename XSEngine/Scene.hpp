#pragma once
#include <stack>
#include <allegro.h>

class Scene
{
public:
	virtual void draw(BITMAP *bmp);
	virtual void clear(BITMAP *bmp);
	virtual void update();
};

class ScenesStack
{
private:
	bool paused;
	std::stack<Scene*> _stack;
	Scene *tempPauseScene;
public:
	Scene* getTopScene();
	bool isPaused();
	void add(Scene* scene);
	void pause();
	void unpause();
	void draw(BITMAP *bmp);
	void remove();
	void update();
};