import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.3

Window {
    visible: true

    ComboBox {
        width: parent.width
        model: recorder.inputs
    }

}
