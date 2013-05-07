// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 386
    height: 249
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
    }
    Rectangle {
               id: textEditRect //Имя поля вывода

               //Размещаем ниже
               x: parent.width / 4 -70;
               y: parent.height / 4 + 30 ;

               //Размеры поле вывода
               width: 250
               height: 35

               //Цвет поля вывода
               color: "gray"

               TextEdit{
                   id: textEdit
                   objectName: "textEdit"
                   wrapMode: TextEdit.Wrap
                   width:parent.width;
                   readOnly:true
               }
           }
    Rectangle {
        width:400;
        height: 400;

        Rectangle {
                id:comboBox
                property variant items: ["Item 1", "Item 2", "Item 3"]
                property alias selectedItem: chosenItemText.text;
                property alias selectedIndex: listView.currentIndex;
                signal comboClicked;
                x: 259
                y: 27
                width: 100;
                height: 30;
                z: 100;
                smooth:true;
       }
    }
    //кнопка pushButton_2 open
    Rectangle {
        id: pushButton_2
        x: parent.width / 4 - 70 ;
        y: parent.height/4 -40;

        radius:10
        color:"#111";
        width: 70
        height: 30
        border.width: 1
        border.color: "#ffffff"
        smooth: true
        Text {
            id: textpushButton_2
            text: "Open"
            anchors.centerIn: parent;
            font.pixelSize: 12
            font.family: "Segoe Print"
            color: "white"
        }
        //Действие мыши
        MouseArea {
            anchors.fill: parent
            id: mouseAreapushButton_2
            onClicked: window.pushButton_2();
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
        id: pushButton
        x: parent.width / 4 - 70 ;
        y: parent.height/4 +140;

        radius:10
        color:"#111";
        width: 100
        height: 30
        border.width: 1
        border.color: "#ffffff"
        smooth: true
        Text {
            id: textpushButton
            text: "Back to menu"
            anchors.centerIn: parent;
            font.pixelSize: 12
            font.family: "Segoe Print"
            color: "white"
        }
        //Действие мыши
        MouseArea {
            anchors.fill: parent
            id: mouseAreapushButton
            onClicked: window.pushButton();
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
        id: pushButton_3
        x: parent.width / 4 + 160 ;
        y: parent.height/4 +140;

        radius:10
        color:"#111";
        width: 100
        height: 30
        border.width: 1
        border.color: "#ffffff"
        smooth: true
        Text {
            id: textpushButton_3
            text: "Import"
            anchors.centerIn: parent;
            font.pixelSize: 12
            font.family: "Segoe Print"
            color: "white"
        }
        //Действие мыши
        MouseArea {
            anchors.fill: parent
            id: mouseAreapushButton_3
            onClicked: window.pushButton_3();
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
}
