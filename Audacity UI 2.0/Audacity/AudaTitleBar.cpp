#include "Auda.h"

class AudaTitleBar : public AudaPanel
{
public:
    AudaTitleBar(wxWindow* parent, const wxPoint& position, const wxSize& size, const wxColour& color);

private:
    void OnMouseLeftDown(wxMouseEvent& event);

    void OnMouseLeftUp(wxMouseEvent&);

    void OnMouseMotion(wxMouseEvent& event);

    void OnMouseCaptureLost(wxMouseCaptureLostEvent&);

    void FinishDrag();

    wxPoint m_dragStartMouse;
    wxPoint m_dragStartWindow;
    bool m_dragging;
};

AudaTitleBar::AudaTitleBar(wxWindow* parent, const wxPoint& position, const wxSize& size, const wxColour& color) :
    AudaPanel(parent, OUTLINE_COLOR, 2, wxID_ANY, position, size)
{
    m_dragging = false;

    SetBackgroundColour(color);
    Bind(wxEVT_LEFT_DOWN, &AudaTitleBar::OnMouseLeftDown, this);
    Bind(wxEVT_MOUSE_CAPTURE_LOST, &AudaTitleBar::OnMouseCaptureLost,
        this);
}

void AudaTitleBar::OnMouseLeftDown(wxMouseEvent& event)
{
    if (!m_dragging)
    {
        Bind(wxEVT_LEFT_UP, &AudaTitleBar::OnMouseLeftUp, this);
        Bind(wxEVT_MOTION, &AudaTitleBar::OnMouseMotion, this);
        m_dragging = true;

        wxPoint clientStart = event.GetPosition();
        m_dragStartMouse = ClientToScreen(clientStart);
        m_dragStartWindow = GetParent()->GetPosition();
        CaptureMouse();
    }
}

void AudaTitleBar::OnMouseLeftUp(wxMouseEvent&)
{
    FinishDrag();
}

void AudaTitleBar::OnMouseMotion(wxMouseEvent& event)
{
    wxPoint curClientPsn = event.GetPosition();
    wxPoint curScreenPsn = ClientToScreen(curClientPsn);
    wxPoint movementVector = curScreenPsn - m_dragStartMouse;

    GetParent()->SetPosition(m_dragStartWindow + movementVector);
    //GetParent()->SetPosition(curScreenPsn);
}

void AudaTitleBar::OnMouseCaptureLost(wxMouseCaptureLostEvent&)
{
    FinishDrag();
}

void AudaTitleBar::FinishDrag()
{
    if (m_dragging)
    {
        Unbind(wxEVT_LEFT_UP, &AudaTitleBar::OnMouseLeftUp, this);
        Unbind(wxEVT_MOTION, &AudaTitleBar::OnMouseMotion, this);
        m_dragging = false;
    }

    if (HasCapture())
    {
        ReleaseMouse();
    }
}






//class Customframe : public wxFrame
//{
//public:
//    Customframe(wxWindow* p)
//        :wxFrame(p, wxID_ANY, wxString(), wxDefaultPosition, wxSize(150, 100),
//            wxBORDER_NONE)
//    {
//        AudaTitleBar* t = new AudaTitleBar(this);
//        SetBackgroundColour(*wxBLUE);
//        wxBoxSizer* szr = new wxBoxSizer(wxVERTICAL);
//        szr->Add(t, wxSizerFlags(0).Expand());
//        SetSizer(szr);
//        Layout();
//    }
//};