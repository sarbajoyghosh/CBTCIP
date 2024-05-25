#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100  // Maximum number of accounts the system can handle

// Define a structure to represent a bank account
typedef struct {
    int accountNumber;       // Account number
    char accountType[10];    // Type of account: savings or checking
    char ownerName[50];      // Name of the account owner
    double balance;          // Account balance
    double interestRate;     // Interest rate (applicable only for savings accounts)
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];  // Array to store all bank accounts
int accountCount = 0;                // Counter to keep track of the number of accounts

// Function to create a new bank account
void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }

    BankAccount newAccount;
    newAccount.accountNumber = accountCount + 1;  // Assign a unique account number
    printf("Enter account type (savings/checking): ");
    scanf("%s", newAccount.accountType);
    printf("Enter owner's name: ");
    scanf("%s", newAccount.ownerName);
    printf("Enter initial deposit: ");
    scanf("%lf", &newAccount.balance);

    // Set interest rate if the account type is savings
    if (strcmp(newAccount.accountType, "savings") == 0) {
        printf("Enter interest rate: ");
        scanf("%lf", &newAccount.interestRate);
    } else {
        newAccount.interestRate = 0;
    }

    // Add the new account to the accounts array
    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully. Account Number: %d\n", newAccount.accountNumber);
}

// Function to deposit funds into an account
void depositFunds() {
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter deposit amount: ");
    scanf("%lf", &amount);

    if (accountNumber > 0 && accountNumber <= accountCount) {
        accounts[accountNumber - 1].balance += amount;  // Add the amount to the account balance
        printf("Deposit successful. New Balance: %.2lf\n", accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}

// Function to withdraw funds from an account
void withdrawFunds() {
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);

    if (accountNumber > 0 && accountNumber <= accountCount) {
        if (accounts[accountNumber - 1].balance >= amount) {
            accounts[accountNumber - 1].balance -= amount;  // Deduct the amount from the account balance
            printf("Withdrawal successful. New Balance: %.2lf\n", accounts[accountNumber - 1].balance);
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("Invalid account number.\n");
    }
}

// Function to check the balance of an account
void checkBalance() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber > 0 && accountNumber <= accountCount) {
        printf("Current Balance: %.2lf\n", accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}

// Function to calculate and add interest for savings accounts
void calculateInterest() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber > 0 && accountNumber <= accountCount) {
        if (strcmp(accounts[accountNumber - 1].accountType, "savings") == 0) {
            double interest = accounts[accountNumber - 1].balance * (accounts[accountNumber - 1].interestRate / 100);
            accounts[accountNumber - 1].balance += interest;  // Add interest to the account balance
            printf("Interest calculated and added. New Balance: %.2lf\n", accounts[accountNumber - 1].balance);
        } else {
            printf("Interest calculation only applicable for savings accounts.\n");
        }
    } else {
        printf("Invalid account number.\n");
    }
}

// Function to display the main menu
void displayMenu() {
    printf("\nBank Account Management System\n");
    printf("1. Create Account\n");
    printf("2. Deposit Funds\n");
    printf("3. Withdraw Funds\n");
    printf("4. Check Balance\n");
    printf("5. Calculate Interest\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Main function
int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositFunds();
                break;
            case 3:
                withdrawFunds();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                calculateInterest();
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
