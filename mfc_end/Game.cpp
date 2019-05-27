#include "pch.h"
#include "Game.h"


Game::Game()
{
	H = new Player();
	H->next = NULL;
	H->no = 0;
}


Game::~Game()
{
}

void Game::CreateGame(int n)
{
	Player* temp, * rare;
	for (int i = n; i > 0; i--)
	{
		temp = new Player();
		temp->no = i;
		temp->next = H->next;
		H->next = temp;
	}
	rare = H->next;
	while (rare->next)
	{
		rare = rare->next;
	}
	rare->next = H->next;
}

void Game::SetStart(int count)
{
	for (int i = 1; i < count; i++)
	{
		H->next = H->next->next;
	}
}

int Game::runonce(int start)
{
	for (int i = 1; i < start; i++)
	{
		H->next = H->next->next;
	}
	int x = H->next->no;
	Player* temp = H->next;
	H->next = temp->next;
	delete temp;
	return x;
}
