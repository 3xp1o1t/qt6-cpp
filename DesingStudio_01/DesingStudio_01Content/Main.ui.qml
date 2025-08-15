/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick
import QtQuick.Controls

Item {
    id: root
    width: 800
    height: 600

    Image {
        id: dark_Nature
        anchors.fill: parent
        source: "images/background.png"
        fillMode: Image.Tile
    }

    Rectangle {
        id: topPanel
        height: 74
        border.color: "#80000000"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.topMargin: 0
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#805bcce9"
            }

            GradientStop {
                position: 1
                color: "#000000"
            }
            orientation: Gradient.Vertical
        }

        Text {
            id: dateTime
            color: "#ffffff"
            text: qsTr("Wednesday, 09-08-2025 4:04 PM")
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: 0
            anchors.topMargin: 29
            font.pixelSize: 12
        }

        Rectangle {
            id: shutdownButton
            width: 50
            height: 50
            color: "#27a9e3"
            radius: 2
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.rightMargin: 10
            anchors.topMargin: 8

            Image {
                id: shutdownIcon
                anchors.fill: parent
                source: "images/shutdown-icon.png"
                fillMode: Image.PreserveAspectFit
            }
        }

        Rectangle {
            id: restartButton
            x: 740
            y: 8
            width: 50
            height: 50
            color: "#27a9e3"
            radius: 2
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.rightMargin: 70
            anchors.topMargin: 8
            Image {
                id: restartIcon
                anchors.fill: parent
                source: "images/restart-icon.png"
                fillMode: Image.PreserveAspectFit
            }
        }
    }

    Rectangle {
        id: loginForm
        width: 360
        height: 200
        color: "#80000000"
        radius: 15
        anchors.verticalCenterOffset: 100
        anchors.horizontalCenterOffset: 0
        anchors.centerIn: parent

        Text {
            id: text1
            x: 37
            y: 54
            color: "#ffffff"
            text: qsTr("Username:")
            font.pixelSize: 12
        }

        Text {
            id: text2
            x: 37
            y: 92
            color: "#ffffff"
            text: qsTr("Password:")
            font.pixelSize: 12
        }

        TextInput {
            id: username
            x: 117
            y: 54
            width: 203
            height: 20
            text: qsTr("Text Input")
            font.pixelSize: 12

            Rectangle {
                id: rectangle
                color: "#ffffff"
                radius: 5
                anchors.fill: parent
            }
        }

        TextInput {
            id: password
            x: 117
            y: 92
            width: 203
            height: 20
            text: qsTr("Text Input")
            font.pixelSize: 12

            Rectangle {
                id: rectangle1
                color: "#ffffff"
                radius: 5
                anchors.fill: parent
            }
        }

        Rectangle {
            id: login
            x: 37
            y: 149
            width: 283
            height: 29
            color: "#27a0e3"
            radius: 5

            MouseArea {
                id: mouseArea
                x: -37
                y: -149
                anchors.fill: parent
            }

            Text {
                id: text3
                color: "#ffffff"
                text: qsTr("Login")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignLeft
                anchors.centerIn: parent
            }
        }

    }

    Image {
        id: logo
        x: 144
        y: 88
        width: 512
        height: 200
        source: "images/logo.jpg"
        fillMode: Image.PreserveAspectFit
    }



}
