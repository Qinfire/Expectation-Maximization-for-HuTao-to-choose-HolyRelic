#include<iostream>
#include<vector>
#include "Ganyu.h"

using namespace std;

Ganyu::Ganyu()
{
	hrclass = 2;
}

//装配圣遗物


//计算面板
void Ganyu::data()
{
	//计算生命
	life = 9797 * (1 + 0.2 + 0.25 + flower.x3 + feather.x3 + hourglass.x3 + cup.x3 + crown.x3) + (flower.x4 + feather.x4 + hourglass.x4 + cup.x4 + crown.x4);

	//计算攻击
	attack = 943 * (1 + 0.496 + 0.25+0.2 + flower.x5 + feather.x5 + hourglass.x5 + cup.x5 + crown.x5) + (flower.x6 + feather.x6 + hourglass.x6 + cup.x6 + crown.x6)+1.19*865;
	//计算暴击率
	baoji = 0.25 + (flower.x1 + feather.x1 + hourglass.x1 + cup.x1 + crown.x1);
	//计算爆伤
	baoshang = 0.884 + (flower.x2 + feather.x2 + hourglass.x2 + cup.x2 + crown.x2);
	//计算精通
	jingtong = flower.x7 + feather.x7 + hourglass.x7 + cup.x7 + crown.x7 + 80;
}


//计算4乐团期望
double Ganyu::E1()
{
	if (num() <= 3)return -1;
	double m = 1.5 * (1 + ((2.18 * jingtong) / (1400 + jingtong)));
	if (baoji >= 1.0)baoji = 1.0;

	double E = attack * m * ((1 + baoshang) * baoji + (1 - baoji));

	return E;
}

double Ganyu::E2()
{
	if (num() <= 3)return -1;
	if (baoji >= 1.0)baoji = 1.0;

	double E = attack * ((1 + baoshang) * baoji + (1 - baoji));

	return E;
}
