#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of Task structure
typedef struct Task {
    int taskId;
    char description[100];
    int priority;
    struct Task* next;
} Task;

// Function prototypes
void addTask(Task** head, int id, char desc[], int prio);
void deleteTask(Task** head, int id);
void displayTasks(Task* head);
void prioritizeTasks(Task** head);
int searchTask(Task* head, int id);

// Add a task to the list
void addTask(Task** head, int id, char desc[], int prio) {
    Task* t = (Task*)malloc(sizeof(Task));
    t->taskId = id;
    strcpy(t->description, desc);
    t->priority = prio;
    t->next = NULL;
    if (!*head) *head = t;
    else { Task* tmp = *head; while(tmp->next) tmp=tmp->next; tmp->next=t; }
    printf("Task %d added.\n", id);
}

// Delete a task by ID
void deleteTask(Task** head, int id) {
    Task *tmp = *head, *prev = NULL;
    while(tmp && tmp->taskId != id) { prev=tmp; tmp=tmp->next; }
    if(!tmp) { printf("Task %d not found.\n", id); return; }
    if(prev) prev->next=tmp->next; else *head=tmp->next;
    free(tmp);
    printf("Task %d deleted.\n", id);
}

// Display all tasks
void displayTasks(Task* head) {
    if(!head){ printf("No tasks.\n"); return; }
    printf("\n--- Tasks ---\n");
    while(head){
        printf("ID:%d | Priority:%d | Desc: %s\n", head->taskId, head->priority, head->description);
        head = head->next;
    }
}

// Sort tasks by priority (highest first)
void prioritizeTasks(Task** head) {
    if(!*head || !(*head)->next) return;
    for(Task* i=*head; i!=NULL; i=i->next) {
        for(Task* j=i->next; j!=NULL; j=j->next) {
            if(j->priority > i->priority){
                int tempId=i->taskId; i->taskId=j->taskId; j->taskId=tempId;
                char tempDesc[100]; strcpy(tempDesc,i->description); strcpy(i->description,j->description); strcpy(j->description,tempDesc);
                int tempPrio=i->priority; i->priority=j->priority; j->priority=tempPrio;
            }
        }
    }
    printf("Tasks prioritized by priority.\n");
}

// Search for a task by ID
int searchTask(Task* head, int id) {
    int index = 0;
    while(head){ if(head->taskId==id) return index; head=head->next; index++; }
    return -1;
}

// Main menu-driven program
int main(){
    Task* head=NULL; int choice,id,prio,pos; char desc[100];
    while(1){
        printf("\n1.Add 2.Delete 3.Display 4.Prioritize 5.Search 6.Exit\nChoice: "); scanf("%d",&choice); getchar();
        switch(choice){
            case 1:
                printf("Enter ID: "); scanf("%d",&id); getchar();
                printf("Enter description: "); fgets(desc,100,stdin); desc[strcspn(desc,"\n")]=0;
                printf("Enter priority: "); scanf("%d",&prio); getchar();
                addTask(&head,id,desc,prio);
                break;
            case 2:
                printf("Enter ID to delete: "); scanf("%d",&id); getchar();
                deleteTask(&head,id);
                break;
            case 3:
                displayTasks(head);
                break;
            case 4:
                prioritizeTasks(&head);
                break;
            case 5:
                printf("Enter ID to search: "); scanf("%d",&id); getchar();
                pos = searchTask(head,id);
                printf(pos!=-1?"Task %d found at position %d.\n":"Task %d not found.\n",id,pos);
                break;
            case 6:
                while(head){ Task* tmp=head; head=head->next; free(tmp); }
                return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
