// Datastructures.h - common data structures for the Chameleon project
#ifndef DATASTRUCTURES__H
#define DATASTRUCTURES__H

#define CHAMELEON_VERSION_NUM " 0.1beta4 "

#include <wx/hashmap.h>
#include <wx/string.h>
#include <wx/dynarray.h>
#include <wx/filename.h>
//#include <wx/treectrl.h>
#include <wx/process.h>

class wxWindow;
class ChameleonEditor;
class wxTextOutputStream;

enum VariableNames
{
	VN_NUMPAGES,
	VN_CURRENTPAGE,
	VN_CLICKEDTAB,
};

enum MarkerTypes
{
	MARKER_BREAKPOINT,
	MARKER_FOCUSEDLINE,
};


enum WindowID
{
	// menu items
	ID_QUIT = 5200,

	// File menu
	ID_NEW_SOURCE,
	ID_SAVE,
	ID_SAVE_SOURCE_LOCAL,
	ID_SAVE_SOURCE_REMOTE,
	ID_OPEN_SOURCE_LOCAL,
	ID_OPEN_SOURCE_REMOTE,
	ID_CLOSEPAGE,
	ID_CLOSEALL,
	ID_CLOSETAB,
	ID_NEW_PROJECT,
	ID_OPEN_PROJECT_LOCAL,
	ID_OPEN_PROJECT_REMOTE,
	ID_CLOSE_PROJECT,

	ID_PRINT_PAGE,
	ID_PRINT_PREVIEW,
	ID_PRINT_SETUP,


	// major widgets
	ID_NOTEBOOK_ED,
	ID_NOTEBOOK_TERM,
	ID_CONTAINER_TERM,
	ID_CONTAINER_DEBUGTERM,
	ID_TAB_ED,
	ID_PANEL_ED,
	ID_ED,
	ID_TERMINAL,
	ID_SPLITEDITOROUTPUT,
	ID_SPLITPROJECTEDITOR,
	ID_PROJECTTREE,
	ID_OPTIONSDIALOG,
	ID_REMOTEFILEDIALOG,
	ID_COMPILERTEXTBOX,
	ID_COMPILERLISTCTRL,
	ID_COMPILEROUTPUT,
	ID_VARWATCHPANEL,
	ID_DEBUGTERMINAL,

	// edit menu items
	ID_UNDO,
	ID_REDO,
	ID_COPY,
	ID_CUT,
	ID_PASTE,
	ID_FIND,
	ID_REPLACE,
	ID_INDENT,
	ID_UNINDENT,
	ID_SELECTALL,
	ID_SELECTLINE,

	// tools menu items
	ID_OPTIONS,
	ID_STARTCONNECT,
	ID_DISCONNECT,

	ID_COMPILE,
	ID_COMPILE_PROJECT,

	ID_STATUSTIMER,

	ID_ABOUT,
	ID_HELP,

	ID_TEST,

	ID_PROJECT_ADDFILE,
	ID_PROJECT_REMOVEFILE,
	ID_PROJECT_SETTINGS,

	ID_PROJECT_ADD_SOURCEFILE,
	ID_PROJECT_ADD_HEADERFILE,
	ID_PROJECT_ADD_LIBRARYFILE,
	ID_PROJECT_REMOVE_SOURCEFILE,
	ID_PROJECT_REMOVE_HEADERFILE,
	ID_PROJECT_REMOVE_LIBRARYFILE,

	ID_PROJECT_EXCLUDE_FILE,
	ID_PROJECT_INCLUDE_FILE,

	// debugging command IDs
	ID_DEBUG_IDS_FIRST,
	ID_DEBUG_START = ID_DEBUG_IDS_FIRST,
	ID_DEBUG_CONTINUE,
	ID_DEBUG_STOP,
	ID_DEBUG_STEPNEXT,
	ID_DEBUG_STEPOVER,
	ID_DEBUG_STEPOUT,
	ID_DEBUG_IDS_LAST,

	ID_DEBUG_ADDEDITORBREAKPOINT,
	ID_DEBUG_MODIFYBREAKPOINTS,
	ID_DEBUG_REMOVEEDITORBREAKPOINT,
	ID_DEBUG_CLEAREDITORBREAKPOINTS,

	ID_DEBUG_ADD_BREAKPOINT,
	ID_DEBUG_REMOVE_BREAKPOINT,
	ID_DEBUG_CLEAR_ALL_BREAKPOINTS,
	ID_DEBUG_RUNTOCURSOR,
	ID_DEBUG_ADD_WATCH,
	ID_DEBUG_REMOVE_WATCH,
	ID_DEBUG_WATCH_SELECTION,
	ID_DEBUG_DISPLAY_SELECTION,

	ID_DEBUG_VARINFO,

	ID_DEBUG_BREAKPOINT,
	ID_DEBUG_EXIT_NORMAL,
	ID_DEBUG_EXIT_ERROR,
};

