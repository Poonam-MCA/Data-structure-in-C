//a Menu driven C program to accomplish the following functionalities in circular linked list
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

// Function to create a circular linked list
void createCircularList() {
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number of nodes\n");
        return;
    }
    printf("Enter the data of nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtEnd(data);
    }
    head->next = head; // Make the last node point to the first node to create a circular list
}

// Function to display the circular linked list
void displayCircularList() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(int data) {
    struct Node *new_node = newNode(data);
    if (head == NULL) {
        head = new_node;
        new_node->next = new_node;
    } else {
        new_node->next = head;
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        head = new_node;
    }
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node *new_node = newNode(data);
    if (head == NULL) {
        head = new_node;
        new_node->next = new_node;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}

// Function to delete a node from the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    } else if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = head->next;
    }
}

// Function to delete a node from the end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    } else if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node *temp1 = head;
        struct Node *temp2 = head;
        while (temp2->next != head) {
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        free(temp2);
    }
}

// Function to delete a node after a given node
void deleteAfter(int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    } else {
        struct Node *temp1 = head;
        struct Node *temp2 = head;
        while (temp2 != NULL && temp2->data != key) {
            temp1 = temp2;
            temp2 = temp2->next;
        }
        if (temp2 == NULL) {
            printf("Key not found\n");
        } else if (temp2->next == head) {
            temp1->next = head;
            free(temp2);
        } else {
            temp1->next = temp2->next;
            free(temp2);
        }
    }
}

// Function to delete the entire circular linked list
void deleteCircularList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            struct Node *to_delete = temp->next;
            temp->next = to_delete->next;
            free(to_delete);
        }
        free(temp);
        head = NULL;
    }
}

int main() {
    int choice, data, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a circular linked list\n");
        printf("2. Display the elements of a circular linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Delete a node from the beginning\n");
        printf("6. Delete a node from the end\n");
        printf("7. Delete a node after a given node\n");
        printf("8. Delete the entire circular linked list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createCircularList();
                break;
            case 2:
                displayCircularList();
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
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteAfter(key);
                break;
            case 8:
                deleteCircularList();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
