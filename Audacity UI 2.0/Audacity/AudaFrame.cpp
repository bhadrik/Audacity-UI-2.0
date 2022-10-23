#include "Auda.h"

AudaFrame::AudaFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : 
    wxFrame(NULL, wxID_ANY, title, pos, size)
{
    //DWORD nFonts;
    //size_t len = sizeof(FONT_FROM_THE_C_FILE_WE_CONVERTED);
    //void* data = NAME_OF_THE_FONT_FROM_THE_C_FILE_WE_CONVERTED;

    //void* m_fonthandle = AddFontMemResourceEx(data, len, NULL, &nFonts);
    //if (m_fonthandle == NULL)
    //    wxLogError("Font add failed.");


    SetBackgroundColour(AudaColor::L1_100);
    Maximize(true);
    
    AudaMenuBar* menuBar = new AudaMenuBar(this, wxDefaultPosition, wxSize(200, 30), L2_100_COLOR);

    AudaMenu* fileMenu = new AudaMenu(menuBar, "File", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* editMenu = new AudaMenu(menuBar, "Edit", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* selectMenu = new AudaMenu(menuBar, "Select", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* viewMenu = new AudaMenu(menuBar, "View", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* transportMenu = new AudaMenu(menuBar, "Transport", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* tracksMenu = new AudaMenu(menuBar, "Tracks", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* analyzeMenu = new AudaMenu(menuBar, "Analyze", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* toolMenu = new AudaMenu(menuBar, "Tool", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    menuBar->Append(fileMenu);
    menuBar->Append(editMenu);
    menuBar->Append(selectMenu);
    menuBar->Append(viewMenu);
    menuBar->Append(transportMenu);
    menuBar->Append(tracksMenu);
    menuBar->Append(analyzeMenu);
    menuBar->Append(toolMenu);



    AudaPanel* mainPanel = new AudaPanel(this, OUTLINE_COLOR, 1, wxID_ANY, wxDefaultPosition, wxSize(500, 400));
    mainPanel->SetBackgroundColour(L1_100_COLOR);

    //wxStaticText* demo = new wxStaticText(mainPanel, wxID_ANY, "Demo text here");

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(menuBar, 0, wxEXPAND);
    sizer->Add(mainPanel, 1, wxEXPAND);

    this->SetSizerAndFit(sizer);
    //SetSizer(sizer);

    Layout();

    /*wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar* menuBar = new wxMenuBar(0L);
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    menuBar->SetBackgroundColour(L2_100_COLOR);
    menuBar->SetForegroundColour(L2_100_COLOR);*/
}

