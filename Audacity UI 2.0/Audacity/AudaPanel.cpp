#include "Auda.h"

AudaPanel::AudaPanel(wxWindow* parent, wxSize size, wxPoint position):
    wxPanel(parent, wxID_ANY, position, size){}

void AudaPanel::paintEvent(wxPaintEvent& evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void AudaPanel::render(wxDC& dc)
{
    dc.SetBrush(wxBrush(wxColor(50,50,200,0), wxBrushStyle::wxBRUSHSTYLE_TRANSPARENT));
    dc.SetPen(wxPen(m_borderColor, m_borderSize, wxPenStyle::wxPENSTYLE_SOLID));

    dc.DrawRectangle(GetPosition(), GetSize());
}

void AudaPanel::SetBorderColor(wxColor color) {
    m_borderColor = color;
    Refresh();
}

void AudaPanel::SetBorderSize(int size) {
    m_borderSize = size;
    Refresh();
}


BEGIN_EVENT_TABLE(AudaPanel, wxPanel)

EVT_PAINT(AudaPanel::paintEvent)

END_EVENT_TABLE()