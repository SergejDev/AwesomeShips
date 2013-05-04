import QtQuick 1.1

Rectangle {
    width: 187
    height: 358

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

            Text {
                id: textName
                x: parent.width/4 - textName.width / 2
                y: serverAddressEdit.y +40
                color: "#ffffff"
                text: qsTr("Name:")
                font.family: "Segoe Print"
                font.pixelSize: 18
            }

            Text {
                id: textPassword
                x: parent.width/2
                y: textIP.y +40
                color: "#ffffff"
                text: qsTr("Password:")
                font.family: "Segoe Print"
                font.pixelSize: 18
            }

            Text {
                id: textTitle
                x: parent.width/2 - textTitle.width / 2
                y: 10
                color: "#ffffff"
                text: qsTr("Awesome ships")
                font.family: "Segoe Print"
                font.pixelSize: 18
            }

            Text {
                id: textIP
                x: parent.width/4 - textIP.width / 2
                y: textTitle.y+40
                color: "#ffffff"
                text: qsTr("IP:")
                font.family: "Segoe Print"
                font.pixelSize: 18
            }
        }

        //Adress
        Rectangle {
            id: serverAddressEdit
            x: parent.width / 2 - serverAddressEdit.width / 2;
            y: textTitle.y+40
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
            width: 80;
            height: 30
            border.width: 1
            border.color: "#ffffff"

                TextInput {
                    id: ip
                    objectName: "ip"
                    x: 10
                    y: 5
                    width: 60
                    height: 30
                    color: "#fdfdfd"
                    text: "127.0.0.1"
                    font.family: "Segoe Print"
                    cursorVisible: false
                    font.pixelSize: 12
                }
                MouseArea {
                    anchors.fill: parent
                    id: mouseAreaIP
                    hoverEnabled: true
                    onEntered: {
                        parent.border.width = 2
                        ip.cursorVisible = true
                        ip.forceActiveFocus()
                    }
                    onExited:  {
                        parent.border.width = 1
                    }
                }
            }

        //UserName
        Rectangle {
            id: rectUserName
            x: parent.width / 4 - rectUserName.width / 2;
            y: textName.y+40
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
            width: 70;
            height: 30
            border.width: 1
            border.color: "#ffffff"

                TextInput {
                    id: username
                    objectName: "username"
                    x: 10
                    y: 5
                    width: 50
                    height: 30
                    color: "#fdfdfd"
                    text: ""
                    font.family: "Segoe Print"
                    cursorVisible: false
                    font.pixelSize: 12
                }
                MouseArea {
                    anchors.fill: parent
                    id: mouseAreaUserName
                    hoverEnabled: true
                    onEntered: {
                        parent.border.width = 2
                        username.cursorVisible = true
                        username.forceActiveFocus()
                    }
                    onExited:  {
                        parent.border.width = 1
                    }
                }
            }

        //Password
     Rectangle {
        id: rectPassword
        x: parent.width / 2 + password.width / 2;
        y: textName.y +40
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
        width: 70;
        height: 30
        border.width: 1
        border.color: "#ffffff"

            TextInput {
                id: password
                objectName: "password"
                x: 10
                y: 5
                width: 50
                height: 30
                color: "#fdfdfd"
                text: ""
                font.family: "Segoe Print"
                cursorVisible: false
                font.pixelSize: 12
                echoMode: TextInput.Password
            }

            MouseArea {
                anchors.fill: parent
                id: mouseAreaPassword
                hoverEnabled: true
                onEntered: {
                    parent.border.width = 2
                    password.cursorVisible = true
                    password.forceActiveFocus()
                }
                onExited:  {
                    parent.border.width = 1
                }
            }
        }

        //Кнопка Register
            Rectangle {
                id: _RegisterButton //Имя кнопки

                //Размещаем в центре
                x: parent.width / 2 - _RegisterButton.width / 2
                y: rectPassword.y +40

                radius:10
                color:"#111";
                width: 70;
                height: 30
                border.width: 1
                border.color: "#ffffff"

                //Текст кнопки
                Text {
                    id: textExit
                    text: "Register"
                    anchors.centerIn: parent;
                    font.pixelSize: 12
                    font.family: "Segoe Print"
                    color: "white"
                }

                //Действие мыши
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
            Rectangle {
                id: startPushButton
                x: parent.width / 2 - startPushButton.width / 2;
                y: _RegisterButton.y+40;

                radius:10
                color:"#111";
                width: 70;
                height: 30
                border.width: 1
                border.color: "#ffffff"

                Text {
                    id: textstartPushButton
                    text: "Start"
                    anchors.centerIn: parent;
                    font.pixelSize: 12
                    font.family: "Segoe Print"
                    color: "white"
                }
                //Действие мыши
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
            Rectangle {
                id: settingsPushButton
                x: parent.width / 2 - settingsPushButton.width / 2;
                y: startPushButton.y+40;

                radius:10
                color:"#111";
                width: 70;
                height: 30
                border.width: 1
                border.color: "#ffffff"

                Text {
                    id: textsettingsPushButton
                    text: "Setting"
                    anchors.centerIn: parent;
                    font.pixelSize: 12
                    font.family: "Segoe Print"
                    color: "white"
                }
                //Действие мыши
                MouseArea {
                    anchors.fill: parent
                    id: mouseAreaSetting
                    onClicked: window.SettingsButtonPressed();
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

                    //кнопка Quit
                    Rectangle {
                        id: quitPushButton
                        x: parent.width / 2 - quitPushButton.width / 2;
                        y: settingsPushButton.y+40;

                        radius:10
                        color:"#111";
                        width: 70;
                        height: 30
                        border.width: 1
                        border.color: "#ffffff"

                        Text {
                            id: textquitPushButton
                            text: "Quit"
                            anchors.centerIn: parent;
                            font.pixelSize: 12
                            font.family: "Segoe Print"
                            color: "white"
                        }
                        //Действие мыши
                        MouseArea {
                            anchors.fill: parent
                            id: mouseAreaExit
                            onClicked: window.QuitButtonPressed();
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

