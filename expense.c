#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void addExpense();
void viewExpenses();
void totalExpense();
void saveFile();
void loadFile();

// Structure
struct Expense
{
    char category[30];
    float amount;
};

// Global Variables
struct Expense expenses[100];
int count = 0;

// Add Expense Function
void addExpense()
{
    if (count >= 100)
    {
        printf("Expense list is full!\n");
        return;
    }

    printf("Enter Category: ");
    scanf("%29s", expenses[count].category);

    printf("Enter Amount: ");
    scanf("%f", &expenses[count].amount);

    count++;

    printf("Expense Added Successfully!\n");
}

// View Expenses Function
void viewExpenses()
{
    if (count == 0)
    {
        printf("No expenses found!\n");
        return;
    }

    printf("\n===== Expense List =====\n");
    printf("%-20s %-10s\n", "Category", "Amount");
    printf("--------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-20s %.2f\n",
               expenses[i].category,
               expenses[i].amount);
    }
}

// Calculate Total Expense
void totalExpense()
{
    if (count == 0)
    {
        printf("No expenses found!\n");
        return;
    }

    float total = 0;

    for (int i = 0; i < count; i++)
    {
        total += expenses[i].amount;
    }

    printf("\nTotal Spending: %.2f\n", total);
}

// Save Expenses to File
void saveFile()
{
    if (count == 0)
    {
        printf("No expenses to save!\n");
        return;
    }

    FILE *fp;

    fp = fopen("expenses.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp,
                "%s %.2f\n",
                expenses[i].category,
                expenses[i].amount);
    }

    fclose(fp);

    printf("Expenses saved successfully!\n");
}

// Load Expenses from File
void loadFile()
{
    FILE *fp;

    fp = fopen("expenses.txt", "r");

    if (fp == NULL)
    {
        printf("No saved file found!\n");
        return;
    }

    count = 0;

    while (count < 100 &&
           fscanf(fp,
                  "%29s %f",
                  expenses[count].category,
                  &expenses[count].amount) == 2)
    {
        count++;
    }

    fclose(fp);

    printf("Expenses loaded successfully!\n");
}

// Main Function
int main()
{
    int choice;

    do
    {
        printf("\n==============================");
        printf("\n      EXPENSE TRACKER");
        printf("\n==============================");
        printf("\n1. Add Expense");
        printf("\n2. View Expenses");
        printf("\n3. Total Spending");
        printf("\n4. Save to File");
        printf("\n5. Load from File");
        printf("\n6. Exit");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addExpense();
            break;

        case 2:
            viewExpenses();
            break;

        case 3:
            totalExpense();
            break;

        case 4:
            saveFile();
            break;

        case 5:
            loadFile();
            break;

        case 6:
            printf("\nThank you for using Expense Tracker!\n");
            printf("Goodbye!\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}