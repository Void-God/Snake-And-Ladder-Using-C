#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int BLUE=-1,GREEN=-1,RED=-1,YELLOW=-1;  //tokens

int H[] = {17,54,64,62,87,93,95};    //snake's head
int T[] = {7,26,41,19,36,5,75};   //snake's tail

int B[] = {4,8,9,21,47,72,80};   //ladder's bottom
int Tp[] = {37,14,31,42,84,91,99};   //ladder's top

int num=0;

void gameBoard() { //show the game board (snake and ladders)
    int i,j,k=100;
    printf("\n");
    for(i=0;i<10;i++) {
        for(j=0;j<10;j++)
            printf(" -----");
        printf("\n");
        for(j=0;j<10;j++) {
            printf("|");
            if(BLUE == k){
                printf("  B  ");
                if(i%2==0){
                    if(k%10 == 1)
                        k -= 10;
                    else
                        k--;
                }
                else {
                    if(k%10 == 0)
                        k -= 10;
                    else
                        k++;
                }
            }
            else if(GREEN == k){
                printf("  G  ");
                if(i%2==0){
                    if(k%10 == 1)
                        k -= 10;
                    else
                        k--;
                }
                else {
                    if(k%10 == 0)
                        k -= 10;
                    else
                        k++;
                }
            }
            else if(RED == k){
                printf("  R  ");
                if(i%2==0){
                    if(k%10 == 1)
                        k -= 10;
                    else
                        k--;
                }
                else {
                    if(k%10 == 0)
                        k -= 10;
                    else
                        k++;
                }
            }
            else if(YELLOW == k){
                printf("  Y  ");
                if(i%2==0){
                    if(k%10 == 1)
                        k -= 10;
                    else
                        k--;
                }
                else {
                    if(k%10 == 0)
                        k -= 10;
                    else
                        k++;
                }
            }
            else if(checkSnake(k) != -1){
                printf(" SH%d ",checkSnake(k));
                if(i%2==0){
                    if(k%10 == 1)
                        k -= 10;
                    else
                        k--;
                }
                else {
                    if(k%10 == 0)
                        k -= 10;
                    else
                        k++;
                }
            }
            else if(checkLadder(k) != -1){
                printf(" LB%d ",checkLadder(k));
                if(i%2==0){
                    if(k%10 == 1)
                        k -= 10;
                    else
                        k--;
                }
                else {
                    if(k%10 == 0)
                        k -= 10;
                    else
                        k++;
                }
            }
            else if(snakeTail(k) != -1){
                printf("  S%d ",snakeTail(k));
                if(i%2==0){
                    if(k%10 == 1)
                        k -= 10;
                    else
                        k--;
                }
                else {
                    if(k%10 == 0)
                        k -= 10;
                    else
                        k++;
                }
            }
            else if(ladderTop(k) != -1){
                printf("  L%d ",ladderTop(k));
                if(i%2==0){
                    if(k%10 == 1)
                        k -= 10;
                    else
                        k--;
                }
                else {
                    if(k%10 == 0)
                        k -= 10;
                    else
                        k++;
                }
            }
            else if(k==100) {
                printf(" WIN ");
                k--;
            }
            else if(i%2==0){
                printf(" %d  ",k);
                if(k%10 == 1)
                    k -= 10;
                else
                    k--;
            }
            else {
                if(i==9&&j<9)
                    printf("  %d  ",k);
                else
                    printf(" %d  ",k);
                if(k%10 == 0)
                    k -= 10;
                else
                    k++;
            }

        }
        printf("|\n");
    }
    for(i=0;i<10;i++)
        printf(" -----");
}
int checkSnake(int position) { //check for snakes
    int i;
    for(i=0;i<7;i++){
        if(position == H[i]){
            return i;
        }
    }
    return -1;
}
int checkLadder(int position) { //check for ladder
    int i;
    for(i=0;i<7;i++) {
        if(position == B[i]){
            return i;
        }
    }
    return -1;
}
int snakeTail(int position) {
    int i;
    for(i=0;i<7;i++) {
        if(position == T[i]){
            return i;
        }
    }
    return -1;
}
int ladderTop(int position) {
    int i;
    for(i=0;i<7;i++) {
        if(position == Tp[i]){
            return i;
        }
    }
    return -1;
}
int endOfGame() {
    if(BLUE==100){
        printf("\n\n====BLUE WINS!====");
        return 1;
    }
    else if(GREEN==100){
        printf("\n\n====GREEN WINS!====");
        return 2;
    }
    else if(RED==100){
        printf("\n\n====RED WINS!====");
        return 3;
    }
    else if(YELLOW==100){
        printf("\n\n====YELLOW WINS!====");
        return 4;
    }
    return 0;
}
void play(int *ptr){
    int dice;
    printf("\nEnter to roll the dice :");
    getchar();
    dice = (rand()%6)+1;
    printf("\nDICE SHOWED : %d",dice);
    if(*ptr != -1 && checkSnake(*ptr+dice) != -1){
        printf("\nYOU HAVE STUMBLED UPON SNAKE\n");
        *ptr = T[checkSnake(*ptr+dice)];
    }
    else if(*ptr != -1 && checkLadder(*ptr+dice) != -1){
        printf("\nA LADDER!\n");
        *ptr = Tp[checkLadder(*ptr+dice)];
        num--;
        printf("\nYOUR TURN AGAIN!\n");
    }
    else {
        if(*ptr==-1 && dice !=6){
            printf("\nNEED A 6 TO START");
        }
        else if(*ptr==-1 && dice == 6){
            *ptr = 1;
            num--;
        }
        else if(*ptr+dice > 100){
            printf("\nYOU NEED %d TO WIN THIS GAME!",100-*ptr);
        }
        else if(dice == 6){
            *ptr += 6;
            num--;
            printf("\nYOUR TURN AGAIN!");
        }
        else {
            *ptr += dice;
        }
    }
}
int main()
{
    int n;
    srand(time(0));
    printf("\n->SH use for snake's head");
    printf("\n->S use for snake's tail");
    printf("\n->LB for ladder's bottom");
    printf("\n->L for ladder's top\n\n\n");
    gameBoard();
    printf("\nEnter the number of player : ");
    scanf("%d",&n);
    getchar();
    while(1) {
        if(num%n==0){
            printf("\n\nBlue's Turn \n");
            play(&BLUE);
            if(BLUE != -1){
                printf("\nBLUE : %d",BLUE);
            }
        }
        else if(num%n==1){
            printf("\n\nGreen's Turn \n");
            play(&GREEN);
            if(GREEN != -1){
                printf("\n\nGREEN : %d",GREEN);
            }

        }
        else if(num%n==2) {
            printf("\n\nRed's Turn \n");
            play(&RED);
            if(RED != -1){
                printf("\nRED : %d",RED);
            }
        }
        else {
            printf("\n\nYellow's Turn \n");
            play(&YELLOW);
            if(YELLOW != -1){
                printf("\nYELLOW : %d",YELLOW);
            }
        }
        gameBoard();
        if(endOfGame()){
            printf("\n\nGame End!!!!");
            break;
        }
        num++;

    }

    return 0;
}
