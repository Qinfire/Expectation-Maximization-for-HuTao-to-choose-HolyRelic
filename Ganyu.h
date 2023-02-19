#pragma once
#include"HolyRelic.h"
#include"chara.h"
#include<vector>

using namespace std;

class Ganyu:public chara
{
public:

	//构造函数
	Ganyu();

	//装配圣遗物

	//计算面板
	void data();

	//计算4乐团期望
	//反应
	double E1();

	//裸伤
	double E2();

};
