
/**************************************************************************************
			The Luzj's Zte Project
			//////////////////////
			Copyleft ? 2009 Luzj
		Author:Luzj		QQ:86829232
		http://blog.csdn.net/luzjqq
		Email: luzjcn@gmail.com
	///////////////////////////////////
关于Luzj's Zte认证端的声明：

1、本软件所有涉及的中兴认证的功能的实现均是通过黑盒分析得来，并未通过任何不正当方法获得。

2、本软件仅供研究学习之用，不得使用本软件损害中兴公司商业利益。

3、本软件不可用于任何商业和非法用途，否则责任自负。

4、本软件在发布前均通过一般性应用测试，但不保证任何情况下对机器无害，
由于未知的使用环境或不当的使用对计算机造成的损害，责任由使用者全部承担。

5.本软件版权没有，翻印不究，但请协助改进本作品。

6.本软件属开源软件，如果需要修改本软件源码以进行二次发布，也请继续公开源代码。

由于任何不遵守上叙条例引起的纠纷，均与本人无关，如不同意该声明请不要使用该软件，谢谢合作。
**************************************************************************************/


// Luzj_ZTE.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Luzj_ZTE.h"
#include "Luzj_ZTEDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLuzj_ZTEApp

BEGIN_MESSAGE_MAP(CLuzj_ZTEApp, CWinApp)
	//{{AFX_MSG_MAP(CLuzj_ZTEApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLuzj_ZTEApp construction

CLuzj_ZTEApp::CLuzj_ZTEApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CLuzj_ZTEApp object

CLuzj_ZTEApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CLuzj_ZTEApp initialization

BOOL CLuzj_ZTEApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif


	HANDLE g_mutex	=  CreateMutex(NULL,FALSE,"LuzjZte");
	HWND findHwnd;
	if ( GetLastError()== ERROR_ALREADY_EXISTS )
	{
		//MessageBox(NULL,"您已经运行了一个认证端!","错误",MB_OK |MB_ICONERROR);
		if ((findHwnd=FindWindow(NULL,STR_AppName))!=NULL)
		{
			//MessageBox(NULL,"找到那个认证端了","错误",MB_OK |MB_ICONERROR);
			ShowWindow(findHwnd,SW_SHOW);
			MessageBox(findHwnd,"只允许运行一个认证端!","错误",MB_OK |MB_ICONERROR);
		}
		else
		{
			MessageBox(NULL,"只允许运行一个认证端!","错误",MB_OK |MB_ICONERROR);
		}
		return 0;
	}

	CLuzj_ZTEDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
