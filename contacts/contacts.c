#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Contact{
    char name[50];
    char phone[50];
    char email[50];
};

struct Contact contacts[100];
int totalContacts = 0;

void displayMenu(){
    printf("\n*****Contact Management System*****\n");
    printf("1.Add Contact\n");
    printf("2.View Contacts\n");
    printf("3.Search Contact\n");
    printf("4.Update Contact\n");
    printf("5.Delete Contact\n");
    printf("6.Exit Program\n");
};

void addContacts(){
    printf("\nEnter your name: ");
    scanf(" %[^\n]",contacts[totalContacts].name);

    printf("\nEnter your phone number: ");
    scanf("%s",contacts[totalContacts].phone);

    printf("\nEnter your email Id: ");
    scanf("%s",contacts[totalContacts].email);

    totalContacts++;

    printf("\nContact added Successfully !\n");
}

void viewContacts()
{
    if(totalContacts == 0)
    {
        printf("\nNo contacts found!\n");
        return;
    }

    for(int i = 0; i < totalContacts; i++)
    {
        printf("\n========== Contact %d ==========\n", i + 1);
        printf("Name  : %s\n", contacts[i].name);
        printf("Phone : %s\n", contacts[i].phone);
        printf("Email : %s\n", contacts[i].email);
    }
}

void Search()
{
    char searchName[50];
    int found = 0;

    printf("\nEnter name to search: ");
    scanf(" %[^\n]", searchName);

    for(int i = 0; i < totalContacts; i++)
    {
        // Compare the entered name with the current contact's name
        if(strcmp(searchName, contacts[i].name) == 0)
        {
            printf("\n===== Contact Found =====\n");
            printf("Name  : %s\n", contacts[i].name);
            printf("Phone : %s\n", contacts[i].phone);
            printf("Email : %s\n", contacts[i].email);

            found = 1;
            break;      // Stop searching once found
        }
    }

    if(found == 0)
    {
        printf("\nContact not found!\n");
    }
}

void update()
{
    char searchName[50];
    int found = 0;

    printf("\nEnter name of contact to update: ");
    scanf(" %[^\n]", searchName);

    for(int i = 0; i < totalContacts; i++)
    {
        // Compare the entered name with the current contact's name
        if(strcmp(searchName, contacts[i].name) == 0)
        {
            printf("\nContact Found !");

            printf("\nEnter new name: ");
            scanf(" %[^\n]", contacts[i].name);

            printf("\nEnter new phone number: ");
            scanf("%s", contacts[i].phone);


            printf("\nEnter new email Id: ");
            scanf("%s", contacts[i].email);

            printf("Contact updated succesfully !");
            found = 1;
            break;
            
        }
    }

    if(found == 0)
    {
        printf("\nContact not found!\n");
    }
}

void deleteContact()
{
    char searchName[50];
    int found = 0;

    printf("\nEnter the name to delete: ");
    scanf(" %[^\n]", searchName);

    for(int i = 0; i < totalContacts; i++)
    {
        if(strcmp(searchName, contacts[i].name) == 0)
        {
            for(int j = i; j < totalContacts - 1; j++)
            {
                contacts[j] = contacts[j + 1];
            }

            totalContacts--;
            found = 1;

            printf("\nContact deleted successfully!\n");
            break;
        }
    }

    if(found == 0)
    {
        printf("\nContact not found!\n");
    }
}







int main(){
    int choice;

    do{
        displayMenu();
        printf("Enter you choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
            addContacts();
            break;

            case 2:
            viewContacts();
            break;

            case 3:
            Search();
            break;

            case 4:
            update();
            break;

            case 5:
            deleteContact();
            break;

            case 6:
            printf("\nThank you for using Contact Management System!\n");
            printf("Goodbye!\n");
            break;

            default: 
            printf("Invalid choice !\n");
            }

    
    }while(choice!=6);
     return 0;
}