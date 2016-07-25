#ifndef TWITCH_FLAPPER
#define TWITCH_FLAPPER

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/Rigidbody.h"

class Flapper
{
public:
	
	Flapper();
	Flapper(Sprite _sprite);

	void Update();
	void Render();

	Sprite& GetSprite();
	Rigidbody& GetRB();

private:
	Sprite sprite;
	Rigidbody rb;
};

#endif
