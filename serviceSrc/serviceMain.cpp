#include <QCoreApplication>
#include "Shop.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Shop* shop = new Shop(&a);
    shop->startDBusService();

    return a.exec();
}
