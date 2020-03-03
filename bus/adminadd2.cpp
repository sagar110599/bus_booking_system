#include "adminadd2.h"
#include "Admin2.h"
#include <wx/msgdlg.h>
#include<mysql.h>
using namespace std;
    MYSQL* conn3;

    MYSQL_RES *res3;
    int qstate3;

//(*InternalHeaders(adminadd2)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(adminadd2)
const long adminadd2::ID_STATICTEXT1 = wxNewId();
const long adminadd2::ID_STATICTEXT2 = wxNewId();
const long adminadd2::ID_STATICTEXT3 = wxNewId();
const long adminadd2::ID_TEXTCTRL1 = wxNewId();
const long adminadd2::ID_TEXTCTRL2 = wxNewId();
const long adminadd2::ID_TOGGLEBUTTON1 = wxNewId();
const long adminadd2::ID_TOGGLEBUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(adminadd2,wxFrame)
	//(*EventTable(adminadd2)
	//*)
END_EVENT_TABLE()

adminadd2::adminadd2(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(adminadd2)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("ADD NEW ADMIN HERE"), wxPoint(64,40), wxSize(288,32), wxST_NO_AUTORESIZE|wxALIGN_LEFT, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("username"), wxPoint(88,144), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("password"), wxPoint(88,216), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxPoint(168,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxPoint(168,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	ToggleButton1 = new wxToggleButton(this, ID_TOGGLEBUTTON1, _("add "), wxPoint(224,264), wxSize(131,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
	ToggleButton2 = new wxToggleButton(this, ID_TOGGLEBUTTON2, _("back"), wxPoint(24,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON2"));

	Connect(ID_TOGGLEBUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&adminadd2::OnToggleButton1Toggle);
	Connect(ID_TOGGLEBUTTON2,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&adminadd2::OnToggleButton2Toggle);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&adminadd2::OnClose);
	//*)
	 conn3 = mysql_init(0);
    conn3= mysql_real_connect(conn3,"localhost","root","","bus system",0,NULL,0);

}

adminadd2::~adminadd2()
{
	//(*Destroy(adminadd2)
	//*)
	mysql_close(conn3);

}


void adminadd2::OnClose(wxCloseEvent& event)
{
}

void adminadd2::OnToggleButton2Toggle(wxCommandEvent& event)
{
     Admin2 *bb2=new Admin2(0);
   this->Hide();
   bb2->Show();

}

void adminadd2::OnToggleButton1Toggle(wxCommandEvent& event)
{
     string s=(TextCtrl1->GetValue()).ToStdString();
    string d=(TextCtrl2->GetValue()).ToStdString();
     string q34="insert into admin values('"+s+"','"+d+"');";
    const char* q4 = q34.c_str();

    qstate3 = mysql_query(conn3,q4);
    if(!qstate3)
            wxMessageBox("record added . go back to login","info");
    else

          wxMessageBox("record not added ","info");
}
