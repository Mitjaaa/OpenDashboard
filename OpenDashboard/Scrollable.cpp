#include "Scrollable.h"
#include "WidgetMenu.h"
#include "ODashboardApp.h"

Scrollable::Scrollable(wxWindow* parent, wxPoint pos, wxSize size) : wxScrolledWindow(parent, wxID_ANY, pos, size)
{
    sizer = new wxBoxSizer(wxVERTICAL);
}

Scrollable::~Scrollable()
{
}       
    
void Scrollable::addToSizer(WidgetFrame* widget) {
    wxButton* button = new wxButton(this, widget->handlerID, widget->widgetName, wxDefaultPosition, wxSize(142, 25), wxBORDER_NONE);
    
    button->SetBackgroundColour(wxColour(64, 64, 64));
    button->SetForegroundColour(wxColour(105, 203, 214));
    button->SetCursor(wxCURSOR_HAND);

    button->Bind(wxEVT_BUTTON, &Scrollable::WidgetSelected, this    );

    sizer->Add(button, 0, wxALL, 3);
}

void Scrollable::configureSizer() {
    this->SetSizer(sizer);

    this->FitInside();
    this->SetScrollRate(5, 5);
}

void Scrollable::WidgetSelected(wxCommandEvent& event)
{
    ODashboardApp::getApp()->createSelectedWidget(event);
}