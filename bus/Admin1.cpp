#include "Admin1.h"
#include "busMain.h"
#include "Admin2.h"

#include <wx/msgdlg.h>
#include<mysql.h>
using namespace std;
    MYSQL* conn1;

    MYSQL_RES *res1;
    int qstate1,qstate10,qstate110;
//(*InternalHeaders(Admin1)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Admin1)
const long Admin1::ID_TEXTCTRL1 = wxNewId();
const long Admin1::ID_TOGGLEBUTTON1 = wxNewId();
const long Admin1::ID_STATICTEXT2 = wxNewId();
const long Admin1::ID_TEXTCTRL2 = wxNewId();
const long Admin1::ID_STATICTEXT3 = wxNewId();
const long Admin1::ID_TOGGLEBUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Admin1,wxFrame)
	//(*EventTable(Admin1)
	//*)
END_EVENT_TABLE()

Admin1::Admin1(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Admin1)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(144,112), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	ToggleButton1 = new wxToggleButton(this, ID_TOGGLEBUTTON1, _("LOGIN"), wxPoint(152,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("USERNAME"), wxPoint(64,120), wxDefaultSize, wxST_NO_AUTORESIZE|wxALIGN_LEFT, _T("ID_STATICTEXT2"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(144,176), wxSize(152,21), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("PASSWORD"), wxPoint(64,184), wxSize(72,13), 0, _T("ID_STATICTEXT3"));
	ToggleButton2 = new wxToggleButton(this, ID_TOGGLEBUTTON2, _("BACK"), wxPoint(296,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON2"));

	Connect(ID_TOGGLEBUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&Admin1::OnToggleButton1Toggle);
	Connect(ID_TOGGLEBUTTON2,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&Admin1::OnToggleButton2Toggle);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Admin1::OnClose);
	//*)
	 conn1 = mysql_init(0);
    conn1 = mysql_real_connect(conn1,"localhost","root","","bus system",0,NULL,0);

}

Admin1::~Admin1()
{
	//(*Destroy(Admin1)
	//*)

     mysql_close(conn1);
}

string u;
void Admin1::OnToggleButton1Toggle(wxCommandEvent& event)
{
    string username1=(TextCtrl1->GetValue()).ToStdString();
    string pass1=(TextCtrl2->GetValue()).ToStdString();
    u=username1;


    string query1="select * from admin where uname='"+username1+"' and pword='"+pass1+"'";
    const char* q1 = query1.c_str();

    qstate1 = mysql_query(conn1,q1);
    if(!qstate1)
    {
       res1=mysql_store_result(conn1);
        if(mysql_num_rows(res1)!=0){
                string qu10="update admin set stat='logged in' where uname='"+username1+"'";
         const char* q10 = qu10.c_str();
         qstate10 = mysql_query(conn1,q10);

        Admin2 *rr = new Admin2(0);
    this->Hide();
    rr->Show();
        }

    else
        wxMessageBox("wrong username and password","try again");  }
}

void Admin1::OnToggleButton2Toggle(wxCommandEvent& event)
{

    busFrame *b=new busFrame(0);
    this->Hide();
    b->Show();

}

void Admin1::OnClose(wxCloseEvent& event)
{
}
