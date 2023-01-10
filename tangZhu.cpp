#include<iostream>
#include<vector>
#include "tangzhu.h"

using namespace std;

tangZhu::tangZhu()
{

}

//装配圣遗物
void tangZhu::HolyR(holy_Relic flo, holy_Relic fea, holy_Relic hou, holy_Relic c, holy_Relic cro)
{
	flower = flo;
	feather = fea;
	hourglass = hou;
	cup = c;
	crown = cro;
}

//计算面板
void tangZhu::data()
{
	//计算生命
	life = 15552 * (1 + 0.2 + flower.x3 + feather.x3 + hourglass.x3 + cup.x3 + crown.x3) + (flower.x4 + feather.x4 + hourglass.x4 + cup.x4 + crown.x4);
	//计算攻击
	attack = 715 * (1 + flower.x5 + feather.x5 + hourglass.x5 + cup.x5 + crown.x5) + life * (0.626 + 0.018) + (flower.x6 + feather.x6 + hourglass.x6 + cup.x6 + crown.x6);
	//计算暴击率
	baoji = 0.05 + (flower.x1 + feather.x1 + hourglass.x1 + cup.x1 + crown.x1);
	//计算爆伤
	baoshang = 0.884 + 0.622 + (flower.x2 + feather.x2 + hourglass.x2 + cup.x2 + crown.x2);
	//计算精通
	jingtong = flower.x7 + feather.x7 + hourglass.x7 + cup.x7 + crown.x7;
}

//计算4魔女期望
double tangZhu::E4()
{
	double m = 1.5 * (1 + ((2.18 * jingtong) / (1400 + jingtong)) + 0.15);
	if (baoji >= 1.0)baoji = 1.0;

	double E = attack * m * ((1 + baoshang) * baoji + (1 - baoji));

	return E;
}

//计算2+2期望
double tangZhu::E2p2()
{
	double m = 1.5 * (1 + ((2.18 * (23 * (jingtong + 80))) / (1400 + (23 * (jingtong + 80)))));

	double E = attack * m * ((1 + baoshang) * baoji + (1 - baoji));

	return E;
}
