#include "KAP.h"
#include "KAPChecker.h"

BEGIN_MESSAGE_MAP(CKAPApp, CWinApp)
END_MESSAGE_MAP()

CKAPApp::CKAPApp()
{
}

CKAPApp theApp;

// CKAPApp initialization
BOOL CKAPApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

CKAPChecker * gpMyPlugin = NULL;

void __declspec (dllexport) EuroScopePlugInInit(EuroScopePlugIn::CPlugIn ** ppPlugInInstance)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// create the instance
	*ppPlugInInstance = gpMyPlugin = new CKAPChecker();
}

void __declspec (dllexport) EuroScopePlugInExit(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	// delete the instance
	delete gpMyPlugin;
}
