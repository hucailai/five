// ChessAI.h: interface for the CChessAI class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHESSAI_H__DAD6397F_6A68_414B_88B9_7C41E5CCA982__INCLUDED_)
#define AFX_CHESSAI_H__DAD6397F_6A68_414B_88B9_7C41E5CCA982__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include <list>
#include <map>

using namespace std;

typedef struct stAI_POINT
{
	LONG x;
	LONG y;
	INT64 score;
}AI_POINT;


#define BASE_ADDR 0x0041D148

#define WIDTH_COUNT 15
#define HEIGHT_COUNT 15

#define WHITE_CHESS		1	// 白棋
#define BLACK_CHESS		2	// 黑棋
#define NO_CHESS		0	// 空白

#define COLOR_INVERT(color)  (color) == WHITE_CHESS ? BLACK_CHESS : WHITE_CHESS

#define CUT_SCORE		(0x8FFFFFFFFFFFFFF)

#define F_INFINITE      10000000000

// 得分相关指标
#define FIVE_SCORE		F_INFINITE		 // 五子得分
#define FOUR_SCORE		5000			 // 四子得分
#define THREE_SCORE     1000			 // 三子得分
#define TWO_SCORE		100			     // 两子得分
#define ONE_SCORE		1				 // 单子得分

#define S_THREE_SCORE   10				 // 单三得分
#define D_THREE_SCORE   F_INFINITE 		 // 双三得分

#define MAX_LEVEL 20  // 最大搜索深度

#define MAX_CANDIDATE  20 // 最大候选节点个数


#define FIVECELL_MAX	 3*3*3*3*3
#define TENCELL_MAX		 3*3*3*3*3*3*3*3*3*3

#define MAX(a,b)   (a) > (b) ? (a) : (b)

#define MIN(a,b)   (a) < (b) ? (a) : (b)


extern LARGE_INTEGER g_tc;
extern INT64 g_FiveCellMap[3][3][3][3][3];
extern INT64 g_aui64LevelScore[MAX_LEVEL];


#define GET_NS(b,e)  (((e.QuadPart)-(b.QuadPart))*1000*1000*1000)/(g_tc.QuadPart)


enum DIRECTION
{
	DIRECTION_A = 0,	// X方向
	DIRECTION_B = 1,	// Y方向
	DIRECTION_C = 2,	// X，Y同方向
	DIRECTION_D = 3,	// X，Y反方向
	DIRECTION_MAX,
};
//#define DIRECTION_A		0	// X方向
//#define DIRECTION_B		1	// Y方向
//#define DIRECTION_C		2	// X，Y同方向
//#define DIRECTION_D		3	// X，Y反方向


AI_POINT AI(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiAIColor, UINT32 uiLevel, INT64 *score, INT64 uiBase);
void ClearLevelScore();
void FiveCellMapInit();
extern inline INT64 Evaluate(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor);  // 53300ns
extern inline INT64 Evaluate2(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor);  // 53300ns
inline INT64 Get15CellScore(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9,
							int a10, int a11, int a12, int a13, int a14);
inline INT64 GetALLObliqueLinesScore(BYTE a[HEIGHT_COUNT][WIDTH_COUNT]);
extern inline BOOL IsWin(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor, UINT32 uiX, UINT32 uiY);
extern inline INT64 GetPointScore(BYTE a[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor, UINT32 uiX, UINT32 uiY);




class CChessAI  
{
public:
	// 棋面数据。
	BYTE m_chessArray[HEIGHT_COUNT][WIDTH_COUNT]; // 0表示没有棋，1表示白棋，2表示黑棋
	CChessAI();
	virtual ~CChessAI();

	vector<AI_POINT> m_blackChessArray;
	vector<AI_POINT> m_whiteChessArray;

	void UpdataChessData(BYTE *pData);

	void GetPos(AI_POINT &pt);

	BOOL CanFive(AI_POINT pt, int nColor);

	BOOL CanFour(AI_POINT pt, int nColor);

	BOOL CanThree(AI_POINT pt, int nColor, int nDirection);

};

#endif // !defined(AFX_CHESSAI_H__DAD6397F_6A68_414B_88B9_7C41E5CCA982__INCLUDED_)
