#include <stdio.h>


void mem_init(size_t size) {
    int mem_arr[size];
    for (int i = 0; i < size; i++) {
        mem_arr[i] = 0; //free spaces
        };
    return &mem_arr;
};

void* mem_alloc(size_t size) {
    bool find = false;
    int check = 0;
    bool clear = true;
    while (!find){
        if check > sizeof(mem_arr) {
            printf("Memory is full");
            return NULL;
        };

        if (mem_arr[check] = 0){//finds free space
            for (int i = check; i < size + check; i++){ //cheks in front
                if (mem_arr[i] == 1){ //if  there is a used space
                    clear = false;
                };
            };
            if (clear == true){ //if there is no used space in front
                for (int i = check; i < size + check; i++){ //allocates the space
                mem_arr[i] == 1;
                };
                find = true;
            };
        };
        clear = true;
        check++; //moves forward
    };
    return &mem_arr[check - size]; //returns the address of the allocated space

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