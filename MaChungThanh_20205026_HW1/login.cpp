#include "account.h"
#include <stdio.h>
#include <string.h>

int login(const char *username, Account *accounts, int num_accounts, char *logged_in_user, FILE *log_file) {
    if (*logged_in_user) {
        log_activity(log_file, "1", username, "-ERR (Already logged in)");
        printf("Login failed. You are already logged in.\n");
        return 0;
    }

    int account_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            account_index = i;
            break;
        }
    }

    if (account_index >= 0) {
        if (accounts[account_index].status == 1) {
            log_activity(log_file, "1", username, "+OK");
            printf("Login successful.\n");
            strcpy(logged_in_user, username);
            return 1;
        } else {
            log_activity(log_file, "1", username, "-ERR (Account is locked)");
            printf("Login failed. The account is locked.\n");
        }
    } else {
        log_activity(log_file, "1", username, "-ERR (Account not found)");
        printf("Login failed. Account not found.\n");
    }

    return 0;
}