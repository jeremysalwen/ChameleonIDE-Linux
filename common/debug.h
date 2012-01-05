#ifndef DEBUG__H
#define DEBUG__H

#include <wx/log.h>

#ifdef _DEBUG
//#include "../nvwa/debug_new.h"
#endif
#define DEBUG_NEW new
//#define DEBUGLOG(x) wxString logstring; logstring << __FILE__ << ":" << __LINE__ << ": " << x; ::wxLogDebug(logstring);
//#define DEBUGLOG(x) wxLogDebug(wxT("%s(%d): %s"),__TFILE__, __LINE__, x);




#endif
