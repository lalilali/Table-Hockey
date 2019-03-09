#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include <windows.h>
#include"mylib.h"
#include"place.h"
int main()
{
    int y=12;
    char ch;


    set_console_color(10);
    gotoxy(30,0);
    printf("Table Hockey\n");

    gotoxy(31,12);
    set_console_color(4);
    printf("¡÷-Start-¡¹");
    gotoxy(31,14);
    set_console_color(7);
    printf("  -Exit-");

    do
    {
        ch=getch();
        if(ch==72)
        {
            if(y-2==12)
            {
                gotoxy(31,12);
                set_console_color(4);
                printf("¡÷-Start-¡¹");
                gotoxy(31,14);
                set_console_color(7);
                printf("  -Exit-  ");
                y=y-2;
            }
        }
        if(ch==80)
        {
            if(y+2==14)
            {
                gotoxy(31,14);
                set_console_color(4);
                printf("¡÷-Exit-¡¹");
                gotoxy(31,12);
                set_console_color(7);
                printf("  -Start-  ");
                y=y+2;
            }
        }
    }
    while(ch!=13);
    system("cls");
    if(y==12)
    {
        gotoxy(25,12);
        set_console_color(4);
        printf("Player  v.s  Player");
        gotoxy(20,14);
        set_console_color(7);
        printf("Player  v.s  Nightmare Computer");
        do
        {
            ch=getch();
            if(ch==72)
            {
                if(y-2==12)
                {
                    gotoxy(25,12);
                    set_console_color(4);
                    printf("Player  v.s  Player");
                    gotoxy(20,14);
                    set_console_color(7);
                    printf("Player  v.s  Nightmare Computer");
                    y=y-2;
                }
            }
            if(ch==80)
            {
                if(y+2==14)
                {
                    gotoxy(20,14);
                    set_console_color(4);
                    printf("Player  v.s  Nightmare Computer");
                    gotoxy(25,12);
                    set_console_color(7);
                    printf("Player  v.s  Player");
                    y=y+2;
                }
            }
        }
        while(ch!=13);
        system("cls");
    }
    else
    {
        return 0;
    }


    if(y==12)
    {
        rule();
        system("pause");
        system("cls");
        int x1=2,y1=8,xball=28,yball=8,score1=0,score2=0;
        int x2=55,y2=8;
        int move=0;
        map();

        set_console_color(11);
        gotoxy(x1,y1);
        printf("@");
        gotoxy(x2,y2);
        printf("@");

        set_console_color(14);
        gotoxy(xball,yball);
        printf("O");

        set_console_color(7);
        gotoxy(26,20);
        printf("score");
        gotoxy(23,20);
        printf("%d",score1);
        gotoxy(34,20);
        printf("%d",score2);



        do
        {
            if((xball==54&&yball==7) || (xball==54&&yball==8) || (xball==54&&yball==9))
            {
                score1+=1;
                gotoxy(23,20);
                printf("%d",score1);
            }
            if((xball==4&&yball==7)|| (xball==4&&yball==8) || (xball==4&&yball==9))
            {
                score2+=1;
                gotoxy(34,20);
                printf("%d",score2);
            }
            peoplemove(ch,&x1,&y1);
            peoplemove2(ch,&x2,&y2);
            hit_ball(x1,y1,&xball,&yball,&move,x2,y2,&score1,&score2);
            peoplemove(ch,&x1,&y1);
            peoplemove2(ch,&x2,&y2);

            if(xball<=30 && xball>=26)
            {
                gotoxy(0,0);
                map();

                set_console_color(11);
                gotoxy(x1,y1);
                printf("@");
                gotoxy(x2,y2);
                printf("@");

                set_console_color(14);
                gotoxy(xball,yball);
                printf("O");

                set_console_color(7);
                gotoxy(26,20);
                printf("score");
                gotoxy(23,20);
                printf("%d",score1);
                gotoxy(34,20);
                printf("%d",score2);

            }


        }
        while(score1<6&&score2<6);
        system("cls");

        if(score1>=6)
        {
            gotoxy(25,6);
            printf("Congratulaions! Player1 wins!!");
            gotoxy(32,12);
            set_console_color(4);
            printf("Back to main menu");
            gotoxy(38,14);
            set_console_color(7);
            printf("Exit");
            do
            {
                ch=getch();
                if(ch==72)
                {
                    if(y-2==12)
                    {
                        gotoxy(32,12);
                        set_console_color(4);
                        printf("Back to main menu");
                        gotoxy(38,14);
                        set_console_color(7);
                        printf("Exit");
                        y=y-2;
                    }
                }
                if(ch==80)
                {
                    if(y+2==14)
                    {
                        gotoxy(38,14);
                        set_console_color(4);
                        printf("Exit");
                        gotoxy(32,12);
                        set_console_color(7);
                        printf("Back to main menu");
                        y=y+2;
                    }
                }
            }
            while(ch!=13);
            if(y==12)
            {
                system("cls");
                main();
            }

        }
        else
        {
            printf("Congratulaions! Player2 wins!!");
            gotoxy(32,12);
            set_console_color(4);
            printf("Back to main menu");
            gotoxy(38,14);
            set_console_color(7);
            printf("Exit");
            do
            {
                ch=getch();
                if(ch==72)
                {
                    if(y-2==12)
                    {
                        gotoxy(32,12);
                        set_console_color(4);
                        printf("Back to main menu");
                        gotoxy(38,14);
                        set_console_color(7);
                        printf("Exit");
                        y=y-2;
                    }
                }
                if(ch==80)
                {
                    if(y+2==14)
                    {
                        gotoxy(38,14);
                        set_console_color(4);
                        printf("Exit");
                        gotoxy(32,12);
                        set_console_color(7);
                        printf("Back to main menu");
                        y=y+2;
                    }
                }
            }
            while(ch!=13);
            if(y==12)
            {
                system("cls");
                main();
            }
        }
        return 0;

    }
    if(y==14)
    {
        rule_to_computer();
        system("pause");
        system("cls");
        int x1=2,y1=8,xball=28,yball=8,score1=0,score2=0;
        int x2=55,y2=8;
        int move=0;
        map();
        set_console_color(11);
        gotoxy(x1,y1);
        printf("@");
        gotoxy(x2,y2);
        printf("@");

        set_console_color(14);
        gotoxy(xball,yball);
        printf("O");

        set_console_color(7);
        gotoxy(26,20);
        printf("score");
        gotoxy(23,20);
        printf("%d",score1);
        gotoxy(34,20);
        printf("%d",score2);
        do
        {

            peoplemove(ch,&x1,&y1);
            computermove(&x2,&y2);
            hit_ball(x1,y1,&xball,&yball,&move,x2,y2,&score1,&score2);
            if((xball==54&&yball==7) || (xball==54&&yball==8) || (xball==54&&yball==9))
            {
                score1+=1;
                gotoxy(23,20);
                printf("%d",score1);
            }
            if((xball==4&&yball==7)|| (xball==4&&yball==8) || (xball==4&&yball==9))
            {
                score2+=1;
                gotoxy(34,20);
                printf("%d",score2);
            }
            if(xball<=30 && xball>=26)
            {
                gotoxy(0,0);
                map();

                set_console_color(11);
                gotoxy(x1,y1);
                printf("@");
                gotoxy(x2,y2);
                printf("@");

                set_console_color(14);
                gotoxy(xball,yball);
                printf("O");

                set_console_color(7);
                gotoxy(26,20);
                printf("score");
                gotoxy(23,20);
                printf("%d",score1);
                gotoxy(34,20);
                printf("%d",score2);

            }



        }
        while(score1<6 && score2<6);
        if(score1>=6)
        {
            gotoxy(25,6);
            printf("Congratulaions! You win!!");
            gotoxy(32,12);
            set_console_color(4);
            printf("Back to main menu");
            gotoxy(38,14);
            set_console_color(7);
            printf("Exit");
            do
            {
                ch=getch();
                if(ch==72)
                {
                    if(y-2==12)
                    {
                        gotoxy(32,12);
                        set_console_color(4);
                        printf("Back to main menu");
                        gotoxy(38,14);
                        set_console_color(7);
                        printf("Exit");
                        y=y-2;
                    }
                }
                if(ch==80)
                {
                    if(y+2==14)
                    {
                        gotoxy(38,14);
                        set_console_color(4);
                        printf("Exit");
                        gotoxy(32,12);
                        set_console_color(7);
                        printf("Back to main menu");
                        y=y+2;
                    }
                }
            }
            while(ch!=13);
            if(y==12)
            {
                system("cls");
                main();
            }
        }
        else
        {
            printf("Sorry, you lose! You better try hard!");
            gotoxy(32,12);
            set_console_color(4);
            printf("Back to main menu");
            gotoxy(38,14);
            set_console_color(7);
            printf("Exit");
            do
            {
                ch=getch();
                if(ch==72)
                {
                    if(y-2==12)
                    {
                        gotoxy(32,12);
                        set_console_color(4);
                        printf("Back to main menu");
                        gotoxy(38,14);
                        set_console_color(7);
                        printf("Exit");
                        y=y-2;
                    }
                }
                if(ch==80)
                {
                    if(y+2==14)
                    {
                        gotoxy(38,14);
                        set_console_color(4);
                        printf("Exit");
                        gotoxy(32,12);
                        set_console_color(7);
                        printf("Back to main menu");
                        y=y+2;
                    }
                }
            }
            while(ch!=13);
            if(y==12)
            {
                system("cls");
                main();
            }


        }
    }



    return 0;
}
