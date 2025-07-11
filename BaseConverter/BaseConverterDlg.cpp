
// BaseConverterDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "BaseConverter.h"
#include "BaseConverterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <string>
#include <iostream>
using namespace std;


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBaseConverterDlg dialog



CBaseConverterDlg::CBaseConverterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BASECONVERTER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBaseConverterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_editCtrl);
	DDX_Control(pDX, IDC_EDIT1, m_StaticText);
}

BEGIN_MESSAGE_MAP(CBaseConverterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT2, &CBaseConverterDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CBaseConverterDlg::BinaryConvert)
	ON_BN_CLICKED(IDC_BUTTON2, &CBaseConverterDlg::HexadecimalConvert)
	ON_BN_CLICKED(IDC_BUTTON5, &CBaseConverterDlg::DecimalConvert)
	ON_BN_CLICKED(IDC_BUTTON3, &CBaseConverterDlg::Base36Convert)
	ON_BN_CLICKED(IDC_BUTTON4, &CBaseConverterDlg::Base62Convert)
END_MESSAGE_MAP()


// CBaseConverterDlg message handlers

BOOL CBaseConverterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetWindowText(L"Base Converter");

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBaseConverterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBaseConverterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBaseConverterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CBaseConverterDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}



        void CBaseConverterDlg::BinaryConvert()
        {
	
									CString inputText;
									m_editCtrl.GetWindowTextW(inputText);
									if (inputText.IsEmpty())
									{
										AfxMessageBox(L"Please enter a value to convert.");
										return;
									}
									std::wstring inputStr = inputText.GetString();
									if ((inputText.GetLength() == 8) || (inputText.GetLength() == 4))
									{
										bool isBinary = true;
										for (int i = 0; i < inputText.GetLength(); ++i)
										{
											if (inputText[i] != L'0' && inputText[i] != L'1')
											{
												isBinary = false;
												break;
											}
										}
										if (isBinary)
										{
											m_StaticText.SetWindowTextW(inputText);
											return;
										}
									}

							
									bool isHex = true;
									for (int i = 0; i < inputText.GetLength(); ++i)
									{
										wchar_t ch = inputText[i];
										if (!((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F') || (ch >= L'a' && ch <= L'f')))
										{
											isHex = false;
											break;
										}
									}
									if (!isHex)
									{
										AfxMessageBox(L"Input is not a valid hexadecimal value.");
										return;
									}

									
									std::wstring binaryResult;
									for (wchar_t ch : inputStr)
									{
										int value = 0;
										if (ch >= L'0' && ch <= L'9')
											value = ch - L'0';
										else if (ch >= L'A' && ch <= L'F')
											value = 10 + (ch - L'A');
										else if (ch >= L'a' && ch <= L'f')
											value = 10 + (ch - L'a');

										for (int i = 3; i >= 0; --i)
										{
											binaryResult += ((value >> i) & 1) ? L'1' : L'0';
										}
										binaryResult += L" ";

				}
									
				m_StaticText.SetWindowTextW(binaryResult.c_str());
        }




    void CBaseConverterDlg::HexadecimalConvert()
    {
					CString inputText;
					m_editCtrl.GetWindowTextW(inputText);
					if (inputText.IsEmpty())
					{
						AfxMessageBox(L"Please enter a value to convert.");
						return;
					}
					std::wstring inputStr = inputText.GetString();

					
					bool isBinary = true;
					for (int i = 0; i < inputText.GetLength(); ++i)
					{
						if (inputText[i] != L'0' && inputText[i] != L'1')
						{
							isBinary = false;
							break;
						}
					}
					if (isBinary && (inputText.GetLength() % 4 == 0))
					{
						std::wstring hexResult;
						for (int i = 0; i < inputText.GetLength(); i += 4)
						{
							int value = 0;
							for (int j = 0; j < 4; ++j)
							{
								value = (value << 1) | (inputText[i + j] == L'1' ? 1 : 0);
							}
							wchar_t hexChar;
							if (value < 10)
								hexChar = L'0' + value;
							else
								hexChar = L'A' + (value - 10);
							hexResult += hexChar;
						}
						m_StaticText.SetWindowTextW(hexResult.c_str());
						return;
					}

					
					
					bool isDecimal = true;
					for (int i = 0; i < inputText.GetLength(); ++i)
					{
						if (!(inputText[i] >= L'0' && inputText[i] <= L'9'))
						{
							isDecimal = false;
							break;
						}
					}
					if (isDecimal)
					{
						unsigned long value = std::stoul(inputStr, nullptr, 10);
						wchar_t hexBuffer[20];
						swprintf_s(hexBuffer, L"%X", value);
						m_StaticText.SetWindowTextW(hexBuffer);
						return;
					}

					bool isHex = true;
					for (int i = 0; i < inputText.GetLength(); ++i)
					{
						wchar_t ch = inputText[i];
						if (!((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F') || (ch >= L'a' && ch <= L'f')))
						{
							isHex = false;
							break;
						}
					}
					if (isHex)
					{
						unsigned long value = std::stoul(inputStr, nullptr, 16);
						wchar_t hexBuffer[20];
						swprintf_s(hexBuffer, L"%X", value);
						m_StaticText.SetWindowTextW(hexBuffer);
						return;
					}

					AfxMessageBox(L"Input is not a valid hexadecimal, binary, or decimal value.");

    }

	
	


void CBaseConverterDlg::DecimalConvert()  
{  
    CString InputText;  
    m_editCtrl.GetWindowTextW(InputText);
    if (InputText.IsEmpty())
    {
        AfxMessageBox(L"Please enter a value to convert.");
        return;
    }

   
    if (InputText.GetLength() == 9 && InputText[1] == L'#')
    {
        CString binPart = InputText.Mid(1, 8);
        bool isBinary = true;
        for (int i = 0; i < 8; ++i)
        {
            if (binPart[i] != L'0' && binPart[i] != L'1')
            {
                isBinary = false;
                break;
            }
        }
        if (isBinary)
        {
            unsigned long decimalValue = 0;
            for (int i = 0; i < 8; ++i)
            {
                decimalValue = (decimalValue << 1) | (binPart[i] - L'0');
            }
            CString decimalResult;
            decimalResult.Format(L"%lu", decimalValue);
            m_StaticText.SetWindowTextW(decimalResult);
            return;
        }
    }
    if (InputText.GetLength() == 5 && InputText[0] == L'#')
    {
        CString binPart = InputText.Mid(1, 4);
        bool isBinary = true;
        for (int i = 0; i < 4; ++i)
        {
            if (binPart[i] != L'0' && binPart[i] != L'1')
            {
                isBinary = false;
                break;
            }
        }
        if (isBinary)
        {
            unsigned long decimalValue = 0;
            for (int i = 0; i < 4; ++i)
            {
                decimalValue = (decimalValue << 1) | (binPart[i] - L'0');
            }
            CString decimalResult;
            decimalResult.Format(L"%lu", decimalValue);
            m_StaticText.SetWindowTextW(decimalResult);
            return;
        }
    }

    if (InputText.GetLength() == 8 || InputText.GetLength() == 4)
    {
        bool isBinary = true;
        for (int i = 0; i < InputText.GetLength(); ++i)
        {
            if (InputText[i] != L'0' && InputText[i] != L'1')
            {
                isBinary = false;
                break;
            }
        }
        if (isBinary)
        {
            if (InputText.GetLength() == 8 || InputText.GetLength() == 4)
            {
                unsigned long decimalValue = 0; 
                for (int i = 0; i < InputText.GetLength(); ++i)
                {
                    decimalValue = (decimalValue << 1) | (InputText[i] - L'0');
                }
                CString decimalResult;
                decimalResult.Format(L"%lu", decimalValue);
                m_StaticText.SetWindowTextW(decimalResult);
                return;
            }
            else
            {
                AfxMessageBox(L"Binary input must be 4 or 8 bits long.");
                return;
            }
        }
    }

    bool isDecimal = true;
    for (int i = 0; i < InputText.GetLength(); ++i)
    {
        if (!(InputText[i] >= L'0' && InputText[i] <= L'9'))
        {
            isDecimal = false;
            break;
        }
    }
    if (isDecimal)
    {
        unsigned long decimalValue = std::stoul(InputText.GetString(), nullptr, 10);
        CString decimalResult;
        decimalResult.Format(L"%lu", decimalValue);
        m_StaticText.SetWindowTextW(decimalResult);
        return;
    }

	bool isHex = true;
	for (int i = 0; i < InputText.GetLength(); ++i)
	{
		wchar_t ch = InputText[i];
		if (!((ch >= L'0' && ch <= L'9') || (ch >= L'A' && ch <= L'F') || (ch >= L'a' && ch <= L'f')))
		{
			isHex = false;
			break;
		}
	}
	if (isHex)
	{
		unsigned long decimalValue = std::stoul(InputText.GetString(), nullptr, 16);
		CString decimalResult;
		decimalResult.Format(L"%lu", decimalValue);
		m_StaticText.SetWindowTextW(decimalResult);
		return;
	}

}


void CBaseConverterDlg::Base36Convert()
{
	const char digits[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	CString inputText;
	m_editCtrl.GetWindowTextW(inputText);
	if (inputText.IsEmpty())
	{
		AfxMessageBox(L"Please enter a value to convert.");
		return;
	}
		
	// Check if input is a valid decimal number
	bool isDecimal = true;
	for (int i = 0; i < inputText.GetLength(); ++i)
	{
		if (!(inputText[i] >= L'0' && inputText[i] <= L'9'))
		{
			isDecimal = false;
			break;
		}
	}
	if (!isDecimal)
	{
		AfxMessageBox(L"Input is not a valid decimal value.");
		return;
	}

	
	unsigned long value = std::stoul(inputText.GetString(), nullptr, 10);
	std::string base36Result;
	if (value == 0)
	{
		base36Result = "0";
	}
	else
	{
		while (value > 0)
		{
			base36Result = digits[value % 36] + base36Result;
			value /= 36;
		}
	}

	CString result(base36Result.c_str());
	m_StaticText.SetWindowTextW(result);
}

	
void CBaseConverterDlg::Base62Convert()
{
	const char digits[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	CString inputText;
	m_editCtrl.GetWindowTextW(inputText);
	if(inputText.IsEmpty())
	{
		AfxMessageBox(L"Please enter a value to convert.");
		return;
	}
	bool isDecimal = true;
	for (int i = 0; i < inputText.GetLength(); ++i)
	{
		if (!(inputText[i] >= L'0' && inputText[i] <= L'9'))
		{
			isDecimal = false;
			break;
		}
	}
	if (!isDecimal)
	{
		AfxMessageBox(L"Input is not a valid decimal value.");
		return;
	}
	unsigned long value = std::stoul(inputText.GetString(), nullptr, 10);
	std::string base62Result;
	if (value == 0)
	{
		base62Result = "0";
	}
	else
	{
		while (value > 0)
		{
			base62Result = digits[value % 62] + base62Result;
			value /= 62;
		}
	}
	CString result(base62Result.c_str());
	m_StaticText.SetWindowTextW(result);


	bool isBinary = true;
	for (int i = 0; i < inputText.GetLength(); ++i)
	{
		if (inputText[i] != L'0' && inputText[i] != L'1')
		{
			isBinary = false;
			break;
		}
	}
	if (isBinary && (inputText.GetLength() == 8 || inputText.GetLength() == 4))
	{
		unsigned long decimalValue = 0;
		for (int i = 0; i < inputText.GetLength(); ++i)
		{
			decimalValue = (decimalValue << 1) | (inputText[i] - L'0');
		}
		CString decimalResult;
		decimalResult.Format(L"%lu", decimalValue);
		m_StaticText.SetWindowTextW(decimalResult);
		return;
	}



}
