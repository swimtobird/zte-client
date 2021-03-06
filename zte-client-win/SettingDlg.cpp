

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
// SettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Luzj_ZTE.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg dialog


CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingDlg)
	DDX_Control(pDX, IDC_EMAILME, m_emailme);
	DDX_Control(pDX, IDC_WEBURL, m_url);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialog)
	//{{AFX_MSG_MAP(CSettingDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg message handlers

BOOL CSettingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CheckDlgButton(IDC_CHK_AUTOLOGON,Config.m_bAutologon?BST_CHECKED:BST_UNCHECKED);
	CheckDlgButton(IDC_CHK_AUTORUN,Config.m_bAutorun?BST_CHECKED:BST_UNCHECKED);
	CheckDlgButton(IDC_CHK_BUBBLE,Config.m_bShowBubble?BST_CHECKED:BST_UNCHECKED);


	char szTemp[MAX_STRING];
	sprintf(szTemp,"%d",Config.m_iTimeout);
	GetDlgItem(IDC_TIMEOUT)->SetWindowText(szTemp);
	


	m_url.SetURL(STR_WebUrl);
	m_emailme.SetURL(STR_EmailUrl);
	GetDlgItem(IDC_VERSION)->SetWindowText(STR_AppName"       "STR_Version);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSettingDlg::OnOK() 
{
	char szTemp[MAX_STRING];
	if (IsDlgButtonChecked(IDC_CHK_AUTOLOGON))
	{
		Config.m_bAutologon=TRUE;
	}
	else
	{
		Config.m_bAutologon=FALSE;
	}


	if (IsDlgButtonChecked(IDC_CHK_AUTORUN))
	{
		Config.m_bAutorun=TRUE;
	}
	else
	{
		Config.m_bAutorun=FALSE;
	}


	if (IsDlgButtonChecked(IDC_CHK_BUBBLE))
	{
		Config.m_bShowBubble=TRUE;
	}
	else
	{
		Config.m_bShowBubble=FALSE;
	}


	GetDlgItem(IDC_TIMEOUT)->GetWindowText(szTemp,MAX_STRING);
	Config.m_iTimeout=atoi(szTemp);

	Config.SvaeConfig();
	CDialog::OnOK();
}
