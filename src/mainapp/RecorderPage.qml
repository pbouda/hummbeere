import QtQuick 2.0

Column {

    //model: root.playerMusic.currentPlaylist

    Component.onCompleted: {
        taskbar.source = "qrc:/RecorderPageTaskBar.qml"
    }
}
