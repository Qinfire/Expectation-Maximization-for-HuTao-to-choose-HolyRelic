#include<iostream>
#include<vector>
#include "chara.h"

using namespace std;

chara::chara()
{
	hrclass = 0;
}

//装配圣遗物
void chara::HolyR(holy_Relic flo, holy_Relic fea, holy_Relic hou, holy_Relic c, holy_Relic cro)
{
	flower = flo;
	feather = fea;
	hourglass = hou;
	cup = c;
	crown = cro;
}

//计算面板
void chara::data()
{

}

int chara::num()
{
	int n = 0;
	if (flower.sclass == hrclass)n++;
	if (feather.sclass == hrclass)n++;
	if (hourglass.sclass == hrclass)n++;
	if (cup.sclass == hrclass)n++;
	if (crown.sclass == hrclass)n++;

	return n;
}


