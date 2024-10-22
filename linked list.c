#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/*###################################################################*/
// task 2

typedef struct Node {
    uint16_t data; // Stores the data as an unsigned 16-bit integer
    struct Node* next; // A pointer to the next node in the List
} Node;


void list_init(Node** head, size_t size){
    *head = NULL; //pointer to head node
}

void list_insert(Node** head, uint16_t data) {
    Node* new_node = (Node*)mem_alloc(sizeof(Node));
    
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void list_insert_after(Node* prev_node, uint16_t data) {
    Node* new_node = (Node*)mem_alloc(sizeof(Node));

    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void list_insert_before(Node** head, Node* next_node, uint16_t data) {
    Node* prev = *head;
    while (prev->next && prev->next != next_node) {
        prev = prev->next;
    }

    if (prev->next == next_node) {
        Node* new_node = (Node*)mem_alloc(sizeof(Node));
        if (!new_node) {
            printf("Memory allocation for new node failed.\n");
            return;
        }
        new_node->data = data;
        new_node->next = next_node;
        prev->next = new_node;
    }
}

void list_delete(Node** head, uint16_t data){
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    if (temp->data == data) {
        *head = temp->next;
        mem_free(temp);
        return;
    }

    while (temp && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    mem_free(temp);
}

Node* list_search(Node** head, uint16_t data) {

};

void list_display(Node** head) {

};

void list_display_range(Node** head, Node* start_node, Node* end_node) {

};

int list_count_nodes(Node** head) {

};

void list_cleanup(Node** head) {

};

void main(){
    mem_init(1024);
    
    // Example usage
    void* p1 = mem_alloc(100);
    if (p1) {
        printf("Allocated 100 bytes at %p\n", p1);
    };
};