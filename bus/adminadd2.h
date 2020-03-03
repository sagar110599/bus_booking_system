#ifndef ADMINADD2_H
#define ADMINADD2_H

//(*Headers(adminadd2)
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>
//*)

class adminadd2: public wxFrame
{
	public:

		adminadd2(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~adminadd2();

		//(*Declarations(adminadd2)
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxToggleButton* ToggleButton1;
		wxToggleButton* ToggleButton2;
		//*)

	protected:

		//(*Identifiers(adminadd2)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TOGGLEBUTTON1;
		static const long ID_TOGGLEBUTTON2;
		//*)

	private:

		//(*Handlers(adminadd2)
		void OnClose(wxCloseEvent& event);
		void OnToggleButton2Toggle(wxCommandEvent& event);
		void OnToggleButton1Toggle(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
