// FiveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Five.h"
#include "FiveDlg.h"
#include "ChessAI.h"
#include "testcase.h"
#include <tlhelp32.h>
#include <windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFiveDlg dialog

CFiveDlg::CFiveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFiveDlg::IDD, pParent)
	, m_uiX(0)
	, m_uiY(0)
{
	//{{AFX_DATA_INIT(CFiveDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFiveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFiveDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_EDIT1, m_uiX);
	DDX_Text(pDX, IDC_EDIT2, m_uiY);
}

BEGIN_MESSAGE_MAP(CFiveDlg, CDialog)
	//{{AFX_MSG_MAP(CFiveDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CFiveDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFiveDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFiveDlg message handlers

BOOL CFiveDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CString str;

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	QueryPerformanceFrequency(&g_tc);
	//g_tc.QuadPart = 2338476;
	FiveCellMapInit();

	str.Format("0x%p", g_aui64LevelScore);
	SetDlgItemText(IDC_RESULT, str);


	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFiveDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFiveDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFiveDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

#define BASE_POS_X		 210	
#define BASE_POS_Y		 110
#define CELL_WIDTH		 38
#define CELL_HEIGHT		 38

DWORD GetProcessIDByName(const char* pName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot) {
		return NULL;
	}
	PROCESSENTRY32 pe = { sizeof(pe) };
	for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {
		if (strcmp(pe.szExeFile, pName) == 0) {
			CloseHandle(hSnapshot);
			return pe.th32ProcessID;
		}
		//printf("%-6d %s\n", pe.th32ProcessID, pe.szExeFile);
	}
	CloseHandle(hSnapshot);
	return 0;
}

struct handle_data {
	unsigned long process_id;
	HWND best_handle;
};

BOOL IsMainWindow(HWND handle)
{   
	return GetWindow(handle, GW_OWNER) == (HWND)0 && IsWindowVisible(handle);
}

BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam)
{
	handle_data& data = *(handle_data*)lParam;
	unsigned long process_id = 0;
	GetWindowThreadProcessId(handle, &process_id);
	if (data.process_id != process_id || !IsMainWindow(handle)) {
		return TRUE;
	}
	data.best_handle = handle;
	return FALSE;   
}

HWND FindMainWindow(unsigned long process_id)
{
	handle_data data;
	data.process_id = process_id;
	data.best_handle = 0;
	::EnumWindows(EnumWindowsCallback, (LPARAM)&data);
	return data.best_handle;
}




void CFiveDlg::ClickChess(int x, int y)
{

	DWORD processid = GetProcessIDByName("Five.exe");
	POINT p;
	RECT r1;
	LPARAM lParam = x*CELL_WIDTH + BASE_POS_X + ((y*CELL_WIDTH + BASE_POS_Y)<<16); 

	HWND hwnd = FindMainWindow(processid);
	::GetWindowRect(hwnd, &r1);
	GetCursorPos(&p);
	SetCursorPos(x*CELL_WIDTH + BASE_POS_X+r1.left, y*CELL_WIDTH + BASE_POS_Y+r1.top);

    //鼠标在当前位置按下
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	//鼠标在当前位置抬起
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);

	//SetCursorPos(p.x,p.y);

	//::SendMessage((HWND)0x001012FA, WM_LBUTTONDOWN , 1, lParam);
	//::SendMessage((HWND)0x001012FA, WM_LBUTTONUP , 1, lParam);
}

