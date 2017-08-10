#ifndef TWITCH_PIPEMANAGER
#define TWITCH_PIPEMANAGER

#include "Pipe.h"
#include "Flapper.h"

#include <vector>
using namespace std;

class PipeManager
{
public:
	PipeManager();
	~PipeManager();

	void Update();
	void Render();

	bool CheckCollision(Flapper& flapper);

private:
	void CreatePipe();

private:
	vector<Pipe*> pipes;

	float xSeparation;
	float ySeparation;
	float minXSeparation;
	float minYSeparation;
	float xSeparationSpeed;
	float ySeparationSpeed;

	int minSpawnY;
	int maxSpawnY;

	int totalPipes;
};

#endif
