#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;

Account accounts[10];
int totalAccounts = 0;

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n=== Banking Management System ===\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account Details\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                displayAccount();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void createAccount() {
    if (totalAccounts >= 10) {
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = totalAccounts + 1;
    printf("Enter account holder name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.balance = 0.0;

    accounts[totalAccounts] = newAccount;
    totalAccounts++;

    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void depositMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > totalAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Amount deposited successfully! New Balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > totalAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }

    if (accounts[accountNumber - 1].balance < amount) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Amount withdrawn successfully! New Balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void displayAccount() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > totalAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    Account acc = accounts[accountNumber - 1];
    printf("\nAccount Number: %d\n", acc.accountNumber);
    printf("Account Holder: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}

void displayAllAccounts() {
    if (totalAccounts == 0) {
        printf("No accounts to display.\n");
        return;
    }

    printf("\n=== All Accounts ===\n");
    for (int i = 0; i < totalAccounts; i++) {
        Account acc = accounts[i];
        printf("Account Number: %d\n", acc.accountNumber);
        printf("Account Holder: %s\n", acc.name);
        printf("Balance: %.2f\n", acc.balance);
        printf("--------------------------\n");
    }
}
