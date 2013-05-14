// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
//import com.nokia.meego 1.0

Rectangle{
    id: combobox

    x: 125
    y: 92

    width: 100
    height: 30

    property alias model:selDial.model
    property alias selectedIndex:selDial.selectedIndex
    property alias titleSelectionDialog:selDial.titleText
    property alias combobox_text:combobox_style.text

    radius:10
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#00BFFF"
        }

        GradientStop {
            position: 1
            color: "#000000"
        }
    }
    border.width: 1
    border.color: "#ffffff"
    smooth: true

    ALabel
    {
        id: combobox_style
        x: 5
        y: 0
        text: "???"
    }

    MouseArea
    {
        id: mouseAreaCombobox
        x: 0
        y: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        onClicked: selDial.open()

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


    SelectionDialog
    {
        id: selDial
        anchors.fill: parent

        selectedIndex: 0
        onAccepted: { combobox_style.text = selDial.model.get(selDial.selectedIndex).name }
        //onSelectedIndexChanged: { combobox_style.text = selDial.model.get(selDial.selectedIndex).name }
    }

}
