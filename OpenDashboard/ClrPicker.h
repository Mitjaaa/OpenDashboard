#pragma once
#include "wx/wx.h"
#include "globalColour.h"
#include "Colors.h"

extern bool picking;

class ClrPicker : public wxButton
{
public:
	ClrPicker(wxWindow* parent,
        wxWindowID id, 
        int section,
        int index,
        bool mf,
        const wxString& label = wxEmptyString,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = 0,
        const wxValidator& validator = wxDefaultValidator,
        const wxString& name = wxButtonNameStr);

	~ClrPicker();


private:
    int section;
    int index;
    bool mainframe;
    
    void OnPick(wxCommandEvent& event);
};

