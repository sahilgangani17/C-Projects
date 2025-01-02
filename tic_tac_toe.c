#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
//#include <graphics.h>
void reset();
void printfboard();
void playermove();
void botmove();
void printfwinner();
void printfirstboard();
int smartbot(char ,int * ,int *);
int checkfreespace();
int checkwinner();

char board[3][3];
char winner= ' ';
const char player = 'X';
const char bot= 'O';

int main()
{
    char wannaplay=' ';
    system("cls");
    system("title Tic Tac Toe");
    fflush(stdout);
    do
    {
        winner=' ';
        wannaplay=' ';
        reset();
        system("cls");
        printfirstboard();
        while (winner==' ' && checkfreespace()!=0)
        {
            printfboard();
            playermove();
            winner=checkwinner();
            if(winner!=' ' || checkfreespace()==0)
                break;
            botmove();
            winner=checkwinner();
            if(winner!=' ' || checkfreespace()==0)
                break;
        }
        printfboard();
        printfwinner();
        // printf("Wanna ride bot more (Y|N): ");
        // fflush(stdin);
        // scanf("%c",&wannaplay);
        // wannaplay=toupper(wannaplay);

        printf("Wanna ride bot more (Y|N): ");
        while ((getchar()) != '\n'); 
        wannaplay = getchar();
        wannaplay = toupper(wannaplay);
    } while (wannaplay=='Y');
    return 0;
}
void reset()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            board[i][j]=' ';
            //printf(" ",board[i][j]);
        }
        printf("\n");
    }
}
void printfirstboard()
{
    printf(" 1 %c 2 %c 3 ",179,179);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,179,196,196,196,179,196,196,196);
    printf(" 4 %c 5 %c 6 ",179,179);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,179,196,196,196,179,196,196,196);
    printf(" 7 %c 8 %c 9 \n",179,179);

}
void printfboard()
{
    printf("\n\n %c %c %c %c %c ",board[0][0],179,board[0][1],179,board[0][2]);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,179,196,196,196,179,196,196,196);
    printf(" %c %c %c %c %c ",board[1][0],179,board[1][1],179,board[1][2]);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,179,196,196,196,179,196,196,196);
    printf(" %c %c %c %c %c \n\n",board[2][0],179,board[2][1],179,board[2][2]);
}
int checkfreespace()
{
    int space=9;
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]!=' ')
            {
                space--;
            }
        }
    }
    return space;
}
int checkwinner()
{
    int i;
    //rows
    for(i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1]&&board[i][0]==board[i][2])
        {
            return board[i][0];
        }
    }
    //column
    for(i=0;i<3;i++)
    {
        if(board[0][i]==board[1][i]&&board[0][i]==board[2][i])
        {
            return board[0][i];
        }
    }
    //diagnol
    if(board[0][0]==board[1][1]&&board[0][0]==board[2][2])
    {
        return board[0][0];
    }
    if(board[0][2]==board[1][1]&&board[0][2]==board[2][0])
    {
        return board[0][2];
    }

    return ' ';
}
void printfwinner()
{
   /*  int x=150,y=150;
    int font 8;
    int direction=0;
    int font_size=5;
    int gd=DETECT ,gm;
    initgraph(&gd,&gm, "C:\\TURBOC3\\BGI");
    settextstyle(font, direction, font_size); */
    if(winner==player)
    {
        //outtextxy(x,y,"YOU ARE WINNER");
        printf("YOU ARE WINNER\n");
    }
       
    else if(winner==bot)
    {
        //outtextxy(x,y,"BOT IS WINNER");
        printf("BOT IS WINNER\n");
    }
    else
    {
        //outtextxy(x,y,"IT'S A TIE");
        printf("ITS A TIE\n");
    }
}
void playermove()
{
    int x,y;
    int element;
    do
    {
        /* printf("\nEnter Row & Column (0-2): ");
        scanf("%d%d",&x,&y); */
        printf("Enter Element: ");
        fflush(stdin);
        scanf("%d",&element);
       /*  switch (element)
        {
        case 1:
            x=0;y=0;
            break;
        case 2:
            x=0;y=1;
            break;
        case 3:
            x=0;y=2;
            break;
        case 4:
            x=1;y=0;
            break;
        case 5:
            x=1;y=1;
            break;
        case 6:
            x=1;y=2;
            break;
        case 7:
            x=2;y=0;
            break;
        case 8:
            x=2;y=1;
            break;
        case 9:
            x=2;y=2;
            break;
         default:
            printf("\nInvalid Input\n");
            break; 
        } */
        x=(element-1)/3;
        y=(element-1)%3; 
        if(board[x][y]!=' ')
        {
            printf("Invalid Move\n");
        }
        else
        {
            board[x][y]=player;
            break;
        }
    } while (board[x][y]!=' ');
}
void botmove()
{
    int x,y;
    srand(time(NULL));
    if(checkfreespace()!=0)
    {
        //Let's Win
        if(smartbot(bot ,&x ,&y))
        {
            board[x][y]=bot;
            return ;
        }
        //block player
        if(smartbot(player, &x ,&y))
        {
            board[x][y]=bot;
            return ;
        }
        //check for corner
        if(board[0][0]==' ')
        {
            board[0][0]=bot;
            return ;
        }
        if(board[0][2]==' ')
        {
            board[0][2]=bot;
            return ;
        }
        if(board[2][0]==' ')
        {
            board[2][0]=bot;
            return ;
        }
        if(board[2][2]==' ')
        {
            board[2][2]=bot;
            return ;
        }
        //First Random Move
        do
        {
            x=rand()%3;
            y=rand()%3;
        } while (board[x][y]!=' ');
        board[x][y]=bot;  
    }
}
int smartbot(char sign,int *x ,int *y)
{
    int i;
    //rows
    for(i=0;i<3;i++)
    {
        if(board[i][0]==sign && board[i][1]==sign && board[i][2]==' ')
        {
            *x=i;
            *y=2;
            return 1;
        }
        if(board[i][0]==sign && board[i][2]==sign && board[i][1]==' ')
        {
            *x=i;
            *y=1;
            return 1;
        }
        if(board[i][1]==sign && board[i][2]==sign && board[i][0]==' ')
        {
            *x=i;
            *y=0;
            return 1;
        }
    }
    //column
    for(i=0;i<3;i++)
    {
        if(board[0][i]==sign && board[1][i]==sign && board[2][i]==' ')\
        {
            *x=2;
            *y=i;
            return 1;
        }
        if(board[0][i]==sign && board[2][i]==sign && board[1][i]==' ')
        {
            *x=1;
            *y=i;
            return 1;
        }
        if(board[2][i]==sign && board[1][i]==sign && board[0][i]==' ')
        {
            *x=0;
            *y=i;
            return 1;
        }
    }
    //diagnoal
    for(i=0;i<3;i++)
    {
        if(board[0][0]==sign && board[1][1]==sign && board[2][2]==' ')
        {
            *x=2;
            *y=2;
            return 1;
        }
        if(board[0][0]==sign && board[2][2]==sign && board[1][1]==' ')
        {
            *x=1;
            *y=1;
            return 1;
        }
        if(board[2][2]==sign && board[1][1]==sign && board[0][0]==' ')
        {
            *x=0;
            *y=0;
            return 1;
        }
    }
    return 0;
}