#pragma once

class RemoteControl
{
public:
    using CommandFunc = function<void()>;
private:
    static const int BUTTONS = 3;

    CommandFunc _noCommand = []()
    {
    };

    CommandFunc _onCommands[BUTTONS];
    CommandFunc _offCommands[BUTTONS];
public:
    RemoteControl()
    {
        for(size_t i = 0; i < BUTTONS; ++i)
        {
            _onCommands[i] = _noCommand;
            _offCommands[i] = _noCommand;
        }
    }

    void SetCommand(int slot, CommandFunc onCommand, CommandFunc offCommand)
    {
        _onCommands[slot] = onCommand;
        _offCommands[slot] = offCommand;
    }

    void PressOnButton(int slot)
    {
        _onCommands[slot]();
    }

    void PressOffButton(int slot)
    {
        _offCommands[slot]();
    }
};