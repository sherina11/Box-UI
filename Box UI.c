#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Color Codes
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

// Structure
struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student s[100];
int count = 0;

// Clear screen
void clearScreen() {
    system("cls || clear");
}

// Pause
void pauseScreen() {
    printf(YELLOW "\nPress Enter to continue..." RESET);
    getchar();
    getchar();
}

// Box UI
void printLine() {
    printf(BLUE "+--------------------------------------+\n" RESET);
}

// Title Box
void printTitle(char title[]) {
    printLine();
    printf(BLUE "| %-36s |\n" RESET, title);
    printLine();
}

// Add Student
void addStudent() {
    clearScreen();
    printTitle("ADD STUDENT");

    printf(" Enter ID    : ");
    scanf("%d", &s[count].id);

    printf(" Enter Name  : ");
    scanf("%s", s[count].name);

    printf(" Enter Marks : ");
    scanf("%f", &s[count].marks);

    count++;
    printf(GREEN "\n ✔ Student Added Successfully!\n" RESET);

    pauseScreen();
}

// Display Students
void displayStudents() {
    clearScreen();
    printTitle("STUDENT LIST");

    if (count == 0) {
        printf(RED " No records found!\n" RESET);
    } else {
        printLine();
        for (int i = 0; i < count; i++) {
            printf(" ID: %d | Name: %-10s | Marks: %.2f\n",
                   s[i].id, s[i].name, s[i].marks);
        }
        printLine();
    }

    pauseScreen();
}

// Search Student
void searchStudent() {
    int id, found = 0;

    clearScreen();
    printTitle("SEARCH STUDENT");

    printf(" Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            printf(GREEN "\n ✔ Found: %s (Marks: %.2f)\n" RESET,
                   s[i].name, s[i].marks);
            found = 1;
        }
    }

    if (!found) {
        printf(RED "\n ✘ Student not found!\n" RESET);
    }

    pauseScreen();
}

// Menu
void showMenu() {
    clearScreen();

    printTitle("STUDENT MANAGEMENT SYSTEM");

    printf(YELLOW " 1. Add Student\n" RESET);
    printf(YELLOW " 2. Display Students\n" RESET);
    printf(YELLOW " 3. Search Student\n" RESET);
    printf(YELLOW " 4. Exit\n" RESET);

    printLine();
    printf(CYAN " Enter your choice: " RESET);
}

// Main
int main() {
    int choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4:
                printf(GREEN "\n Thank you! Exiting...\n" RESET);
                exit(0);
            default:
                printf(RED "\n Invalid choice!\n" RESET);
                pauseScreen();
        }
    }
}