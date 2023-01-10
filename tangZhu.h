#pragma once
#include"HolyRelic.h"
#include<vector>

using namespace std;

class tangZhu
{
public:
	//圣遗物
	holy_Relic flower;
	holy_Relic feather;
	holy_Relic hourglass;
	holy_Relic cup;
	holy_Relic crown;

	//面板
	double life = 0;
	double attack = 0;//开e
	double baoji = 0;
	double baoshang = 0;
	double jingtong = 0;

	//构造函数
	tangZhu();

	//装配圣遗物
	void HolyR(holy_Relic flo, holy_Relic fea, holy_Relic hou, holy_Relic c, holy_Relic cro);

	//计算面板
	void data();


	//计算4魔女期望
	double E4();


	double E2p2();

};
