#pragma once
#include "Player.h"
class Game //��Ϸ��
{
public:
	Game();
	~Game();
	Player* H;//��ǰָ��
	Player* rare;//Hǰ��ָ��
	void CreateGame(int n);//������Ϸ�������������num
	void SetStart(int count);//Ѱ�Ҳ����ÿ�ʼλ��
	int runonce(int start);//Hָ����start��ҳ��֣����س�������Ϣ
};

