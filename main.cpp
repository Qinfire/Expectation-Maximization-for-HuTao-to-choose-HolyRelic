#include "HuTao.h"
#include <QtWidgets/QApplication>
#include<QTextCodec>

int main(int argc, char *argv[])
{
    //-------------
    //�����������
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    //-------------


    QApplication a(argc, argv);
    HuTao w;
    w.show();
    return a.exec();
}
