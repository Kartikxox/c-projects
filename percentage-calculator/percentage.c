#include<stdio.h>

int main() {
    float physics, chemistry, english, maths, cs;
    float avg, per;

    printf("Enter the marks for Physics: ");
    scanf("%f", &physics);

    printf("Enter the marks for Chemistry: ");
    scanf("%f", &chemistry);

    printf("Enter the marks for English: ");
    scanf("%f", &english);

    printf("Enter the marks for Maths: ");
    scanf("%f", &maths);

    printf("Enter the marks for CS: ");
    scanf("%f", &cs);

    avg = (physics + chemistry + english + maths + cs) / 5;

    per = ((physics + chemistry + english + maths + cs) / 500) * 100;

    printf("\nAverage Marks: %.2f", avg);
    printf("\nPercentage: %.2f%%\n", per);

    if (per > 80 && per <= 100) {
        printf("Grade A");
    }
    else if (per > 70) {
        printf("Grade B");
    }
    else if (per > 60) {
        printf("Grade C");
    }
    else if (per > 50) {
        printf("Grade D");
    }
    else if (per > 40) {
        printf("Grade E");
    }
    else if (per >= 33) {
        printf("Pass");
    }
    else if (per >= 0) {
        printf("Fail");
    }
    else {
        printf("Enter valid marks!");
    }

    return 0;
}