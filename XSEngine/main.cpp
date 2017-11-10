#include "XSEngine.hpp"
#include "TestScene.hpp"
#include "TestScene2.hpp"
#include "InputHandler.hpp"
#include "TestScene3.hpp"

int main()
{
	XSEngine game = XSEngine(1280, 720);
	game.initialize(false);

	ScenesStack scenes;
	InputHandler input = InputHandler(&game);

	static BITMAP* bmp = create_bitmap(screen->w,screen->h);
	
	scenes.add(new TestScene());
	scenes.add(new TestScene2());
	scenes.add(new TestScene());
	scenes.add(new TestScene2());
	scenes.add(new TestScene());
	scenes.add(new TestScene2());
	scenes.add(new TestScene3());

	game.setStack(&scenes);

	while (game.isPlaying())
	{
		game.goFullscreen();
		
		input.handle();
		scenes.update();
		scenes.draw(bmp);
	}

	allegro_exit();
	return 0;
}
END_OF_MAIN()
