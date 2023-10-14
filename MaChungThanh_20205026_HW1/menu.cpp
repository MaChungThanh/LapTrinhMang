#include "menu.h"
#include <stdio.h>

int display_menu() {
    printf("Menu:\n1. Log in\n2. Post message\n3. Logout\n4. Exit\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}