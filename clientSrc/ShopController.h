#ifndef SHOPCONTROLLER_H
#define SHOPCONTROLLER_H

#include <QObject>
#include "ShopInterface.h"
#include "../common/datasets/Product.h"

class ShopController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Product> products READ products NOTIFY productsChanged)

public:
    explicit ShopController(QObject *parent = nullptr);

    QList<Product> products();

public slots:
    void addProduct(const QString &name, const int &amount);

signals:
    void productsChanged();

private:
    ComScythestudioDbusShopInterface* m_interface;
};

#endif // SHOPCONTROLLER_H
