#pragma once
#include<QTextCodec>
#include <QtWidgets/QWidget>
#include <ui_HuTao.h>
#include<vector>
#include<QVector>
#include<cstring>
#include "tangZhu.h"
#include"Ganyu.h"
#include"holyRelic.h"
#include"chara.h"

class HuTao : public QWidget
{
    Q_OBJECT

public:
    HuTao(QWidget *parent = Q_NULLPTR);
    ~HuTao();

private:
    //±äÁ¿
    Ui::HuTaoClass ui;
    QVector<QString> X;
    tangZhu tao;
    Ganyu ganyu;

    vector<holy_Relic> Flower;
    vector<holy_Relic> Feather;
    vector<holy_Relic> Hourglass;
    vector<holy_Relic> Cup;
    vector<holy_Relic> Crown;

    //º¯Êý
    void addX();
    QTableWidget** getTable();
    void load_data();
    void load(QTableWidget** table, vector<holy_Relic>& holyR);
    void showmax(int cha[]);
    void showchara(QTableWidget** table, int n);
    void showdata(double data[]);
    void computeChara(chara& cha);
  
private slots:
    
    void addValues();
    void deleteValues();
    void transformPage(int n);
    void transformTab(int n);
    void compute();
    void recover();
    void clear();
    void clearT(QTableWidget** table);
    void save();
    void saveT(QTableWidget** table, string name);
    void read();
    void read_csv(QTableWidget** table, string name);
};

