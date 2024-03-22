#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node
{
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int value)
 {
    struct Node* newNode = createNode(value);
    newNode->next = head;

    return newNode;
}

// Function to delete a node with a specific value
struct Node* deleteNode(struct Node* head, int value)
{
    struct Node* current = head;
    struct Node* prev = NULL;

    // Handle the case where the head node needs to be deleted
    if (current != NULL && current->data == value)
    {
        head = current->next;
        free(current);

        return head;
    }

    // Search for the node to be deleted
    while (current != NULL && current->data != value)
    {
        prev = current;
        current = current->next;
    }

    // If the value is not found
    if (current == NULL)
    {
        printf("Node with value %d not found.\n", value);
        return head;
    }

    // Unlink the node from the list
    prev->next = current->next;
    free(current);

    return head;
}

// Function to print the linked list
void printList(struct Node* head)
{
    struct Node* current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to write linked list data to a file
void writeToFile(struct Node* head, const char* filename)
{
    FILE* file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        exit(1);
    }

    struct Node* current = head;

    while (current != NULL)
    {
        fprintf(file, "%d\n", current->data);
        current = current->next;
    }

    fclose(file);
}

int main()
 {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    printf("Original list: ");
    printList(head);

    // Delete a node with value 20
    head = deleteNode(head, 20);
    printf("List after deleting node with value 20: ");
    printList(head);

    // Write linked list data to a file
    writeToFile(head, "linked_list_data.txt");
    printf("Data written to linked_list_data.txt\n");

    // Clean up memory
    while (head != NULL)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