BYTE g_chess[15][15]=
{	        /*  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14   */	
		/*0 */  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*1 */  0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*2 */  0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,
		/*3 */  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
		/*4 */  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*5 */  0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 1, 0, 0, 0, 2,
		/*6 */  0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*7 */  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*8 */  0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		/*9 */  0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0,
		/*10*/  0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
		/*11 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*12*/  0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*13*/  0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0,
		/*14 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

};

LARGE_INTEGER g_tc;

extern UINT32 uiAiCnt;

extern UINT32 g_uiLeafCnt;
// 开始
void CFiveDlg::OnStart() 
{
	
	POINT pt;
	INT64 i64Score;
	BYTE array[15][15] = {0};





	//UpdateData(1);
	//ClickChess(m_uiX, m_uiY);
	//CChessAI ai;
	//ai.UpdataChessData((BYTE*)(VOID*)array);

	//return;

	//HWND hwnd=::FindWindow("Afx:400000:b:10011:6:280891","五子棋");
	//HWND hwnd=(HWND)0x02AA1140;
	//获取窗口进程ID
	DWORD processid;
	//::GetWindowThreadProcessId(hwnd,&processid);

	processid = GetProcessIDByName("Five.exe");


	//打开指定进程
	HANDLE processH=::OpenProcess(PROCESS_ALL_ACCESS,false,processid);
	//读指定进程 内存数据
	DWORD byread;
	LPCVOID pbase=(LPCVOID)BASE_ADDR;   //棋盘数据基址
	int x = 0;
	LPVOID  nbuffer=(LPVOID)&array;    //存放棋盘数据
	BOOL b = ::ReadProcessMemory(processH,pbase,nbuffer,4,&byread);
	//LPCVOID poffAddr = nbuffer
	x = * (int *)nbuffer;

	pbase = (LPCVOID)(x + 244);

	nbuffer=(LPVOID)&array;    //存放棋盘数据

	b = ::ReadProcessMemory(processH,pbase,nbuffer,15*15,&byread);

	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 15; y++)
		{
			if (array[x][y] == 5)
			{
				array[x][y] = WHITE_CHESS;
			}
			else if (array[x][y] == 6)
			{
				array[x][y] = BLACK_CHESS;
			}
		}
	}

	BYTE temp;
	for (int x = 0; x < 15; x++)
	{
		for (int j = 0; j <= x; j++)
		{
			temp = array[x][j];
			array[x][j] = array[j][x];
			array[j][x] = temp;
		}
	}

	//memcpy(array, g_chess, 15*15);


	SetDlgItemText(IDC_RESULT, "");

	UINT32 uiStart = GetTickCount();


	i64Score = 0;
	pt = AI(array, BLACK_CHESS, 3, &i64Score);
	ClearLevelScore();

	CString str2;
	str2.Format("AI Cnt=%d\n", uiAiCnt);
	OutputDebugString(str2);

	UINT32 uiEnd = GetTickCount();
	LARGE_INTEGER t1, t2;
	QueryPerformanceCounter(&t1);
	QueryPerformanceCounter(&t2);
	//UINT64 x = GET_NS(t1,t2);

	CString str;
	str.Format("叶子节点数:%u总共耗时:%u(ms)  位置（x:%u,y:%u） 得分:%d", g_uiLeafCnt, uiEnd - uiStart, pt.x, pt.y, i64Score);
	SetDlgItemText(IDC_RESULT, str);

	ClickChess(pt.y,pt.x);
	
}




void CFiveDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//ClickChess(0,0);
	
	// 测试 计算性能
	LARGE_INTEGER t1, t2;
	QueryPerformanceCounter(&t1);
	Evaluate(g_chess, BLACK_CHESS);
	QueryPerformanceCounter(&t2);
	UINT64 x = GET_NS(t1,t2);
	CString str2;
	str2.Format("老算法盘面得分===%d\n",x);
	OutputDebugString(str2);

	return;
}

void CFiveDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	TestSuit();
/*
	LARGE_INTEGER t1, t2;
	QueryPerformanceCounter(&t1);
	Evaluate2(g_chess, BLACK_CHESS);
	QueryPerformanceCounter(&t2);
	UINT64 x = GET_NS(t1,t2);
	CString str2;
	str2.Format("新算法盘面得分===%d\n",x);
	OutputDebugString(str2);


	QueryPerformanceCounter(&t1);
	IsWin(g_chess, BLACK_CHESS, 7, 7);
	QueryPerformanceCounter(&t2);
	x = GET_NS(t1,t2);
	str2.Format("落子输赢判断===%d\n",x);
	OutputDebugString(str2);
	*/
}


