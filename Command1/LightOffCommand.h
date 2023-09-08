#pragma once

#include "pch.h"

class LightOffCommand
    : public ICommand
{
    Light& _light;
public:
    LightOffCommand(Light& light)
        : _light(light)
    {
    }

    virtual void Execute() override
    {
        _light.Off();
    }

    virtual void Undo() override
    {
        _light.On();
    }
};
