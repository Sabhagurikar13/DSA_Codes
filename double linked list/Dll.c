#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
    }

    return newNode;
}

// Function to insert a node at the beginning of the list
void insertFront(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);

    if (newNode != NULL)
    {
        newNode->next = *head;
        if (*head != NULL)
        {
            (*head)->prev = newNode;
        }
        *head = newNode;
    }
}

// Function to remove a node from the list
void removeNode(struct Node** head, int data)
{
    struct Node* current = *head;

    while (current != NULL)
    {
        if (current->data == data)
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
                if (current->next != NULL)
                {
                    current->next->prev = current->prev;
                }
            free(current);
            break;
        }
        current = current->next;
    }
}

// Function to display the list
void displayList(struct Node* head)
{
    struct Node* current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to save the list to a file
void saveToFile(struct Node* head, const char* filename)
{
    FILE* file = fopen(filename, "w");

    if (file != NULL)
    {
        struct Node* current = head;

        while (current != NULL)
        {
            fprintf(file, "%d\n", current->data);
            current = current->next;
        }
        fclose(file);
        printf("List saved to %s\n", filename);
    }
    else
    {
        printf("Error opening file for writing.\n");
    }
}

// Function to load the list from a file
void loadFromFile(struct Node** head, const char* filename)
{
    FILE* file = fopen(filename, "r");

    if (file != NULL)
    {
        int data;

        while (fscanf(file, "%d", &data) != EOF)
        {
            insertFront(head, data);
        }
        fclose(file);
        printf("List loaded from %s\n", filename);
    }
    else
    {
        printf("Error opening file for reading.\n");
    }
}

int main()
{
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insertFront(&head, 3);
    insertFront(&head, 2);
    insertFront(&head, 1);

    printf("Original doubly linked list: ");
    displayList(head);

    // Save the list to a file
    saveToFile(head, "doubly_linked_list.txt");

    // Remove node with value 2
    removeNode(&head, 2);
    printf("After removing node with value 2: ");
    displayList(head);

    // Load the list from the file
    loadFromFile(&head, "doubly_linked_list.txt");
    printf("List loaded from file: ");
    displayList(head);

    // Clean up memory (free nodes)
    while (head != NULL)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

