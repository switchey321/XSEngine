#pragma once
#include "Scene.hpp"

class XSEngine {
private:
	bool playing;
	ScenesStack* _stack;
	static volatile long timer;

	static void increment_timer();
public:
	int screenWidth;
	int screenHeight;
	bool fullscreen;
	int bcgColor;

	XSEngine(int screenWidth, int screenHeight);
	XSEngine(int screenWidth, int screenHeight, ScenesStack *stack);

	void goFullscreen();
	int initialize(bool fullscreen);
	void backgroundColor(int r, int g, int b);
	void backgroundColor(int color);
	bool isPlaying();
	void close();
	ScenesStack* getStack();
	void setStack(ScenesStack *stack);
};
