#pragma once

#include "pch.h"

class LightOnCommand 
    : public ICommand
{
    Light& _light;
public:
    LightOnCommand(Light& light) 
        : _light(light)
    {
    }

    virtual void Execute() override
    {
        _light.On();
    }

    virtual void Undo() override
    {
        _light.Off();
    }
};
