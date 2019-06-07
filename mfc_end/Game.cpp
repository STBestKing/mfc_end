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

void Game::CreateGame(int n) //������Ϸ�������
{
	Player* temp = NULL, * end = NULL;
	H = end = new Player();
	H->no = 1;
	for (int i = 2; i <= n; i++)
	{
		temp = new Player();
		temp->no = i;
		temp->next = H;
		end->next = temp;
		end = temp;
	}
}

void Game::SetStart(int count) //Ѱ�ҿ�ʼλ�ã��ƶ�Hλ�ø�rareλ�ã�
{
	rare = H;
	while (rare->next != H)
	{
		rare = rare->next;
	}
	for (int i = 1; i < count; i++)
	{
		H = H->next;
		rare = rare->next;
	}
}

int Game::runonce(int start) //����һ����ң�H��ĵ�start����
{
	if (H)
	{
		for (int i = 1; i < start; i++)
		{
			H = H->next;
			rare = rare->next;
		}
		int x = H->no;
		rare->next = H->next;
		delete H;
		H = rare->next;
		return x;
	}
	else
	{
		return -1;
	}
}
