#pragma once
#include "wx/wx.h"

class globalColour : wxColour
{
public:
    globalColour(ChannelType red,
        ChannelType green,
        ChannelType blue, 
        int section,
        int index,
        bool autoSetting,
        ChannelType alpha = wxALPHA_OPAQUE);
    globalColour();
	~globalColour();

    wxColour clr;
    int section;
    int index;
    bool autoSetting;
};

