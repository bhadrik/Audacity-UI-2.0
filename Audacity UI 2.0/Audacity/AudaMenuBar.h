#pragma once
#include "AudaPanel.h"
#include "AudaMenu.h"
#include <list>

using namespace std;

class AudaMenuBar : public AudaPanel
{
private:
    list<AudaMenu*> m_menuList;
    wxBoxSizer* m_menuSizer;

public:
    AudaMenuBar(wxWindow* parent, const wxPoint& position, const wxSize& size, const wxColour& color);

    void Append(AudaMenu* menu);
    
    void SetupSizer();

private:
    void OnMouseLeftDown(wxMouseEvent& event);

    void OnMouseLeftUp(wxMouseEvent&);

    void OnMouseMotion(wxMouseEvent& event);

    void OnMouseCaptureLost(wxMouseCaptureLostEvent&);

    void FinishDrag();

    void AddToSizer(AudaMenu* menu);


    wxPoint m_dragStartMouse;
    wxPoint m_dragStartWindow;
    bool m_dragging;
};