#pragma once
#include "Player.h"
class Game //游戏类
{
public:
	Game();
	~Game();
	Player* H;//当前指针
	Player* rare;//H前的指针
	void CreateGame(int n);//建立游戏并输入玩家人数num
	void SetStart(int count);//寻找并设置开始位置
	int runonce(int start);//H指针后第start玩家出局，返回出局人信息
};

