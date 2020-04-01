#ifndef AIFENGMINCONNECT6_H_INCLUDED
#define AIFENGMINCONNECT6_H_INCLUDED
using namespace std;

//下面是所有的头文件
#include<stdio.h>
#include<winbgim.h>
#include<stdlib.h>
#include<vector>
#include<iostream>

//下面是常量
#define LEFT 30
#define RIGHT 570
#define TOP 30
#define BOTTOM 570
#define STEP 30

//下面是用到的结构体
//存储下棋位置的结构体
typedef struct chessposition
{
    int x;
    int y;
}CHESSPOS;

//下一手棋的价值(包括两个棋的位置和价值)
typedef struct chessmove
{
    CHESSPOS chessPos1;
    CHESSPOS chessPos2;
    int Score;
}CHESSMOVE;

//下面是函数声明
vector<CHESSPOS>MoveGenerater(int chessSide);
void Init();
void PaintBackGround(int x,int y);
void PaintBlackChess(int x,int y);
void PaintWhiteChess(int x,int y);
void PaintBoard();
bool IsLegal(int x,int y);
bool IsFull();
bool IsBlackWin(int x,int y);
bool IsWhiteWin(int x,int y);
int Value();
int AlphaBeta(int depth,int alpha,int beta);
void PlayManToMan();
void PlayComputerToComputer();

//下面是变量的声明
static int board[19][19];
static int side;
static int depth;
static int bestMove;

#endif // AIFENGMINCONNECT6_H_INCLUDED
