#pragma once
#include<iostream>
using namespace std;

//ʥ����
class holy_Relic
{
public:
    int sclass = 1;//ʥ�������
    double x1 = 0;//������
    double x2 = 0;//�����˺�
    double x3 = 0;//������
    double x4 = 0;//С����
    double x5 = 0;//�󹥻�
    double x6 = 0;//С����
    double x7 = 0;//��ͨ

    holy_Relic()
    {

    }

    holy_Relic(double x11, double x22, double x33, double x44, double x55, double x66, double x77, int s)
    {
        x1 = x11;
        x2 = x22;
        x3 = x33;
        x4 = x44;
        x5 = x55;
        x6 = x66;
        x7 = x77;
        sclass = s;
    }
};