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
	g_uiLeafCnt++;
	//return 0;
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

/* 计算候选节点 */
VOID Candidate(BYTE abChessArray[WIDTH_COUNT][HEIGHT_COUNT], vector<POINT> *pCandidate)
{

	int candFlag = 1;
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
			iScoreTemp = Evaluate(abChessArray, uiColor);
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



INT64 g_FiveCellMap[FIVECELL_MAX]={0};
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
	int index = 0;
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
						index = a[0]*81 + a[1]*27 + a[2]*9 + a[3]*3 + a[4];
						g_FiveCellMap[index] = GenFiveCellScore(a);
					}
				}
			}
		}
	}
}



