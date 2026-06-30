#include<stdio.h>

void checkbalance(float balance);
float deposit();
float withdraw();


int main(){

int choice = 0.0;
float balance = 0.0f;

printf("***Welcome to the bank***");


do{
    printf("\nSelect an option\n");
    printf("\n 1. Check Balance\n");
    printf("2.Deposit Balance\n");
    printf("3.Withdraw Balance\n");
    printf("4.Exit\n");
    printf("Enter choice: \n");
    scanf("%d",&choice);

    switch(choice){
        case 1: 
        checkbalance(balance);
        break;

        case 2:
        balance += deposit();
        break;
        
        case 3:
        balance -= deposit();
        break;

        case 4:
        printf("Thank you for using the bank !");
        break;
        default:
            printf("\nInvalid choice !");

    }



}while(choice !=4);
    return 0;
}

void checkbalance(float balance){

    printf("\nYour current Balance is : $%.2f\n",balance);

}
float deposit(){
float amount = 0.0f;
printf("\nEnte amount to deposit: $");
scanf("%f",&amount);

if(amount<0){
    printf("\nEnter valid amount");
    return 0.0f;
}else{
    printf("Succesfully deposited $%.2f",amount);
}

return amount;
}

float withdraw(float balance){
float amount = 0.0f;

printf("\nEnter amount to be withdraw: $");
scanf("%f",&amount);

if(amount<0){
    printf("\nInvalid amount");
    return 0.0f;
}
else{
    printf("Succesfully withdrawn: $",amount);
    return amount;
}
return 0.0f;
}