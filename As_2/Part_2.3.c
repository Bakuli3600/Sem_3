#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of Student structure
typedef struct Student {
    char name[50];
    int rollNumber;
    float marks;
    struct Student* next;
} Student;

// Global head pointer
Student* head = NULL;

// Function prototypes
void addStudent(char name[], int rollNumber, float marks);
void deleteStudent(int rollNumber);
void displayStudents();
int searchStudent(int rollNumber);

// Add a student to the list
void addStudent(char name[], int rollNumber, float marks) {
    Student* s = (Student*)malloc(sizeof(Student));
    strcpy(s->name, name);
    s->rollNumber = rollNumber;
    s->marks = marks;
    s->next = NULL;

    if (!head) head = s;
    else {
        Student* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = s;
    }
    printf("Student %s added.\n", name);
}

// Delete a student by roll number
void deleteStudent(int rollNumber) {
    Student *temp = head, *prev = NULL;
    while(temp && temp->rollNumber != rollNumber) { prev=temp; temp=temp->next; }
    if(!temp) { printf("Student %d not found.\n", rollNumber); return; }
    if(prev) prev->next = temp->next; else head = temp->next;
    free(temp);
    printf("Student %d deleted.\n", rollNumber);
}

// Display all students
void displayStudents() {
    if(!head){ printf("No student records.\n"); return; }
    printf("\n--- Student Records ---\n");
    Student* temp = head;
    while(temp){
        printf("Roll: %d | Name: %s | Marks: %.2f\n", temp->rollNumber, temp->name, temp->marks);
        temp = temp->next;
    }
}

// Search for a student by roll number
int searchStudent(int rollNumber) {
    Student* temp = head;
    int index = 0;
    while(temp){ if(temp->rollNumber==rollNumber) return index; temp=temp->next; index++; }
    return -1;
}

// Main menu-driven program
int main() {
    int choice, roll;
    float marks;
    char name[50];

    while(1){
        printf("\n1.Add 2.Delete 3.Display 4.Search 5.Exit\nChoice: "); scanf("%d",&choice); getchar();
        switch(choice){
            case 1:
                printf("Enter name: "); fgets(name,50,stdin); name[strcspn(name,"\n")]=0;
                printf("Enter roll number: "); scanf("%d",&roll); getchar();
                printf("Enter marks: "); scanf("%f",&marks); getchar();
                addStudent(name, roll, marks);
                break;
            case 2:
                printf("Enter roll number to delete: "); scanf("%d",&roll); getchar();
                deleteStudent(roll);
                break;
            case 3:
                displayStudents();
                break;
            case 4:
                printf("Enter roll number to search: "); scanf("%d",&roll); getchar();
                int pos = searchStudent(roll);
                if(pos!=-1) printf("Student %d found at position %d.\n", roll, pos);
                else printf("Student %d not found.\n", roll);
                break;
            case 5:
                while(head){ Student* tmp=head; head=head->next; free(tmp); }
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
