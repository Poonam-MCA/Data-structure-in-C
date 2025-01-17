//MENU DRIVEN C PROGRAM TO ACCOMPLISH THE FOLLOWING FUNCTIONALITIES IN A SINGLE LINKED LIST 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node before a given node
void insertBefore(int data, int target) {
    struct Node *newNode = createNode(data);
    if (head == NULL || head->data == target) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Target node not found.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert a node after a given node
void insertAfter(int data, int target) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        printf("Target node not found.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target node not found.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node from the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// Function to delete a node from the end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node after a given node
void deleteAfter(int target) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Target node not found.\n");
        return;
    }
    struct Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

// Function to delete the entire linked list
void deleteList() {
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to display the elements of the linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data, target;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a single linked list\n");
        printf("2. Display the elements of a single linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node before a given node\n");
        printf("6. Insert a node after a given node\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire single linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                printf("Enter data and target: ");
                scanf("%d %d", &data, &target);
                insertBefore(data, target);
                break;
            case 6:
                printf("Enter data and target: ");
                scanf("%d %d", &data, &target);
                insertAfter(data, target);
                break;
            case 7:
                deleteAtBeginning();
                break;
            case 8:
                deleteAtEnd();
                break;
            case 9:
                printf("Enter target: ");
                scanf("%d", &target);
                deleteAfter(target);
                break;
            case 10:
                deleteList();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
