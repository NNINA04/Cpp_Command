#pragma once

#include "pch.h"

class StereoOnWithCDCommand
    : public ICommand
{
    Stereo& _stereo;
public:
    StereoOnWithCDCommand(Stereo& stereo)
        : _stereo(stereo)
    {
    }

    virtual void Execute() override
    {
        _stereo.On();
        _stereo.SetCD();
        _stereo.SetVolume(10);
    }

    virtual void Undo() override
    {
        _stereo.Off();
    }
};
