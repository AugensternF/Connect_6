#ifndef AIFENGMINCONNECT6_H_INCLUDED
#define AIFENGMINCONNECT6_H_INCLUDED
using namespace std;

//���������е�ͷ�ļ�
#include<stdio.h>
#include<winbgim.h>
#include<stdlib.h>
#include<vector>
#include<iostream>

//�����ǳ���
#define LEFT 30
#define RIGHT 570
#define TOP 30
#define BOTTOM 570
#define STEP 30

//�������õ��Ľṹ��
//�洢����λ�õĽṹ��
typedef struct chessposition
{
    int x;
    int y;
}CHESSPOS;

//��һ����ļ�ֵ(�����������λ�úͼ�ֵ)
typedef struct chessmove
{
    CHESSPOS chessPos1;
    CHESSPOS chessPos2;
    int Score;
}CHESSMOVE;

//�����Ǻ�������
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

//�����Ǳ���������
static int board[19][19];
static int side;
static int depth;
static int bestMove;

#endif // AIFENGMINCONNECT6_H_INCLUDED
