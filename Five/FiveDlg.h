// FiveDlg.h : header file
//

#if !defined(AFX_FIVEDLG_H__1EDA4D45_E6E9_46CE_B2A3_69E040E54B7B__INCLUDED_)
#define AFX_FIVEDLG_H__1EDA4D45_E6E9_46CE_B2A3_69E040E54B7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFiveDlg dialog

class CFiveDlg : public CDialog
{
// Construction
public:
	CFiveDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFiveDlg)
	enum { IDD = IDD_FIVE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFiveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFiveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	void ClickChess(int x, int y);
	unsigned int m_uiX;
	unsigned int m_uiY;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIVEDLG_H__1EDA4D45_E6E9_46CE_B2A3_69E040E54B7B__INCLUDED_)
