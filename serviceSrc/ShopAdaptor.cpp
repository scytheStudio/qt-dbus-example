/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp ../common/Shop.xml -i ../common/datasets/Product.h -a ShopAdaptor
 *
 * qdbusxml2cpp is Copyright (C) 2023 The Qt Company Ltd and other contributors.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "ShopAdaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class ShopAdaptor
 */

ShopAdaptor::ShopAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

ShopAdaptor::~ShopAdaptor()
{
    // destructor
}

void ShopAdaptor::addProduct(Product product)
{
    // handle method call com.scythestudio.dbus.shop.addProduct
    QMetaObject::invokeMethod(parent(), "addProduct", Q_ARG(Product, product));
}

QList<Product> ShopAdaptor::getProducts()
{
    // handle method call com.scythestudio.dbus.shop.getProducts
    QList<Product> out0;
    QMetaObject::invokeMethod(parent(), "getProducts", Q_RETURN_ARG(QList<Product>, out0));
    return out0;
}

