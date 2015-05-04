import QtQuick 2.0

import "helpers.js" as Helpers

Rectangle {
    color: "black"

    TaskBarButton {
        id: button1
        width: parent.width/2 - 2
        icon: "qrc:/images/media-record.png"

        MouseArea {
            anchors.fill: parent
            onClicked: recorder.record()
        }
    }

    TaskBarButton {
        id: button2
        anchors.left: button1.right
        width: parent.width/2 - 2
        anchors.leftMargin: 4
        icon: "qrc:/images/media-playback-stop.png"

        MouseArea {
            anchors.fill: parent
            onClicked: recorder.stop()
        }
    }

}

