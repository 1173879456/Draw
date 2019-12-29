// Mydialog.cpp: 实现文件
//

#include "stdafx.h"
#include "Drawing.h"
#include "Mydialog.h"
#include "afxdialogex.h"


// Mydialog 对话框

IMPLEMENT_DYNAMIC(Mydialog, CDialogEx)

Mydialog::Mydialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, wr(0)
	, h(0)
	, text(_T(""))
	, lw(1)
	, index1(0)
	, index2(0)
	
{

	index = 0;
}

Mydialog::~Mydialog()
{
}

void Mydialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT3, wr);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT4, h);
	DDX_Text(pDX, IDC_EDIT5, text);
	DDX_Text(pDX, IDC_EDIT6, lw);
	DDX_Control(pDX, IDC_COMBO1, Combox);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON1, color1);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON2, color2);
	DDX_Control(pDX, IDC_LIST1, listbox1);
	DDX_Control(pDX, IDC_LIST2, listbox2);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, colorbtn1);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, colorbtn2);
	DDX_LBIndex(pDX, IDC_LIST1, index1);
	DDX_LBIndex(pDX, IDC_LIST2, index2);
}


BEGIN_MESSAGE_MAP(Mydialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Mydialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Mydialog::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Mydialog::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// Mydialog 消息处理程序


BOOL Mydialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//COLORREF color3= RGB(255,255.0);
	colorbtn2.SetColor(RGB(255,255,0));
	Combox.SetCurSel(0);
	CString m_strstyle[6];
	CString m_str[6];
	m_str[0] = _T("PS_SOLD");
	m_str[1] = _T("PS_DASH");
	m_str[2] = _T("PS_DOT");
	m_str[3] = _T("PS_DASHDOT");
	m_str[4] = _T("PS_DASHDOTDOT");
	m_str[5] = _T("PS_NULL");

	for (int i = 0; i < 6; i++)
	{
		listbox1.AddString(m_str[i]);
	}
	
	m_strstyle[0] = _T("HS_HORIZONTAL");
	m_strstyle[1] = _T("HS_CROSS");
	m_strstyle[2] = _T("HS_DIAGCROSS");
	m_strstyle[3] = _T("HS_FDIAGONAL");
	m_strstyle[4] = _T("HS_HORIZONTAL");
	m_strstyle[5] = _T("HS_VERTICAL");
	for (int i = 0; i < 6; i++)
	{
		listbox2.AddString(m_strstyle[i]);
	}
	CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STA4);
	pStatic->ShowWindow(SW_HIDE);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
	pEdit->ShowWindow(SW_HIDE);
	pStatic = (CStatic*)GetDlgItem(IDC_STA5);
	pStatic->ShowWindow(SW_HIDE);
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT5);
	pEdit->ShowWindow(SW_HIDE);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Mydialog::OnBnClickedButton1()
{
	CDialogEx::OnOK();
	color1 = colorbtn1.GetColor();
	color2 = colorbtn2.GetColor();
	index1 = listbox1.GetCurSel();
	index2 = listbox2.GetCurSel();
	// TODO: 在此添加控件通知处理程序代码
}


void Mydialog::OnBnClickedButton2()
{
	CDialogEx::OnCancel();
	// TODO: 在此添加控件通知处理程序代码
}


void Mydialog::OnCbnSelchangeCombo1()
{
	//隐藏
	index = Combox.GetCurSel();
	//
	if (0 == index)
	{
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STA4);
		pStatic->ShowWindow(SW_HIDE);
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
		pEdit->ShowWindow(SW_HIDE);
		pStatic = (CStatic*)GetDlgItem(IDC_STA5);
		pStatic->ShowWindow(SW_HIDE);
		pEdit = (CEdit*)GetDlgItem(IDC_EDIT5);
		pEdit->ShowWindow(SW_HIDE);
	}
	if (1 == index)
	{
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STA4);
		pStatic->ShowWindow(SW_SHOW);
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
		pEdit->ShowWindow(SW_SHOW);
		pStatic = (CStatic*)GetDlgItem(IDC_STA5);
		pStatic->ShowWindow(SW_HIDE);
		pEdit = (CEdit*)GetDlgItem(IDC_EDIT5);
		pEdit->ShowWindow(SW_HIDE);
	}
	if (2 == index)
	{
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STA4);
		pStatic->ShowWindow(SW_HIDE);
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
		pEdit->ShowWindow(SW_HIDE);
		pStatic = (CStatic*)GetDlgItem(IDC_STA5);
		pStatic->ShowWindow(SW_HIDE);
		pEdit = (CEdit*)GetDlgItem(IDC_EDIT5);
		pEdit->ShowWindow(SW_HIDE);
	}
	if (3 == index)
	{
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STA4);
		pStatic->ShowWindow(SW_SHOW);
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
		pEdit->ShowWindow(SW_SHOW);
		pStatic = (CStatic*)GetDlgItem(IDC_STA5);
		pStatic->ShowWindow(SW_HIDE);
		pEdit = (CEdit*)GetDlgItem(IDC_EDIT5);
		pEdit->ShowWindow(SW_HIDE);
	}
	if (4 == index)
	{
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STA4);
		pStatic->ShowWindow(SW_HIDE);
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
		pEdit->ShowWindow(SW_HIDE);
		pStatic = (CStatic*)GetDlgItem(IDC_STA5);
		pStatic->ShowWindow(SW_HIDE);
		pEdit = (CEdit*)GetDlgItem(IDC_EDIT5);
		pEdit->ShowWindow(SW_HIDE);
	}
	if (5 == index)
	{
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STA4);
		pStatic->ShowWindow(SW_SHOW);
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
		pEdit->ShowWindow(SW_SHOW);
		pStatic = (CStatic*)GetDlgItem(IDC_STA5);
		pStatic->ShowWindow(SW_SHOW);
		pEdit = (CEdit*)GetDlgItem(IDC_EDIT5);
		pEdit->ShowWindow(SW_SHOW);
	}

	// TODO: 在此添加控件通知处理程序代码
}