void TestCase1()
{
	POINT pt;
	INT64 i64Score;
	CString str;
	UINT32 uiStart;
	UINT32 uiEnd;
	BYTE array[15][15]=
	{	        /*  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14   */	
		/*0 */  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*1 */  0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*2 */  0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,
		/*3 */  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
		/*4 */  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*5 */  0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 1, 0, 0, 0, 2,
		/*6 */  0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*7 */  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*8 */  0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
		/*9 */  0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0,
		/*10*/  0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
		/*11 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*12*/  0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*13*/  0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0,
		/*14 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

	};
	i64Score = 0;
	uiStart = GetTickCount();
	pt = AI(array, BLACK_CHESS, 3, &i64Score);
	uiEnd = GetTickCount();
	ClearLevelScore();
	ASSERT(pt.x == 5 && pt.y == 5);

	str.Format("TestCase1:总共耗时(%u(ms))  位置（x:%u,y:%u） 得分:%d\n", uiEnd - uiStart, pt.x, pt.y, i64Score);
	OutputDebugString(str);

	i64Score = 0;
	uiStart = GetTickCount();
	pt = AI(array, BLACK_CHESS, 2, &i64Score);
	uiEnd = GetTickCount();
	ClearLevelScore();
	ASSERT(pt.x == 5 && pt.y == 5);
	str.Format("TestCase1:总共耗时(%u(ms))  位置（x:%u,y:%u） 得分:%d\n", uiEnd - uiStart, pt.x, pt.y, i64Score);
	OutputDebugString(str);

	i64Score = 0;
	uiStart = GetTickCount();
	pt = AI(array, BLACK_CHESS, 1, &i64Score);
	uiEnd = GetTickCount();
	ClearLevelScore();
	

	ASSERT(pt.x == 5 && pt.y == 5);
	str.Format("TestCase1:总共耗时(%u(ms))  位置（x:%u,y:%u） 得分:%d\n", uiEnd - uiStart, pt.x, pt.y, i64Score);
	OutputDebugString(str);
}


void TestCase2()
{
	POINT pt;
	INT64 i64Score;
	CString str;
	UINT32 uiStart;
	UINT32 uiEnd;
	BYTE array[15][15]=
	{	    /*  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14   */	
		/*0 */  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*1 */  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*2 */  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*3 */  0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
		/*4 */  0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0,
		/*5 */  0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 1, 0, 0, 0, 0,
		/*6 */  0, 0, 0, 0, 0, 0, 1, 1, 2, 0, 2, 0, 0, 0, 0,
		/*7 */  0, 0, 0, 0, 1, 0, 2, 2, 2, 1, 0, 2, 0, 0, 0,
		/*8 */  0, 0, 0, 0, 0, 0, 2, 1, 1, 0, 0, 0, 1, 0, 0,
		/*9 */  0, 0, 0, 0, 0, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0,
		/*10*/  0, 0, 0, 0, 0, 2, 1, 0, 1, 0, 0, 0, 0, 0, 0,
		/*11 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*12*/  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*13*/  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		/*14 */ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

	};
	i64Score = 0;
	uiStart = GetTickCount();
	pt = AI(array, BLACK_CHESS, 3, &i64Score);
	uiEnd = GetTickCount();
	ClearLevelScore();
	ASSERT(pt.x == 5 && pt.y == 5);

	str.Format("TestCase1:总共耗时(%u(ms))  位置（x:%u,y:%u） 得分:%d\n", uiEnd - uiStart, pt.x, pt.y, i64Score);
	OutputDebugString(str);
}

void TestSuit()
{
	//TestCase1();
	TestCase2();
}