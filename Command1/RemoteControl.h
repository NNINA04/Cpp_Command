#pragma once

#include "pch.h"

class RemoteControl
{
    static const int BUTTONS = 3;

    ICommand* _noCommand = new NoCommand();
    ICommand* _undoCommand = _noCommand;

    ICommand* _onCommands[BUTTONS];
    ICommand* _offCommands[BUTTONS];
public:
    RemoteControl()
    {
        for(size_t i = 0; i < BUTTONS; ++i)
        {
            _onCommands[i] = _noCommand;
            _offCommands[i] = _noCommand;
        }
    }

    void SetCommand(int slot, ICommand* onCommand, ICommand* offCommand)
    {
        _onCommands[slot] = onCommand;
        _offCommands[slot] = offCommand;
    }

    void PressOnButton(int slot)
    {
        _onCommands[slot]->Execute();
        _undoCommand = _onCommands[slot];
    }

    void PressOffButton(int slot)
    {
        _offCommands[slot]->Execute();
        _undoCommand = _offCommands[slot];
    }

    void PressUndoButton()
    {
        cout << "Pressing UNDO button: ";
        _undoCommand->Undo();
    }

    ~RemoteControl()
    {
        delete _noCommand;
    }
};