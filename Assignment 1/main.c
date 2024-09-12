#include <stdio.h>

//array of structs whit a pointer to the memory, the structs are a block

struct MemoryBlock
{
    int *segment_ptr
    bool isAllocated = false;
};

void mem_init(size_t size) {
    int mem_array[size];
    for (int i = 0; i < size; i++) {
        mem_array[i] = 0;
        }
};

void* mem_alloc(size_t size){
    bool free_block = false;
    int i = 0;
    while (free_block != true) {
        if (mem_alloc[i] == 0) {//if space is free
            for (alocated=0; alocated < size; alocated++) {
                mem_alloc[i+alocated] = 1

            }
        }
        i++;
    }
};
/*
void mem_free(void* block);

void* mem_resize(void* block, size_t size); 

void mem_deinit();
*/
void main(){
    mem_init(5);
    return 0;
};