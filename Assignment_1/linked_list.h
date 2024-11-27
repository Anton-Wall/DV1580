#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/*########################################*/
/*#             Assingment 1             #*/
/*########################################*/
/*              Task 1                    */

typedef struct Block {
    size_t size; // Size
    int free; // free or not
    struct Block* next; // pointer to the next block
} Block;

#define POOL_SIZE 1024
static unsigned char* memory_pool[POOL_SIZE]; //memorypool
static Block* free_list  = NULL;  // first free block

void mem_init(size_t size);

void* mem_alloc(size_t size);

void mem_free(void* block);

void* mem_resize(void* block, size_t size);

/*###################################################################*/
// task 2

typedef struct Node {
    uint16_t data; // Stores the data as an unsigned 16-bit integer
    struct Node* next; // A pointer to the next node in the List
} Node;


void list_init(Node** head, size_t size);

void list_insert(Node** head, uint16_t data);

void list_insert_after(Node* prev_node, uint16_t data);

void list_insert_before(Node** head, Node* next_node, uint16_t data);

void list_delete(Node** head, uint16_t data);

Node* list_search(Node** head, uint16_t data);

void list_display(Node** head);

void list_display_range(Node** head, Node* start_node, Node* end_node);

int list_count_nodes(Node** head);

void list_cleanup(Node** head);

