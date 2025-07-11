
// BaseConverterDlg.h : header file
//

#pragma once


// CBaseConverterDlg dialog
class CBaseConverterDlg : public CDialogEx
{
// Construction
public:
	CBaseConverterDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BASECONVERTER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	CEdit m_editCtrl;
	afx_msg void BinaryConvert();
	afx_msg void HexadecimalConvert();
	afx_msg void DecimalConvert();
	afx_msg void Base36Convert();
	afx_msg void Base62Convert();
	CEdit m_StaticText;
};
