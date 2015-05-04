import QtQuick 2.0

ListView {

    //model: root.playerMusic.currentPlaylist

    Component.onCompleted: {
        taskbar.source = "qrc:/RecorderPageTaskBar.qml"
    }
}
