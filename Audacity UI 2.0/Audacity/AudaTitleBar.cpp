#include "Auda.h"


AudaTitleBar::AudaTitleBar(wxWindow* parent, wxPoint pos, int height, wxColour color) : AudaPanel(parent, wxSize(100, height), pos)
{
    m_dragging = false;

    //SetSize(wxSize(100, height));

    SetBackgroundColour(color);
    Bind(wxEVT_LEFT_DOWN, &AudaTitleBar::OnMouseLeftDown, this);
    Bind(wxEVT_MOUSE_CAPTURE_LOST, &AudaTitleBar::OnMouseCaptureLost,
        this);
}

//wxSize AudaTitleBar::DoGetBestClientSize() const
//{
//    return wxSize(-1, 20);
//}

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