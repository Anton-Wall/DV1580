#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
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
    if (size == 0) return NULL;  // Handle zero-size allocation case

    size = ALIGN_SIZE(size); // Align requested size
    Block* best_fit = NULL;
    Block* prev = NULL;
    Block* curr = free_list;
    Block* prev_best = NULL;

    // Find the best-fitting free block
    while (curr) {
        if (curr->free && curr->size >= size) {
            if (!best_fit || curr->size < best_fit->size) {
                best_fit = curr;
                prev_best = prev;
            }
            if (curr->size == size) break; // Perfect fit, stop searching
        }
        prev = curr;
        curr = curr->next;
    }

    if (!best_fit) {
        printf("Memory allocation failed: No suitable block found.\n");
        return NULL; // No suitable block found
    }

    // Check if the block should be split
    if (best_fit->size >= size + sizeof(Block) + 8) { // Ensure space for another block
        Block* new_block = (Block*)((unsigned char*)best_fit + sizeof(Block) + size);
        new_block->size = best_fit->size - size - sizeof(Block);
        new_block->free = 1;
        new_block->next = best_fit->next;

        best_fit->size = size;
        best_fit->next = new_block;
    }

    best_fit->free = 0; // Mark as allocated
    return (unsigned char*)best_fit + sizeof(Block); // Return pointer to usable memory
}

void mem_free(void* block) {
    if (!block) {
        printf("Attempt to free a NULL pointer.\n");
        return;
    }

    // Retrieve the block header
    Block* to_free = (Block*)((unsigned char*)block - sizeof(Block));

    // Prevent double free
    if (to_free->free) {
        printf("Double free detected!\n");
        return;
    }

    to_free->free = 1;  // Mark block as free

    // Coalescing: Merge adjacent free blocks
    Block* curr = free_list;

    while (curr) {
        if (curr->free && curr->next && curr->next->free) {
            // Merge curr with next
            curr->size += curr->next->size + sizeof(Block);
            curr->next = curr->next->next;
            continue; // Check again in case further merging is possible
        }
        curr = curr->next;
    }
}


void* mem_resize(void* block, size_t size) {
    if (!block) {
        return mem_alloc(size);
    }

    size = ALIGN_SIZE(size);
    Block* curr = (Block*)((unsigned char*)block - sizeof(Block));
    if (curr->size >= size) {
        return block; // No need to resize if the block is already large enough
    }

    // Allocate new memory and copy old data
    void* new_block = mem_alloc(size);
    if (new_block) {
        memcpy(new_block, block, curr->size);
        mem_free(block);
    } else {
        printf("Resize failed: insufficient memory.\n");
    }
    return new_block;
}

void mem_deinit() { //remove the memory pool
    free(memory_pool);
    memory_pool = NULL;
    free_list = NULL;
}