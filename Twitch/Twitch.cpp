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

	Sprite testSprite2 = Sprite("Assets/Art/Biplane.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	testSprite2.SetScale(0.25f);

	Flapper player(testSprite);
	Flapper player2(testSprite2);

	InputManager im(&player);

	while (true)
	{
		engine.Update();
		player.Update();
		player2.Update();
		bool isColliding = Rigidbody::IsColliding(player.GetRB(), player2.GetRB());
		cout << (isColliding ? "COLLIDING!!!!" : "....") << endl;
		im.Update();

		engine.BeginRender();
		player.Render();
		player2.Render();
		engine.EndRender();
	}

	return 0;
}