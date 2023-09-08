#pragma once

#include "pch.h"

class GarageDoorOpenCommand
    : public ICommand
{
    GarageDoor& _garageDoor;
public:
    GarageDoorOpenCommand(GarageDoor& garageDoor)
        : _garageDoor(garageDoor)
    {
    }

    virtual void Execute() override
    {
        _garageDoor.Up();
        _garageDoor.LightOn();
    }

    virtual void Undo() override
    {
        _garageDoor.Down();
        _garageDoor.LightOff();
    }
};
