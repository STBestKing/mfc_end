#pragma once
#include "Player.h"
class Game
{
public:
	Game();
	~Game();
	Player* H;
	void CreateGame(int n);
	void SetStart(int count);
	int runonce(int start);
};

