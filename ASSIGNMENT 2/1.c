//Menu driven C program to accomplish the following functionalities in single linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node *newNode(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to display the linked list
void displayList() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(int data) {
    struct Node *new_node = newNode(data);
    new_node->next = head;
    head = new_node;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node *new_node = newNode(data);
    if (head == NULL) {
        head = new_node;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to insert a node before a given node
void insertBefore(int key, int data) {
    struct Node *new_node = newNode(data);
    if (head == NULL || head->data == key) {
        insertAtBeginning(data);
    } else {
        struct Node *temp = head;
        while (temp->next != NULL && temp->next->data != key) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            printf("Key not found\n");
        } else {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

// Function to insert a node after a given node
void insertAfter(int key, int data) {
    struct Node *new_node = newNode(data);
    if (head == NULL) {
        printf("Key not found\n");
    } else {
        struct Node *temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Key not found\n");
        } else {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

// Function to delete a node from the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to delete a node from the end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

// Function to delete a node after a given node
void deleteAfter(int key) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node *temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            printf("Key not found or no node after it\n");
        } else {
            struct Node *to_delete = temp->next;
            temp->next = to_delete->next;
            free(to_delete);
        }
    }
}

// Function to delete the entire linked list
void deleteList() {
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice, data, key;

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
                printf("Enter key and data: ");
                scanf("%d %d", &key, &data);
                insertBefore(key, data);
                break;
            case 6:
                printf("Enter key and data: ");
                scanf("%d %d", &key, &data);
                insertAfter(key, data);
                break;
            case 7:
                deleteAtBeginning();
                break;
            case 8:
                deleteAtEnd();
                break;
            case 9:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteAfter(key);
                break;
            case 10:
                deleteList();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
