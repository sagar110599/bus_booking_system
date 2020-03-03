/***************************************************************
 * Name:      busApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2019-07-09
 * Copyright:  ()
 * License:
 **************************************************************/

#include "busApp.h"

//(*AppHeaders
#include "busMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(busApp);

bool busApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	busFrame* Frame = new busFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
