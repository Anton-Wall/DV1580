#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "memory_manager.h"


/*########################################*/
/*#             Assingment 1             #*/
/*########################################*/
/*              Task 1                    */

typedef struct Block {
    size_t size; // Size
    int free; // free or not
    struct Block* next; // pointer to the next block
} Block;

void* memory_pool; //memorypool
static Block* free_list;  // first free block

#define ALIGN_SIZE(size) (((size) + 7) & ~7) // stack alignment

void mem_init(size_t size) {
    // Allocate the memory pool (with some extra space for block headers)
    memory_pool = malloc(size);
    
    // Check if the memory allocation was successful
    if (!memory_pool) {
        printf("Memory initialization failed.\n");
        exit(EXIT_FAILURE);
    }
    
    // Initialize the first free block header
    free_list = (Block*)memory_pool;
    free_list->size = size - sizeof(Block); // Block size minus the header size
    free_list->free = 1;  // Mark the block as free
    free_list->next = NULL; // No other free blocks yet
}

void* mem_alloc(size_t size) {
    size = ALIGN_SIZE(size); // Align requested size
    Block* curr = free_list;

    // Find a suitable block
    while (curr) {
        if (curr->free && curr->size >= size) {
            // Check if splitting is possible
            if (curr->size >= size + sizeof(Block) + 8) {
                Block* new_block = (Block*)((unsigned char*)curr + sizeof(Block) + size);
                new_block->size = curr->size - size - sizeof(Block);
                new_block->free = 1;
                new_block->next = curr->next;

                curr->size = size;
                curr->next = new_block;
            }
            curr->free = 0;
            return (unsigned char*)curr + sizeof(Block);
        }
        curr = curr->next;
    }

    printf("No suitable block found.\n");
    return NULL;
}

void mem_free(void* block) {
    if (!block) {
        printf("Attempt to free a NULL pointer.\n");
        return;
    }

    // Mark the block as free
    Block* to_free = (Block*)((unsigned char*)block - sizeof(Block));
    to_free->free = 1;

    // Coalesce adjacent free blocks
    Block* curr = free_list;
    while (curr && curr->next) {
        if (curr->free && curr->next->free &&
            (unsigned char*)curr + curr->size + sizeof(Block) == (unsigned char*)curr->next) {
            curr->size += curr->next->size + sizeof(Block);
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
}

void* mem_resize(void* block, size_t size) {
    if (block == NULL) {
        return mem_alloc(size); //if no block. return a new one
    }
    
    // Free and allocate new memory if shrinking or extending size
    mem_free(block);
    return mem_alloc(size);
}

void mem_deinit() { //remove the memory pool
    free(memory_pool);
    memory_pool = NULL;
    free_list = NULL;
}
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

}

void list_display(Node** head) {

}

void list_display_range(Node** head, Node* start_node, Node* end_node) {

}

int list_count_nodes(Node** head) {

}

void list_cleanup(Node** head) {

}