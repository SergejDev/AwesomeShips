import QtQuick 1.1

Rectangle {
    property string text: ""
    radius:10
    width: 80
    height: 30
    border.width: 1
    border.color: "#ffffff"
    smooth: true
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#585151"
        }

        GradientStop {
            position: 1
            color: "#000000"
        }
    }
    TextInput {
        id: ip
        x: 10
        y: 5
        width: 60
        height: 30
        color: "#fdfdfd"
        text: parent.text
        font.family: "Segoe Print"
        cursorVisible: false
        font.pixelSize: 12
    }
    MouseArea {
        anchors.fill: parent
        id: mouseAreaIP
        hoverEnabled: true
        onEntered: {
            parent.border.width = 2
            ip.cursorVisible = true
            ip.forceActiveFocus()
        }
        onExited:  {
            parent.border.width = 1
        }
    }
}
