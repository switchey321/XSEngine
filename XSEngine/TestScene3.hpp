#include "Scene.hpp"
#include "Sprite.hpp"

class TestScene3 : public Scene
{
private:
	Sprite ship;
public:
	TestScene3();
	~TestScene3();

	void draw(BITMAP* bmp) override;
	void update() override;
};
