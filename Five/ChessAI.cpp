// ChessAI.cpp: implementation of the CChessAI class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Five.h"
#include "ChessAI.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


UINT32 g_uiAIColor = BLACK_CHESS;
vector<POINT> m_gBlackChessArray;
vector<POINT> m_gWhiteChessArray;




CChessAI::CChessAI()
{
	memset(m_chessArray, 0, sizeof(m_chessArray));

	
}

CChessAI::~CChessAI()
{

}


/* 找到一个五个就返回 */
UINT32 FiveCount(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor)
{
	UINT32 uiTotalCnt = 0;
	UINT32 uiContinueCnt = 0;

	/* x轴成五 */
	for (int x = 0; x < WIDTH_COUNT; x++)
	{
		for (int y = 0; y <HEIGHT_COUNT; y++)
		{
			if (abChessArray[x][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 5)
				{
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/* y轴成五 */
	for (int y = 0; y < HEIGHT_COUNT; y++)
	{
		for (int x = 0; x < WIDTH_COUNT; x++)
		{
			if (abChessArray[x][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 5)
				{
					uiTotalCnt++;
					uiContinueCnt = 0;
					//return 1;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/// x+，y+成五
	for (int j = 0; j < HEIGHT_COUNT; j++)
	{
		int cnt = 0;
		for (int y = j; y < HEIGHT_COUNT; y++,cnt++)
		{
			if (abChessArray[0 + cnt][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 5)
				{
					uiTotalCnt++;
					uiContinueCnt = 0;
					//return 1;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	for (int j = 1; j < WIDTH_COUNT; j++)
	{
		int cnt = 0;
		for (int x = j; x < WIDTH_COUNT; x++,cnt++)
		{
			if (abChessArray[x][0 + cnt] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 5)
				{
					uiTotalCnt++;
					uiContinueCnt = 0;
					//return 1;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/// x+，y-成五
	for (int j = 0; j < HEIGHT_COUNT; j++)
	{
		int cnt = 0;
		for (int y = j; y >= 0; y--,cnt++)
		{
			if (abChessArray[0 + cnt][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 5)
				{
					uiTotalCnt++;
					uiContinueCnt = 0;
					//return 1;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	for (int j = 1; j < WIDTH_COUNT; j++)
	{
		int cnt = 0;
		for (int x = j; x < WIDTH_COUNT; x++,cnt++)
		{
			if (abChessArray[x][HEIGHT_COUNT-1 - cnt] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 5)
				{
					//return 1;
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	return uiTotalCnt;
}

UINT32 FourCount(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor)
{
	UINT32 uiTotalCnt = 0;
	UINT32 uiContinueCnt = 0;

	/* x轴成四 */
	for (int x = 0; x < WIDTH_COUNT; x++)
	{
		for (int y = 0; y < HEIGHT_COUNT; y++)
		{
			if (abChessArray[x][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 4)
				{
					if (y + 1 >= HEIGHT_COUNT || abChessArray[x][y+1] != NO_CHESS ||
						y - 4 < 0 || abChessArray[x][y-4] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}

					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/* y轴成四 */
	for (int y = 0; y < HEIGHT_COUNT; y++)
	{
		for (int x = 0; x < WIDTH_COUNT; x++)
		{
			if (abChessArray[x][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 4)
				{
					if (x + 1 >= HEIGHT_COUNT || abChessArray[x+1][y] != NO_CHESS ||
						x - 4 < 0 || abChessArray[x-4][y] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/// x+，y+成四
	for (int j = 0; j < HEIGHT_COUNT; j++)
	{
		int cnt = 0;
		for (int y = j; y < HEIGHT_COUNT; y++,cnt++)
		{
			if (abChessArray[0 + cnt][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 4)
				{
					if (0 + cnt + 1 >= WIDTH_COUNT || y + 1 >= HEIGHT_COUNT || abChessArray[0+cnt+1][y+1] != NO_CHESS ||
						0 + cnt - 4 < 0 || y - 4 < 0 || abChessArray[0+cnt-4][y-4] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	for (int j = 1; j < WIDTH_COUNT; j++)
	{
		int cnt = 0;
		for (int x = j; x < WIDTH_COUNT; x++,cnt++)
		{
			if (abChessArray[x][0 + cnt] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 4)
				{
					if (x + 1 >= WIDTH_COUNT || 0 + cnt + 1 >= HEIGHT_COUNT || abChessArray[x+1][0+cnt+1] != NO_CHESS ||
						x - 4 < 0 || 0 + cnt - 4 < 0 || abChessArray[x-4][0+cnt-4] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/// x+，y-成四
	for (int j = 0; j < HEIGHT_COUNT; j++)
	{
		int cnt = 0;
		for (int y = j; y >= 0; y--,cnt++)
		{
			if (abChessArray[0 + cnt][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 4)
				{
					if (0+cnt+1 >= WIDTH_COUNT || y-1 < 0 || abChessArray[0+cnt+1][y-1] != NO_CHESS ||
						0 + cnt - 4 < 0 || y+4 >=HEIGHT_COUNT || abChessArray[0+cnt-4][y+4] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	for (int j = 1; j < WIDTH_COUNT; j++)
	{
		int cnt = 0;
		for (int x = j; x < WIDTH_COUNT; x++,cnt++)
		{
			if (abChessArray[x][HEIGHT_COUNT-1 - cnt] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 4)
				{
					if (0+cnt+1 >= WIDTH_COUNT || HEIGHT_COUNT-1 - cnt -1 < 0 || abChessArray[x+1][HEIGHT_COUNT-1 - cnt -1] != NO_CHESS ||
						x - 4 < 0 || HEIGHT_COUNT-1 - cnt +4 >= HEIGHT_COUNT || abChessArray[x - 4][HEIGHT_COUNT-1 - cnt +4] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	return uiTotalCnt;
}

UINT32 ThreeCount(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor)
{
	UINT32 uiTotalCnt = 0;
	UINT32 uiContinueCnt = 0;

	/* x轴成三 */
	for (int x = 0; x < WIDTH_COUNT; x++)
	{
		for (int y = 0; y < HEIGHT_COUNT; y++)
		{
			if (abChessArray[x][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 3)
				{
					if (y + 1 >= HEIGHT_COUNT || abChessArray[x][y+1] != NO_CHESS ||
						y - 3 < 0 || abChessArray[x][y-3] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}

					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/* y轴成三 */
	for (int y = 0; y < HEIGHT_COUNT; y++)
	{
		for (int x = 0; x < WIDTH_COUNT; x++)
		{
			if (abChessArray[x][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 3)
				{
					if (x + 1 >= HEIGHT_COUNT || abChessArray[x+1][y] != NO_CHESS ||
						x - 3 < 0 || abChessArray[x-3][y] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/// x+，y+成三
	for (int j = 0; j < HEIGHT_COUNT; j++)
	{
		int cnt = 0;
		for (int y = j; y < HEIGHT_COUNT; y++,cnt++)
		{
			if (abChessArray[0 + cnt][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 3)
				{
					if (0 + cnt + 1 >= WIDTH_COUNT || y + 1 >= HEIGHT_COUNT || abChessArray[0+cnt+1][y+1] != NO_CHESS ||
						0 + cnt - 3 < 0 || y - 3 < 0 || abChessArray[0+cnt-3][y-3] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	for (int j = 1; j < WIDTH_COUNT; j++)
	{
		int cnt = 0;
		for (int x = j; x < WIDTH_COUNT; x++,cnt++)
		{
			if (abChessArray[x][0 + cnt] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 3)
				{
					if (x + 1 >= WIDTH_COUNT || 0 + cnt + 1 >= HEIGHT_COUNT || abChessArray[x+1][0+cnt+1] != NO_CHESS ||
						x - 3 < 0 || 0 + cnt - 3 < 0 || abChessArray[x-3][0+cnt-3] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/// x+，y-成三
	for (int j = 0; j < HEIGHT_COUNT; j++)
	{
		int cnt = 0;
		for (int y = j; y >= 0; y--,cnt++)
		{
			if (abChessArray[0 + cnt][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 3)
				{
					if (0+cnt+1 >= WIDTH_COUNT || y-1 < 0 || abChessArray[0+cnt+1][y-1] != NO_CHESS ||
						0 + cnt - 3 < 0 || y+3 >=HEIGHT_COUNT || abChessArray[0+cnt-3][y+3] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	for (int j = 1; j < WIDTH_COUNT; j++)
	{
		int cnt = 0;
		for (int x = j; x < WIDTH_COUNT; x++,cnt++)
		{
			if (abChessArray[x][HEIGHT_COUNT - cnt] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 3)
				{
					if (0+cnt+1 >= WIDTH_COUNT || HEIGHT_COUNT-1 - cnt -1 < 0 || abChessArray[x+1][HEIGHT_COUNT-1 - cnt -1] != NO_CHESS ||
						x - 3 < 0 || HEIGHT_COUNT-1 - cnt +3 >= HEIGHT_COUNT || abChessArray[x - 3][HEIGHT_COUNT-1 - cnt +3] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	return uiTotalCnt;
}

UINT32 TwoCount(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor)
{
	UINT32 uiTotalCnt = 0;
	UINT32 uiContinueCnt = 0;

	/* x轴成二 */
	for (int x = 0; x < WIDTH_COUNT; x++)
	{
		for (int y = 0; y < HEIGHT_COUNT; y++)
		{
			if (abChessArray[x][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 2)
				{
					if (y + 1 >= HEIGHT_COUNT || abChessArray[x][y+1] != NO_CHESS ||
						y - 2 < 0 || abChessArray[x][y-2] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}

					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/* y轴成二 */
	for (int y = 0; y < HEIGHT_COUNT; y++)
	{
		for (int x = 0; x < WIDTH_COUNT; x++)
		{
			if (abChessArray[x][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 2)
				{
					if (x + 1 >= HEIGHT_COUNT || abChessArray[x+1][y] != NO_CHESS ||
						x - 2 < 0 || abChessArray[x-2][y] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/// x+，y+成二
	for (int j = 0; j < HEIGHT_COUNT; j++)
	{
		int cnt = 0;
		for (int y = j; y < HEIGHT_COUNT; y++,cnt++)
		{
			if (abChessArray[0 + cnt][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 2)
				{
					if (0 + cnt + 1 >= WIDTH_COUNT || y + 1 >= HEIGHT_COUNT || abChessArray[0+cnt+1][y+1] != NO_CHESS ||
						0 + cnt - 2 < 0 || y - 2 < 0 || abChessArray[0+cnt-2][y-2] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	for (int j = 1; j < WIDTH_COUNT; j++)
	{
		int cnt = 0;
		for (int x = j; x < WIDTH_COUNT; x++,cnt++)
		{
			if (abChessArray[x][0 + cnt] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 2)
				{
					if (x + 1 >= WIDTH_COUNT || 0 + cnt + 1 >= HEIGHT_COUNT || abChessArray[x+1][0+cnt+1] != NO_CHESS ||
						x - 2 < 0 || 0 + cnt - 2 < 0 || abChessArray[x-2][0+cnt-2] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/// x+，y-成二
	for (int j = 0; j < HEIGHT_COUNT; j++)
	{
		int cnt = 0;
		for (int y = j; y >= 0; y--,cnt++)
		{
			if (abChessArray[0 + cnt][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 2)
				{
					if (0+cnt+1 >= WIDTH_COUNT || y-1 < 0 || abChessArray[0+cnt+1][y-1] != NO_CHESS ||
						0 + cnt - 2 < 0 || y+2 >=HEIGHT_COUNT || abChessArray[0+cnt-2][y+2] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	for (int j = 1; j < WIDTH_COUNT; j++)
	{
		int cnt = 0;
		for (int x = j; x < WIDTH_COUNT; x++,cnt++)
		{
			if (abChessArray[x][HEIGHT_COUNT-1 - cnt] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 2)
				{
					if (0+cnt+1 >= WIDTH_COUNT || HEIGHT_COUNT-1 - cnt -1 < 0 || abChessArray[x+1][HEIGHT_COUNT-1 - cnt -1] != NO_CHESS ||
						x - 2 < 0 || HEIGHT_COUNT-1 - cnt +2 >= HEIGHT_COUNT || abChessArray[x - 2][HEIGHT_COUNT-1 - cnt +2] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	return uiTotalCnt;
}

UINT32 OneCount(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor)
{
	UINT32 uiTotalCnt = 0;
	UINT32 uiContinueCnt = 0;

	/* x轴成一 */
	for (int x = 0; x < WIDTH_COUNT; x++)
	{
		for (int y = 0; y < HEIGHT_COUNT; y++)
		{
			if (abChessArray[x][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 1)
				{
					if (y + 1 >= HEIGHT_COUNT || abChessArray[x][y+1] != NO_CHESS ||
						y - 1 < 0 || abChessArray[x][y-1] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}

					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/* y轴成一 */
	for (int y = 0; y < HEIGHT_COUNT; y++)
	{
		for (int x = 0; x < WIDTH_COUNT; x++)
		{
			if (abChessArray[x][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 1)
				{
					if (x + 1 >= HEIGHT_COUNT || abChessArray[x+1][y] != NO_CHESS ||
						x - 1 < 0 || abChessArray[x-1][y] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/// x+，y+成一
	for (int j = 0; j < HEIGHT_COUNT; j++)
	{
		int cnt = 0;
		for (int y = j; y < HEIGHT_COUNT; y++,cnt++)
		{
			if (abChessArray[0 + cnt][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 1)
				{
					if (0 + cnt + 1 >= WIDTH_COUNT || y + 1 >= HEIGHT_COUNT || abChessArray[0+cnt+1][y+1] != NO_CHESS ||
						0 + cnt - 1 < 0 || y - 1 < 0 || abChessArray[0+cnt-1][y-1] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	for (int j = 1; j < WIDTH_COUNT; j++)
	{
		int cnt = 0;
		for (int x = j; x < WIDTH_COUNT; x++,cnt++)
		{
			if (abChessArray[x][0 + cnt] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 1)
				{
					if (x + 1 >= WIDTH_COUNT || 0 + cnt + 1 >= HEIGHT_COUNT || abChessArray[x+1][0+cnt+1] != NO_CHESS ||
						x - 1 < 0 || 0 + cnt - 1 < 0 || abChessArray[x-1][0+cnt-1] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}
	/// x+，y-成一
	for (int j = 0; j < HEIGHT_COUNT; j++)
	{
		int cnt = 0;
		for (int y = j; y >= 0; y--,cnt++)
		{
			if (abChessArray[0 + cnt][y] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 1)
				{
					if (0+cnt+1 >= WIDTH_COUNT || y-1 < 0 || abChessArray[0+cnt+1][y-1] != NO_CHESS ||
						0 + cnt - 1 < 0 || y+1 >=HEIGHT_COUNT || abChessArray[0+cnt-1][y+1] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	for (int j = 1; j < WIDTH_COUNT; j++)
	{
		int cnt = 0;
		for (int x = j; x < WIDTH_COUNT; x++,cnt++)
		{
			if (abChessArray[x][HEIGHT_COUNT - cnt -1] == uiColor)
			{
				uiContinueCnt++;
				if (uiContinueCnt >= 1)
				{
					if (0+cnt+1 >= WIDTH_COUNT || HEIGHT_COUNT-1 - cnt -1 < 0 || abChessArray[x+1][HEIGHT_COUNT-1 - cnt -1] != NO_CHESS ||
						x - 1 < 0 || HEIGHT_COUNT-1 - cnt +1 >= HEIGHT_COUNT || abChessArray[x - 1][HEIGHT_COUNT-1 - cnt +1] != NO_CHESS)
					{
						uiContinueCnt = 0;
						continue;
					}
					uiTotalCnt++;
					uiContinueCnt = 0;
				}
				continue;
			}

			uiContinueCnt = 0; 
		}

		uiContinueCnt = 0; 
	}

	return uiTotalCnt;
}

void TEST(int x, int y)
{

}


UINT32 g_uiLeafCnt = 0;
/* 黑棋得分-白棋得分 */
inline INT64 Evaluate(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor)  // 53300ns
{
	UINT64 ui64BlackEvaluate = 0;
	UINT64 ui64WhiteEvaluate = 0;
	UINT32 uiBlackFive,uiWhiteFive;
	UINT32 uiBlackFour,uiWhiteFour;
	UINT32 uiBlackThree,uiWhiteThree;
	UINT32 uiBlackTwo,uiWhiteTwo;
	UINT32 uiBlackOne = 0,uiWhiteOne;

	


	uiBlackFive = FiveCount(abChessArray, BLACK_CHESS);   // 开销 7068ns



	uiWhiteFive = FiveCount(abChessArray, WHITE_CHESS);	  // 开销 4800ns


	uiBlackFour = FourCount(abChessArray, BLACK_CHESS);   // 开销 5000ns



	uiWhiteFour = FourCount(abChessArray, WHITE_CHESS);   // 开销 4718ns



	uiBlackThree = ThreeCount(abChessArray, BLACK_CHESS);   // 开销 6000ns

	uiWhiteThree = ThreeCount(abChessArray, WHITE_CHESS);


	uiBlackTwo = TwoCount(abChessArray, BLACK_CHESS);
	uiWhiteTwo = TwoCount(abChessArray, WHITE_CHESS);
	uiBlackOne = OneCount(abChessArray, BLACK_CHESS);
	uiWhiteOne = OneCount(abChessArray, WHITE_CHESS);

	ui64BlackEvaluate = uiBlackFive * FIVE_SCORE + uiBlackFour * FOUR_SCORE + 
						uiBlackThree * THREE_SCORE +  uiBlackTwo * TWO_SCORE+ uiBlackOne *ONE_SCORE;

	ui64WhiteEvaluate = uiWhiteFive * FIVE_SCORE + uiWhiteFour * FOUR_SCORE + 
						uiWhiteThree * THREE_SCORE +  uiWhiteTwo * TWO_SCORE+ uiWhiteOne *ONE_SCORE;



	if (uiColor == BLACK_CHESS)
	{
		return ui64BlackEvaluate - ui64WhiteEvaluate;
	}

	return ui64WhiteEvaluate - ui64BlackEvaluate;
}

/* 黑棋得分-白棋得分 */
inline INT64 Evaluate2(BYTE a[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor)
{
	INT64 score = 0;
	for (int i = 0; i < HEIGHT_COUNT; i++)
	{
		score += Get15CellScore(a[i][0],a[i][1],a[i][2],a[i][3],a[i][4],a[i][5],a[i][6],a[i][7],a[i][8],a[i][9],a[i][10],a[i][11],a[i][12],a[i][13],a[i][14]);
	}

	for (int j = 0; j < WIDTH_COUNT; j++)
	{
		score += Get15CellScore(a[0][j],a[1][j],a[2][j],a[3][j],a[4][j],a[5][j],a[6][j],a[7][j],a[8][j],a[9][j],a[10][j],a[11][j],a[12][j],a[13][j],a[14][j]);
	}


	score += GetALLObliqueLinesScore(a);



	return uiColor == BLACK_CHESS ?  score : -score;
}
/* 计算候选节点 */
VOID Candidate(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], vector<POINT> *pCandidate)
{

	int candFlag = 2;
	map<LONG, LONG> temp;

	for (int i = 0; i < WIDTH_COUNT; i++)
	{
		for (int j = 0; j < HEIGHT_COUNT; j++)
		{

			if (abChessArray[i][j] == NO_CHESS)
			{
				continue;
			}

			for (int m = i - candFlag; m <= i + candFlag; m++)
			{
				for (int n = j - candFlag; n <= j + candFlag; n++)
				{
					if ((m < 0 || n < 0 || m >= WIDTH_COUNT || n >= HEIGHT_COUNT) || (m == i && n == j))
					{
						continue;
					}

					if (temp.find((m<<16)+n) != temp.end())
					{
						// 该点已经加入候选队列了
						continue;
					}
					if (abChessArray[m][n] != NO_CHESS)
					{
						// 是已经下过点
						continue;
					}

					POINT pt = {m,n};
					pCandidate->push_back(pt);
					temp.insert(pair<LONG, LONG>((m<<16)+n, 0));
				}
			}
		}
	}

	if (pCandidate->size() == 0)
	{
		POINT pt = {7,7};
		pCandidate->push_back(pt);
	}
}


UINT32 uiAiCnt = 0;

INT64 g_aui64LevelScore[MAX_LEVEL] = {-CUT_SCORE,-CUT_SCORE,-CUT_SCORE,-CUT_SCORE,-CUT_SCORE,-CUT_SCORE,-CUT_SCORE,-CUT_SCORE,};
void ClearLevelScore()
{
	for (int i = 0; i < MAX_LEVEL; i++)
	{
		g_aui64LevelScore[i] = -CUT_SCORE;
	}
}


CString str;
POINT AI(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor, UINT32 uiLevel, INT64 *pScore)
{

	uiAiCnt++;
	vector<POINT> candidate;
	POINT p = {0};
	INT64 iScoreTemp = 0;
	INT64 iMaxScore = -F_INFINITE;
	POINT stMaxPnt = {0};

	/* 1.计算候选结点 */
	Candidate(abChessArray, &candidate);

	/* 2.为每个候选结点打分 */
	if (uiLevel == 1)
	{
		for (UINT32 i = 0; i < candidate.size(); i++)
		{
			p = candidate[i];

			abChessArray[p.x][p.y] = uiColor;
			iScoreTemp = Evaluate2(abChessArray, uiColor);
			abChessArray[p.x][p.y] = NO_CHESS;

			if (iScoreTemp > g_aui64LevelScore[uiLevel] && -CUT_SCORE != g_aui64LevelScore[uiLevel])
			{
				*pScore = -CUT_SCORE;
				return stMaxPnt;
			}
			
			if (iScoreTemp > iMaxScore)
			{
				iMaxScore = iScoreTemp;
				stMaxPnt.x = p.x;
				stMaxPnt.y = p.y;
			}
		}

		if (iMaxScore > g_aui64LevelScore[uiLevel])
		{
			g_aui64LevelScore[uiLevel] = iMaxScore;
		}

		*pScore = -iMaxScore;
	}
	else
	{
		for (UINT32 i = 0; i < candidate.size(); i++)
		{
			p = candidate[i];

			//str.Format("+候选[%d,%d]  color=%d\n",p.x,p.y,uiColor);
			//OutputDebugString(str);
			
			if (IsWin(abChessArray, uiColor, p.x, p.y))
			{
				stMaxPnt.x = p.x;
				stMaxPnt.y = p.y;
				*pScore = -CUT_SCORE;
				return stMaxPnt;
			}
			abChessArray[p.x][p.y] = uiColor;
			AI(abChessArray, COLOR_INVERT(uiColor), uiLevel - 1, &iScoreTemp);
			abChessArray[p.x][p.y] = NO_CHESS;
			//str.Format("-候选[%d,%d]  color=%d\n",p.x,p.y,uiColor);
			//OutputDebugString(str);

			if (iScoreTemp > g_aui64LevelScore[uiLevel] && -CUT_SCORE != g_aui64LevelScore[uiLevel])
			{
				*pScore = -CUT_SCORE;
				return stMaxPnt;
			}

			if (iScoreTemp > iMaxScore)
			{
				iMaxScore = iScoreTemp;
				stMaxPnt.x = p.x;
				stMaxPnt.y = p.y;
			}
		}

		if (iMaxScore > g_aui64LevelScore[uiLevel])
		{
			g_aui64LevelScore[uiLevel] = iMaxScore;
		}

		*pScore = -iMaxScore;
	}

	return stMaxPnt;
}



INT64 g_FiveCellMap[3][3][3][3][3]={0};

INT64 g_TenCellMap[TENCELL_MAX]={0};

// 计算5个子的得分, a[]是一个5个元素的数组
INT64 GenFiveCellScore(int a[])
{
	int blackCnt = 0;
	int whiteCnt = 0;
	int base = 0;

	for (int i = 0; i < 5; i++)
	{
		if (a[i] == BLACK_CHESS)
		{
			blackCnt++;	
		}
		else if (a[i] == WHITE_CHESS)
		{
			whiteCnt++;
		}
	}

	// 全0得分为0
	if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0)
	{
		return 0;
	}
	
	// 黑白混在一起得0分
	if (blackCnt > 0 && whiteCnt > 0)
	{
		return 0;
	}

	// 只有一个黑
	if (blackCnt == 1)
	{
		if (a[0] == BLACK_CHESS)
		{
			return (ONE_SCORE);
		}
		else if (a[1] == BLACK_CHESS)
		{
			return (ONE_SCORE + 1);
		}
		else if (a[2] == BLACK_CHESS)
		{
			return (ONE_SCORE + 2);
		}
		else if (a[3] == BLACK_CHESS)
		{
			return (ONE_SCORE + 1);
		}
		else
		{
			return (ONE_SCORE);
		}
	}
	
	// 只有一个白
	if (whiteCnt == 1)
	{
		if (a[0] == WHITE_CHESS)
		{
			return -(ONE_SCORE);
		}
		else if (a[1] == WHITE_CHESS)
		{
			return -(ONE_SCORE + 1);
		}
		else if (a[2] == WHITE_CHESS)
		{
			return -(ONE_SCORE + 2);
		}
		else if (a[3] == WHITE_CHESS)
		{
			return -(ONE_SCORE + 1);
		}
		else
		{
			return -(ONE_SCORE);
		}
	}

	// 两个黑，基准分100分，每靠边一个减10分，中间每多一个0减10分
	base = TWO_SCORE;
	if (blackCnt == 2)
	{
		if (a[0] == BLACK_CHESS)
		{
			base -= 10;
		}	

		if (a[4] == BLACK_CHESS)
		{
			base -= 10;
		}


		int i = 0;
		int zeroCnt = 0;
		for (int i = 0; i < 5; i++)
		{
			if (a[i] == BLACK_CHESS)
			{
				break;
			}
		}
		i++;
		for (; i < 5; i++)
		{
			if (a[i] == BLACK_CHESS)
			{
				break;
			}
			else if (a[i] == NO_CHESS)
			{
				zeroCnt++;
			}
		}

		base -= 10 * zeroCnt;
		
		return base;
	}

	// 两个白，基准分100分，每靠边一个减10分，中间每多一个0减10分
	base = TWO_SCORE;
	if (whiteCnt == 2)
	{
		if (a[0] == WHITE_CHESS)
		{
			base -= 10;
		}	

		if (a[4] == WHITE_CHESS)
		{
			base -= 10;
		}


		int i = 0;
		int zeroCnt = 0;
		for (int i = 0; i < 5; i++)
		{
			if (a[i] == WHITE_CHESS)
			{
				break;
			}
		}
		i++;
		for (; i < 5; i++)
		{
			if (a[i] == WHITE_CHESS)
			{
				break;
			}
			else if (a[i] == NO_CHESS)
			{
				zeroCnt++;
			}
		}

		base -= 10 * zeroCnt;

		return -base;
	}

	// 三个黑，基准分1000分，每靠边一个减100分
	base = THREE_SCORE;
	if (blackCnt == 3)
	{
		if (a[0] == BLACK_CHESS)
		{
			base -= 100;
		}	

		if (a[4] == BLACK_CHESS)
		{
			base -= 100;
		}

		return base;
	}

	// 三个白，基准分1000分，每靠边一个减100分
	base = THREE_SCORE;
	if (whiteCnt == 3)
	{
		if (a[0] == WHITE_CHESS)
		{
			base -= 100;
		}	

		if (a[4] == WHITE_CHESS)
		{
			base -= 100;
		}

		return -base;
	}

	// 四黑，基准分 1000
	if (blackCnt == 4)
	{
		return FOUR_SCORE;
	}

	// 四白，基准分 1000
	if (whiteCnt == 4)
	{
		return -FOUR_SCORE;
	}

	// 五黑
	if (blackCnt == 5)
	{
		return FIVE_SCORE;
	}

	// 五白
	return -FIVE_SCORE;
}

void FiveCellMapInit()
{
	int a[5] = {0};
	for (a[0]=0; a[0] < 3; a[0]++)
	{
		for (a[1] = 0; a[1] < 3; a[1]++)
		{
			for (a[2] = 0; a[2] < 3; a[2]++)
			{
				for (a[3] = 0; a[3] < 3; a[3]++)
				{
					for (a[4] = 0; a[4] < 3; a[4]++)
					{
						g_FiveCellMap[a[0]][a[1]][a[2]][a[3]][a[4]] = GenFiveCellScore(a);
					}
				}
			}
		}
	}
}


inline INT64 Get5CellScore(int a0, int a1, int a2, int a3, int a4)
{
	return g_FiveCellMap[a0][a1][a2][a3][a4];
}

inline INT64 Get6CellScore(int a0, int a1, int a2, int a3, int a4, int a5)
{
	INT64 score = 0;
	score += g_FiveCellMap[a0][a1][a2][a3][a4];
	score += g_FiveCellMap[a1][a2][a3][a4][a5];
	return score;
}

inline INT64 Get7CellScore(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
	INT64 score = 0;
	score += g_FiveCellMap[a0][a1][a2][a3][a4];
	score += g_FiveCellMap[a1][a2][a3][a4][a5];
	score += g_FiveCellMap[a2][a3][a4][a5][a6];
	return score;
}

inline INT64 Get8CellScore(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
	INT64 score = 0;
	score += g_FiveCellMap[a0][a1][a2][a3][a4];
	score += g_FiveCellMap[a1][a2][a3][a4][a5];
	score += g_FiveCellMap[a2][a3][a4][a5][a6];
	score += g_FiveCellMap[a3][a4][a5][a6][a7];
	return score;
}

inline INT64 Get9CellScore(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
	INT64 score = 0;
	score += g_FiveCellMap[a0][a1][a2][a3][a4];
	score += g_FiveCellMap[a1][a2][a3][a4][a5];
	score += g_FiveCellMap[a2][a3][a4][a5][a6];
	score += g_FiveCellMap[a3][a4][a5][a6][a7];
	score += g_FiveCellMap[a4][a5][a6][a7][a8];
	return score;
}

inline INT64 Get10CellScore(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
	INT64 score = 0;
	score += g_FiveCellMap[a0][a1][a2][a3][a4];
	score += g_FiveCellMap[a1][a2][a3][a4][a5];
	score += g_FiveCellMap[a2][a3][a4][a5][a6];
	score += g_FiveCellMap[a3][a4][a5][a6][a7];
	score += g_FiveCellMap[a4][a5][a6][a7][a8];
	score += g_FiveCellMap[a5][a6][a7][a8][a9];
	return score;
}



inline INT64 Get11CellScore(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
	INT64 score = 0;
	score += g_FiveCellMap[a0][a1][a2][a3][a4];
	score += g_FiveCellMap[a1][a2][a3][a4][a5];
	score += g_FiveCellMap[a2][a3][a4][a5][a6];
	score += g_FiveCellMap[a3][a4][a5][a6][a7];
	score += g_FiveCellMap[a4][a5][a6][a7][a8];
	score += g_FiveCellMap[a5][a6][a7][a8][a9];
	score += g_FiveCellMap[a6][a7][a8][a9][a10];
	return score;
}

inline INT64 Get12CellScore(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
	INT64 score = 0;
	score += g_FiveCellMap[a0][a1][a2][a3][a4];
	score += g_FiveCellMap[a1][a2][a3][a4][a5];
	score += g_FiveCellMap[a2][a3][a4][a5][a6];
	score += g_FiveCellMap[a3][a4][a5][a6][a7];
	score += g_FiveCellMap[a4][a5][a6][a7][a8];
	score += g_FiveCellMap[a5][a6][a7][a8][a9];
	score += g_FiveCellMap[a6][a7][a8][a9][a10];
	score += g_FiveCellMap[a7][a8][a9][a10][a11];
	return score;
}

inline INT64 Get13CellScore(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
	INT64 score = 0;
	score += g_FiveCellMap[a0][a1][a2][a3][a4];
	score += g_FiveCellMap[a1][a2][a3][a4][a5];
	score += g_FiveCellMap[a2][a3][a4][a5][a6];
	score += g_FiveCellMap[a3][a4][a5][a6][a7];
	score += g_FiveCellMap[a4][a5][a6][a7][a8];
	score += g_FiveCellMap[a5][a6][a7][a8][a9];
	score += g_FiveCellMap[a6][a7][a8][a9][a10];
	score += g_FiveCellMap[a7][a8][a9][a10][a11];
	score += g_FiveCellMap[a8][a9][a10][a11][a12];
	return score;
}

inline INT64 Get14CellScore(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9,
							int a10, int a11, int a12, int a13)
{
	INT64 score = 0;
	score += g_FiveCellMap[a0][a1][a2][a3][a4];
	score += g_FiveCellMap[a1][a2][a3][a4][a5];
	score += g_FiveCellMap[a2][a3][a4][a5][a6];
	score += g_FiveCellMap[a3][a4][a5][a6][a7];
	score += g_FiveCellMap[a4][a5][a6][a7][a8];
	score += g_FiveCellMap[a5][a6][a7][a8][a9];
	score += g_FiveCellMap[a6][a7][a8][a9][a10];
	score += g_FiveCellMap[a7][a8][a9][a10][a11];
	score += g_FiveCellMap[a8][a9][a10][a11][a12];
	score += g_FiveCellMap[a9][a10][a11][a12][a13];
	return score;
}


inline INT64 Get15CellScore(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9,
							int a10, int a11, int a12, int a13, int a14)
{
	INT64 score = 0;
	score += g_FiveCellMap[a0][a1][a2][a3][a4];
	score += g_FiveCellMap[a1][a2][a3][a4][a5];
	score += g_FiveCellMap[a2][a3][a4][a5][a6];
	score += g_FiveCellMap[a3][a4][a5][a6][a7];
	score += g_FiveCellMap[a4][a5][a6][a7][a8];
	score += g_FiveCellMap[a5][a6][a7][a8][a9];
	score += g_FiveCellMap[a6][a7][a8][a9][a10];
	score += g_FiveCellMap[a7][a8][a9][a10][a11];
	score += g_FiveCellMap[a8][a9][a10][a11][a12];
	score += g_FiveCellMap[a9][a10][a11][a12][a13];
	score += g_FiveCellMap[a10][a11][a12][a13][a14];

	return score;
}


inline INT64 GetALLObliqueLinesScore(BYTE a[HEIGHT_COUNT][WIDTH_COUNT])
{
	INT64 score = 0 ;
	score += Get15CellScore(a[0][0],a[1][1],a[2][2],a[3][3],a[4][4],a[5][5],a[6][6],a[7][7],a[8][8],a[9][9],a[10][10],a[11][11],a[12][12],a[13][13],a[14][14]);
	score += Get14CellScore(a[0][1],a[1][2],a[2][3],a[3][4],a[4][5],a[5][6],a[6][7],a[7][8],a[8][9],a[9][10],a[10][11],a[11][12],a[12][13],a[13][14]);
	score += Get13CellScore(a[0][2],a[1][3],a[2][4],a[3][5],a[4][6],a[5][7],a[6][8],a[7][9],a[8][10],a[9][11],a[10][12],a[11][13],a[12][14]);
	score += Get12CellScore(a[0][3],a[1][4],a[2][5],a[3][6],a[4][7],a[5][8],a[6][9],a[7][10],a[8][11],a[9][12],a[10][13],a[11][14]);
	score += Get11CellScore(a[0][4],a[1][5],a[2][6],a[3][7],a[4][8],a[5][9],a[6][10],a[7][11],a[8][12],a[9][13],a[10][14]);
	score += Get10CellScore(a[0][5],a[1][6],a[2][7],a[3][8],a[4][9],a[5][10],a[6][11],a[7][12],a[8][13],a[9][14]);
	score += Get9CellScore(a[0][6],a[1][7],a[2][8],a[3][9],a[4][10],a[5][11],a[6][12],a[7][13],a[8][14]);
	score += Get8CellScore(a[0][7],a[1][8],a[2][9],a[3][10],a[4][11],a[5][12],a[6][13],a[7][14]);
	score += Get7CellScore(a[0][8],a[1][9],a[2][10],a[3][11],a[4][12],a[5][13],a[6][14]);
	score += Get6CellScore(a[0][9],a[1][10],a[2][11],a[3][12],a[4][13],a[5][14]);
	score += Get5CellScore(a[0][10],a[1][11],a[2][12],a[3][13],a[4][14]);

	score += Get14CellScore(a[1][0],a[2][1],a[3][2],a[4][3],a[5][4],a[6][5],a[7][6],a[8][7],a[9][8],a[10][9],a[11][10],a[12][11],a[13][12],a[14][13]);
	score += Get13CellScore(a[2][0],a[3][1],a[4][2],a[5][3],a[6][4],a[7][5],a[8][6],a[9][7],a[10][8],a[11][9],a[12][10],a[13][11],a[14][12]);
	score += Get12CellScore(a[3][0],a[4][1],a[5][2],a[6][3],a[7][4],a[8][5],a[9][6],a[10][7],a[11][8],a[12][9],a[13][10],a[14][11]);
	score += Get11CellScore(a[4][0],a[5][1],a[6][2],a[7][3],a[8][4],a[9][5],a[10][6],a[11][7],a[12][8],a[13][9],a[14][10]);
	score += Get10CellScore(a[5][0],a[6][1],a[7][2],a[8][3],a[9][4],a[10][5],a[11][6],a[12][7],a[13][8],a[14][9]);
	score += Get9CellScore(a[6][0],a[7][1],a[8][2],a[9][3],a[10][4],a[11][5],a[12][6],a[13][7],a[14][8]);
	score += Get8CellScore(a[7][0],a[8][1],a[9][2],a[10][3],a[11][4],a[12][5],a[13][6],a[14][7]);
	score += Get7CellScore(a[8][0],a[9][1],a[10][2],a[11][3],a[12][4],a[13][5],a[14][6]);
	score += Get6CellScore(a[9][0],a[10][1],a[11][2],a[12][3],a[13][4],a[14][5]);
	score += Get5CellScore(a[10][0],a[11][1],a[12][2],a[13][3],a[14][4]);

	score += Get15CellScore(a[14][0],a[13][1],a[12][2],a[11][3],a[10][4],a[9][5],a[8][6],a[7][7],a[6][8],a[5][9],a[4][10],a[3][11],a[2][12],a[1][13],a[0][14]);
	score += Get14CellScore(a[14][1],a[13][2],a[12][3],a[11][4],a[10][5],a[9][6],a[8][7],a[7][8],a[6][9],a[5][10],a[4][11],a[3][12],a[2][13],a[1][14]);
	score += Get13CellScore(a[14][2],a[13][3],a[12][4],a[11][5],a[10][6],a[9][7],a[8][8],a[7][9],a[6][10],a[5][11],a[4][12],a[3][13],a[2][14]);
	score += Get12CellScore(a[14][3],a[13][4],a[12][5],a[11][6],a[10][7],a[9][8],a[8][9],a[7][10],a[6][11],a[5][12],a[4][13],a[3][14]);
	score += Get11CellScore(a[14][4],a[13][5],a[12][6],a[11][7],a[10][8],a[9][9],a[8][10],a[7][11],a[6][12],a[5][13],a[4][14]);
	score += Get10CellScore(a[14][5],a[13][6],a[12][7],a[11][8],a[10][9],a[9][10],a[8][11],a[7][12],a[6][13],a[5][14]);
	score += Get9CellScore(a[14][6],a[13][7],a[12][8],a[11][9],a[10][10],a[9][11],a[8][12],a[7][13],a[6][14]);
	score += Get8CellScore(a[14][7],a[13][8],a[12][9],a[11][10],a[10][11],a[9][12],a[8][13],a[7][14]);
	score += Get7CellScore(a[14][8],a[13][9],a[12][10],a[11][11],a[10][12],a[9][13],a[8][14]);
	score += Get6CellScore(a[14][9],a[13][10],a[12][11],a[11][12],a[10][13],a[9][14]);
	score += Get5CellScore(a[14][10],a[13][11],a[12][12],a[11][13],a[10][14]);

	score += Get14CellScore(a[13][0],a[12][1],a[11][2],a[10][3],a[9][4],a[8][5],a[7][6],a[6][7],a[5][8],a[4][9],a[3][10],a[2][11],a[1][12],a[0][13]);
	score += Get13CellScore(a[12][0],a[11][1],a[10][2],a[9][3],a[8][4],a[7][5],a[6][6],a[5][7],a[4][8],a[3][9],a[2][10],a[1][11],a[0][12]);
	score += Get12CellScore(a[11][0],a[10][1],a[9][2],a[8][3],a[7][4],a[6][5],a[5][6],a[4][7],a[3][8],a[2][9],a[1][10],a[0][11]);
	score += Get11CellScore(a[10][0],a[9][1],a[8][2],a[7][3],a[6][4],a[5][5],a[4][6],a[3][7],a[2][8],a[1][9],a[0][10]);
	score += Get10CellScore(a[9][0],a[8][1],a[7][2],a[6][3],a[5][4],a[4][5],a[3][6],a[2][7],a[1][8],a[0][9]);
	score += Get9CellScore(a[8][0],a[7][1],a[6][2],a[5][3],a[4][4],a[3][5],a[2][6],a[1][7],a[0][8]);
	score += Get8CellScore(a[7][0],a[6][1],a[5][2],a[4][3],a[3][4],a[2][5],a[1][6],a[0][7]);
	score += Get7CellScore(a[6][0],a[5][1],a[4][2],a[3][3],a[2][4],a[1][5],a[0][6]);
	score += Get6CellScore(a[5][0],a[4][1],a[3][2],a[2][3],a[1][4],a[0][5]);
	score += Get5CellScore(a[4][0],a[3][1],a[2][2],a[1][3],a[0][4]);

	return score;
}


/* 判断落子后是否战斗结束 uiX：行，uiY：列 */
inline BOOL IsWin(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor, UINT32 uiX, UINT32 uiY)
{
	int m;
	int count = 1;
	for (m = uiX - 1; m >= 0 ; m--)
	{
		if (abChessArray[m][uiY] == uiColor)
		{
			count ++;
			continue;
		}
		break;
	}

	for (m = uiX + 1; m <  HEIGHT_COUNT ; m++)
	{
		if (abChessArray[m][uiY] == uiColor)
		{
			count ++;
			continue;
		}
		break;
	}
	if (count >= 5)
	{
		return TRUE;
	}

	count = 1;
	for (m = uiY - 1; m >= 0 ; m--)
	{
		if (abChessArray[uiX][m] == uiColor)
		{
			count ++;
			continue;
		}
		break;
	}

	for (m = uiY + 1; m <  WIDTH_COUNT ; m++)
	{
		if (abChessArray[uiX][m] == uiColor)
		{
			count ++;
			continue;
		}
		break;
	}
	if (count >= 5)
	{
		return TRUE;
	}
	
	/// x+,y+
	count = 1;
	for (m = 0; m < HEIGHT_COUNT ; m++)
	{
		if (uiX - m < 0 || uiY - m < 0)
		{
			break;
		}
		if (abChessArray[uiX-m][uiY-m] == uiColor)
		{
			count ++;
			continue;
		}
		break;
	}

	for (m = 0; m < HEIGHT_COUNT ; m++)
	{
		if (uiX + m >= HEIGHT_COUNT || uiY + m >= WIDTH_COUNT )
		{
			break;
		}
		if (abChessArray[uiX+m][uiY+m] == uiColor)
		{
			count ++;
			continue;
		}
		break;
	}
	if (count >= 5)
	{
		return TRUE;
	}


	/// x+, y-
	count = 1;
	for (m = 0; m < HEIGHT_COUNT ; m++)
	{
		if (uiX - m < 0 || uiY + m >= WIDTH_COUNT)
		{
			break;
		}
		if (abChessArray[uiX-m][uiY+m] == uiColor)
		{
			count ++;
			continue;
		}
		break;
	}

	for (m = 0; m < HEIGHT_COUNT ; m++)
	{
		if (uiX + m >= HEIGHT_COUNT || uiY - m < 0 )
		{
			break;
		}
		if (abChessArray[uiX+m][uiY-m] == uiColor)
		{
			count ++;
			continue;
		}
		break;
	}
	if (count >= 5)
	{
		return TRUE;
	}


	return FALSE;
}


/*  uiX：行，uiY：列 */
inline INT64 GetPointScore(BYTE a[WIDTH_COUNT][HEIGHT_COUNT], UINT32 uiColor, UINT32 uiX, UINT32 uiY)
{
	INT64 begin_score = 0 ,end_score = 0,score;

begin:
	for (int i = uiX - 4; i < uiX; i++)
	{
		if (i < 0)
		{
			continue;
		}
		if (i >= HEIGHT_COUNT)
		{
			break;
		}

		score += Get5CellScore(a[i][uiY],a[i+1][uiY],a[i+2][uiY],a[i+3][uiY],a[i+4][uiY]);
	}

	for (int i = uiY - 4; i < uiY; i++)
	{
		if (i < 0)
		{
			continue;
		}
		if (i >= WIDTH_COUNT)
		{
			break;
		}

		score += Get5CellScore(a[uiX][i],a[uiX][i+1],a[uiX][i+2],a[uiX][i+3],a[uiX][i+4]);
	}

	for (int i = 4; i >= 0; i--)
	{
		if (uiX - i < 0 || uiY - i < 0)
		{
			continue;
		}

		if (uiX - i + 4 >= HEIGHT_COUNT || uiY - i + 4 >= WIDTH_COUNT)
		{
			break;
		}

		score += Get5CellScore(a[uiX -i][uiY-i],a[uiX -i+1][uiY-i+1],a[uiX -i+2][uiY-i+2],a[uiX -i+3][uiY-i+3],a[uiX -i+4][uiY-i+4]);
	}

	for (int i = 4; i >= 0; i--)
	{
		if (uiX - i < 0 || uiY + i >= WIDTH_COUNT)
		{
			continue;
		}

		if (uiX - i + 4 >= HEIGHT_COUNT || uiY + i - 4 < 0)
		{
			break;
		}

		score += Get5CellScore(a[uiX -i][uiY+i],a[uiX -i+1][uiY+i-1],a[uiX -i+2][uiY+i-2],a[uiX -i+3][uiY+i-3],a[uiX -i+4][uiY+i-4]);
	}

	if (a[uiX][uiY] == NO_CHESS)
	{
		begin_score = score;
		a[uiX][uiY] = uiColor;
		goto begin;
	}
	else
	{
		end_score = score;
		a[uiX][uiY] = NO_CHESS;
	}

	
	
	return TRUE;
}
