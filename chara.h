#pragma once
#include"HolyRelic.h"
#include"chara.h"
#include<vector>
class chara
{
public:
	//ʥ����
	int hrclass;
	holy_Relic flower;
	holy_Relic feather;
	holy_Relic hourglass;
	holy_Relic cup;
	holy_Relic crown;

	//���
	double life = 0;
	double attack = 0;//��e
	double baoji = 0;
	double baoshang = 0;
	double jingtong = 0;
	chara();

	void HolyR(holy_Relic flo, holy_Relic fea, holy_Relic hou, holy_Relic c, holy_Relic cro);

	//�������
	virtual void data();

	int num();

	//����4��������
	//��Ӧ
	virtual double E1()=0;

	//����
	virtual double E2()=0;
};