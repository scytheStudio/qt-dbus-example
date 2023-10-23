import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    id: root

    width: 640
    height: 480

    visible: true
    title: qsTr("Shop")
    color: "#18171c"

    RowLayout {
        id: columnLayout

        anchors.fill: parent

        spacing: 20

        ListView {
            id: productsListView

            Layout.maximumWidth: 300
            Layout.minimumWidth: 300

            Layout.fillHeight: true

            clip: true
            model: shopController.products

            delegate: Rectangle {
                id: delegateBackground

                width: productsListView.width
                height: 75

                color: "#218165"

                border {
                    width: 4
                    color: "#18171c"
                }

                Text {
                    id: delegate

                    anchors.centerIn: parent

                    text: modelData.name+ " " + modelData.amount
                    color: "white"
                }
            }
        }

        ColumnLayout {
            id: rowLayout

            Layout.fillWidth: true
            Layout.fillHeight: true

            spacing: 30

            Text {
                id: nameText

                text: "Name"
                color: "white"
            }

            TextField {
                id: productField

                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            Text {
                id: amountText

                text: "Amount"
                color: "white"
            }

            TextField {
                id: amountField

                Layout.fillHeight: true
                Layout.fillWidth: true

                validator: IntValidator{}
            }

            Button {
                id: addButton

                Layout.fillWidth: true
                Layout.fillHeight: true

                text: "Add product"

                onClicked: {
                    shopController.addProduct(productField.text, amountField.text)
                    productField.clear()
                    amountField.clear()
                }
            }
        }
    }
}
