#include "XSEngine.hpp"
#include "Colors.hpp"

void XSEngine::increment_timer(){timer++;} LOCK_FUNCTION(increment_timer);
long volatile XSEngine::timer = 0; // for the sake of static usage in int_ext

XSEngine::XSEngine(int screenWidth, int screenHeight) {
	allegro_init();
	install_keyboard();
	install_mouse();
	install_timer();
	LOCK_FUNCTION(increment_timer);
	LOCK_VARIABLE(timer);
	install_int_ex(increment_timer, BPS_TO_TIMER(100));
	set_color_depth(32);
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
}

XSEngine::XSEngine(int screenWidth, int screenHeight, ScenesStack* stack)
{
	XSEngine(screenWidth, screenHeight);
	_stack = stack;
};

int XSEngine::initialize(bool fullscreen) {
	if (fullscreen) {
		set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, this->screenWidth, this->screenHeight, 0, 0);
		this->fullscreen = true;
	}
	else {
		set_gfx_mode(GFX_AUTODETECT_WINDOWED, this->screenWidth, this->screenHeight, 0, 0);
		this->fullscreen = false;
	}
	backgroundColor(black);
	show_mouse(screen);
	playing = true;
	return 1;
}

void XSEngine::goFullscreen() {
	if (key[KEY_F11]) {
		BITMAP *bmp = create_bitmap(this->screenWidth, this->screenHeight);
		blit(screen, bmp, 0, 0, 0, 0, this->screenWidth, this->screenHeight);
		if (!fullscreen)
		{
			set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, this->screenWidth, this->screenHeight, 0, 0);
			fullscreen = true;
		}
		else
		{
			set_gfx_mode(GFX_AUTODETECT_WINDOWED, this->screenWidth, this->screenHeight, 0, 0);
			fullscreen = false;
		}
		blit(bmp, screen, 0, 0, 0, 0, this->screenWidth, this->screenHeight);
	}
}

void XSEngine::backgroundColor(int r, int g, int b) {
	BITMAP *bmp = create_bitmap(this->screenWidth, this->screenHeight);
	clear_to_color(screen, makecol(r, g, b));
	blit(bmp, screen, 0, 0, 0, 0, this->screenWidth, this->screenHeight);
	this->bcgColor = makecol(r, g, b);
}

void XSEngine::backgroundColor(int color) {
	BITMAP *bmp = create_bitmap(this->screenWidth, this->screenHeight);
	clear_to_color(bmp, color);
	blit(bmp, screen, 0, 0, 0, 0, this->screenWidth, this->screenHeight);
	this->bcgColor = color;
}

bool XSEngine::isPlaying()
{
	return playing;
}

void XSEngine::close()
{
	playing = false;
}

ScenesStack* XSEngine::getStack()
{
	return _stack;
}

void XSEngine::setStack(ScenesStack* stack)
{
	_stack = stack;
}
