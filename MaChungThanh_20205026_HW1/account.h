#ifndef ACCOUNT_H
#define ACCOUNT_H

#define MAX_USERNAME_LENGTH 50
#define MAX_LOG_LENGTH 100

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    int status;
} Account;

void log_activity(FILE *log_file, const char *function, const char *user, const char *result);

#endif