#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular doubly linked list node
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = newNode->prev = NULL;

    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int value)
{
    struct Node* newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode->prev = newNode; // Circular link
    }
    else
    {
        struct Node* last = (*head)->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

// Function to remove a node with a specific value
void removeNode(struct Node** head, int value)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node* curr = *head;
    struct Node* prev_1 = NULL;

    do
    {
        if (curr->data == value)
        {
            if (curr == *head)
            {
                *head = (*head)->next;
                (*head)->prev = curr->prev;
            }

            else
            {
                prev_1->next = curr->next;
                curr->next->prev = prev_1;
            }

            free(curr);
            printf("Node with value %d removed successfully.\n", value);

            return;
        }

        prev_1 = curr;
        curr = curr->next;

    } while (curr != *head);

    printf("Node with value %d not found in the list.\n", value);
}

// Function to display the circular doubly linked list
void display(struct Node* head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node* curr = head;
    do
    {
        printf("%d ", curr->data);
        curr = curr->next;

    } while (curr != head);

    printf("\n");
}

int main()
{
    struct Node* head = NULL;

    // Example usage
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    display(head);

    removeNode(&head, 20);
    display(head);

    // Save the list to a file
    FILE* file = fopen("linked_list.txt", "w");

    if (file)
    {
        struct Node* curr = head;

        do
        {
            fprintf(file, "%d\n", curr->data);
            curr = curr->next;

        } while (curr != head);

        fclose(file);
        printf("List saved to 'linked_list.txt'.\n");

    }

    else
    {
        printf("Error opening file for writing.\n");
    }

    // Load the list from the file
    file = fopen("linked_list.txt", "r");

    if (file)
    {
        int value;

        while (fscanf(file, "%d", &value) != EOF)
        {
            insertEnd(&head, value);
        }

        fclose(file);
        printf("List loaded from 'linked_list.txt'.\n");
        display(head);
    }

    else
    {
        printf("Error opening file for reading.\n");
    }

    return 0;
}

