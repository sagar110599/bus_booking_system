#ifndef ADMIN1_H
#define ADMIN1_H

//(*Headers(Admin1)
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>
//*)

class Admin1: public wxFrame
{
	public:

		Admin1(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Admin1();

		//(*Declarations(Admin1)
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxToggleButton* ToggleButton1;
		wxToggleButton* ToggleButton2;
		//*)

	protected:

		//(*Identifiers(Admin1)
		static const long ID_TEXTCTRL1;
		static const long ID_TOGGLEBUTTON1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_TOGGLEBUTTON2;
		//*)

	private:

		//(*Handlers(Admin1)
		void OnToggleButton1Toggle(wxCommandEvent& event);
		void OnToggleButton2Toggle(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
