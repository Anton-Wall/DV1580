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

void mem_init(size_t size) {
    free_list = (Block*)memory_pool;
    free_list->size = size - sizeof(Block);
    free_list->free = 1;
    free_list->next = NULL;

    printf("Memory pool initialized with size %zu bytes.\n", size);
}

void* mem_alloc(size_t size) {
    // Find the first free block
    Block* curr = free_list;
    
    while (curr != NULL) { // find a free block
        if (curr->free && curr->size >= size) {
            if (curr->size > size + sizeof(Block)) { //make the free block into tow smaler blocks, one of the right size and the other whit the rest
                Block* new_block = (Block*)((unsigned char*)curr + sizeof(Block) + size);
                new_block->size = curr->size - size - sizeof(Block);
                new_block->free = 1;
                new_block->next = curr->next;
                
                curr->size = size;
                curr->next = new_block;
            }
            curr->free = 0;
            return (void*)(curr + 1); // Return the memory just after the block
        }
        curr = curr->next;
    }
    printf("No suitable block found.\n"); //if no block found
    return NULL;
};

void mem_free(void* block) {
    if (block == NULL) {
        printf("Attempt to free a NULL pointer.\n");
        return;
    }
    
    // Get the block header from the pointer
    Block* header = (Block*)block - 1;
    header->free = 1; // Mark the block as free
    
    // Coalesce adjacent free blocks
    Block* curr = free_list;
    while (curr != NULL && curr->next != NULL) {
        
        Block* next = curr->next;
        
        if (curr->free && next && next->free && 
            (char*)curr + curr->size + sizeof(Block) == (char*)next) {
            // Merge current and next block
            curr->size += next->size + sizeof(Block);
            curr->next = next->next; // Bypass the next block
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
    free_list = (Block*)memory_pool;
    free_list->size = sizeof(Block);
    free_list->free = 1;
    free_list->next = NULL;
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
}