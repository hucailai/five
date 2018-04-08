// Five.h : main header file for the FIVE application
//

#if !defined(AFX_FIVE_H__4D4602F4_035D_40FF_A3EE_864782FCE16D__INCLUDED_)
#define AFX_FIVE_H__4D4602F4_035D_40FF_A3EE_864782FCE16D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFiveApp:
// See Five.cpp for the implementation of this class
//

class CFiveApp : public CWinApp
{
public:
	CFiveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFiveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFiveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//void UpdataChessData(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT])
//{
//	m_gBlackChessArray.clear();
//	m_gWhiteChessArray.clear();
//	for (int i = 0; i < WIDTH_COUNT; i++)
//	{
//		for (int j = 0; j < HEIGHT_COUNT; j++)
//		{
//			POINT pt = {i,j};
//			if (abChessArray[i][j] == BLACK_CHESS)
//			{
//				m_gBlackChessArray.push_back(pt);
//			}
//			else if (abChessArray[i][j] == WHITE_CHESS)
//			{
//				m_gWhiteChessArray.push_back(pt);
//			}
//		}
//	}
//}

//void CChessAI::UpdataChessData(BYTE *pData)
//{
//	m_blackChessArray.clear();
//	m_whiteChessArray.clear();
//	for (int i = 0; i < HEIGHT_COUNT; i++)
//	{
//		for (int j = 0; j < WIDTH_COUNT; j++)
//		{
//			if ((*(pData+i * WIDTH_COUNT+j))==1 || (*(pData+i * WIDTH_COUNT+j))==5)
//			{
//				POINT pt = {i,j};
//				m_blackChessArray.push_back(pt);
//				m_chessArray[i][j] = WHITE_CHESS;
//			}
//			else if ((*(pData+i * WIDTH_COUNT+j))==2 || (*(pData+i * WIDTH_COUNT+j))==6)
//			{
//				POINT pt = {i,j};
//				m_whiteChessArray.push_back(pt);
//				m_chessArray[i][j] = BLACK_CHESS;
//
//			}
//			else
//			{
//				m_chessArray[i][j] = NO_CHESS;
//			}
//		}
//	}
//}
//
//BOOL CChessAI::CanFive(POINT pt, int nColor)
//{
//	int nCount = 1;
//	int m,n;
//	//////////////////////////////////////////////////////////////////////////x+
//	for (m = pt.x + 1; m < WIDTH_COUNT; m++)
//	{
//		if (m_chessArray[m][pt.y] == nColor)
//		{
//			nCount++;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	for (m = pt.x - 1; m > 0; m--)
//	{
//		if (m_chessArray[m][pt.y] == nColor)
//		{
//			nCount++;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if (nCount == 5) return TRUE;
//
//	//////////////////////////////////////////////////////////////////////////y+
//	for (n = pt.y + 1; n < HEIGHT_COUNT; n++)
//	{
//		if (m_chessArray[pt.x][n] == nColor)
//		{
//			nCount++;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	for (n = pt.x - 1; n > 0; n--)
//	{
//		if (m_chessArray[pt.x][n] == nColor)
//		{
//			nCount++;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if (nCount == 5) return TRUE;
//	////////////////////////////////////////////////////////////////////////// x+,y+
//	for (m = pt.x + 1,n = pt.y+1; m < WIDTH_COUNT && n < HEIGHT_COUNT; m++,n++)
//	{
//		if (m_chessArray[m][n] == nColor)
//		{
//			nCount++;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	for (m = pt.x - 1, n = pt.y - 1; m > 0 && n > 0; m--, n--)
//	{
//		if (m_chessArray[m][n] == nColor)
//		{
//			nCount++;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if (nCount == 5) return TRUE;
//	//////////////////////////////////////////////////////////////////////////x+,y-
//	for (m = pt.x + 1,n = pt.y-1; m < WIDTH_COUNT && n > 0; m++,n--)
//	{
//		if (m_chessArray[m][n] == nColor)
//		{
//			nCount++;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	for (m = pt.x - 1, n = pt.y + 1; m > 0 && n < WIDTH_COUNT; m--, n++)
//	{
//		if (m_chessArray[m][n] == nColor)
//		{
//			nCount++;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if (nCount == 5) return TRUE;
//
//	return FALSE;
//}
//
//BOOL CChessAI::CanFour(POINT pt, int nColor)
//{
//	int nCount = 1;
//	int m,n;
//	//////////////////////////////////////////////////////////////////////////x+
//	for (m = pt.x + 1; m < WIDTH_COUNT; m++)
//	{
//		if (m_chessArray[m][pt.y] == nColor)
//		{
//			nCount++;
//		}
//		else if (m_chessArray[m][pt.y] == NO_CHESS)
//		{
//			nCount++;
//			break;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	for (m = pt.x - 1; m > 0; m--)
//	{
//		if (m_chessArray[m][pt.y] == nColor)
//		{
//			nCount++;
//		}
//		else if (m_chessArray[m][pt.y] == NO_CHESS)
//		{
//			nCount++;
//			break;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if (nCount == 6) return TRUE;
//
//	//////////////////////////////////////////////////////////////////////////y+
//	for (n = pt.y + 1; n < HEIGHT_COUNT; n++)
//	{
//		if (m_chessArray[pt.x][n] == nColor)
//		{
//			nCount++;
//		}
//		else if (m_chessArray[pt.x][n] == NO_CHESS)
//		{
//			nCount++;
//			break;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	for (n = pt.x - 1; n > 0; n--)
//	{
//		if (m_chessArray[pt.x][n] == nColor)
//		{
//			nCount++;
//		}
//		else if (m_chessArray[pt.x][n] == NO_CHESS)
//		{
//			nCount++;
//			break;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if (nCount == 6) return TRUE;
//	////////////////////////////////////////////////////////////////////////// x+,y+
//	for (m = pt.x + 1,n = pt.y+1; m < WIDTH_COUNT && n < HEIGHT_COUNT; m++,n++)
//	{
//		if (m_chessArray[m][n] == nColor)
//		{
//			nCount++;
//		}
//		else if (m_chessArray[m][n] == NO_CHESS)
//		{
//			nCount++;
//			break;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	for (m = pt.x - 1, n = pt.y - 1; m > 0 && n > 0; m--, n--)
//	{
//		if (m_chessArray[m][n] == nColor)
//		{
//			nCount++;
//		}
//		else if (m_chessArray[m][n] == NO_CHESS)
//		{
//			nCount++;
//			break;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if (nCount == 6) return TRUE;
//	//////////////////////////////////////////////////////////////////////////x+,y-
//	for (m = pt.x + 1,n = pt.y-1; m < WIDTH_COUNT && n > 0; m++,n--)
//	{
//		if (m_chessArray[m][n] == nColor)
//		{
//			nCount++;
//		}
//		else if (m_chessArray[m][n] == NO_CHESS)
//		{
//			nCount++;
//			break;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	for (m = pt.x - 1, n = pt.y + 1; m > 0 && n < WIDTH_COUNT; m--, n++)
//	{
//		if (m_chessArray[m][n] == nColor)
//		{
//			nCount++;
//		}
//		else if (m_chessArray[m][n] == NO_CHESS)
//		{
//			nCount++;
//			break;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if (nCount == 6) return TRUE;
//
//	return FALSE;
//}
//
//BOOL CChessAI::CanThree(POINT pt, int nColor, int nDirection)
//{
//	int x = pt.x;
//	int y = pt.y;
//	if (nDirection == DIRECTION_A)
//	{
//		if (x+1 < WIDTH_COUNT && m_chessArray[x+1][y] == nColor && 
//			x+2 < WIDTH_COUNT && m_chessArray[x+2][y] == nColor &&
//			x+3 < WIDTH_COUNT && m_chessArray[x+3][y] == NO_CHESS &&
//			x-1 > 0 && m_chessArray[x-1][y] == NO_CHESS && 
//			((x-2 > 0 && m_chessArray[x-2][y]) == NO_CHESS) ||
//			(x+4 < WIDTH_COUNT && m_chessArray[x+4][y] == NO_CHESS))
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && m_chessArray[x+1][y] == nColor && 
//			x+2 < WIDTH_COUNT && m_chessArray[x+2][y] == NO_CHESS &&
//			x-1 > 0 && m_chessArray[x-1][y] == nColor &&
//			x-2 > 0 && m_chessArray[x-2][y] == NO_CHESS && 
//			((x-3 > 0 && m_chessArray[x-3][y]) == NO_CHESS) ||
//			(x+3 < WIDTH_COUNT && m_chessArray[x+3][y] == NO_CHESS))
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && m_chessArray[x+1][y] == NO_CHESS && 
//			x-1 > 0 && m_chessArray[x-1][y] == nColor &&
//			x-2 > 0 && m_chessArray[x-2][y] == nColor &&
//			x-3 > 0 && m_chessArray[x-3][y] == NO_CHESS && 
//			((x-4 > 0 && m_chessArray[x-4][y]) == NO_CHESS) ||
//			(x+2 < WIDTH_COUNT && m_chessArray[x+2][y] == NO_CHESS))
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && m_chessArray[x+1][y] == NO_CHESS && 
//			x+2 < WIDTH_COUNT && m_chessArray[x+2][y] == nColor &&
//			x+3 < WIDTH_COUNT && m_chessArray[x+3][y] == NO_CHESS &&
//			x-1 > 0 && m_chessArray[x-1][y] == nColor && 
//			x-2 > 0 && m_chessArray[x-2][y] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && m_chessArray[x+1][y] == NO_CHESS && 
//			x+2 < WIDTH_COUNT && m_chessArray[x+2][y] == nColor &&
//			x+3 < WIDTH_COUNT && m_chessArray[x+3][y] == nColor &&
//			x+4 < WIDTH_COUNT && m_chessArray[x+4][y] == NO_CHESS && 
//			x-1 > 0 && m_chessArray[x-1][y] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && m_chessArray[x+1][y] == nColor && 
//			x+2 < WIDTH_COUNT && m_chessArray[x+2][y] == NO_CHESS &&
//			x+3 < WIDTH_COUNT && m_chessArray[x+3][y] == nColor &&
//			x+4 < WIDTH_COUNT && m_chessArray[x+4][y] == NO_CHESS && 
//			x-1 > 0 && m_chessArray[x-1][y] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && m_chessArray[x+1][y] == nColor && 
//			x+2 < WIDTH_COUNT && m_chessArray[x+2][y] == NO_CHESS &&
//			x-1 > 0 && m_chessArray[x-1][y] == NO_CHESS &&
//			x-2 > 0 && m_chessArray[x-2][y] == nColor && 
//			x-3 > 0 && m_chessArray[x-3][y] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && m_chessArray[x+1][y] == NO_CHESS && 
//			x-1 > 0 && m_chessArray[x-1][y] == NO_CHESS &&
//			x-2 > 0 && m_chessArray[x-2][y] == nColor &&
//			x-3 > 0 && m_chessArray[x-3][y] == nColor && 
//			x-4 > 0 && m_chessArray[x-4][y] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && m_chessArray[x+1][y] == NO_CHESS && 
//			x-1 > 0 && m_chessArray[x-1][y] == nColor &&
//			x-2 > 0 && m_chessArray[x-2][y] == NO_CHESS &&
//			x-3 > 0 && m_chessArray[x-3][y] == nColor && 
//			x-4 > 0 && m_chessArray[x-4][y] == NO_CHESS)
//		{
//			return TRUE;
//		}
//	}
//	else if (nDirection == DIRECTION_B)
//	{
//		if (y+1 < WIDTH_COUNT && m_chessArray[x][y+1] == nColor && 
//			y+2 < WIDTH_COUNT && m_chessArray[x][y+2] == nColor &&
//			y+3 < WIDTH_COUNT && m_chessArray[x][y+3] == NO_CHESS &&
//			y-1 > 0 && m_chessArray[x][y-1] == NO_CHESS && 
//			((y-2 > 0 && m_chessArray[x][y-2]) == NO_CHESS) ||
//			(y+4 < WIDTH_COUNT && m_chessArray[x][y+4] == NO_CHESS))
//		{
//			return TRUE;
//		}
//		if (y+1 < WIDTH_COUNT && m_chessArray[x][y+1] == nColor && 
//			y+2 < WIDTH_COUNT && m_chessArray[x][y+2] == NO_CHESS &&
//			y-1 > 0 && m_chessArray[x][y-1] == nColor &&
//			y-2 > 0 && m_chessArray[x][y-2] == NO_CHESS && 
//			((y-3 > 0 && m_chessArray[x][y-3]) == NO_CHESS) ||
//			(y+3 < WIDTH_COUNT && m_chessArray[x][y+3] == NO_CHESS))
//		{
//			return TRUE;
//		}
//		if (y+1 < WIDTH_COUNT && m_chessArray[x][y+1] == NO_CHESS && 
//			y-1 > 0 && m_chessArray[x][y-1] == nColor &&
//			y-2 > 0 && m_chessArray[x][y-2] == nColor &&
//			y-3 > 0 && m_chessArray[x][y-3] == NO_CHESS && 
//			((y-4 > 0 && m_chessArray[x][y-4]) == NO_CHESS) ||
//			(y+2 < WIDTH_COUNT && m_chessArray[x][y+2] == NO_CHESS))
//		{
//			return TRUE;
//		}
//		if (y+1 < WIDTH_COUNT && m_chessArray[x][y+1] == NO_CHESS && 
//			y+2 < WIDTH_COUNT && m_chessArray[x][y+2] == nColor &&
//			y+3 < WIDTH_COUNT && m_chessArray[x][y+3] == NO_CHESS &&
//			y-1 > 0 && m_chessArray[x][y-1] == nColor && 
//			y-2 > 0 && m_chessArray[x][y-2] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (y+1 < WIDTH_COUNT && m_chessArray[x][y+1] == NO_CHESS && 
//			y+2 < WIDTH_COUNT && m_chessArray[x][y+2] == nColor &&
//			y+3 < WIDTH_COUNT && m_chessArray[x][y+3] == nColor &&
//			y+4 < WIDTH_COUNT && m_chessArray[x][y+4] == NO_CHESS && 
//			y-1 > 0 && m_chessArray[x][y-1] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (y+1 < WIDTH_COUNT && m_chessArray[x][y+1] == nColor && 
//			y+2 < WIDTH_COUNT && m_chessArray[x][y+2] == NO_CHESS &&
//			y+3 < WIDTH_COUNT && m_chessArray[x][y+3] == nColor &&
//			y+4 < WIDTH_COUNT && m_chessArray[x][y+4] == NO_CHESS && 
//			y-1 > 0 && m_chessArray[x][y-1] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (y+1 < WIDTH_COUNT && m_chessArray[x][y+1] == nColor && 
//			y+2 < WIDTH_COUNT && m_chessArray[x][y+2] == NO_CHESS &&
//			y-1 > 0 && m_chessArray[x][y-1] == NO_CHESS &&
//			y-2 > 0 && m_chessArray[x][y-2] == nColor && 
//			y-3 > 0 && m_chessArray[x][y-3] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (y+1 < WIDTH_COUNT && m_chessArray[x+1][y] == NO_CHESS && 
//			y-1 > 0 && m_chessArray[x][y-1] == NO_CHESS &&
//			y-2 > 0 && m_chessArray[x][y-2] == nColor &&
//			y-3 > 0 && m_chessArray[x][y-3] == nColor && 
//			y-4 > 0 && m_chessArray[x][y-4] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (y+1 < WIDTH_COUNT && m_chessArray[x][y+1] == NO_CHESS && 
//			y-1 > 0 && m_chessArray[x][y-1] == nColor &&
//			y-2 > 0 && m_chessArray[x][y-2] == NO_CHESS &&
//			y-3 > 0 && m_chessArray[x][y-3] == nColor && 
//			y-4 > 0 && m_chessArray[x][y-4] == NO_CHESS)
//		{
//			return TRUE;
//		}
//	}
//	else if (nDirection == DIRECTION_C)
//	{
//		if (x+1 < WIDTH_COUNT && y+1 < WIDTH_COUNT && m_chessArray[x+1][y+1] == nColor && 
//			x+2 < WIDTH_COUNT && y+2 < WIDTH_COUNT && m_chessArray[x+2][y+2] == nColor &&
//			x+3 < WIDTH_COUNT && y+3 < WIDTH_COUNT && m_chessArray[x+3][y+3] == NO_CHESS &&
//			x-1 > 0 && y-1 > 0 && m_chessArray[x-1][y-1] == NO_CHESS && 
//			((x-2 > 0 && y-2 > 0 && m_chessArray[x-2][y-2]) == NO_CHESS) ||
//			(x+4 < WIDTH_COUNT && y+4 < WIDTH_COUNT && m_chessArray[x+4][y+4] == NO_CHESS))
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && y+1 < WIDTH_COUNT && m_chessArray[x+1][y+1] == nColor && 
//			x+2 < WIDTH_COUNT && y+2 < WIDTH_COUNT && m_chessArray[x+2][y+2] == NO_CHESS &&
//			x-1 > 0 && y-1 > 0 && m_chessArray[x-1][y-1] == nColor &&
//			x-2 > 0 && y-2 > 0 && m_chessArray[x-2][y-2] == NO_CHESS && 
//			((x-3 > 0 && y-3 > 0 && m_chessArray[x-3][y-3]) == NO_CHESS) ||
//			(x+3 < WIDTH_COUNT && y+3 < WIDTH_COUNT && m_chessArray[x+3][y+3] == NO_CHESS))
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && y+1 < WIDTH_COUNT && m_chessArray[x+1][y+1] == NO_CHESS && 
//			x-1 > 0 && y-1 > 0 && m_chessArray[x-1][y-1] == nColor &&
//			x-2 > 0 && y-2 > 0 && m_chessArray[x-2][y-2] == nColor &&
//			x-3 > 0 && y-3 > 0 && m_chessArray[x-3][y-3] == NO_CHESS && 
//			((x-4 > 0 && y-4 > 0 && m_chessArray[x-4][y-4]) == NO_CHESS) ||
//			(x+2 < WIDTH_COUNT && y+2 < WIDTH_COUNT && m_chessArray[x+2][y+2] == NO_CHESS))
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && y+1 < WIDTH_COUNT && m_chessArray[x+1][y+1] == NO_CHESS && 
//			x+2 < WIDTH_COUNT && y+2 < WIDTH_COUNT && m_chessArray[x+2][y+2] == nColor &&
//			x+3 < WIDTH_COUNT && y+3 < WIDTH_COUNT && m_chessArray[x+3][y+3] == NO_CHESS &&
//			x-1 > 0 && y-1 > 0 && m_chessArray[x-1][y-1] == nColor && 
//			x-2 > 0 && y-2 > 0 && m_chessArray[x-2][y-2] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && y+1 < WIDTH_COUNT && m_chessArray[x+1][y+1] == NO_CHESS && 
//			x+2 < WIDTH_COUNT && y+2 < WIDTH_COUNT && m_chessArray[x+2][y+2] == nColor &&
//			x+3 < WIDTH_COUNT && y+3 < WIDTH_COUNT && m_chessArray[x+3][y+3] == nColor &&
//			x+4 < WIDTH_COUNT && y+4 < WIDTH_COUNT && m_chessArray[x+4][y+4] == NO_CHESS && 
//			x-1 > 0 && y-1 > 0 && m_chessArray[x-1][y-1] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && y+1 < WIDTH_COUNT && m_chessArray[x+1][y+1] == nColor && 
//			x+2 < WIDTH_COUNT && y+2 < WIDTH_COUNT && m_chessArray[x+2][y+2] == NO_CHESS &&
//			x+3 < WIDTH_COUNT && y+3 < WIDTH_COUNT && m_chessArray[x+3][y+3] == nColor &&
//			x+4 < WIDTH_COUNT && y+4 < WIDTH_COUNT && m_chessArray[x+4][y+4] == NO_CHESS && 
//			x-1 > 0 && y-1 > 0 && m_chessArray[x-1][y-1] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && y+1 < WIDTH_COUNT && m_chessArray[x+1][y+1] == nColor && 
//			x+2 < WIDTH_COUNT && y+2 < WIDTH_COUNT && m_chessArray[x+2][y+2] == NO_CHESS &&
//			x-1 > 0 && y-1 > 0 && m_chessArray[x-1][y-1] == NO_CHESS &&
//			x-2 > 0 && y-2 > 0 && m_chessArray[x-2][y-2] == nColor && 
//			x-3 > 0 && y-3 > 0 && m_chessArray[x-3][y-3] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && y+1 < WIDTH_COUNT && m_chessArray[x+1][y+1] == NO_CHESS && 
//			x-1 > 0 && y-1 > 0 && m_chessArray[x-1][y-1] == NO_CHESS &&
//			x-2 > 0 && y-2 > 0 && m_chessArray[x-2][y-2] == nColor &&
//			x-3 > 0 && y-3 > 0 && m_chessArray[x-3][y-3] == nColor && 
//			x-4 > 0 && y-4 > 0 && m_chessArray[x-4][y-4] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x+1 < WIDTH_COUNT && y+1 < WIDTH_COUNT && m_chessArray[x+1][y+1] == NO_CHESS && 
//			x-1 > 0 && y-1 > 0 && m_chessArray[x-1][y-1] == nColor &&
//			x-2 > 0 && y-2 > 0 && m_chessArray[x-2][y-2] == NO_CHESS &&
//			x-3 > 0 && y-3 > 0 && m_chessArray[x-3][y-3] == nColor && 
//			x-4 > 0 && y-4 > 0 && m_chessArray[x-4][y-4] == NO_CHESS)
//		{
//			return TRUE;
//		}
//	}
//	else if (nDirection == DIRECTION_D)
//	{
//		if (x-1 >0 && y+1 < WIDTH_COUNT && m_chessArray[x-1][y+1] == nColor && 
//			x-2 >0 && y+2 < WIDTH_COUNT && m_chessArray[x-2][y+2] == nColor &&
//			x-3 >0 && y+3 < WIDTH_COUNT && m_chessArray[x-3][y+3] == NO_CHESS &&
//			x+1 < WIDTH_COUNT && y-1 > 0 && m_chessArray[x+1][y-1] == NO_CHESS && 
//			((x+2 < WIDTH_COUNT && y-2 > 0 && m_chessArray[x+2][y-2]) == NO_CHESS) ||
//			(x-4 >0 && y+4 < WIDTH_COUNT && m_chessArray[x-4][y+4] == NO_CHESS))
//		{
//			return TRUE;
//		}
//		if (x-1 >0 && y+1 < WIDTH_COUNT && m_chessArray[x-1][y+1] == nColor && 
//			x-2 >0 && y+2 < WIDTH_COUNT && m_chessArray[x-2][y+2] == NO_CHESS &&
//			x+1 < WIDTH_COUNT && y-1 > 0 && m_chessArray[x+1][y-1] == nColor &&
//			x+2 < WIDTH_COUNT && y-2 > 0 && m_chessArray[x+2][y-2] == NO_CHESS && 
//			((x+3 < WIDTH_COUNT && y-3 > 0 && m_chessArray[x+3][y-3]) == NO_CHESS) ||
//			(x-3 >0 && y+3 < WIDTH_COUNT && m_chessArray[x-3][y+3] == NO_CHESS))
//		{
//			return TRUE;
//		}
//		if (x-1 >0 && y+1 < WIDTH_COUNT && m_chessArray[x-1][y+1] == NO_CHESS && 
//			x+1 < WIDTH_COUNT && y-1 > 0 && m_chessArray[x+1][y-1] == nColor &&
//			x+2 < WIDTH_COUNT && y-2 > 0 && m_chessArray[x+2][y-2] == nColor &&
//			x+3 < WIDTH_COUNT && y-3 > 0 && m_chessArray[x+3][y-3] == NO_CHESS && 
//			((x+4 < WIDTH_COUNT && y-4 > 0 && m_chessArray[x+4][y-4]) == NO_CHESS) ||
//			(x-2 >0 && y+2 < WIDTH_COUNT && m_chessArray[x-2][y+2] == NO_CHESS))
//		{
//			return TRUE;
//		}
//		if (x-1 >0 && y+1 < WIDTH_COUNT && m_chessArray[x-1][y+1] == NO_CHESS && 
//			x-2 >0 && y+2 < WIDTH_COUNT && m_chessArray[x-2][y+2] == nColor &&
//			x-3 >0 && y+3 < WIDTH_COUNT && m_chessArray[x-3][y+3] == NO_CHESS &&
//			x+1 < WIDTH_COUNT && y-1 > 0 && m_chessArray[x+1][y-1] == nColor && 
//			x+2 < WIDTH_COUNT && y-2 > 0 && m_chessArray[x+2][y-2] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x-1 >0 && y+1 < WIDTH_COUNT && m_chessArray[x-1][y+1] == NO_CHESS && 
//			x-2 >0 && y+2 < WIDTH_COUNT && m_chessArray[x-2][y+2] == nColor &&
//			x-3 >0 && y+3 < WIDTH_COUNT && m_chessArray[x-3][y+3] == nColor &&
//			x-4 >0 && y+4 < WIDTH_COUNT && m_chessArray[x-4][y+4] == NO_CHESS && 
//			x+1 < WIDTH_COUNT && y-1 > 0 && m_chessArray[x+1][y-1] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x-1 > 0 && y+1 < WIDTH_COUNT && m_chessArray[x-1][y+1] == nColor && 
//			x-2 > 0 && y+2 < WIDTH_COUNT && m_chessArray[x-2][y+2] == NO_CHESS &&
//			x-3 > 0 && y+3 < WIDTH_COUNT && m_chessArray[x-3][y+3] == nColor &&
//			x-4 > 0 && y+4 < WIDTH_COUNT && m_chessArray[x-4][y+4] == NO_CHESS && 
//			x+1 < WIDTH_COUNT && y-1 > 0 && m_chessArray[x+1][y-1] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x-1 > 0 && y+1 < WIDTH_COUNT && m_chessArray[x-1][y+1] == nColor && 
//			x-2 > 0 && y+2 < WIDTH_COUNT && m_chessArray[x-2][y+2] == NO_CHESS &&
//			x+1 < WIDTH_COUNT && y-1 > 0 && m_chessArray[x+1][y-1] == NO_CHESS &&
//			x+2 < WIDTH_COUNT && y-2 > 0 && m_chessArray[x+2][y-2] == nColor && 
//			x+3 < WIDTH_COUNT && y-3 > 0 && m_chessArray[x+3][y-3] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x-1 > 0 && y+1 < WIDTH_COUNT && m_chessArray[x-1][y+1] == NO_CHESS && 
//			x+1 < WIDTH_COUNT && y-1 > 0 && m_chessArray[x+1][y-1] == NO_CHESS &&
//			x+2 < WIDTH_COUNT && y-2 > 0 && m_chessArray[x+2][y-2] == nColor &&
//			x+3 < WIDTH_COUNT && y-3 > 0 && m_chessArray[x+3][y-3] == nColor && 
//			x+4 < WIDTH_COUNT && y-4 > 0 && m_chessArray[x+4][y-4] == NO_CHESS)
//		{
//			return TRUE;
//		}
//		if (x-1 > 0 && y+1 < WIDTH_COUNT && m_chessArray[x-1][y+1] == NO_CHESS && 
//			x+1 < WIDTH_COUNT && y-1 > 0 && m_chessArray[x+1][y-1] == nColor &&
//			x+2 < WIDTH_COUNT && y-2 > 0 && m_chessArray[x+2][y-2] == NO_CHESS &&
//			x+3 < WIDTH_COUNT && y-3 > 0 && m_chessArray[x+3][y-3] == nColor && 
//			x+4 < WIDTH_COUNT && y-4 > 0 && m_chessArray[x+4][y-4] == NO_CHESS)
//		{
//			return TRUE;
//		}
//	}
//
//	return FALSE;
//}
//
//void CChessAI::GetPos(POINT &pt)
//{
//	// 1 计算是黑棋还是白棋
//	int nChessType = NO_CHESS;
//	vector<POINT> *pchessArray;
//	if (m_blackChessArray.size() == m_whiteChessArray.size())
//	{
//		nChessType = BLACK_CHESS;
//		pchessArray = &m_blackChessArray;
//	}
//	else
//	{
//		nChessType = WHITE_CHESS;
//		pchessArray = &m_whiteChessArray;
//	}
//
//
//	// 2 计算候选点
//	vector<POINT> candidate;
//	map<LONG, LONG>temp;
//	for (unsigned int i = 0; i < pchessArray->size(); i++)
//	{
//		for (int m = (*pchessArray)[i].x - 3; m <= (*pchessArray)[i].x + 3; m++)
//		{
//			for (int n = (*pchessArray)[i].y - 3; n <= (*pchessArray)[i].y + 3; n++)
//			{
//				if (temp.find((m<<16)+n) != temp.end())
//				{
//					// 该点已经加入候选队列了
//					continue;
//				}
//				if (m_chessArray[m][n] != NO_CHESS)
//				{
//					// 是已经下过点
//					continue;
//				}
//
//				POINT pt = {m,n};
//				candidate.push_back(pt);
//				temp.insert(pair<LONG, LONG>((m<<16)+n, 0));
//			}
//		}
//	}
//
//	// 3 为每个候选点计算得分
//
//
//
//	// 4 得分最高的点为下棋的点
//
//}



/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIVE_H__4D4602F4_035D_40FF_A3EE_864782FCE16D__INCLUDED_)
