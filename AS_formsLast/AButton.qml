// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: button_awesome

    property string button_text: "ОК :)"
    signal clicked

    radius:10
    //color:"#111";
    width: 70;
    height: 30
    border.width: 1
    border.color: "#ffffff"
    smooth: true

    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#808080"
        }

        GradientStop {
            position: 1
            color: "#000000"
        }
    }

    //Текст кнопки
    Text {
        id: button_text
        text: button_awesome.button_text
        anchors.centerIn: parent;
        font.pixelSize: 12
        font.family: "Segoe Print"
        color: "white"

    }


    MouseArea{
        anchors.fill: parent
        onClicked: button_awesome.clicked()
        hoverEnabled: true

        onEntered: {
            parent.border.width = 2
            parent.color = "#333"
        }
        onExited:  {
            parent.border.width = 1
            parent.color = "#111"
        }

    }
}
