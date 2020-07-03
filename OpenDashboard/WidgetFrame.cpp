 #include "WidgetFrame.h"
#include "ODashboardApp.h"
#include "Colors.h"

BEGIN_EVENT_TABLE(WidgetFrame, wxFrame)
EVT_LEFT_DOWN(OnLeftDown)
EVT_LEFT_UP(OnLeftUp)
EVT_MOTION(OnMouseMove)
END_EVENT_TABLE()

WidgetFrame::WidgetFrame(std::string name, bool useEvents, bool showName, int idForHandlers) : wxFrame(nullptr, wxID_ANY, name), events(useEvents), handlerID(idForHandlers)
{
    SetWindowStyle(wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);
    wxStaticText* placeholder = new wxStaticText(this, wxID_ANY, "");

    widgetName = name + "Widget";
    ODashboardApp::getApp()->menuEntries++;

    close = new wxButton(this, wxID_ANY, "X", wxDefaultPosition, wxSize(25, 15), wxBORDER_NONE);
    close->SetBackgroundColour(color4);
    close->SetForegroundColour(closecolor);
    close->SetCursor(wxCURSOR_HAND);
    close->Bind(wxEVT_BUTTON, &WidgetFrame::OnClose, this);
    
    if (showName) {
        wname = new WidgetText(this, wxID_ANY, widgetName, wxDefaultPosition, wxDefaultSize, 0, "WidgetText");
        wname->SetPosition(wxPoint(2, 0));
        wname->SetFont(wxFont(8,
            wxFONTFAMILY_DEFAULT,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL,
            false));
        wname->SetForegroundColour(textcolor2);
    }
}

WidgetFrame::~WidgetFrame() {}

void WidgetFrame::OnLeftDown(wxMouseEvent& event)
{
    if (events) {
        CaptureMouse();
        capturing = true;

        const auto eventSource = static_cast<wxWindow*>(event.GetEventObject());
        const auto screenPosClicked = eventSource->ClientToScreen(event.GetPosition());
        const auto origin = GetPosition();

        mouseDownPos = screenPosClicked - origin;
    }
}

void WidgetFrame::OnMouseMove(wxMouseEvent& event)
{
    if (event.Dragging() && event.LeftIsDown() && capturing && events)
    {
        const auto screenPosCurrent = ClientToScreen(event.GetPosition());
        Move(screenPosCurrent - mouseDownPos);
    }
}

void WidgetFrame::OnLeftUp(wxMouseEvent& event)
{
    if (capturing && events) {
        ReleaseMouse();
        capturing = false;
    }
}

void WidgetFrame::UpdateSize(wxSize size, bool useClose)
{
    SetSize(size);
    if (useClose) close->SetPosition(wxPoint(size.x - 27, 0));
    else close->Hide();
}

void WidgetFrame::SetVectorIndex(int index)
{
    vectorIndex = index;
}

WidgetFrame* WidgetFrame::getWidgetFrame()
{
    return this;
}

WidgetFrame* WidgetFrame::createNewObj()
{
    return new WidgetFrame("WidgetFrame", false, false, wxID_ANY);
}

void WidgetFrame::OnClose(wxCommandEvent& event)
{
    ODashboardApp::getApp()->removeFromWidgets(this);
    Destroy();
}
