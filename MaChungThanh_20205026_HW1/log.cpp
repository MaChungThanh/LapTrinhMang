#include "account.h"
#include <stdio.h>
#include <time.h>

void log_activity(FILE *log_file, const char *function, const char *user, const char *result) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char timestamp[MAX_LOG_LENGTH];
    strftime(timestamp, MAX_LOG_LENGTH, "[%d/%m/%Y %H:%M:%S]", timeinfo);

    fprintf(log_file, "%s $ %s $ %s $ %s $ %s\n", timestamp, function, user, result);
}