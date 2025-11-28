#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DATA_FILE "accounts.txt"

struct Account {
    char username[50];
    char password[50];
    float balance;
};

// Function prototypes
void mainMenu();
void registerAccount();
int login(struct Account *user);
void userMenu(struct Account user);
void saveAccount(struct Account user);
int loadAccount(char *username, struct Account *user);

int main() {
    mainMenu();
    return 0;
}

void mainMenu() {
    int choice;

    while (1) {
        printf("\n=============================\n");
        printf("     ONLINE BANKING SYSTEM\n");
        printf("=============================\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            registerAccount();
            break;
        case 2: {
            struct Account user;
            if (login(&user)) {
                userMenu(user);
            } else {
                printf("\nLogin failed. Try again.\n");
            }
            break;
        }
        case 3:
            printf("\nThank you for using the system.\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}

void registerAccount() {
    struct Account newUser;

    printf("\n--- Register New Account ---\n");
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);
    newUser.balance = 0.0;

    saveAccount(newUser);
    printf("\nAccount created successfully!\n");
}

int login(struct Account *user) {
    char username[50], password[50];

    printf("\n--- Login ---\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (loadAccount(username, user)) {
        if (strcmp(password, user->password) == 0) {
            printf("\nLogin successful.\n");
            return 1;
        }
    }

    return 0;
}

void userMenu(struct Account user) {
    int choice;
    float amount;

    while (1) {
        printf("\n=============================\n");
        printf("Welcome, %s\n", user.username);
        printf("=============================\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Logout\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nYour balance: K%.2f\n", user.balance);
            break;

        case 2:
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            user.balance += amount;
            saveAccount(user);
            printf("Deposit successful.\n");
            break;

        case 3:
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > user.balance) {
                printf("Insufficient funds.\n");
            } else {
                user.balance -= amount;
                saveAccount(user);
                printf("Withdrawal successful.\n");
            }
            break;

        case 4:
            printf("\nLogging out...\n");
            return;

        default:
            printf("Invalid choice.\n");
        }
    }
}

void saveAccount(struct Account user) {
    FILE *fp = fopen(DATA_FILE, "a+");

    if (fp == NULL) {
        printf("Error saving account.\n");
        return;
    }

    fprintf(fp, "%s %s %.2f\n", user.username, user.password, user.balance);
    fclose(fp);
}

int loadAccount(char *username, struct Account *user) {
    FILE *fp = fopen(DATA_FILE, "r");

    if (fp == NULL) return 0;

    while (fscanf(fp, "%s %s %f", user->username, user->password, &user->balance) != EOF) {
        if (strcmp(username, user->username) == 0) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}
