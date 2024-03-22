#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
struct Node* insertAtEnd(struct Node* last, int data) {
    struct Node* newNode = createNode(data);
    if (last == NULL) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    return last;
}

// Function to display the circular singly linked list
void display(struct Node* last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = last->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

// Function to write the circular singly linked list data to a file
void writeToFile(struct Node* last, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    struct Node* temp = last->next;
    do {
        fprintf(file, "%d\n", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    fclose(file);
}

// Function to read the circular singly linked list data from a file
struct Node* readFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return NULL;
    }
    struct Node* last = NULL;
    int data;
    while (fscanf(file, "%d", &data) != EOF) {
        last = insertAtEnd(last, data);
    }
    fclose(file);
    return last;
}

int main() {
    struct Node* last = NULL;

    // Insert nodes at the end
    last = insertAtEnd(last, 10);
    last = insertAtEnd(last, 20);
    last = insertAtEnd(last, 30);

    // Display the circular singly linked list
    printf("Circular Singly Linked List: ");
    display(last);

    // Write the linked list data to a file
    writeToFile(last, "linked_list_data.txt");
    printf("Data written to file 'linked_list_data.txt'.\n");

    // Read the data back from the file
    struct Node* newList = readFromFile("linked_list_data.txt");
    printf("Circular Singly Linked List read from file: ");
    display(newList);

    // Clean up memory (free nodes, close file, etc.)

    return 0;
}

