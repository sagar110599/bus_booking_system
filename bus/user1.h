#ifndef USER1_H
#define USER1_H

//(*Headers(user1)
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>
//*)

class user1: public wxFrame
{
	public:

		user1(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~user1();

		//(*Declarations(user1)
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxToggleButton* ToggleButton1;
		wxToggleButton* ToggleButton2;
		wxToggleButton* ToggleButton3;
		//*)

	protected:

		//(*Identifiers(user1)
		static const long ID_STATICTEXT1;
		static const long ID_TOGGLEBUTTON1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TOGGLEBUTTON2;
		static const long ID_TOGGLEBUTTON3;
		//*)

	private:

		//(*Handlers(user1)
		void OnToggleButton1Toggle(wxCommandEvent& event);
		void OnToggleButton3Toggle(wxCommandEvent& event);
		void OnToggleButton2Toggle(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
