#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand( time(NULL));

    int guess=0;
    int tries=0;
    int min=1;
    int max=100;
    int answer = (rand()%(max-min+1))+min;

    printf("********Number guess Game*********");
    do{

        printf("Guess number between %d - %d : ",min,max);
        scanf("%d",&guess);
        tries++;

        if(guess<answer){
            printf("Too low");
        }
        else if(guess>answer){
            printf("High!"); 
        }
        else{
            printf("Correc!!!");
        }

    }while(guess != answer);
    printf("Answer is %d\n",answer);

    printf("It took you %d tries\n",tries);
    return 0;
}