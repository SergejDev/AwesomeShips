// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

//window's size&appiarance
Rectangle {
    id: settingsWindow

    width: 290
    height: 350


    Image {
        id: backgrImg
        x: 0
        y: 0
        width: 317
        height: 351
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        source: "deepness_1600.png"
        anchors.fill: parent

        ALabel {
            id: label_Settings
            x:97
            y:31
            text: "Settings"
            font.pixelSize: 25
        }

        //label_Language
        ALabel {
            id: label_Language
            x:31
            y:103
            text: "Language"
        }
        //label_Topic
        ALabel {
            id: label_Topic
            x:31
            y:152
            text: "Topic"
        }

        //comboboxes


        //combobox_Language

        NewAComboBox{
            objectName: "combo_lang"
            id: combobox_lang
            x: 160
            y: 103
            items: ["Русский", "English"]
            z:101
            //selectedindex: 0;
        }
        //combobox_Topic

        NewAComboBox{
            objectName: "combo_topic"
            id: combobox_topic
            x: 160
            y: 152
            //selectedindex: 0;
            items: ["Food", "Weather", "Animals"]
        }


        //end comboboxes

        AButton
        {
          id: button_toMainMenu
          x: 31
          y: 276
          width: 80
          height: 30
          button_text: "Back"
          onClicked: window.ButtonBackClickedSlot()


        }

        AButton
        {
          id: button_Save
          x: 179
          y: 276
          width: 80
          height: 30
          button_text: "Save"
          onClicked: window.on_button_Save_clicked()
        }

        AButton
        {
          id: button_Baza
          x: 31
          y: 222
          width: 228
          height: 30
          button_text: "Upload words from file"
          onClicked: window.button_baza_clicked()


        }
    }   
}
//end window's size&appiarance


