/////////////////////////////////////////////////////////////////////////////
// Name:        OptionsDialog.h
// Purpose:
// Author:      Mark Erikson
// Modified by:
// Created:     11/23/03 16:02:26
// RCS-ID:
// Copyright:
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _OPTIONSDIALOG_H_
#define _OPTIONSDIALOG_H_

#ifdef __GNUG__
#pragma interface "OptionsDialog.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/notebook.h"
#include "wx/spinctrl.h"
////@end includes


class ChameleonWindow;

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG 10000
#define ID_NOTEBOOK 10001
#define ID_PANELFEATURES 10006
#define ID_CHECKLISTBOX 10007
#define ID_PROFCODE 10004
#define ID_SETAUTHCODE 10012
#define ID_PANELNETWORK 10005
#define ID_HOSTNAME 10008
#define ID_USERNAME 10009
#define ID_PASSWORD1 10010
#define ID_PASSWORD2 10011
#define ID_PANELCOMPILER 10015
#define ID_TEXTMINGWPATH 10014
#define ID_BTNFINDMINGW 10020
#define ID_BUTTON1 10021
#define ID_CHECKBOX1 10023
#define ID_PANELMISC 10016
#define ID_PRINTSTYLE 10017
#define ID_PRINTLINENUMBERS 10013
#define ID_SHOWTOOLBARTEXT 10018
#define ID_COMBINEWATCH 10022
#define ID_SPINCTRL 10019
#define ID_BUTTON_OK 10002
#define ID_BUTTON_CANCEL 10003
#define SYMBOL_OPTIONSDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_OPTIONSDIALOG_TITLE _("Options")
#define SYMBOL_OPTIONSDIALOG_IDNAME ID_DIALOG
#define SYMBOL_OPTIONSDIALOG_SIZE wxSize(420, 315)
#define SYMBOL_OPTIONSDIALOG_POSITION wxDefaultPosition
////@end control identifiers

//#include <wx/wx.h>
#include <wx/combobox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/string.h>
class wxCheckListBox;
class Options;

/*!
 * OptionsDialog class declaration
 */

class OptionsDialog: public wxDialog
{
    DECLARE_CLASS( OptionsDialog )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    OptionsDialog( );
    OptionsDialog( wxWindow* parent, Options* options, wxWindowID id = -1,  const wxString& caption = _("Options"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = -1, const wxString& caption = _("Options"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU );

    /// Creates the controls and sizers
    void CreateControls();

////@begin OptionsDialog event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SETAUTHCODE
    void OnUpdateAuthCode( wxCommandEvent& event );

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTMINGWPATH
    void OnTextmingwpathUpdated( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTNFINDMINGW
    void OnFindMingwClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON1
    void OnVerifyMingwClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_OK
    void OnButtonOkClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_CANCEL
    void OnButtonCancelClick( wxCommandEvent& event );

////@end OptionsDialog event handler declarations

	void OnChar(wxKeyEvent &event);



////@begin OptionsDialog member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end OptionsDialog member function declarations

	bool VerifyMingwPath(bool showResults = false);

    /*
    wxCheckListBox* GetListBox();
    wxString GetServerAddress();
    wxString GetUsername();
    wxString GetPassword1();
    wxString GetPassword2();
	wxString GetAuthCode();
	wxString GetMingwPath(){ return m_txtMingwPath->GetValue(); }
	*/

	void BrowseForDir(wxTextCtrl* textbox, wxString name);
	bool EvaluateOptions();

	void InitializeDialog();
	void UpdateChecklist();
	void ExitDialog();
	void OnEnter(wxCommandEvent &event);

/*
    void SetServerAddress(wxString address);
    void SetUsername(wxString username);
    void SetPassword1(wxString pwd);
    void SetPassword2(wxString pwd);
	void SetAuthCode(wxString authcode);
*/

	void EnableServerSettings();
	void DisableServerSettings();

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin OptionsDialog member variables
    wxNotebook* m_optionsNotebook;
    wxCheckListBox* m_checkList;
    wxTextCtrl* m_txtProfCode;
    wxButton* m_butSetAuthCode;
    wxStaticText* m_authCodeLabel;
    wxTextCtrl* m_hostname;
    wxTextCtrl* m_username;
    wxTextCtrl* m_password1;
    wxTextCtrl* m_password2;
    wxTextCtrl* m_txtMingwPath;
    wxCheckBox* m_chkShowCompileCommands;
    wxComboBox* m_printStyle;
    wxCheckBox* m_cbPrintLineNumbers;
    wxCheckBox* m_showToolbarText;
    wxCheckBox* m_chkCombineWatchWindow;
    wxSpinCtrl* m_termHistory;
////@end OptionsDialog member variables

	ChameleonWindow* m_parentFrame;
	Options* m_options;

	wxArrayInt m_permMappings;

	bool m_mingwPathValidated;
};

#endif
    // _OPTIONSDIALOG_H_
