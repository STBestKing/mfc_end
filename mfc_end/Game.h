#pragma once
#include "Player.h"
class Game
{
public:
	Game();
	~Game();
	Player* H;
	Player* rare;
	void CreateGame(int n);
	void SetStart(int count);
	int runonce(int start);
};

