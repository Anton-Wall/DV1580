#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Block {
    size_t size; // Size
    int free; // free or not
    struct Block* next; // pointer to the next block
} Block;

static unsigned char* memory_pool[]; //memorypool
static Block* free_list  = NULL;  // first free block

void mem_init(size_t size);

void* mem_alloc(size_t size);

void mem_free(void* block);

void* mem_resize(void* block, size_t size);
