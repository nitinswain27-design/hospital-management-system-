#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

struct Patient p[MAX];
int count = 0;

// Function to add patient
void addPatient() {
    printf("\nEnter Patient ID: ");
    scanf("%d", &p[count].id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", p[count].name);

    printf("Enter Age: ");
    scanf("%d", &p[count].age);

    printf("Enter Disease: ");
    scanf(" %[^\n]", p[count].disease);

    count++;
    printf("\nPatient added successfully!\n");
}

// Function to display patients
void viewPatients() {
    if (count == 0) {
        printf("\nNo patient records found.\n");
        return;
    }

    printf("\n--- Patient Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nID: %d", p[i].id);
        printf("\nName: %s", p[i].name);
        printf("\nAge: %d", p[i].age);
        printf("\nDisease: %s\n", p[i].disease);
    }
}

// Function to search patient by ID
void searchPatient() {
    int id, found = 0;
    printf("\nEnter Patient ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("\nPatient Found!");
            printf("\nName: %s", p[i].name);
            printf("\nAge: %d", p[i].age);
            printf("\nDisease: %s\n", p[i].disease);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nPatient not found.\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n===== Hospital Management System =====");
        printf("\n1. Add Patient");
        printf("\n2. View Patients");
        printf("\n3. Search Patient");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: printf("\nExiting program...\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
