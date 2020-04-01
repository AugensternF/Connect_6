#include"aifengminconnect6.h"

//走法生成器
vector<CHESSPOS>MoveGenerater(int chessSide)
{
    int i,j,k;
    int x,y;    //生成五连的第二个位置，只要合法即可
    int number;
    CHESSPOS pos;
    CHESSMOVE move;
    vector<CHESSPOS>chessPos;
    vector<CHESSMOVE>movePosition;
    vector<CHESSPOS>oppMove;  //对方五连或者是四连的时候一定得堵

    if(chessSide == 1)
    {
        side = 1;
    }
    if(chessSide == 7)
    {
        side = 7;
    }

    /*没有优化的，只要是空就加进去
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


    //水平分析
    for(i=0;i<19;i++)
    {
        for(j=0;j<14;j++)
        {
            number = board[i][j]+board[i][j+1]+board[i][j+2]+board[i][j+3]+board[i][j+4]+board[i][j+5];
            if(number == 4*side)   //说明这一路有四个棋子，把剩下的两个空位存起来
            {
                for(k=0;k<6;k++)
                {
                    if(board[i][j+k] == 0)
                    {
                        //剩下的两个空位都放在pos中未进行特殊存储
                        pos.x = i;
                        pos.y = j+k;
                        chessPos.push_back(pos);
                    }
                }
            }
            else if(number == 5*side)   //说明这一路有五个棋子，把唯一的一个空位存起来
            {
                for(k=0;k<6;k++)
                {
                    if(board[i][j+k] == 0)
                    {
                        //连六子剩下的最后一子，放在move中
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
                                    movePosition.push_back(move);   //五连那个子下完，在随便找一个合法位置和它凑成一对
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
            else if(number == 5*(8-side) || number == 4*(8-side))   //检查到对方有了四连或五连,在自己不赢的时候必下
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
    //竖直分析
    for(j=0;j<19;j++)
    {
        for(i=0;i<14;i++)
        {
            number = board[i][j]+board[i+1][j]+board[i+2][j]+board[i+3][j]+board[i+4][j]+board[i+5][j];
            if(number == 4*side)   //说明这一路有四个棋子，把剩下的两个空位存起来
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
            else if(number == 5*side)   //说明这一路有五个棋子，把唯一的一个空位存起来
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
                                    movePosition.push_back(move);   //五连那个子下完，在随便找一个合法位置和它凑成一对
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
            else if(number == 5*(8-side) || number == 4*(8-side))   //检查到对方有了四连或五连,在自己不赢的时候必下
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
    //左斜方向分析
    for(i=0;i<14;i++)
    {
        for(j=0;j<14;j++)
        {
            number = board[i][j]+board[i+1][j+1]+board[i+2][j+2]+board[i+3][j+3]+board[i+4][j+4]+board[i+5][j+5];
            if(number == 4*side)   //说明这一路有四个棋子，把剩下的两个空位存起来
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
            else if(number == 5*side)   //说明这一路有五个棋子，把唯一的一个空位存起来
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
                                    movePosition.push_back(move);   //五连那个子下完，在随便找一个合法位置和它凑成一对
                                }
                            }
                        }
                    }
                }
            }
            else if(number == 5*(8-side) || number == 4*(8-side))   //检查到对方有了四连或五连,在自己不赢的时候必下
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
    //右斜方向分析
    for(i=0;i<14;i++)
    {
        for(j=19;j>6;j--)
        {
            number = board[i][j]+board[i+1][j-1]+board[i+2][j-2]+board[i+3][j-3]+board[i+4][j-4]+board[i+5][j-5];
            if(number == 4*side)   //说明这一路有四个棋子，把剩下的两个空位存起来
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
            else if(number == 5*side)   //说明这一路有五个棋子，把唯一的一个空位存起来
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
                                    movePosition.push_back(move);   //五连那个子下完，在随便找一个合法位置和它凑成一对
                                }
                            }
                        }
                    }
                }
            }
            else if(number == 5*(8-side) || number == 4*(8-side))   //检查到对方有了四连或五连,在自己不赢的时候必下
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

//初始化函数
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
    side = 7;      //黑棋用7表示，白棋用1表示
    depth = 2;
}

//画背景颜色
void PaintBackGround(int x,int y)
{
    //画底盘的格子
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

    //画定位星
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

//画黑棋(side = 1)
void PaintBlackChess(int x,int y)
{
    setfillstyle(1,0);
    fillellipse(x*STEP+LEFT,y*STEP+TOP,15,15);
}

//画白棋(side = -1)
void PaintWhiteChess(int x,int y)
{
    setfillstyle(1,WHITE);
    fillellipse(x*STEP+LEFT,y*STEP+TOP,15,15);
}

//画整个棋盘
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
            if(board[i][j] == 7)  //1为7为黑棋
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

//判断下棋的位置是否合法
bool IsLegal(int x,int y)
{
    if(board[x][y] == 0)
    {
        return true;
    }
    return false;
    /*
    //判断x,y左边俩个位置是否为空
    if(y-2>0 && board[x][y-2]==0)
    {
        return true;
    }
    if(y-1>0 && board[x][y-1]==0)
    {
        return true;
    }
    //判断x,y右边俩个位置是否为空
    if(y+2<19 && board[x][y+2]==0)
    {
        return true;
    }
    if(y+1<19 && board[x][y+1]==0)
    {
        return true;
    }
    //判断x,y上边俩个位置是否为空
    if(x-2>0 && board[x-2][y]==0)
    {
        return true;
    }
    if(x-1>0 && board[x-1][y]==0)
    {
        return true;
    }
    //判断x,y下边俩个位置是否为空
    if(x+2<19 && board[x+2][y]==0)
    {
        return true;
    }
    if(x+1<19 && board[x+1][y]==0)
    {
        return true;
    }
    //判断x,y左上方俩个位置是否为空
    if(x-2>0 &&y-2>0 && board[x-2][y-2]==0)
    {
        return true;
    }
    if(x-1>0 && y-1>0 && board[x-1][y-1]==0)
    {
        return true;
    }
    //判断x,y左下方俩个位置是否为空
    if(x+2>0 &&y-2>0 && board[x+2][y-2]==0)
    {
        return true;
    }
    if(x+1>0 && y-1>0 && board[x+1][y-1]==0)
    {
        return true;
    }
    //判断x,y右上方俩个位置是否为空
    if(x-2>0 &&y+2>0 && board[x-2][y+2]==0)
    {
        return true;
    }
    if(x-1>0 && y+1>0 && board[x-1][y+1]==0)
    {
        return true;
    }
    //判断x,y左下方俩个位置是否为空
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

//判断棋盘是否已满
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

//判断黑方是否赢了
bool IsBlackWin(int x,int y)
{
    int countBlack = 1;
    //int countWhite = 1;
    int k,l;
    //从横、竖、左斜、右斜四个方向来算是不是已经六连
    //横
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
    //竖
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
    //左斜
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
    //右斜
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

//判断白方是否赢了
bool IsWhiteWin(int x,int y)
{
    //int countBlack = 1;
    int countWhite = 1;
    int k,l;
    //从横、竖、左斜、右斜四个方向来算是不是已经六连
    //横
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
    //竖
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
    //左斜
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
    //右斜
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

//估值函数
/*int Value()
{
    int i,j,k;
    int number;
    int score;
    int NumberOfMyRoad[7];
    int NumberOfEnemyRoad[7];
    int ScoreOfRoad[7];

    //给每条路赋值
    ScoreOfRoad[0] = 0;
    ScoreOfRoad[1] = 20;
    ScoreOfRoad[2] = 80;
    ScoreOfRoad[3] = 150;
    ScoreOfRoad[4] = 800;
    ScoreOfRoad[5] = 1000;
    ScoreOfRoad[6] = 10000;   //六连的时候就象征着赢棋，用10000表示

    //初始化双方数组
    for(k=0;k<7;k++)
    {
        NumberOfMyRoad[k] = 0;
        NumberOfEnemyRoad[k] = 0;
    }

    //横向
    for(i=0;i<19;i++)
    {
        for(j=0;j<14;j++)
        {
            number = board[i][j]+board[i][j+1]+board[i][j+2]+board[i][j+3]+board[i][j+4]+board[i][j+5];
            if(number == 0 || (number>6 && number%7 != 0)) //number==0表示没有棋子，大于6还不能被7整除就说明同时有黑棋和白棋
            {
                continue;
            }
            if(number<7)
            {
                NumberOfEnemyRoad[number]++;    //side==1方的路数
            }
            else
            {
                NumberOfMyRoad[number/7]++;      //side==7方的路数
            }
        }
    }

    //纵向
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

    //左斜
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

    //右斜
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

    //算最终的分数
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
//αβ剪枝算法
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

//机机对战
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
