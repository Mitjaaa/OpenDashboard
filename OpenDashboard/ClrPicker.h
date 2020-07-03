#pragma once
#include "wx/wx.h"

class ClrPicker : public wxButton
{
public:
	ClrPicker(wxWindow* parent,
        wxWindowID id,
        wxColour colour,
        const wxString& label = wxEmptyString,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = 0,
        const wxValidator& validator = wxDefaultValidator,
        const wxString& name = wxButtonNameStr);
	~ClrPicker();


private:
    wxColour clr;
	void OnPick(wxCommandEvent& event);

};

