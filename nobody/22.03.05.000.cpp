#include<iostream>
using namespace std;

//#define N 8
//int tile = 0; 
//int tile2 = 1;
//int Board[N][N];
//
//void ChessBoard(int tr, int tc, int dr, int dc, int size) {
//	if (size == 1)
//	{
//		return;
//	}
//	int t = ++tile;
//	int s = size / 2;
//	if (dr < tr + s && dc < tc + s)
//		ChessBoard(tr, tc, dr, dc, s);
//	else {
//		Board[tr + s - 1][tc + s - 1] = t;
//		ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
//	}
//	if (dr < tr + s && dc >= tc + s)
//		ChessBoard(tr, tc + s, dr, dc, s);
//	else {
//		Board[tr + s - 1][tc + s] = t;
//		ChessBoard(tr, tc + s, tr + s - 1, tc + s , s);
//	}
//	if (dr >= tr + s && dc < tc + s)
//		ChessBoard(tr + s, tc, dr, dc, s);
//	else {
//		Board[tr + s][tc + s - 1] = t;
//		ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
//	}
//	if (dr >= tr + s && dc >= tc + s)
//		ChessBoard(tr + s, tc + s, dr, dc, s);
//	else {
//		Board[tr + s][tc + s] = t;
//		ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
//	}
//}
//
//
//void ChessBoard2(int tr, int tc, int dr, int dc, int size){
//	tile2++;
//	if (size == 2)
//	{
//		for (int i = 0; i < 2; i++)
//		{
//			for (int j = 0; j < 2; j++)
//			{
//				if (Board[tr + i][tc + j] == 0)
//					Board[tr + i][tc + j] = tile2;
//			}
//		}
//		return;
//	}
//	int s = size / 2;
//	if (dr < tr + s && dc < tc + s)
//	{
//		Board[tr + s][tc + s] = tile2;
//		Board[tr + s - 1][tc + s] = tile2;
//		Board[tr + s][tc + s - 1] = tile2;
//		ChessBoard2(tr, tc, dr, dc, s);
//		ChessBoard2(tr + s, tc + s, tr + s, tc + s, s);
//		ChessBoard2(tr, tc + s, tr + s - 1, tc + s, s);
//		ChessBoard2(tr + s, tc, tr + s, tc + s - 1, s);
//	}
//	if (dr < tr + s && dc >= tc + s)
//	{
//		Board[tr + s][tc + s] = tile2;
//		Board[tr + s - 1][tc + s - 1] = tile2;
//		Board[tr + s][tc + s - 1] = tile2;
//		ChessBoard2(tr, tc, dr, dc, s);
//		ChessBoard2(tr + s, tc + s, tr + s, tc + s, s);
//		ChessBoard2(tr, tc + s, tr + s - 1, tc + s - 1, s);
//		ChessBoard2(tr + s, tc, tr + s, tc + s - 1, s);
//	}	
//	if (dr >= tr + s && dc < tc + s)
//	{
//		Board[tr + s][tc + s] = tile2;
//		Board[tr + s - 1][tc + s] = tile2;
//		Board[tr + s - 1][tc + s - 1] = tile2;
//		ChessBoard2(tr, tc, dr, dc, s);
//		ChessBoard2(tr + s, tc + s, tr + s, tc + s, s);
//		ChessBoard2(tr, tc + s, tr + s - 1, tc + s, s);
//		ChessBoard2(tr + s, tc, tr + s - 1, tc + s - 1, s);
//	}	
//	if (dr >= tr + s && dc >= tc + s)
//	{
//		Board[tr + s - 1][tc + s - 1] = tile2;
//		Board[tr + s - 1][tc + s] = tile2;
//		Board[tr + s][tc + s - 1] = tile2;
//		ChessBoard2(tr, tc, dr, dc, s);
//		ChessBoard2(tr + s, tc + s - 1, tr + s - 1, tc + s, s);
//		ChessBoard2(tr, tc + s, tr + s - 1, tc + s, s);
//		ChessBoard2(tr + s, tc, tr + s, tc + s - 1, s);
//	}
//}
//int main()
//{
//	//¿Î±¾
//	ChessBoard(0, 0, 1-1, 3-1, N);
//
//	//×Ô¼º
//	//int dr = 2, dc = 1;
//	//Board[dr][dc] = tile2;
//	//ChessBoard2(0, 0, dr, dc, N);
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			printf("%d ", Board[i][j]);
//		}
//		printf("\n");
//	}
//
//	for (int i = 0; i < N; i++)   //N >= 8 
//	{
//		for (int j = 0; j < N; j++)
//		{
//			printf("%6d", Board[i][j]);
//		}
//		printf("\n");
//		printf("\n");
//		printf("\n");
//
//	}
//	return 0;
//}
//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
//{
//	int* ret = (int*)malloc(4 * numsSize + 40);
//	*returnSize = 0;
//	memset(ret, 0, 4 * numsSize + 40);
//	for (int i = 0; i < numsSize; i++)
//	{
//		ret[nums[i]] = nums[i];
//	}
//	for (int i = 1; i <= numsSize; i++)
//	{
//		if (ret[i] == 0)
//			ret[(*returnSize)++] = i;
//	}
//	return ret;
//}
int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
    int* ret = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    int temp = 0;
    for (int i = 0; i < numsSize; i++)
    {
        temp ^= nums[i];
    }
    int mask = 1;
    while ((temp & mask) == 0) {
        mask <<= 1;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (mask & nums[i])
            ret[0] ^= nums[i];
        else
            ret[1] ^= nums[i];
    }
    return ret;
}
