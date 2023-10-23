#include "Product.h"

Product::Product()
{
}

Product::Product(const QString &name, const int  &amount) :
    m_name(name),
    m_amount(amount)
{
}

Product::~Product()
{
}

QString Product::name() const
{
    return m_name;
}

int Product::amount() const
{
    return m_amount;
}

void Product::registerMetaType()
{
    qRegisterMetaType<Product>("Product");
    qRegisterMetaType<QList<Product>>("QList<Product>");

    qDBusRegisterMetaType<Product>();
    qDBusRegisterMetaType<QList<Product>>();
}

QDBusArgument &operator<<(QDBusArgument &argument, const Product& product)
{
    argument.beginStructure();
    argument << product.m_name;
    argument << product.m_amount;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, Product &product)
{
    argument.beginStructure();
    argument >> product.m_name;
    argument >> product.m_amount;
    argument.endStructure();

    return argument;
}

