#include "pch.h"

/*
    This example is from a book.
    It based on lambda functions.
    It works only if there is one command (method). 
    You can't realize method UNDO like in Command1 project
*/
int main()
{
    using CommandFunc = RemoteControl::CommandFunc;

    RemoteControl remoteControl{};

    Light light{};
    GarageDoor garageDoor{};
    Stereo stereo{};

    CommandFunc lightOnCommand = [&light]()
    {
        light.On();
    };
    CommandFunc lightOffCommand = [&light]()
    {
        light.Off();
    };

    CommandFunc garageDoorOpenCommand = [&garageDoor]()
    {
        garageDoor.Up();
        garageDoor.LightOn();
    };
    CommandFunc garageDoorCloseCommand = [&garageDoor]()
    {
        garageDoor.LightOff();
        garageDoor.Down();
    };

    CommandFunc stereoOnWithCDCommand = [&stereo]()
    {
        stereo.On();
        stereo.SetCD();
        stereo.SetVolume(10);
    };
    CommandFunc stereoOffWithCDCommand = [&stereo]()
    {
        stereo.Off();
    };

    remoteControl.SetCommand(0, lightOnCommand, lightOffCommand);
    remoteControl.SetCommand(1, garageDoorOpenCommand, garageDoorCloseCommand);
    remoteControl.SetCommand(2, stereoOnWithCDCommand, stereoOffWithCDCommand);

    remoteControl.PressOnButton(0);
    remoteControl.PressOnButton(1);
    remoteControl.PressOnButton(2);
    cout << "==========================================" << endl;
    remoteControl.PressOffButton(0);
    remoteControl.PressOffButton(1);
    remoteControl.PressOffButton(2);
}