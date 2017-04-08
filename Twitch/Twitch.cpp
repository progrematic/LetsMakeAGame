#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"

#include "FlappyTwitch/InputManager.h"
#include "FlappyTwitch/Flapper.h"
#include "FlappyTwitch/Pipe.h"

#include <iostream>
using namespace std;

int main()
{
	cout << "Hello, Twitch!" << endl;
	
	Engine engine;
	engine.Initialize("Twitch!");

	Sprite testSprite = Sprite("Assets/Art/Biplane.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	testSprite.SetScale(0.15f);

	Flapper player(testSprite);

	Pipe::Initialize();
	Pipe pipe(Vector3(0, 0, 0));

	InputManager im(&player, &pipe);

	while (true)
	{
		engine.Update();
		player.Update();
		pipe.Update();
		bool isColliding = Rigidbody::IsColliding(player.GetRB(), pipe.GetTopRB()) || Rigidbody::IsColliding(player.GetRB(), pipe.GetBotRB());
		cout << (isColliding ? "COLLIDING!!!!" : "....") << endl;
		im.Update();

		engine.BeginRender();
		player.Render();
		pipe.Render();
		engine.EndRender();
	}

	return 0;
}