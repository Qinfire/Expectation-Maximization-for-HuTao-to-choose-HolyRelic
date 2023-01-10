#include "HuTao.h"
#include<cstring>
#include<fstream>
#include <sstream>
using namespace std;

HuTao::HuTao(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
}

HuTao::~HuTao()
{

}
    
void HuTao::addX()
{
    X.clear();
    X.append(ui.x1->text());
    X.append(ui.x2->text());
    X.append(ui.x3->text());
    X.append(ui.x4->text());
    X.append(ui.x5->text());
    X.append(ui.x6->text());
    X.append(ui.x7->text());
}

QTableWidget** HuTao::getTable()
{
    int sclass = ui.hclass->currentIndex();
    QTableWidget** table = &(ui.tableWidget);
    if (sclass == 0)
    {
        table = &ui.tableWidget;
    }
    else if (sclass == 1)
    {
        table = &ui.tableWidget_2;
    }
    else if (sclass == 2)
    {
        table = &ui.tableWidget_3;
    }
    else if (sclass == 3)
    {
        table = &ui.tableWidget_4;
    }
    else if (sclass == 4)
    {
        table = &ui.tableWidget_5;
    }

    return table;
}

void HuTao::addValues()
{
    if (!(ui.tableWidget->isEnabled()))return;
    QTableWidget** table = getTable();
    int rowIndex = (*table)->rowCount();
    (*table)->setRowCount(rowIndex + 1);

    QTableWidgetItem* item = new QTableWidgetItem(ui.rclass->currentText());
    (*table)->setItem(rowIndex, 0, item);
    addX();
    for (int i = 0; i < 7; i++)
    {
        item = new QTableWidgetItem(X[i]);
        (*table)->setItem(rowIndex, i + 1, item);
    }
}

void HuTao::deleteValues()
{
    if (!(ui.tableWidget->isEnabled()))return;
    QTableWidget** table = getTable();
    int rowIndex = (*table)->currentRow();
    if (rowIndex != -1)
    {
        (*table)->removeRow(rowIndex);
    }
}

void HuTao::transformPage(int n)
{
    ui.tabWidget->setCurrentIndex(n);
}

void HuTao::transformTab(int n)
{
    ui.hclass->setCurrentIndex(n);
}

void HuTao::load(QTableWidget** table, vector<holy_Relic>& holyR)
{
    holyR.clear();
    int s = 1;
    int n = (*table)->rowCount();
    double nu[7] = { 0 };
    for (int i = 0; i < n; i++)
    {
        QString sc = (*table)->item(i, 0)->text();
        QString sclass = ui.rclass->itemText(0);
        if (sclass != sc)s = 0;
        for (int j = 1; j < 8; j++)
        {
            QString str = (*table)->item(i, j)->text();
            int num = str.toInt();
            nu[j - 1] = num;
        }
        holyR.push_back(holy_Relic(nu[0], nu[1], nu[2], nu[3], nu[4], nu[5], nu[6], s));
   }
}

void HuTao::load_data()
{
    load(&ui.tableWidget, Flower);
    load(&ui.tableWidget_2, Feather);
    load(&ui.tableWidget_3, Hourglass);
    load(&ui.tableWidget_4, Cup);
    load(&ui.tableWidget_5, Crown);
}

void HuTao::showtao(QTableWidget** table, int n)
{
    (*table)->insertRow(0);
    for (int i = 0; i < 8; i++)
    {
        QTableWidgetItem* item = new QTableWidgetItem((*table)->item(n + 1, i)->text());
        (*table)->setItem(0, i, item);
    }
}

void HuTao::showmax(int tangzhu[])
{
    showtao(&ui.tableWidget, tangzhu[0]);
    showtao(&ui.tableWidget_2, tangzhu[1]);
    showtao(&ui.tableWidget_3, tangzhu[2]);
    showtao(&ui.tableWidget_4, tangzhu[3]);
    showtao(&ui.tableWidget_5, tangzhu[4]);
}

