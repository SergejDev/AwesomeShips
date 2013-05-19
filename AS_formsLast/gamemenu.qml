// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 246
    height: 200
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
        AButton
        {
          id:_ResumeGameButton
          x: parent.width / 4 - 30
          y: parent.height/4 -20
          width: 187
          height: 50
          button_text: "Resume Game"
          onClicked: window.ResumeGameButton_Pressed()
        }
        AButton
        {
          id: _BackToMenuButton
          x: parent.width / 4 - 30
          y: parent.height/4 + 60
          width: 187
          height: 50
          button_text: "Back To Menu"
          onClicked: window.BackToMenuButton_Pressed()
        }
    }

}
