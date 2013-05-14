import QtQuick 1.1

Rectangle {
    width: 190
    height: 360
    smooth: true
    Image {
        x: 0
        y: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        source: "deepness_1600.jpg"
        sourceSize.width: 698
        sourceSize.height: 821
        anchors.fill: parent

        ALabel
        {
            id: textName
            x: parent.width/4 - textName.width / 2
            y: serverAddressEdit.y + 40
            text: qsTr("Name:")
        }

        ALabel
        {
            id: textPassword
            x: parent.width/2
            y: textIP.y +40
            text: qsTr("Password:")
        }

        ALabel
        {
            id: textTitle
            x: parent.width/2 - textTitle.width / 2
            y: 10            
            text: qsTr("Awesome ships")
        }

        ALabel
        {
            id: textIP
            x: parent.width/4 - textIP.width / 2
            y: textTitle.y+40
            text: qsTr("IP:")
        }
    }

    //Adress
    ATextBox {
        x: parent.width / 2 - serverAddressEdit.width / 2;
        y: textTitle.y+40
        text: "127.0.0.1"
        objectName: "ip"
    }

    //UserName
    ATextBox {
        x: parent.width / 4 - rectUserName.width / 2;
        y: textName.y+40
        text: ""
        objectName: "username"
    }

    //Password
    ATextBox {
        x: parent.width / 2 + password.width / 2;
        y: textName.y +40
        text: ""
        objectName: "password"
    }

    //Кнопка Register
    AButton
    {
      id: _RegisterButton
      x: parent.width / 2 - _RegisterButton.width / 2
      y: rectPassword.y +40
      button_text: "Register"
      MouseArea {
          anchors.fill: parent
          id: mouseAreaReg
          onReleased: window.RegisterButtonPressed();
          onPressed: window.GetUserData();
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

    //кнопка start
    AButton
    {
      id: startPushButton
      x: parent.width / 2 - startPushButton.width / 2;
      y: _RegisterButton.y+40;
      button_text: "Start"
      MouseArea {
          anchors.fill: parent
          id: mouseAreaStart
          onReleased: window.StartButtonPressed();
          onPressed: window.GetUserData();
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

    //кнопка settingsPushButton
    AButton
    {
      id: settingsPushButton
      x: parent.width / 2 - settingsPushButton.width / 2;
      y: startPushButton.y+40;
      button_text: "Setting"
      onClicked: window.SettingsButtonPressed();
    }

    //кнопка Quit
    AButton
    {
      id:quitPushButton
      x: parent.width / 2 - quitPushButton.width / 2;
      y: settingsPushButton.y+40;
      button_text: "Quit"
      onClicked: window.QuitButtonPressed();
    }

}

