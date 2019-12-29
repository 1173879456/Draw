#pragma once


// Mydialog 对话框

class Mydialog : public CDialogEx
{
	DECLARE_DYNAMIC(Mydialog)

public:
	Mydialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Mydialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int x;
	int wr;
	int y;
	int h;
	CString text;
	int lw;
	CComboBox Combox;
	COLORREF color1;
	COLORREF color2;
	virtual BOOL OnInitDialog();
	int index;
	CListBox listbox1;
	CListBox listbox2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();	
	afx_msg void OnCbnSelchangeCombo1();
	CMFCColorButton colorbtn1;
	CMFCColorButton colorbtn2;
	int index1;
	int index2;
};
