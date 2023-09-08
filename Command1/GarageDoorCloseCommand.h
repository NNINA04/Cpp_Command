#pragma once

#include "pch.h"

class GarageDoorCloseCommand
    : public ICommand
{
    GarageDoor& _garageDoor;
public:
    GarageDoorCloseCommand(GarageDoor& garageDoor)
        : _garageDoor(garageDoor)
    {
    }

    virtual void Execute() override
    {
        _garageDoor.LightOff();
        _garageDoor.Down();
    }

    virtual void Undo() override
    {
        _garageDoor.LightOn();
        _garageDoor.Down();
    }
};
