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

    Rectangle {
               id: textEditRect //Имя поля вывода

               //Размещаем ниже
               x: parent.width / 4 -80
               y: parent.height / 4 + 30

               //Размеры поле вывода
               width: 200
               height: 25

               //Цвет поля вывода
               color: "gray"

               TextEdit{
                   id: textEdit
                   objectName: "textEdit"
                   wrapMode: TextEdit.Wrap
                   width:parent.width;
                   height: 25
                   readOnly:true
               }
           }
/*
    AComboBox{
        objectName: "combo_topic"
        id: combobox_topic
        x: 257
        y: 23
        width: 98
        height: 29
        combobox_text: "Food"
        model: model_topic
        titleSelectionDialog: "Topic"

    }
    */
    AButton
    {
      id: on_pushButton_2
      x: parent.width / 4 -80
      y: parent.height/4 -40
      width: 118
      height: 30
      button_text: "Open"
      onClicked: window.ButtonOpen()
    }
    AButton
    {
      id: pushButton
      x: parent.width / 4 - 80
      y: parent.height/4 +140
      width: 118
      height: 30
      button_text: "Back to menu"
      onClicked: window.ButtonBack()
    }
    AButton
    {
      id: pushButton_3
      x: parent.width / 4 + 160
      y: parent.height/4 +140
      width: 119
      height: 30
      button_text: "Import"
      onClicked: window.ButtonImport()
    }

}
    ListModel{
        id: model_topic

            ListElement{
                name: "Food"
            }
            ListElement{
                name: "Weather"
            }
            ListElement{
                name: "Animals"
            }
        }





}
