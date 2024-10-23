//Test target to run the memory manager test program
test_mmanager: $(LIB_NAME)
    $(CC) -o test_memory_manager test_memory_manager.c -L. -lmemory_manager

// Test target to run the linked list test program
test_list: $(LIB_NAME) linked_list.o
    $(CC) -o test_linked_list linked_list.c test_linked_list.c -L. -lmemory_manager