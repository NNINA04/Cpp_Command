#pragma once

#include "pch.h"

class StereoOffWithCDCommand
    : public ICommand
{
    Stereo& _stereo;
public:
    StereoOffWithCDCommand(Stereo& stereo)
        : _stereo(stereo)
    {
    }

    virtual void Execute() override
    {
        _stereo.Off();
    }

    virtual void Undo() override
    {
        _stereo.On();
    }
};
