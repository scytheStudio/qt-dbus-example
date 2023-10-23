#ifndef SHOP_H
#define SHOP_H

#include <QObject>
#include "../common/datasets/Product.h"
#include "ShopAdaptor.h"

class Shop : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.scythestudio.dbus.shop")

public:
    explicit Shop(QObject *parent = nullptr);
    virtual ~Shop();

    void startDBusService();

public slots:
    void addProduct(const Product& product);
    QList<Product> getProducts();

signals:
    void productAdded(const Product &product);

private:
    QList<Product> m_products = {Product("Apple", 21), Product("Orange", 37)};
    ShopAdaptor* m_adaptor;
};

#endif // SHOP_H
