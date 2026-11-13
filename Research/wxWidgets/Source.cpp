#include <wx/wx.h>

class MyApp : public wxApp 
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame 
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    void OnQuit(wxCommandEvent& event);
};


wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() 
{
    MyFrame* frame = new MyFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) 
{
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxButton* button = new wxButton(panel, wxID_EXIT, wxT("Quit"), wxPoint(20, 20));
    Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnQuit));
}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}