#pragma once
#include"HolyRelic.h"
#include"chara.h"
#include<vector>

using namespace std;

class tangZhu:public chara
{
public:

	//构造函数
	tangZhu();

	//装配圣遗物

	//计算面板
	void data();


	//计算4魔女期望
	double E1();


	double E2();

};
