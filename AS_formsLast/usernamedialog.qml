// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: mainWindow
    width: 210
    height: 97

    anchors.fill: parent

    Image {
        id: image
        x: 0
        y: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        source: "deepness_1600.png"
        sourceSize.width: 698
        sourceSize.height: 821
        anchors.fill: parent

        Text {
            id: textName
            width: 192
            height: 48

            x: 45
            y: 9

            color: "#ffffff"
            text: qsTr("Game over")
            font.family: "Segoe Print"
            font.pixelSize: 20
        }

        Rectangle {
            width: 100
            height: 30
            y: textName.y + textName.height + 5
            radius: 10
            color: "transparent";
            border.width: 1
            border.color: "#ffffff"

            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                id: buttonLabel
                text: "Ok"
                font.family: "Segoe Print"
                font.pixelSize: 15
                anchors.centerIn: parent;
            }

            MouseArea {
                id: okButton

                anchors.fill: parent
                hoverEnabled: true
                onExited:  {
                    parent.border.width = 1
                }
                onEntered: {
                    parent.border.width = 2
                }
                onPressed: {
                    parent.border.width = 3
                }
                onReleased: {
                    window.okButtonClicked();
                }
            }
        }
    }
}
