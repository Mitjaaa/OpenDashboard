#include "ImageWindow.h"

BEGIN_EVENT_TABLE(ImageWindow, wxWindow)
EVT_PAINT(ImageWindow::paintEvent)
END_EVENT_TABLE()

ImageWindow::ImageWindow(wxWindow* parent, wxPoint pos, wxSize size, WidgetFrame* parentframe) : wxWindow(parent, wxID_ANY, pos, size), parent(parentframe)
{
    SetBackgroundColour(wxColour(46, 46, 46));
    imgSize = size;
    this->Bind(wxEVT_LEFT_DOWN, &ImageWindow::OnImageClick, this);
}
ImageWindow::~ImageWindow() {}

void ImageWindow::setImage(wxString file, wxBitmapType format) {
    imgFile = file;
    imgFormat = format;

    image.LoadFile(imgFile, imgFormat);

    if (image.GetSize().x > 1250 || image.GetSize().y > 1000) {
        factor = 4;
    }

    isImageSet = true;

    Refresh();
}

void ImageWindow::paintEvent(wxPaintEvent& evt)
{
    if (isImageSet) {
        wxBitmap resized;
        wxPaintDC dc(this);

        resize();

        resized = wxBitmap(image.Scale(image.GetSize().x / factor, image.GetSize().y / factor, wxIMAGE_QUALITY_HIGH));
        dc.DrawBitmap(resized, 0, 0, false);
    }
}

void ImageWindow::resize() {
    SetSize(wxSize(image.GetSize().x / factor, image.GetSize().y / factor));

    OutputDebugStringA("B ");
    OutputDebugStringA(std::to_string(GetSize().x).c_str());
    OutputDebugStringA(" ");
    OutputDebugStringA(std::to_string(GetSize().y).c_str());
    OutputDebugStringA("\n");
}

void ImageWindow::OnImageClick(wxMouseEvent& event)
{
    ImageWindow::parent->OnLeftDown(event);
}