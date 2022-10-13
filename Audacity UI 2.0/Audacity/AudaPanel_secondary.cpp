#include "Auda.h"


// Panel inside panel and parent panel will act as a border

//AudaPanel::AudaPanel(wxWindow* parent)
//{
//	int borderSize = 2;
//	wxColour borderColor = *wxYELLOW;
//
//	m_background = new wxPanel(parent);
//	m_background->SetBackgroundColour(borderColor);
//
//	m_main = new wxPanel(m_background);
//	m_main->SetBackgroundColour(wxColor(200, 50, 50));
//
//	wxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
//	sizer->Add(m_main, 1, wxEXPAND | wxALL, borderSize);
//
//	m_background->SetSizerAndFit(sizer);
//}
//
//wxPanel* AudaPanel::GetBackground() {
//	return m_background;
//}
//
//wxPanel* AudaPanel::GetContainer() {
//	return m_main;
//}


