#include "WidgetText.h"

WidgetText::WidgetText(wxWindow* parent,
    wxWindowID id,
    const wxString& label,
    const wxPoint& pos,
    const wxSize& size,
    long style,
    const wxString& name
    /*WidgetFrame* frame*/) : wxStaticText(parent, id, label, pos, size, style, name)//, parentFrame(frame)
{
    this->Bind(wxEVT_LEFT_DOWN, &WidgetText::OnTextClick, this);
}

WidgetText::~WidgetText() {}

void WidgetText::OnTextClick(wxMouseEvent& event)
{
    //WidgetText::parentFrame->OnLeftDown(event);
}