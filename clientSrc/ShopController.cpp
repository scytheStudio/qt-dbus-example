#include "ShopController.h"

ShopController::ShopController(QObject *parent)
    : QObject{parent}
{
    m_interface = new ComScythestudioDbusShopInterface("com.scythestudio.dbus", "/shop",
                                                       QDBusConnection::sessionBus(), this);

    Product::registerMetaType();
    connect(m_interface, &ComScythestudioDbusShopInterface::productAdded, this, &ShopController::productsChanged);
}

QList<Product> ShopController::products()
{
    if (!m_interface->isValid()) {
        return QList<Product>();
    }

    return m_interface->getProducts().value();
}

void ShopController::addProduct(const QString& name, const int& amount)
{
    if (m_interface->isValid()) {
        Product product(name, amount);
        m_interface->addProduct(product);
    }
}
