#pragma once

#include "pch.h"

class NoCommand
    : public ICommand
{
public:
    virtual void Execute() override
    {
        cout << "NoCommand::Execute: I do nothing" << endl;
    }

    virtual void Undo() override
    {
        cout << "NoCommand::Undo: I do nothing" << endl;
    }
};
