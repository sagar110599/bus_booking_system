#include "user1.h"
#include "user_reseve.h"
#include "register_user.h"
#include "busMain.h"
#include <wx/msgdlg.h>
#include<mysql.h>
using namespace std;
MYSQL* con2;

    MYSQL_RES *res22;
    int qstate22,qstate12;
//(*InternalHeaders(user1)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(user1)
const long user1::ID_STATICTEXT1 = wxNewId();
const long user1::ID_TOGGLEBUTTON1 = wxNewId();
const long user1::ID_STATICTEXT2 = wxNewId();
const long user1::ID_STATICTEXT3 = wxNewId();
const long user1::ID_TEXTCTRL1 = wxNewId();
const long user1::ID_TEXTCTRL2 = wxNewId();
const long user1::ID_TOGGLEBUTTON2 = wxNewId();
const long user1::ID_TOGGLEBUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(user1,wxFrame)
	//(*EventTable(user1)
	//*)
END_EVENT_TABLE()

user1::user1(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(user1)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("CUSTOMER LOGIN"), wxPoint(88,40), wxSize(216,40), wxST_NO_AUTORESIZE|wxALIGN_LEFT, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	ToggleButton1 = new wxToggleButton(this, ID_TOGGLEBUTTON1, _("NEW USER SIGN UP"), wxPoint(288,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("username"), wxPoint(64,120), wxSize(88,24), wxST_NO_AUTORESIZE|wxALIGN_LEFT, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("password"), wxPoint(64,192), wxSize(96,24), wxST_NO_AUTORESIZE|wxALIGN_LEFT, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(176,120), wxSize(176,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(176,192), wxSize(168,21), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	ToggleButton2 = new wxToggleButton(this, ID_TOGGLEBUTTON2, _("LOGIN"), wxPoint(80,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON2"));
	ToggleButton3 = new wxToggleButton(this, ID_TOGGLEBUTTON3, _("back"), wxPoint(288,8), wxSize(99,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON3"));

	Connect(ID_TOGGLEBUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&user1::OnToggleButton1Toggle);
	Connect(ID_TOGGLEBUTTON2,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&user1::OnToggleButton2Toggle);
	Connect(ID_TOGGLEBUTTON3,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&user1::OnToggleButton3Toggle);
	//*)
	con2 = mysql_init(0);
    con2 = mysql_real_connect(con2,"localhost","root","","bus system",0,NULL,0);
}

user1::~user1()
{
	//(*Destroy(user1)
	//*)

     mysql_close(con2);
}


void user1::OnToggleButton1Toggle(wxCommandEvent& event)
{
    register_user *rr=new register_user(0);
    rr->Show();
}
string o;
void user1::OnToggleButton3Toggle(wxCommandEvent& event)
{


    busFrame *bf =new busFrame(0);
    this->Hide();
    bf->Show();

}

void user1::OnToggleButton2Toggle(wxCommandEvent& event)
{
    string username11=(TextCtrl1->GetValue()).ToStdString();
    string pass11=(TextCtrl2->GetValue()).ToStdString();
    o=username11;


    string query2="select * from customer where uname='"+username11+"' and pword='"+pass11+"'";
    const char* q2 = query2.c_str();

    qstate22 = mysql_query(con2,q2);
    if(!qstate22)
    {
       res22=mysql_store_result(con2);
        if(mysql_num_rows(res22)!=0){
                string qu2="update customer set stat='logged in' where uname='"+username11+"'";
         const char* q12 = qu2.c_str();
         qstate12 = mysql_query(con2,q12);

        user_reseve *ur = new user_reseve(0);
    this->Hide();
    ur->Show();
        }

    else
        wxMessageBox("wrong username and password","try again");  }
}
