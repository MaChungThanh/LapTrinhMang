#include "menu.h"
#include "login.h"
#include "log.h"

int main() {
    FILE *log_file = fopen("log_MSSV.txt", "a");
    if (!log_file) {
        perror("Error opening log file");
        return 1;
    }

    Account accounts[] = {{"user1", 1}, {"user2", 0}, {"user3", 1}};
    int num_accounts = sizeof(accounts) / sizeof(accounts[0]);
    char logged_in_user[MAX_USERNAME_LENGTH] = "";

    while (1) {
        int choice = display_menu();

        switch (choice) {
            case 1:
                login_prompt(accounts, num_accounts, logged_in_user, log_file);
                break;
            case 2:
                post_message_prompt(logged_in_user, log_file);
                break;
            case 3:
                logout_action(logged_in_user, log_file);
                break;
            case 4:
                log_activity(log_file, "4", "None", "+OK");
                fclose(log_file);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}