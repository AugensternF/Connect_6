#include"aifengminconnect6.h"

//�߷�������
vector<CHESSPOS>MoveGenerater(int chessSide)
{
    int i,j,k;
    int x,y;    //���������ĵڶ���λ�ã�ֻҪ�Ϸ�����
    int number;
    CHESSPOS pos;
    CHESSMOVE move;
    vector<CHESSPOS>chessPos;
    vector<CHESSMOVE>movePosition;
    vector<CHESSPOS>oppMove;  //�Է�����������������ʱ��һ���ö�

    if(chessSide == 1)
    {
        side = 1;
    }
    if(chessSide == 7)
    {
        side = 7;
    }

    /*û���Ż��ģ�ֻҪ�ǿվͼӽ�ȥ
    for(i=0;i<19;i++)
    {
        for(j=0;j<19;j++)
        {
            if(IsLegal(i,j))
            {
                pos.x = i;
                pos.y = j;
                stonePos.push_back(pos);
            }
        }
    }*/


    //ˮƽ����
    for(i=0;i<19;i++)
    {
        for(j=0;j<14;j++)
        {
            number = board[i][j]+board[i][j+1]+board[i][j+2]+board[i][j+3]+board[i][j+4]+board[i][j+5];
            if(number == 4*side)   //˵����һ·���ĸ����ӣ���ʣ�µ�������λ������
            {
                for(k=0;k<6;k++)
                {
                    if(board[i][j+k] == 0)
                    {
                        //ʣ�µ�������λ������pos��δ��������洢
                        pos.x = i;
                        pos.y = j+k;
                        chessPos.push_back(pos);
                    }
                }
            }
            else if(number == 5*side)   //˵����һ·��������ӣ���Ψһ��һ����λ������
            {
                for(k=0;k<6;k++)
                {
                    if(board[i][j+k] == 0)
                    {
                        //������ʣ�µ����һ�ӣ�����move��
                        move.chessPos1.x = i;
                        move.chessPos1.y = j+k;
                        movePosition.push_back(move);
                        for(x=0;x<19;x++)
                        {
                            for(y=0;y<19;y++)
                            {
                                if(board[x][y]==0)
                                {
                                    move.chessPos2.x = x;
                                    move.chessPos2.y = y;
                                    movePosition.push_back(move);   //�����Ǹ������꣬�������һ���Ϸ�λ�ú����ճ�һ��
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
            else if(number == 5*(8-side) || number == 4*(8-side))   //��鵽�Է���������������,���Լ���Ӯ��ʱ�����
            {
                for(k=0;k<6;k++)
                {
                    if(board[i][j+k] == 0)
                    {
                        pos.x = i;
                        pos.y = j+k;
                        oppMove.push_back(pos);
                    }
                }
            }
        }
    }
    //��ֱ����
    for(j=0;j<19;j++)
    {
        for(i=0;i<14;i++)
        {
            number = board[i][j]+board[i+1][j]+board[i+2][j]+board[i+3][j]+board[i+4][j]+board[i+5][j];
            if(number == 4*side)   //˵����һ·���ĸ����ӣ���ʣ�µ�������λ������
            {
                for(k=0;k<6;k++)
                {
                    if(board[i+k][j] == 0)
                    {
                        pos.x = i+k;
                        pos.y = j;
                        chessPos.push_back(pos);
                    }
                }
            }
            else if(number == 5*side)   //˵����һ·��������ӣ���Ψһ��һ����λ������
            {
                for(k=0;k<6;k++)
                {
                    if(board[i+k][j] == 0)
                    {
                        move.chessPos1.x = i+k;
                        move.chessPos1.y = j;
                        movePosition.push_back(move);
                        for(x=0;x<19;x++)
                        {
                            for(y=0;y<19;y++)
                            {
                                if(board[x][y]==0)
                                {
                                    move.chessPos2.x = x;
                                    move.chessPos2.y = y;
                                    movePosition.push_back(move);   //�����Ǹ������꣬�������һ���Ϸ�λ�ú����ճ�һ��
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
            else if(number == 5*(8-side) || number == 4*(8-side))   //��鵽�Է���������������,���Լ���Ӯ��ʱ�����
            {
                for(k=0;k<6;k++)
                {
                    if(board[i+k][j] == 0)
                    {
                        pos.x = i+k;
                        pos.y = j;
                        oppMove.push_back(pos);
                    }
                }
            }
        }
    }
    //��б�������
    for(i=0;i<14;i++)
    {
        for(j=0;j<14;j++)
        {
            number = board[i][j]+board[i+1][j+1]+board[i+2][j+2]+board[i+3][j+3]+board[i+4][j+4]+board[i+5][j+5];
            if(number == 4*side)   //˵����һ·���ĸ����ӣ���ʣ�µ�������λ������
            {
                for(k=0;k<6;k++)
                {
                    if(board[i+k][j+k] == 0)
                    {
                        pos.x = i+k;
                        pos.y = j+k;
                        chessPos.push_back(pos);
                    }
                }
            }
            else if(number == 5*side)   //˵����һ·��������ӣ���Ψһ��һ����λ������
            {
                for(k=0;k<6;k++)
                {
                    if(board[i+k][j+k] == 0)
                    {
                        move.chessPos1.x = i+k;
                        move.chessPos1.y = j+k;
                        movePosition.push_back(move);
                        for(x=0;x<19;x++)
                        {
                            for(y=0;y<19;y++)
                            {
                                if(board[x][y]==0)
                                {
                                    move.chessPos2.x = x;
                                    move.chessPos2.y = y;
                                    movePosition.push_back(move);   //�����Ǹ������꣬�������һ���Ϸ�λ�ú����ճ�һ��
                                }
                            }
                        }
                    }
                }
            }
            else if(number == 5*(8-side) || number == 4*(8-side))   //��鵽�Է���������������,���Լ���Ӯ��ʱ�����
            {
                for(k=0;k<6;k++)
                {
                    if(board[i+k][j+k] == 0)
                    {
                        pos.x = i+k;
                        pos.y = j+k;
                        chessPos.push_back(pos);
                    }
                }
            }
        }
    }
    //��б�������
    for(i=0;i<14;i++)
    {
        for(j=19;j>6;j--)
        {
            number = board[i][j]+board[i+1][j-1]+board[i+2][j-2]+board[i+3][j-3]+board[i+4][j-4]+board[i+5][j-5];
            if(number == 4*side)   //˵����һ·���ĸ����ӣ���ʣ�µ�������λ������
            {
                for(k=0;k<6;k++)
                {
                    if(board[i+k][j-k] == 0)
                    {
                        pos.x = i+k;
                        pos.y = j-k;
                        chessPos.push_back(pos);
                    }
                }
            }
            else if(number == 5*side)   //˵����һ·��������ӣ���Ψһ��һ����λ������
            {
                for(k=0;k<6;k++)
                {
                    if(board[i+k][j-k] == 0)
                    {
                        move.chessPos1.x = i+k;
                        move.chessPos1.y = j-k;
                        movePosition.push_back(move);
                        for(x=0;x<19;x++)
                        {
                            for(y=0;y<19;y++)
                            {
                                if(board[x][y]==0)
                                {
                                    move.chessPos2.x = x;
                                    move.chessPos2.y = y;
                                    movePosition.push_back(move);   //�����Ǹ������꣬�������һ���Ϸ�λ�ú����ճ�һ��
                                }
                            }
                        }
                    }
                }
            }
            else if(number == 5*(8-side) || number == 4*(8-side))   //��鵽�Է���������������,���Լ���Ӯ��ʱ�����
            {
                for(k=0;k<6;k++)
                {
                    if(board[i+k][j-k] == 0)
                    {
                        pos.x = i+k;
                        pos.y = j-k;
                        chessPos.push_back(pos);
                    }
                }
            }
        }
    }
    return chessPos;
}

//��ʼ������
void Init()
{
    int i,j;
    for(i=0;i<19;i++)
    {
        for(j=0;j<19;j++)
        {
            board[i][j] = 0;
        }
    }
    //board[3][2] = 1;
    //board[0][0] = 1;
    //board[18][18] = -1;
    side = 7;      //������7��ʾ��������1��ʾ
    depth = 2;
}

//��������ɫ
void PaintBackGround(int x,int y)
{
    //�����̵ĸ���
    int poly[8];
    poly[0] = x*STEP+LEFT;
    poly[1] = y*STEP+TOP;
    poly[2] = (x+1)*STEP+LEFT;
    poly[3] = y*STEP+TOP;
    poly[4] = (x+1)*STEP+LEFT;
    poly[5] = (y+1)*STEP+TOP;
    poly[6] = x*STEP+LEFT;
    poly[7] = (y+1)*STEP+TOP;
    setfillstyle(1,LIGHTGRAY);
    fillpoly(4,poly);

    //����λ��
    setfillstyle(1,BLACK);
    fillellipse(LEFT+3*STEP,TOP+3*STEP,5,5);
    fillellipse(LEFT+3*STEP,TOP+9*STEP,5,5);
    fillellipse(LEFT+3*STEP,TOP+15*STEP,5,5);
    fillellipse(LEFT+9*STEP,TOP+3*STEP,5,5);
    fillellipse(LEFT+9*STEP,TOP+9*STEP,5,5);
    fillellipse(LEFT+9*STEP,TOP+15*STEP,5,5);
    fillellipse(LEFT+15*STEP,TOP+3*STEP,5,5);
    fillellipse(LEFT+15*STEP,TOP+9*STEP,5,5);
    fillellipse(LEFT+15*STEP,TOP+15*STEP,5,5);
}

//������(side = 1)
void PaintBlackChess(int x,int y)
{
    setfillstyle(1,0);
    fillellipse(x*STEP+LEFT,y*STEP+TOP,15,15);
}

//������(side = -1)
void PaintWhiteChess(int x,int y)
{
    setfillstyle(1,WHITE);
    fillellipse(x*STEP+LEFT,y*STEP+TOP,15,15);
}

//����������
void PaintBoard()
{
    int i,j;
    for(i=0;i<18;i++)
    {
        for(j=0;j<18;j++)
        {
            PaintBackGround(i,j);
        }
    }
    for(i=0;i<19;i++)
    {
        for(j=0;j<19;j++)
        {
            if(board[i][j] == 7)  //1Ϊ7Ϊ����
            {
                PaintBlackChess(i,j);
            }
            if(board[i][j] == 1)
            {
                PaintWhiteChess(i,j);
            }
        }
    }
    line(LEFT,TOP,RIGHT,TOP);
    line(LEFT,TOP,LEFT,BOTTOM);
    line(LEFT,BOTTOM,RIGHT,BOTTOM);
    line(RIGHT,BOTTOM,RIGHT,TOP);
}

//�ж������λ���Ƿ�Ϸ�
bool IsLegal(int x,int y)
{
    if(board[x][y] == 0)
    {
        return true;
    }
    return false;
    /*
    //�ж�x,y�������λ���Ƿ�Ϊ��
    if(y-2>0 && board[x][y-2]==0)
    {
        return true;
    }
    if(y-1>0 && board[x][y-1]==0)
    {
        return true;
    }
    //�ж�x,y�ұ�����λ���Ƿ�Ϊ��
    if(y+2<19 && board[x][y+2]==0)
    {
        return true;
    }
    if(y+1<19 && board[x][y+1]==0)
    {
        return true;
    }
    //�ж�x,y�ϱ�����λ���Ƿ�Ϊ��
    if(x-2>0 && board[x-2][y]==0)
    {
        return true;
    }
    if(x-1>0 && board[x-1][y]==0)
    {
        return true;
    }
    //�ж�x,y�±�����λ���Ƿ�Ϊ��
    if(x+2<19 && board[x+2][y]==0)
    {
        return true;
    }
    if(x+1<19 && board[x+1][y]==0)
    {
        return true;
    }
    //�ж�x,y���Ϸ�����λ���Ƿ�Ϊ��
    if(x-2>0 &&y-2>0 && board[x-2][y-2]==0)
    {
        return true;
    }
    if(x-1>0 && y-1>0 && board[x-1][y-1]==0)
    {
        return true;
    }
    //�ж�x,y���·�����λ���Ƿ�Ϊ��
    if(x+2>0 &&y-2>0 && board[x+2][y-2]==0)
    {
        return true;
    }
    if(x+1>0 && y-1>0 && board[x+1][y-1]==0)
    {
        return true;
    }
    //�ж�x,y���Ϸ�����λ���Ƿ�Ϊ��
    if(x-2>0 &&y+2>0 && board[x-2][y+2]==0)
    {
        return true;
    }
    if(x-1>0 && y+1>0 && board[x-1][y+1]==0)
    {
        return true;
    }
    //�ж�x,y���·�����λ���Ƿ�Ϊ��
    if(x+2>0 &&y+2>0 && board[x+2][y+2]==0)
    {
        return true;
    }
    if(x+1>0 && y+1>0 && board[x+1][y+1]==0)
    {
        return true;
    }
    return false;*/
}

//�ж������Ƿ�����
bool IsFull()
{
    int i,j;
    for(i=0;i<19;i++)
    {
        for(j=0;j<19;j++)
        {
            if(board[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

//�жϺڷ��Ƿ�Ӯ��
bool IsBlackWin(int x,int y)
{
    int countBlack = 1;
    //int countWhite = 1;
    int k,l;
    //�Ӻᡢ������б����б�ĸ����������ǲ����Ѿ�����
    //��
    //left
    for(k=x-1;k>=0;k--)
    {
        if(board[k][y]==7)
        {
            countBlack++;
            if(countBlack>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    //right
    for(k=x+1;k<19;k++)
    {
        if(board[k][y]==7)
        {
            countBlack++;
            if(countBlack>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    countBlack = 1;
    //��
    //up
    for(l=y-1;l>=0;l--)
    {
        if(board[x][l]==7)
        {
            countBlack++;
            if(countBlack>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    //down
    for(l=y+1;l<19;l++)
    {
        if(board[x][l]==7)
        {
            countBlack++;
            if(countBlack>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    countBlack = 1;
    //��б
    //up-left
    for(k=x-1,l=y-1;k>=0 && l>=0;k--,l--)
    {
        if(board[k][l]==7)
        {
            countBlack++;
            if(countBlack>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    //down-right
    for(k=x+1,l=y+1;k<19 && l<19;k++,l++)
    {
        if(board[k][l]==7)
        {
            countBlack++;
            if(countBlack>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    countBlack = 1;
    //��б
    //up-right
    for(k=x+1,l=y-1;k<19 && l>=0;k++,l--)
    {
        if(board[k][l]==7)
        {
            countBlack++;
            if(countBlack>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    //down-left
    for(k=x-1,l=y+1;k>=0 && l<19;k--,l++)
    {
        if(board[k][l]==7)
        {
            countBlack++;
            if(countBlack>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    return false;
}

//�жϰ׷��Ƿ�Ӯ��
bool IsWhiteWin(int x,int y)
{
    //int countBlack = 1;
    int countWhite = 1;
    int k,l;
    //�Ӻᡢ������б����б�ĸ����������ǲ����Ѿ�����
    //��
    //left
    for(k=x-1;k>=0;k--)
    {
        if(board[k][y]==1)
        {
            countWhite++;
            if(countWhite>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    //right
    for(k=x+1;k<19;k++)
    {
        if(board[k][y]==1)
        {
            countWhite++;
            if(countWhite>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    countWhite = 1;
    //��
    //up
    for(l=y-1;l>=0;l--)
    {
        if(board[x][l]==1)
        {
            countWhite++;
            if(countWhite>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    //down
    for(l=y+1;l<19;l++)
    {
        if(board[x][l]==1)
        {
            countWhite++;
            if(countWhite>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    countWhite = 1;
    //��б
    //up-left
    for(k=x-1,l=y-1;k>=0 && l>=0;k--,l--)
    {
        if(board[k][l]==1)
        {
            countWhite++;
            if(countWhite>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    //down-right
    for(k=x+1,l=y+1;k<19 && l<19;k++,l++)
    {
        if(board[k][l]==1)
        {
            countWhite++;
            if(countWhite>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    countWhite = 1;
    //��б
    //up-right
    for(k=x+1,l=y-1;k<19 && l>=0;k++,l--)
    {
        if(board[k][l]==1)
        {
            countWhite++;
            if(countWhite>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    //down-left
    for(k=x-1,l=y+1;k>=0 && l<19;k--,l++)
    {
        if(board[k][l]==1)
        {
            countWhite++;
            if(countWhite>=6)
            {
                return true;
            }
        }
        else
        {
            break;
        }
    }
    return false;
}

//��ֵ����
/*int Value()
{
    int i,j,k;
    int number;
    int score;
    int NumberOfMyRoad[7];
    int NumberOfEnemyRoad[7];
    int ScoreOfRoad[7];

    //��ÿ��·��ֵ
    ScoreOfRoad[0] = 0;
    ScoreOfRoad[1] = 20;
    ScoreOfRoad[2] = 80;
    ScoreOfRoad[3] = 150;
    ScoreOfRoad[4] = 800;
    ScoreOfRoad[5] = 1000;
    ScoreOfRoad[6] = 10000;   //������ʱ���������Ӯ�壬��10000��ʾ

    //��ʼ��˫������
    for(k=0;k<7;k++)
    {
        NumberOfMyRoad[k] = 0;
        NumberOfEnemyRoad[k] = 0;
    }

    //����
    for(i=0;i<19;i++)
    {
        for(j=0;j<14;j++)
        {
            number = board[i][j]+board[i][j+1]+board[i][j+2]+board[i][j+3]+board[i][j+4]+board[i][j+5];
            if(number == 0 || (number>6 && number%7 != 0)) //number==0��ʾû�����ӣ�����6�����ܱ�7������˵��ͬʱ�к���Ͱ���
            {
                continue;
            }
            if(number<7)
            {
                NumberOfEnemyRoad[number]++;    //side==1����·��
            }
            else
            {
                NumberOfMyRoad[number/7]++;      //side==7����·��
            }
        }
    }

    //����
    for(j=0;j<19;j++)
    {
        for(i=0;i<14;i++)
        {
            number = board[i][j]+board[i+1][j]+board[i+2][j]+board[i+3][j]+board[i+4][j]+board[i+5][j];
            if(number == 0 || (number>6 && number%7 != 0))
            {
                continue;
            }
            if(number<7)
            {
                NumberOfEnemyRoad[number]++;
            }
            else
            {
                NumberOfMyRoad[number/7]++;
            }
        }
    }

    //��б
    for(i=0;i<14;i++)
    {
        for(j=0;j<14;j++)
        {
            number = board[i][j]+board[i+1][j+1]+board[i+2][j+2]+board[i+3][j+3]+board[i+4][j+4]+board[i+5][j+5];
            if(number == 0 || (number>6 && number%7 != 0))
            {
                continue;
            }
            if(number<7)
            {
                NumberOfEnemyRoad[number]++;
            }
            else
            {
                NumberOfMyRoad[number/7]++;
            }
        }
    }

    //��б
    for(i=0;i<14;i++)
    {
        for(j=18;j>=5;j--)
        {
            number = board[i][j]+board[i+1][j-1]+board[i+2][j-2]+board[i+3][j-3]+board[i+4][j-4]+board[i+5][j-5];
            if(number == 0 || (number>6 && number%7 != 0))
            {
                continue;
            }
            if(number<7)
            {
                NumberOfEnemyRoad[number]++;
            }
            else
            {
                NumberOfMyRoad[number/7]++;
            }
        }
    }

    //�����յķ���
    for(k=0;k<7;k++)
    {
        score += (NumberOfMyRoad[k]*ScoreOfRoad[k])-(NumberOfEnemyRoad[k]*ScoreOfRoad[k]);
    }
    if(side == 7)
    {
        return score;
    }
    else
    {
        return -score;
    }
}
*/
//���¼�֦�㷨
/*int AlphaBeta(int depth,int alpha,int beta)
{
    int i,j;
    int val;
    int x,y;
    if(depth == 0 || chessPos.size() == 0)
    {
        return Value();
    }
    else
    {
        for(i=0;i<19;i++)
        {
            for(j=0;j<19;j++)
            {
                if(board[i][j] == 0)
                {
                    board[i][j] == side;
                    val = -AlphaBeta(depth-1,-beta,-alpha);
                    board[i][j] = 0;
                    if(val>=beta)
                    {
                        return beta;
                    }
                    if(val>alpha)
                    {
                        alpha = val;
                        x = i;
                        y = j;
                    }
                }
            }
        }
        bestMove = 3*x+y;
        return alpha;
    }
}*/

//man-man
void PlayManToMan()
{
    PaintBoard();
    int x,y;
    int count = 1;
    while(true)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            x = mousex();
            y = mousey();
            if(x<LEFT-10||x>RIGHT+10||y<TOP-10||y>BOTTOM+10)
            {
                clearmouseclick(WM_LBUTTONDOWN);
                continue;
            }
            if(!IsLegal((x-LEFT)/STEP,(y-TOP)/STEP))
            {
                clearmouseclick(WM_LBUTTONDOWN);
                continue;
            }
            if(IsLegal((x-LEFT)/STEP,(y-TOP)/STEP))
            {
                board[(x-LEFT)/STEP][(y-TOP)/STEP]= side;
                //cleardevice();
                PaintBoard();
                count += 1;
                if(IsFull())
                {
                    outtextxy(10,10,"pingju!");
                    break;
                }
                if(IsBlackWin((x-LEFT)/STEP,(y-TOP)/STEP))
                {
                    outtextxy(10,10,"BlackWin!");
                    break;
                }
                if(IsWhiteWin((x-LEFT)/STEP,(y-TOP)/STEP))
                {
                    outtextxy(10,10,"WhiteWin!");
                    break;
                }
            }
            if(count == 2 && side == 7)
            {
                side = 1;
                count = 0;
            }
            if(count == 2 && side == 1)
            {
                side = 7;
                count = 0;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}

//������ս
/*void PlayComputerToComputer()
{
    PaintBoard();
    int x,y;
    int value;
    int count = 1;
    while(true)
    {
        if(side == 1)
        {
            if(board[9][9] == 0)
            {
                board[9][9] = 1;
                PaintBoard();
                count++;
            }
            else
            {
                value = AlphaBeta(depth,-1000,1000);
                printf("value = %d\n",value);
                printf("side = %d\n",side);
                x = bestMove/3;
                y = bestMove%3;
                if(IsLegal(x,y))
                {
                    board[x][y] = side;
                    PaintBoard();
                    count++;
                    if(IsFull())
                    {
                        outtextxy(10,10,"pingju!");
                        break;
                    }
                    if(IsBlackWin(x,y))
                    {
                        outtextxy(10,10,"black win!");
                        break;
                    }
                    if(IsWhiteWin(x,y))
                    {
                        outtextxy(10,10,"white win!");
                        break;
                    }
                }

            }
            if(count == 2)
            {
                side = 7;
                count = 0;
            }
        }
        if(side == 7)
        {
            if(board[9][9] == 0)
            {
                board[9][9] = 7;
                PaintBoard();
                count++;
            }
            else
            {
                int value = AlphaBeta(depth,-1000,1000);
                printf("value = %d\n",value);
                printf("side = %d\n",side);
                x = bestMove/3;
                y = bestMove%3;
                if(IsLegal(x,y))
                {
                    board[x][y] = side;
                    PaintBoard();
                    count++;
                    if(IsFull())
                    {
                        outtextxy(10,10,"pingju!");
                        break;
                    }
                    if(IsBlackWin(x,y))
                    {
                        outtextxy(10,10,"black win!");
                        break;
                    }
                    if(IsWhiteWin(x,y))
                    {
                        outtextxy(10,10,"white win!");
                        break;
                    }
                }
            }
            if(count == 2)
            {
                side = 1;
                count = 0;
            }
        }
    }
}*/
