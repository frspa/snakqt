import QtQuick 2.3
import QtQuick.Window 2.3

Window {
    id: mainWindow
    visible: true
    color: "yellow"

    Item{
        id: mainScreenArea
        focus: true
        anchors.fill: parent

        Text {
            id: infoText
            text: qsTr("Welcome to Snakqt")
            color: "green"
            font.pointSize: 30
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        Keys.onEscapePressed: {
            mainWindow.close()
            event.accepted = true;
        }
    }
}
