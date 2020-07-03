#include "WidgetText.h"
#include "WidgetFrame.h"

WidgetText::WidgetText(wxWindow* parent,
    wxWindowID id,
    const wxString& label,
    const wxPoint& pos,
    const wxSize& size,
    long style,
    const wxString& name) : wxStaticText(parent, id, label, pos, size, style, name)
{
    this->Bind(wxEVT_LEFT_DOWN, &WidgetText::OnTextClick, this);
}

WidgetText::~WidgetText() {}

void WidgetText::OnTextClick(wxMouseEvent& event)
{
    WidgetFrame* parent = (WidgetFrame*)this->GetParent();
    parent->OnLeftDown(event);
}
