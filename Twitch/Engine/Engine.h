#ifndef TWITCH_ENGINE
#define TWITCH_ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include <iostream>
using namespace std;

class Engine
{
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	Engine();
	~Engine();

	bool Initialize(char* windowTitle);

	void Update();
	void BeginRender();
	void EndRender();

private:
	static GLFWwindow* window;
};

#endif
