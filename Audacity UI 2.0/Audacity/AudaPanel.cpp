#include "Auda.h"

AudaPanel::AudaPanel(
    wxWindow* parent, 
    const wxColour& borderColor,
    int borderSize,
    wxWindowID windowId, 
    const wxPoint& position, 
    const wxSize& size, 
    long style, 
    const wxString& panelName
) : wxPanel(parent, windowId, position, size, style, panelName)
{
    m_borderColor = borderColor;
    m_borderSize = borderSize;
}


void AudaPanel::paintEvent(wxPaintEvent& evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void AudaPanel::render(wxDC& dc)
{
    if (m_borderSize == 0) return;

    dc.SetBrush(wxBrush(wxColor(50,50,200,0), wxBrushStyle::wxBRUSHSTYLE_TRANSPARENT));
    dc.SetPen(wxPen(m_borderColor, m_borderSize, wxPenStyle::wxPENSTYLE_SOLID));

    //wxPoint pos = wxPoint() - wxPoint(m_borderSize, m_borderSize);
    //wxSize sz = GetSize() + wxSize(m_borderSize, m_borderSize);

    wxPoint pos = wxPoint();
    wxSize sz = GetSize();

    dc.DrawRectangle(pos, sz);
}

void AudaPanel::SetBorderColor(wxColor color) {
    m_borderColor = color;
    Refresh();
}

void AudaPanel::SetBorderSize(int size) {
    m_borderSize = size;
    Refresh();
}

//void AudaPanel::OnMouseEnter(wxMouseEvent& event)
//{
//    SetBackgroundColour(TEST_GREEN);
//    Refresh();
//    Update();
//}
//
//void AudaPanel::OnMouseExit(wxMouseEvent& event)
//{
//    SetBackgroundColour(TEST_BLUE);
//    Refresh();
//    Update();
//}

BEGIN_EVENT_TABLE(AudaPanel, wxPanel)

EVT_PAINT(AudaPanel::paintEvent)
//EVT_ENTER_WINDOW(AudaPanel::OnMouseEnter)
//EVT_LEAVE_WINDOW(AudaPanel::OnMouseExit)

END_EVENT_TABLE()