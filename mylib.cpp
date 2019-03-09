#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include <windows.h>
int Uniformrand(int lb,int ub)
{
    return rand()%(ub-lb+1)+lb;
}

void set_console_color(unsigned short color_index)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_index);
}
void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos;
    scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
}
void peoplemove(char ch,int *x1, int *y1)
{
    set_console_color(11);

    if(GetAsyncKeyState(VK_UP))
    {


        if(*y1>1)
        {
            gotoxy(*x1,*y1);
            printf(" ");
            *y1=*y1-1;
            gotoxy(*x1,*y1);
            printf("@");
        }

    }
   if(GetAsyncKeyState(VK_DOWN))
    {
        if(*y1<15)
        {
            gotoxy(*x1,*y1);
            printf(" ");
            *y1=*y1+1;
            gotoxy(*x1,*y1);
            printf("@");
        }


    }
    if(GetAsyncKeyState(VK_LEFT))
    {
        if(*x1>2)
        {
            gotoxy(*x1,*y1);
            printf(" ");
            *x1=*x1-1;
            gotoxy(*x1,*y1);
            printf("@");
        }

    }
    if(GetAsyncKeyState(VK_RIGHT))
    {
        if(*x1<27)
        {
            gotoxy(*x1,*y1);
            printf(" ");
            *x1=*x1+1;
            gotoxy(*x1,*y1);
            printf("@");
        }
    }
}

void peoplemove2(char ch,int *x2,int *y2)
{
    set_console_color(11);

    if(GetAsyncKeyState(VK_NUMPAD8))
    {
        if(*y2>1)
        {
            gotoxy(*x2,*y2);
            printf(" ");
            *y2=*y2-1;
            gotoxy(*x2,*y2);
            printf("@");
        }


    }
    if(GetAsyncKeyState(VK_NUMPAD5))
    {
        if(*y2<15)
        {
            gotoxy(*x2,*y2);
            printf(" ");
            *y2=*y2+1;
            gotoxy(*x2,*y2);
            printf("@");
        }


    }
    if(GetAsyncKeyState(VK_NUMPAD4))
    {
        if(*x2>29)
        {
            gotoxy(*x2,*y2);
            printf(" ");
            *x2=*x2-1;
            gotoxy(*x2,*y2);
            printf("@");
        }
    }
    if(GetAsyncKeyState(VK_NUMPAD6))
    {
        if(*x2<55)
        {
            gotoxy(*x2,*y2);
            printf(" ");
            *x2=*x2+1;
            gotoxy(*x2,*y2);
            printf("@");
        }

    }

}
void moveball(int **xpos, int **ypos,int x,int y)
{

    gotoxy(**xpos,**ypos);
    printf(" ");
    **xpos+=x;
    **ypos+=y;
    set_console_color(14);
    gotoxy(**xpos,**ypos);
    printf("O");
    Sleep(150);

}

