#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int player, bot;
int pts_palyer=0,pts_bot=0,pts_draw=0;
void comp();
void menu();
int logic();
enum game { rock=1, paper=2, scissors=3};
int logic()
{
    if((player==rock && bot==scissors) || (player==paper && bot==rock) ||  ( player==scissors && bot==paper))
    {
        pts_palyer++;
        return 0;
    }
    else if (player==bot)
    {
        pts_draw++;
        return 1;
    }    
    else
    { 
        pts_bot++;
        return 2;
    }
}
void menu()
{
    start: 
   // system("cls");
    printf("PRESS (1) FOR ROCK \n");
    printf("PRESS (2) FOR PAPER \n");
    printf("PRESS (3) FOR SCISSORS \n");
   // printf("PRESS (4) To EXIT \n");
    printf("ENTER YOUR CHOICE: ");
    do
    {
    scanf("%d",&player);
    if(player>3 || player<0)
    {
        printf("INVALID INPUT\n");
        system("pause");
        goto start;
    }
    }while(player>5 || player<0);
}
void comp()
{
    srand(time(NULL));
    /* label:
    bot=rand()%4;
    if(bot==0)
        goto label; */
    bot=rand()%3+1;    //  / %
    menu(); 
}
int main()
{
    fflush(stdout);
    int round;
    system("cls");
    printf("ENTER NO OF ROUND: ");
    scanf("%d",&round);
    for(int i=1;i<=round;i++)
    {
        printf("\n\nROUND #%d\n",i);

    //while(1)
   // {
        start:
      //  system("cls");
        comp();
       /*  if(player==4)
            return 0; */
        int final=logic();
        printf("BOT = %d\n",bot);
        switch (final)
        {
        case 0:
            printf("YOU WON\n");
            break;
        case 2:
            printf("COMPUTER WON\n");
            break;
        case 1:
            printf("DRAW\n");
            break;
        }
        //system("pause");
   // }
    }
   // system("cls");
   system("pause");
   printf("RESULT\n");
    printf("__________________________________________________________\n");
        printf("DRAW = %d\n",pts_draw);
        printf("PLAYER = %d\n",pts_palyer);
        printf("BOT = %d\n",pts_bot);
        if(pts_palyer > (pts_bot || pts_draw))
        {
            printf("YOU WON\n");
        }
        else if(pts_bot> (pts_palyer || pts_draw))
        {
            printf("COMPUTER WON\n");
        }
        else
        {
            printf("DRAW\n");
        }
   // getchar();
   system("pause");
    return 0;
}