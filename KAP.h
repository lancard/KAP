#pragma once
#include <SDKDDKVer.h>
#include <afxwin.h>

class CKAPApp : public CWinApp
{
public:
	CKAPApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
