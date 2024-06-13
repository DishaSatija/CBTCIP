#include <stdio.h>
#include <string.h>
// Interest rates for different types of accounts (as decimal values representing percentages)
#define SAVINGS_INTEREST_RATE 0.03   // 3% annual interest rate
#define CURRENT_INTEREST_RATE 0.01   // 1% annual interest rate
#define FIXED_DEPOSIT_INTEREST_RATE 0.05  // 5% annual interest rate
typedef struct {
    int accountNumber;
    char accountType[20];
    float balance;
} Account;
int main() {
    Account accounts[100];  // Maximum size of account number
    int numAccounts = 0;
    // Giving the choice to user to perform different operations
    int choice;
    do {
        // Displaying the options
        printf("\n===== Bank Account Management System =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Calculate Interest\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: // Create Account
                printf("Enter account number: ");
                scanf("%d", &accounts[numAccounts].accountNumber);
                printf("Enter account type (Savings, Current, Fixed Deposit): ");
                scanf("%s", accounts[numAccounts].accountType);
                accounts[numAccounts].balance = 0;
                numAccounts++;
                printf("Account created successfully!\n");
                break;
            case 2: // Deposit
                if (numAccounts == 0) {
                    printf("No accounts created yet.\n");
                    break;
                }
                int accNumber;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &accNumber);
                // Finding the account number
                int found = 0;
                for (int i = 0; i < numAccounts; i++) {
                    if (accounts[i].accountNumber == accNumber) {
                        printf("Enter amount to deposit: ");
                        scanf("%f", &amount);
                        accounts[i].balance += amount;
                        printf("Deposit successful. Updated balance: %.2f\n", accounts[i].balance);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Account not found.\n");
                }
                break;
            case 3: // Withdraw
                if (numAccounts == 0) {
                    printf("No accounts created yet.\n");
                    break;
                }
                printf("Enter account number: ");
                scanf("%d", &accNumber);
                // Find account
                found = 0;
                for (int i = 0; i < numAccounts; i++) {
                    if (accounts[i].accountNumber == accNumber) {
                        printf("Enter amount to withdraw: ");
                        scanf("%f", &amount);
                        if (amount <= accounts[i].balance) {
                            accounts[i].balance -= amount;
                            printf("Withdrawal successful. Updated balance: %.2f\n", accounts[i].balance);
                        } else {
                            printf("Insufficient balance.\n");
                        }
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Account not found.\n");
                }
                break;
            case 4: // Check Balance
                if (numAccounts == 0) {
                    printf("No accounts created yet.\n");
                    break;
                }
                printf("Enter account number: ");
                scanf("%d", &accNumber);
                // Find account
                found = 0;
                for (int i = 0; i < numAccounts; i++) {
                    if (accounts[i].accountNumber == accNumber) {
                        printf("Account balance: %.2f\n", accounts[i].balance);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Account not found.\n");
                }
                break;
            case 5: // Calculate Interest
                if (numAccounts == 0) {
                    printf("No accounts created yet.\n");
                    break;
                }
                for (int i = 0; i < numAccounts; i++) {
                    float interest = 0.0;
                    if (strcmp(accounts[i].accountType, "Savings") == 0) {
                        interest = accounts[i].balance * SAVINGS_INTEREST_RATE;
                    } else if (strcmp(accounts[i].accountType, "Current") == 0) {
                        interest = accounts[i].balance * CURRENT_INTEREST_RATE;
                    } else if (strcmp(accounts[i].accountType, "Fixed Deposit") == 0) {
                        interest = accounts[i].balance * FIXED_DEPOSIT_INTEREST_RATE;
                    }
                    accounts[i].balance += interest; // Add interest to the account balance
                    printf("Interest for account %d (%s): %.2f\n", accounts[i].accountNumber, accounts[i].accountType, interest);
                    printf("Updated balance: %.2f\n", accounts[i].balance); // Print updated balance
                }
                break;
            case 6: // Exit
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);
    return 0;
}
