#include "wx/wx.h"
#include "Auda.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        AudaFrame* audaFrame = new AudaFrame("Auda frame", wxDefaultPosition, wxSize(300, 300));
        audaFrame->Show();
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);