// IMPORTANT!!!  Any changes to this enum need to be reflected in the
//				 PermStrings array in p.cpp.
enum modules
{
	PERM_FIRST = 0,
	PERM_SYNTAXHIGHLIGHT = PERM_FIRST,
	PERM_AUTOINDENT,
	PERM_DEBUG,
	PERM_TERMINAL,
	PERM_LOCALMODE,
	PERM_PROJECTS,
	PERM_COMPILE,
	//PERM_ADVANCEDCOMPILE,
	PERM_LAST
};

// This enum should match the order of items in the wxImageList
// used for the project tree, as created in RemoteFileDialog's constructor
enum IconIndex
{
	ICON_DEFAULT,
	ICON_PROJECT = ICON_DEFAULT,
	ICON_FOLDERCLOSED,
	ICON_FOLDEROPEN,
	ICON_SOURCE_C,
	ICON_SOURCE_CPP,
	ICON_SOURCE_H,
	ICON_LIBRARY,
	ICON_DISABLED_SOURCE_C,
	ICON_DISABLED_SOURCE_CPP,
	ICON_DISABLED_SOURCE_H,
};

enum CompileResult {
	CR_ERROR = -1,
	CR_OK = 0,
	CR_TERMINATED = 1,
};

// IMPORTANT!!! Any changes to this enum need to be reflected in the
//				PermStrings array in p.cpp.

#pragma warning(push)
#pragma warning(disable : 4284)

WX_DEFINE_ARRAY(wxWindow*, WindowPointerArray);
WX_DEFINE_ARRAY(ChameleonEditor*, EditorPointerArray);
WX_DEFINE_ARRAY_INT(bool, BoolArray);

#pragma warning(pop)


typedef struct
{
	wxArrayInt gdbNumbers;
	wxArrayInt lineNumbers;
} DebugBreakInfo;

//typedef struct
//{
//	bool functionHasBeenVisited;
//	BoolArray variableDisplayed;
//	wxArrayString variableNames;
//} FunctionVariablesInfo;

typedef struct
{
	wxString type;
	wxString name;
	wxString functionName;
	wxString value;
	wxString regexKey;
} VariableInfo;

typedef struct
{
	wxArrayString dirNames;
	wxArrayString fileNames;
} DirListing;

WX_DECLARE_HASH_MAP( int,
					int,
					wxIntegerHash,
					wxIntegerEqual,
					IntIntHashmap );

WX_DECLARE_HASH_MAP(wxString,
					int,
					wxStringHash,
					wxStringEqual,
					StringIntHashmap);

WX_DECLARE_HASH_MAP(wxString,
					DebugBreakInfo,
					wxStringHash,
					wxStringEqual,
					DebugBreakHash);

WX_DECLARE_HASH_MAP(wxString,
					wxArrayInt,
					wxStringHash,
					wxStringEqual,
					FileBreakpointHash);

WX_DECLARE_HASH_MAP(int,
					VariableInfo,
					wxIntegerHash,
					wxIntegerEqual,
					VariableInfoHash);

//WX_DECLARE_HASH_MAP(wxString,
//					FunctionVariablesInfo,
//					wxStringHash,
//					wxStringEqual,
//					FunctionVariablesHash);

WX_DECLARE_STRING_HASH_MAP(wxString,
						   StringStringHashmap);

WX_DECLARE_STRING_HASH_MAP(wxFileName, StringFilenameHash);

WX_DECLARE_OBJARRAY(VariableInfo, VariableInfoArray);

enum PCConnState { // this is used exclusively inside ProcessInfo

	PC_STARTING,	// Waiting for Login confirmation
	PC_READY,		// Connection has been established. Nothing going
					//   on.  Just waiting to be used.
	PC_EXECUTING,	// Very short phase between sending the command
					//   and getting the starttoken
	PC_BUSY,		// Have received the starttoken, so all output is
					//   sent to the "owner"
	PC_ENDING		// Have received the endtoken.  Now in doing term
					//   sequence
};

typedef struct
{
	long pid;
	wxProcess* proc;
	PCConnState state;
	wxTextOutputStream* stdinStream;
	wxString outputBuf;
	wxEvtHandler* owner;
	bool isRunSynch;
} ProcessInfo;

WX_DECLARE_LIST(ProcessInfo, ProcessInfoList);
WX_DEFINE_ARRAY(ProcessInfo*, ProcessInfoArray);

enum NetworkStatus
{
	NET_STARTING = -1, // NEVER used externally
	NET_GOOD = 0,
	NET_UNKNOWN_HOST,  // host finger print not in cache
	NET_CONN_REFUSED,  // host wouldn't allow a connection
	NET_AUTH_FAILED,   // user+pass did not work on host
	NET_ERROR_MESSAGE, // default/catch-all
};

enum NetworkCallResult
{
	NETCALL_WORKED,
	NETCALL_FAILED,
	NETCALL_REDO,
};

enum FileFilterType
{
	FILE_ALLSOURCETYPES,
	FILE_PROJECT,
	FILE_LIBRARIES,
	FILE_SOURCES,
	FILE_HEADERS,
	FILE_ALLFILES,
	FILE_NONSOURCE,
	FILE_LASTTYPE,
};

enum ModifiedFileAction
{
	MODIFIEDFILE_CLOSE,
	MODIFIEDFILE_RELOAD,
	MODIFIEDFILE_COMPILE,
};

#endif
