#pragma once
#include"HolyRelic.h"
#include<vector>

using namespace std;

class tangZhu
{
public:
	//ʥ����
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

	//���캯��
	tangZhu();

	//װ��ʥ����
	void HolyR(holy_Relic flo, holy_Relic fea, holy_Relic hou, holy_Relic c, holy_Relic cro);

	//�������
	void data();


	//����4ħŮ����
	double E4();


	double E2p2();

};
