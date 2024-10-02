#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Block {
    size_t size; // Size
    int free; // free or not
    struct Block* next; // pointer to the next block
} Block;

static unsigned char memory_pool[]; //memorypool

void* memory_pool = NULL;

static Block* free_list = (Block*)memory_pool;  // first free block


void mem_init(size_t size) {
    free_list->size = size - sizeof(Block);
    free_list->free = 1;
    free_list->next = NULL;

};

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
    Block* block = (Block*)block - 1;
    block->free = 1; // Mark the block as free
    
    // Coalesce adjacent free blocks
    Block* curr = free_list;
    while (curr != NULL && curr->next != NULL) {
        if (curr->free && curr->next->free) {
            // Merge current and next block
            curr->size += curr->next->size + sizeof(Block);
            curr->next = curr->next->next;
        }
        curr = curr->next;
    }
};

void* mem_resize(void* block, size_t size); 

void mem_deinit();

void main(){
    mem_init(5);
    return 0;
};