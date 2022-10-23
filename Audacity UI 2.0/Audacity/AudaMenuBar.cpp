#include "Auda.h"

AudaMenuBar::AudaMenuBar(wxWindow* parent, const wxPoint& position, const wxSize& size, const wxColour& color) :
    AudaPanel(parent, OUTLINE_COLOR, 0, wxID_ANY, position, size)
{
    m_dragging = false;

    SetBackgroundColour(color);
    Bind(wxEVT_LEFT_DOWN, &AudaMenuBar::OnMouseLeftDown, this);
    Bind(wxEVT_MOUSE_CAPTURE_LOST, &AudaMenuBar::OnMouseCaptureLost,
        this);

    m_menuSizer = new wxBoxSizer(wxHORIZONTAL);
    //SetSizerAndFit(m_menuSizer);
}

void AudaMenuBar::Append(AudaMenu * menu) {
    m_menuList.push_back(menu);

    //AddToSizer(menu);
}

void AudaMenuBar::AddToSizer(AudaMenu * menu) {
    m_menuSizer->Add(menu, 0, wxEXPAND);
    //SetSizerAndFit(m_menuSizer);
}

void AudaMenuBar::SetupSizer() {

    for (auto const &i : m_menuList)
    {
        m_menuSizer->Add(i, 0, wxEXPAND);
    }

    //SetSizerAndFit(m_menuSizer);
    Layout();
}

void AudaMenuBar::OnMouseLeftDown(wxMouseEvent& event)
{
    if (!m_dragging)
    {
        Bind(wxEVT_LEFT_UP, &AudaMenuBar::OnMouseLeftUp, this);
        Bind(wxEVT_MOTION, &AudaMenuBar::OnMouseMotion, this);
        m_dragging = true;

        wxPoint clientStart = event.GetPosition();
        m_dragStartMouse = ClientToScreen(clientStart);
        m_dragStartWindow = GetParent()->GetPosition();
        CaptureMouse();
    }
}

void AudaMenuBar::OnMouseLeftUp(wxMouseEvent&)
{
    FinishDrag();
}

void AudaMenuBar::OnMouseMotion(wxMouseEvent& event)
{
    wxPoint curClientPsn = event.GetPosition();
    wxPoint curScreenPsn = ClientToScreen(curClientPsn);
    wxPoint movementVector = curScreenPsn - m_dragStartMouse;

    GetParent()->SetPosition(m_dragStartWindow + movementVector);
    //GetParent()->SetPosition(curScreenPsn);
}

void AudaMenuBar::OnMouseCaptureLost(wxMouseCaptureLostEvent&)
{
    FinishDrag();
}

void AudaMenuBar::FinishDrag()
{
    if (m_dragging)
    {
        Unbind(wxEVT_LEFT_UP, &AudaMenuBar::OnMouseLeftUp, this);
        Unbind(wxEVT_MOTION, &AudaMenuBar::OnMouseMotion, this);
        m_dragging = false;
    }

    if (HasCapture())
    {
        ReleaseMouse();
    }
}