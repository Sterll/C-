/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 6.5
import QtQuick.Controls 6.5
import Test

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height
    color: "#191919"


    Rectangle {
        id: valoRectangle
        x: 30
        y: 19
        width: 268
        height: 405
        color: "#494343"
        radius: 19

        Button {
            id: button
            x: 0
            y: 0
            width: 268
            height: 405
            visible: false
            text: qsTr("Button")
            layer.enabled: false

            Connections {
                target: button
                onClicked: rectangle.state = "clicked"
            }
        }
    }

    Text {
        id: text1
        x: 344
        y: 32
        width: 700
        height: 552
        color: "#ffffff"
        text: qsTr("Text")
        font.pixelSize: 12
    }
    states: [
        State {
            name: "clicked"
        }
    ]
}
