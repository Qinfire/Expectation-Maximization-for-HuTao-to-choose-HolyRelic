#include<iostream>
#include<vector>
#include "tangzhu.h"

using namespace std;

tangZhu::tangZhu()
{

}

//װ��ʥ����
void tangZhu::HolyR(holy_Relic flo, holy_Relic fea, holy_Relic hou, holy_Relic c, holy_Relic cro)
{
	flower = flo;
	feather = fea;
	hourglass = hou;
	cup = c;
	crown = cro;
}

//�������
void tangZhu::data()
{
	//��������
	life = 15552 * (1 + 0.2 + flower.x3 + feather.x3 + hourglass.x3 + cup.x3 + crown.x3) + (flower.x4 + feather.x4 + hourglass.x4 + cup.x4 + crown.x4);
	//���㹥��
	attack = 715 * (1 + flower.x5 + feather.x5 + hourglass.x5 + cup.x5 + crown.x5) + life * (0.626 + 0.018) + (flower.x6 + feather.x6 + hourglass.x6 + cup.x6 + crown.x6);
	//���㱩����
	baoji = 0.05 + (flower.x1 + feather.x1 + hourglass.x1 + cup.x1 + crown.x1);
	//���㱬��
	baoshang = 0.884 + 0.622 + (flower.x2 + feather.x2 + hourglass.x2 + cup.x2 + crown.x2);
	//���㾫ͨ
	jingtong = flower.x7 + feather.x7 + hourglass.x7 + cup.x7 + crown.x7;
}

//����4ħŮ����
double tangZhu::E4()
{
	double m = 1.5 * (1 + ((2.18 * jingtong) / (1400 + jingtong)) + 0.15);
	if (baoji >= 1.0)baoji = 1.0;

	double E = attack * m * ((1 + baoshang) * baoji + (1 - baoji));

	return E;
}

//����2+2����
double tangZhu::E2p2()
{
	double m = 1.5 * (1 + ((2.18 * (23 * (jingtong + 80))) / (1400 + (23 * (jingtong + 80)))));

	double E = attack * m * ((1 + baoshang) * baoji + (1 - baoji));

	return E;
}
