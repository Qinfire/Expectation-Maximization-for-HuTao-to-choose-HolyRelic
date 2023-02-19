#pragma once
#include"HolyRelic.h"
#include"chara.h"
#include<vector>
class chara
{
public:
	//圣遗物
	int hrclass;
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
	chara();

	void HolyR(holy_Relic flo, holy_Relic fea, holy_Relic hou, holy_Relic c, holy_Relic cro);

	//计算面板
	virtual void data();

	int num();

	//计算4乐团期望
	//反应
	virtual double E1()=0;

	//裸伤
	virtual double E2()=0;
};