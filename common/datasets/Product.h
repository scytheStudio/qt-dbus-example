#ifndef PRODUCT_H
#define PRODUCT_H

#include <QtDBus>

class Product
{
    Q_GADGET

public:
    Product();
    Product(const QString &name, const int &amount);
    ~Product();

    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(int amount READ amount)

    friend QDBusArgument &operator<<(QDBusArgument &argument, const Product &product);
    friend const QDBusArgument &operator>>(const QDBusArgument &argument, Product &product);

    QString name() const;
    int amount() const;

    //register Product with the Qt type system
    static void registerMetaType();

private:
    QString m_name;
    int m_amount;
};

Q_DECLARE_METATYPE(Product)

#endif // PRODUCT_H
