#include"aifengminconnect6.h"

//�˵�
void menu()
{
    int choice;
    while(true)
    {
        printf("1.ManToMan\n");
        printf("2.ComputerToComputer\n");
        printf("��������Ҫ�����ģʽ��\t");
        scanf("%d",&choice);
        if(choice<1||choice>2)
        {
            printf("��ѡ������ģʽ!\n\n");
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

//������
int main()
{
    initwindow(600,600,"Connect6");
    Init();
    menu();
    system("pause");
    return 0;
}
