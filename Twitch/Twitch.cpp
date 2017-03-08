#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"

#include "FlappyTwitch/InputManager.h"
#include "FlappyTwitch/Flapper.h"

#include <iostream>
using namespace std;

int main()
{
	cout << "Hello, Twitch!" << endl;
	
	Engine engine;
	engine.Initialize("Twitch!");

	Sprite testSprite = Sprite("Assets/Art/Biplane.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	testSprite.SetScale(0.25f);

	Flapper player(testSprite);

	InputManager im(&player);

	while (true)
	{
		engine.Update();
		player.Update();
		im.Update();

		engine.BeginRender();
		player.Render();
		engine.EndRender();
	}

	return 0;
}