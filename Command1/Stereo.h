#pragma once

class Stereo
{
    int _volume = 0;
public:
    void On()
    {
        cout << "The stereo switched to ON state" << endl;
    }

    void Off()
    {
        cout << "The stereo switched to OFF state" << endl;
    }

    void SetCD()
    {
        cout << "Setting a CD to Stereo" << endl;
    }

    void SetDVD()
    {
        cout << "Setting a DVD to Stereo" << endl;
    }

    void SetRadio()
    {
        cout << "Setting radio" << endl;
    }

    void SetVolume(int volume)
    {
        _volume = volume;
    }

    int GetVolume()
    {
        return _volume;
    }
};
