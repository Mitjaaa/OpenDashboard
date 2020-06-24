#pragma once
#include <wx/wx.h>

class WidgetText : public wxStaticText
{
public:
    WidgetText(wxWindow* parent,
        wxWindowID id,
        const wxString& label,
        const wxPoint& pos,
        const wxSize& size,
        long style,
        const wxString& name
        /*WidgetFrame* frame*/);
    ~WidgetText();

    void OnTextClick(wxMouseEvent& event);

public:
    //WidgetFrame* parentFrame;
};

