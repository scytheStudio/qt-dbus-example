#include "Shop.h"

Shop::Shop(QObject *parent)
    : QObject{parent}
{
}

Shop::~Shop()
{
}

void Shop::startDBusService()
{
    Product::registerMetaType();

    m_adaptor = new ShopAdaptor(this);

    auto connection = QDBusConnection::sessionBus();
    if (!connection.registerService("com.scythestudio.dbus"))
    {
        qFatal("Could not register service!");
    }

    if (!connection.registerObject("/shop", this))
    {
        qFatal("Could not register Chat object!");
    }
}

void Shop::addProduct(const Product &product)
{
    m_products.append(product);
    emit productAdded(product);
}

QList<Product> Shop::getProducts()
{
    return m_products;
}
