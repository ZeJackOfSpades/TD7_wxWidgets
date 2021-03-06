/**
 *  @file   main.cpp
 *  @brief  Demo source for wxWidget.
 */
// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
class MyFrame : public wxFrame
{
public:
    MyFrame();
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    //void textEntry(wxCommandEvent& event);
};
enum
{
    ID_Hello            =   1,
    ID_Text             =   2,
    ID_dollarsButton    =   3,
    ID_euroButton       =   4,
    ID_quitButton       =   5
};
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}
MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Hello World")
{
    int w, h, h1, h2, h3, w1, w2;
    GetClientSize(&w, &h);
    h1 = 0.6*h; h2 = 0.2*h; h3 = h-h1-h2;
    w1 = 0.5*w; w2 = w-w1;


    wxBoxSizer *sizerTop       = new wxBoxSizer(wxVERTICAL);
    SetSizer(sizerTop);
    wxBoxSizer *sizerText      = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *sizerButton    = new wxBoxSizer(wxHORIZONTAL);
    
    wxButton *euroButton            =   new wxButton(this, ID_euroButton, _T("EURO"), wxDefaultPosition, wxDefaultSize,0);
    wxButton *quitButton            =   new wxButton(this, ID_quitButton, _T("QUIT"));
    wxButton *dollarsButton         =   new wxButton(this, ID_dollarsButton, _T("DOLLARS"));

    wxTextCtrl *text = new wxTextCtrl(  this,ID_Text, wxEmptyString, 
                                        wxDefaultPosition, wxDefaultSize, 
                                        wxTE_PROCESS_ENTER);

    sizerText->Add(text,0, wxEXPAND | wxTOP | wxRIGHT, 5);
    SetSizer(sizerText);



    sizerButton->Add(quitButton,0, wxEXPAND,12);
    sizerButton->Add(euroButton, 0, wxEXPAND, 12);
    sizerButton->Add(dollarsButton, 0, wxEXPAND, 12);
    

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-h",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    /* wxTextCtrl *text = new wxTextCtrl(  this, ID_Text, "This is a simple test,",
                                        wxPoint(0,0), wxSize(w, h1),
                                        wxALIGN_CENTRE | wxTE_PROCESS_ENTER);
    */
    


   //text->SetDefaultStyle(wxTextAttr(*wxTE_MULTILINE));
    text->AppendText("Test after append");

    SetSizer(sizerButton);

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);

}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