void hit_ball(int x1,int y1,int *x,int *y,int *move,int x2,int y2,int *score1,int *score2)
{
    int xmax=55,xmin=3,ymax=15,ymin=1;

    switch(*move)
    {
    case 1://右
        if(*x<xmax && *x>=xmin && *y>=ymin && *y<=ymax)
        {
            moveball(&x,&y,1,0);
        }
        if(*x==xmax)
        {
            moveball(&x,&y,-1,0);
            *move=2;
        }
        break;
    case 2://左
        if(*x<=xmax && *x>xmin && *y>=ymin && *y<=ymax)
        {
            moveball(&x,&y,-1,0);
        }
        if(*x==xmin)
        {
            moveball(&x,&y,1,0);
            *move=1;
        }
        break;
    case 3://下
        if(*x<=xmax && *x>=xmin && *y>=ymin && *y<ymax)
        {
            moveball(&x,&y,0,1);
        }
        if(*y==ymax)
        {
            moveball(&x,&y,0,-1);
            *move=4;
        }
        break;
    case 4://上
        if(*x<=xmax && *x>=xmin && *y>ymin && *y<=ymax)
        {
            moveball(&x,&y,0,-1);
        }
        if(*y==ymin)
        {
            moveball(&x,&y,0,1);
            *move=3;
        }
        break;
    case 5://左上
        if(*x<=xmax && *x>xmin && *y>ymin && *y<=ymax)
        {
            moveball(&x,&y,-1,-1);
        }
        if(*x==xmin&&*y==ymin)
        {
            moveball(&x,&y,1,1);
            *move=8;
        }
        if(*y==ymin)
        {
            moveball(&x,&y,-1,1);
            *move=6;
        }
        if(*x==xmin)
        {
            moveball(&x,&y,1,-1);
            *move=7;
        }
        break;
    case 6://左下
        if(*x<=xmax && *x>xmin && *y>=ymin && *y<ymax)
        {
            moveball(&x,&y,-1,1);
        }
        if(*x==xmin&&*y==ymax)
        {
            moveball(&x,&y,1,-1);
            *move=7;
        }
        if(*y==ymax)
        {
            moveball(&x,&y,-1,-1);
            *move=5;
        }
        if(*x==xmin)
        {
            moveball(&x,&y,1,1);
            *move=8;
        }
        break;
    case 7://右上
        if(*x<xmax && *x>=xmin && *y>ymin && *y<=ymax)
        {
            moveball(&x,&y,1,-1);
        }
        if(*x==xmax&&*y==ymin)
        {
            moveball(&x,&y,-1,1);
            *move=6;
        }
        if(*y==ymin)
        {
            moveball(&x,&y,1,1);
            *move=8;
        }
        if(*x==xmax)
        {
            moveball(&x,&y,-1,-1);
            *move=5;
        }
        break;
    case 8://右下
        if(*x<xmax && *x>=xmin && *y>=ymin && *y<ymax)
        {
            moveball(&x,&y,1,1);
        }
        if(*x==xmax&&*y==ymax)
        {
            moveball(&x,&y,-1,-1);
            *move=5;
        }
        if(*y==ymax)
        {
            moveball(&x,&y,1,-1);
            *move=7;
        }
        if(*x==xmax)
        {
            moveball(&x,&y,-1,1);
            *move=6;
        }
        break;
    }
    if((x1==*x-1&&y1==*y) || (x2==*x-1&&y2==*y))
    {

        if(*x<57 && *x>2 && *y>1 && *y<15)
        {
            moveball(&x,&y,1,0);
            *move=1;
        }


    }
    else if((x1==*x+1&&y1==*y)|| (x2==*x+1&&y2==*y))
    {
        if(*x<57 && *x>2 && *y>1 && *y<15)
        {
            moveball(&x,&y,-1,0);
            *move=2;
        }
    }
    else if((y1==*y-1&&x1==*x)||(y2==*y-1&&x2==*x))
    {
        if(*x<57 && *x>2 && *y>1 && *y<15)
        {
            moveball(&x,&y,0,1);
            *move=3;
        }
    }

    else if((y1==*y+1&&x1==*x)||(y2==*y+1&&x2==*x))
    {
        if(*x<57 && *x>2 && *y>1 && *y<15)
        {
            moveball(&x,&y,0,-1);
            *move=4;
        }
    }
    else if((y1==*y+1&&x1==*x+1)||(y2==*y+1&&x2==*x+1))
    {
        if(*x<57 && *x>2 && *y>1 && *y<15)
        {
            moveball(&x,&y,-1,-1);
            *move=5;
        }
    }
    else if((y1==*y-1&&x1==*x+1)||(y2==*y-1&&x2==*x+1))
    {
        if(*x<57 && *x>2 && *y>1 && *y<15)
        {
            moveball(&x,&y,-1,1);
            *move=6;
        }
    }
    else if((y1==*y+1&&x1==*x-1)||(y2==*y+1&&x2==*x-1))
    {
        if(*x<57 && *x>2 && *y>1 && *y<15)
        {
            moveball(&x,&y,1,-1);
            *move=7;
        }
    }
    else if((y1==*y-1&&x1==*x-1)||(y2==*y-1&&x2==*x-1))
    {
        if(*x<57 && *x>2 && *y>1 && *y<15)
        {
            moveball(&x,&y,1,1);
            *move=8;
        }
    }
}
void rule()
{
    gotoxy(7,7);
    printf("遊戲玩法:\n"
           "           左方玩家: 上、下、左、右\n"
           "           右方玩家:  8、 5、 6、 4(右邊的鍵盤)\n");
    printf("                                    ");
    system("pause");
    system("cls");
    gotoxy(7,7);
    printf("遊戲規則與說明:(重要)\n"
           "            一開始，大家都有急速搶球的時間，開球後，速度會變回來。\n"
           "            將球拍碰到球即可讓球移動，若球直直的進到了對方洞口，\n"
           "            則得'2'分，側面進入則得'1'分。先得到'6'分的人即獲勝。\n");
    set_console_color(11);
    printf("            在球移動的同時，請隨時移動你的球拍，確保遊戲能夠進行下去。\n");
    set_console_color(7);
    printf("                                    ");
}
void rule_to_computer()
{
    gotoxy(7,7);
    printf("遊戲玩法:\n"
           "           玩家: 上、下、左、右\n");
    printf("                                    ");
    system("pause");
    system("cls");
    gotoxy(7,7);
    printf("遊戲規則與說明:(重要)\n"
           "            一開始，大家都有急速搶球的時間，開球後，速度會變回來。\n"
           "            將球拍碰到球即可讓球移動，若球直直的進到了對方洞口，\n"
           "            則得'2'分，側面進入則得'1'分。先得到'6'分的人即獲勝。\n");
    set_console_color(11);
    printf("            在球移動的同時，請隨時移動你的球拍，確保遊戲能夠進行下去。\n");
    set_console_color(2);
    printf("            惡夢級電腦極度困難，請先練好再來挑戰!\n");
    set_console_color(7);
    printf("                                    ");
}
void computermove(int *x2, int *y2)
{
    for(int i=0; i<=4; i++)
    {
        for(int j=0; j<=6; j++)
        {
            gotoxy(51+i,6+j);
            printf(" ");
        }
    }
    *x2=Uniformrand(51,55);
    *y2=Uniformrand(6,10);
    gotoxy(*x2,*y2);
    printf("@");


}
