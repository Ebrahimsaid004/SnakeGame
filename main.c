#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

unsigned int width =20;
unsigned int length =20;
unsigned int GameOver;
unsigned int X;
unsigned int Y;
unsigned int Score;
unsigned int Flag;
unsigned int F_x;
unsigned int F_y;
unsigned int Tail_X[100];
unsigned int Tail_Y[100];
unsigned int Counter_s;
unsigned int K;

void initializeGame()
{
    GameOver =0;
    X = width/2;
    Y = length/2;

    label1:
    F_x = rand()%20;
    if(0 == F_x)
    {
        goto label1;
    }

    label2:
    F_y = rand()%20;
    if(0 == F_y)
    {
        goto label2;
    }

    Score =0;

}


void drawGame()
{
    unsigned int i = 0;
    unsigned int j = 0;

    system("cls");

    for(i = 0; i < width; i++)
    {

        for(j = 0; j < length; j++)
        {
            if((0 == i)||(i == length-1)||(0 == j)||(j == width-1))
            {
                printf("#");

            }
            else
            {
                if((i == X)&&(j == Y))
                {
                    printf("O");
                }
                else if((i == F_x)&&(j == F_y))
                {
                    printf("F");
                }
                else
                {

                        printf(" ");


                }


            }

        }
        printf("\n");

    }

    printf("SCORE :%d", Score);

}

void INPUT()            // aswd --> move
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'a':
            Flag = 1;
            break;
            case 'd':
            Flag = 2;
            break;
            case 'w':
            Flag = 3;
            break;
            case 's':
            Flag = 4;
            break;
            case 'x':
            GameOver = 1;
            break;

        }

    }


}

void Process()
{

    switch(Flag)
    {
        case 1:
        Y--;
        break;
        case 2:
        Y++;
        break;
        case 3:
        X--;
        break;
        case 4:
        X++;
        break;
        default:
        break;

    }

    if((X < 0)||(X > width)||(Y < 0)||(Y > length))
    {

         GameOver = 1;


    }
    if((X == F_x)&&(Y == F_y))
    {
        label3:
        F_x = rand()%20;
        if(0 == F_x)
        {
            goto label3;
        }

        label4:
        F_y = rand()%20;
        if(0 == F_y)
        {
            goto label4;
        }
        Score+= 10;
    }
}

int main()
{

    char c = 0;
    unsigned int G = 0;
    unsigned int H = 0;
    label5:
    initializeGame();
    while(! GameOver)
    {
        drawGame();
        INPUT();
        Process();
        for(H =0; H <1000;  H++)
        {
            for(G =0; G <10000;  G++)
            {


            }
        }
        for(H =0; H <1000;  H++)
        {
            for(G =0; G <1000;  G++)
            {


            }
        }


    }

    printf("\n---> GameOver \n");
    printf("--->Press The H Continue Again \n");
    scanf("%c", &c);
    if((c == 'h')||(c == 'H'))
    {
        goto label5;
    }


    return 0;
}
