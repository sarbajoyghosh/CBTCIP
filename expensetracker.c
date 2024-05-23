#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORY_LENGTH 30
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char category[MAX_CATEGORY_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Expense;

// Function to input an expense
void inputExpense(Expense *expense) {
    printf("Enter category: ");
    scanf("%s", expense->category);
    printf("Enter description: ");
    scanf(" %[^\n]", expense->description);  // Use %[^\n] to read the whole line
    printf("Enter amount: ");
    scanf("%f", &expense->amount);
}

// Function to display an expense
void displayExpense(Expense *expense) {
    printf("Category: %s\n", expense->category);
    printf("Description: %s\n", expense->description);
    printf("Amount: %.2f\n", expense->amount);
}

// Function to display all expenses
void displayExpenses(Expense expenses[], int count) {
    float total = 0;
    printf("\nExpenses Summary:\n");
    for (int i = 0; i < count; i++) {
        printf("\nExpense %d:\n", i + 1);
        displayExpense(&expenses[i]);
        total += expenses[i].amount;
    }
    printf("\nTotal Expenditure: %.2f\n", total);
}

int main() {
    int numExpenses = 0;
    Expense expenses[MAX_EXPENSES];
    char choice;

    while (1) {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (numExpenses < MAX_EXPENSES) {
                    inputExpense(&expenses[numExpenses]);
                    numExpenses++;
                } else {
                    printf("Maximum number of expenses reached.\n");
                }
                break;
            case '2':
                if (numExpenses > 0) {
                    displayExpenses(expenses, numExpenses);
                } else {
                    printf("No expenses recorded.\n");
                }
                break;
            case '3':
                printf("Exiting Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
