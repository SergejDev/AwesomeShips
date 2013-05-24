import QtQuick 1.1
import Qt 4.7
//import "ColumnWidthCounter.js" as ColumnWidthCounter

Rectangle {
    id: mainWindow
    width: 250
    height: 300

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

        Rectangle{
            x: 5
            y: 5

            width: mainWindow.width - 10
            height: mainWindow.height - 10

            color: "#ffffff"

            /*
            GridView{
                anchors.fill: parent
                cellWidth: 100
                cellHeight: 20

                model: list
                delegate: Row{
                    width: parent.width
                    Column{
                        Text{
                            text: modelData.split(",")[0] + " "
                        }
                    }
                    Column{
                        Text{
                            text: modelData.split(",")[1] + " "
                        }
                    }
                    Column{
                        Text{
                            text: modelData.split(",")[2]
                        }
                    }
                }
            }
            */
            ListView {
                objectName: "listView"
                id: listView
                anchors.fill: parent
                model: list
                delegate:
                    Row{
                    width: parent.width
                    Column{
                        Text{
                            width: 150
                            text: modelData.split(",")[0]
                        }
                    }
                    Column{
                        Text{
                            width: 40
                            text: modelData.split(",")[1]
                        }
                    }
                    Column{
                        Text{
                            text: modelData.split(",")[2]
                        }
                    }
                }
            }
        }
    }
}