void HuTao::compute()
{
    if (!(ui.tableWidget->isEnabled()))return;

    load_data();
    int maxtao[5] = { 0 };
    double maxE = 0;
    int n = 0;
    for (int i = 0; i < Flower.size(); i++)
    {
        for (int j = 0; j < Feather.size(); j++)
        {
            for (int k = 0; k < Hourglass.size(); k++)
            {
                for (int l = 0; l < Cup.size(); l++)
                {
                    for (int m = 0; m < Crown.size(); m++)
                    {
                        int nclass = Flower[i].sclass + Feather[j].sclass + Hourglass[k].sclass + Cup[l].sclass + Crown[m].sclass;
                        if (nclass < 4)continue;
                        tao.HolyR(Flower[i], Feather[j], Hourglass[k], Cup[l], Crown[m]);
                        tao.data();
                        if (tao.E4() > maxE)
                        {
                            maxtao[0] = i;
                            maxtao[1] = j;
                            maxtao[2] = k;
                            maxtao[3] = l;
                            maxtao[4] = m;
                            maxE = tao.E4();
                        }
                    }
                }
            }
        }
    }
    showmax(maxtao);
    ui.tableWidget->setEnabled(false);
    ui.tableWidget_2->setEnabled(false);
    ui.tableWidget_3->setEnabled(false);
    ui.tableWidget_4->setEnabled(false);
    ui.tableWidget_5->setEnabled(false);
}

void HuTao::recover()
{
    if (ui.tableWidget->isEnabled())return;
    ui.tableWidget->setEnabled(true);
    ui.tableWidget->removeRow(0);
    ui.tableWidget_2->setEnabled(true);
    ui.tableWidget_2->removeRow(0);
    ui.tableWidget_3->setEnabled(true);
    ui.tableWidget_3->removeRow(0);
    ui.tableWidget_4->setEnabled(true);
    ui.tableWidget_4->removeRow(0);
    ui.tableWidget_5->setEnabled(true);
    ui.tableWidget_5->removeRow(0);
}

void HuTao::clearT(QTableWidget** table)
{
    while ((*table)->rowCount())
    {
        (*table)->removeRow(0);
    }
}

void HuTao::clear()
{
    if (ui.tableWidget->isEnabled())
    {
        QTableWidget** table = getTable();
        clearT(table);
    }
}

void HuTao::saveT(QTableWidget** table, string name)
{
    int n = (*table)->rowCount();
    ofstream file;
    file.open(name, ios::out);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            QString sc = (*table)->item(i, j)->text();
            string str = sc.toLocal8Bit().toStdString();
            file << str << ",";
        }
        file << '\n';
    }
    file.close();
}

void HuTao::save()
{
    if (!(ui.tableWidget->isEnabled()))return;
    saveT(&ui.tableWidget, "./data/flower.csv");
    saveT(&ui.tableWidget_2, "./data/feather.csv");
    saveT(&ui.tableWidget_3, "./data/hourglass.csv");
    saveT(&ui.tableWidget_4, "./data/cup.csv");
    saveT(&ui.tableWidget_5, "./data/crown.csv");
}

void HuTao::read_csv(QTableWidget** table, string name)
{
    ifstream file(name);
    string line;
    QVector<QString> xx;
    while (getline(file, line))
    {
        string data;
        xx.clear();
        istringstream str(line);

        int rowIndex = (*table)->rowCount();
        (*table)->setRowCount(rowIndex + 1);

        for (int i = 0; i < 8; i++)
        {
            getline(str, data, ',');
            QString stc = QString::fromStdString(data);
            QTableWidgetItem * item = new QTableWidgetItem(stc);
            (*table)->setItem(rowIndex, i, item);
        }
    }
}

void HuTao::read()
{
    if (!(ui.tableWidget->isEnabled()))return;

    clearT(&ui.tableWidget);
    clearT(&ui.tableWidget_2);
    clearT(&ui.tableWidget_3);
    clearT(&ui.tableWidget_4);
    clearT(&ui.tableWidget_5);

    read_csv(&ui.tableWidget, "./data/flower.csv");
    read_csv(&ui.tableWidget_2, "./data/feather.csv");
    read_csv(&ui.tableWidget_3, "./data/hourglass.csv");
    read_csv(&ui.tableWidget_4, "./data/cup.csv");
    read_csv(&ui.tableWidget_5, "./data/crown.csv");
}