import QtQuick 1.1

Rectangle {
    width: 1000
    height: 700
    color: "transparent"
    Text {
        id: scoreLabel
        objectName: "scoreLabel"
        x: 10
        y: 10
        color: "#ffffff"
        text: qsTr("Score:")
        font.family: "Segoe Print"
        font.pixelSize: 18
    }
    Text {
        id: levelLabel
        objectName: "levelLabel"
        x: scoreLabel.width + 20
        y: 10
        color: "#ffffff"
        text: qsTr("Level:")
        font.family: "Segoe Print"
        font.pixelSize: 18
    }

    Rectangle {
        id: gameMenuButton
        x: parent.width - 90;
        y: 15;
        radius:10
        color:"#111";
        width: 70;
        height: 30
        border.width: 1
        border.color: "#ffffff"
        smooth: true
        Text {
            text: "Menu"
            anchors.centerIn: parent;
            font.pixelSize: 12
            font.family: "Segoe Print"
            color: "white"
        }
        MouseArea {
            id: gameMenuButtonMouseArea
            anchors.fill: parent
            onClicked:{
                window.MenuButtonPressed();
                window.PauseGame();
            }
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

    Rectangle {
        id: inputFieldWrapper
        x: parent.width / 2 - width / 2;
        y: parent.height - height - 10;
        radius:10
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
        width: 450
        height: 30
        border.width: 1
        border.color: "#ffffff"
        smooth: true
        TextInput {
            id: inputField
            objectName: "inputField"
            x: 10
            y: 5
            anchors.fill: parent
            anchors.margins: 5
            color: "#fdfdfd"
            text: ""
            font.family: "Segoe Print"
            cursorVisible: false
            font.pixelSize: 12
            onTextChanged: window.InputFieldTextChanged(text)
            focus: true
        }
        MouseArea {
            id: inputFieldWrapperMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                parent.border.width = 2
                inputField.cursorVisible = true
                inputField.forceActiveFocus()
            }
            onExited:  {
                parent.border.width = 1
            }
        }
    }
}
