import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    visible: true

    ListView {
        anchors.fill: parent
        model: recorder.inputs
        delegate: Text {
            text: modelData
        }
    }

}
