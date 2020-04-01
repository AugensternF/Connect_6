#include"aifengminconnect6.h"

//菜单
void menu()
{
    int choice;
    while(true)
    {
        printf("1.ManToMan\n");
        printf("2.ComputerToComputer\n");
        printf("请输入想要玩儿的模式：\t");
        scanf("%d",&choice);
        if(choice<1||choice>2)
        {
            printf("请选择已有模式!\n\n");
        }
        else
        {
            switch(choice)
            {
            case 1:
                {
                    PlayManToMan();
                    break;
                }
            case 2:
                {
                    //PlayComputerToComputer();
                    break;
                }
            }
        }
    }
}

//主函数
int main()
{
    initwindow(600,600,"Connect6");
    Init();
    menu();
    system("pause");
    return 0;
}
