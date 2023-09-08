#include "pch.h"

/*
    This example is from a book.
    It based on overloading method in subclasses
*/
int main()
{
    RemoteControl remoteControl{};

    Light light{};
    GarageDoor garageDoor{};
    Stereo stereo{};

    LightOnCommand lightOnCommand(light);
    LightOffCommand lightOffCommand(light);

    GarageDoorOpenCommand garageDoorOpenCommand(garageDoor);
    GarageDoorCloseCommand garageDoorCloseCommand(garageDoor);

    StereoOnWithCDCommand stereoOnWithCDCommand(stereo);
    StereoOffWithCDCommand stereoOffWithCDCommand(stereo);

    remoteControl.SetCommand(0, &lightOnCommand, &lightOffCommand);
    remoteControl.SetCommand(1, &garageDoorOpenCommand, &garageDoorCloseCommand);
    remoteControl.SetCommand(2, &stereoOnWithCDCommand, &stereoOffWithCDCommand);

    remoteControl.PressOnButton(0);
    remoteControl.PressOnButton(1);
    remoteControl.PressOnButton(2);
    cout << "==========================================" << endl;
    remoteControl.PressOffButton(0);
    remoteControl.PressOffButton(1);
    remoteControl.PressOffButton(2);
    
    remoteControl.PressUndoButton();
}