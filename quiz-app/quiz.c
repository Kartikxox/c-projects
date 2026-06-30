#include<stdio.h>

int main(){

    char questions[][100] = {"WHat is the largest planet in the solar system?",
                             "What is the hottest planet ?",
                            "Which language is primarily used for system programming?",
                            "Who developed the C programming language?"};

    char options[][100] = {"A. Jupiter\nB. Mars\nC. Uranus\nD. Earth",
    "A. Mercury\nB. Venus\nC. Earth\nD. Mars",
    "A. Python\nB. Java\nC. C\nD. HTML",
    "A. Dennis Ritchie\nB. Bjarne Stroustrup\nC. James Gosling\nD. Guido van Rossum"};

    char answerkey[] = {'A','B','C','A'};

        int questioncount = sizeof(questions)/sizeof(questions[0]);

        char guess = '\0';
        int score = 0;

        printf("*******Quiz Game**********");

        for(int i=0;i<questioncount;i++){
            printf("%s\n",questions[i]);
            printf("%s\n",options[i]);
            printf("\nEnter the answer option: ");
            scanf(" %c",&guess);
        
            if(guess==answerkey[i]){
                printf("Correct !");
                score++;
            }else{
                printf("Wrong !");
            }
        
        }

        printf("\nYour score is %d out of %d",score,questioncount);

   return 0;
}