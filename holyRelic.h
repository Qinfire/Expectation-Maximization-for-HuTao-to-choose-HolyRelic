#pragma once
#include<iostream>
using namespace std;

//圣遗物
class holy_Relic
{
public:
    int sclass = 1;//圣遗物类别
    double x1 = 0;//暴击率
    double x2 = 0;//暴击伤害
    double x3 = 0;//大生命
    double x4 = 0;//小生命
    double x5 = 0;//大攻击
    double x6 = 0;//小攻击
    double x7 = 0;//精通

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