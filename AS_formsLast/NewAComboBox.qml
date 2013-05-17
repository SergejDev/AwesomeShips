// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
        id:comboBox
        width:100
        height: 30

        property variant items: ["Item 1", "Item 2", "Item 3"]
        property alias selectedItem: chosenItemText.text;
        property alias selectedindex: listView.currentIndex;
        signal comboClicked;

        radius:10

        smooth: true

        z: 100

        Rectangle {
            id:chosenItem
            radius:parent.radius
            width:parent.width;
            height:comboBox.height;
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
            border.width: 2
            border.color: "#ffffff"

            ALabel {
                anchors.top: parent.top;
                anchors.left: parent.left;
                id:chosenItemText
                x: 14
                y: 0
                text:comboBox.items[0];
                smooth: false
                clip: false
                anchors.leftMargin: 14
                anchors.topMargin: 0
            }

            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    comboBox.state = comboBox.state==="dropDown"?"":"dropDown"
                }
            }
        }

        Rectangle {
            id:dropDown
            width:comboBox.width;
            height:0;
            clip:true;
            radius:parent.radius;
            anchors.top: chosenItem.bottom;
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

            border.width: 2
            border.color: "#ffffff"
            ListView {
                id:listView
                height:500;
                model: comboBox.items
                currentIndex: 0
                delegate: Item{
                    width:comboBox.width;
                    height: comboBox.height;

                    ALabel {
                        text: modelData
                        anchors.top: parent.top;
                        anchors.left: parent.left;
                    }
                    MouseArea {
                        anchors.fill: parent;
                        onClicked: {
                            comboBox.state = ""
                            var prevSelection = chosenItemText.text
                            chosenItemText.text = modelData
                            if(chosenItemText.text != prevSelection){
                                comboBox.comboClicked();
                            }
                            listView.currentIndex = index;
                        }
                    }
                }
            }
        }
        states: State {
            name: "dropDown";
            PropertyChanges { target: dropDown; height:35*comboBox.items.length }
        }

        transitions: Transition {
            NumberAnimation { target: dropDown; properties: "height"; easing.type: Easing.OutExpo; duration: 1000 }
        }
}
