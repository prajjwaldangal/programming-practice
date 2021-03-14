// test functionality as well as error codes

#include <stdio.h>
#include "list.h"
int main() {
	list * ll = create_list();
	char c = 'a';
	char c2 = 'p';
	char c3 = 'p';
	char c4 = 'l';
	char c5 = 'e';
	add_to_list(ll, &c);
	add_to_list(ll, &c2);
	add_to_list(ll, &c3);
	add_to_list(ll, &c4);
	add_to_list(ll, &c5);
<<<<<<< HEAD
	printf("wrote 'apple' to list one letter at a time, printing the list...\n");
    print_list(ll);
    printf("removing from the front of list ...\n");
    char * frontChar = remove_from_list(ll);
    printf("remove from list returns: %s\n", frontChar);
	printf("Currently the list is as follows:\n");
    print_list(ll); 
	frontChar = remove_from_list(ll);
    printf("remove from list returns: %s\n", frontChar);
	printf("Currently the list is as follows:\n");
    print_list(ll); 
	frontChar = remove_from_list(ll);
    printf("remove from list returns: %s\n", frontChar);
	printf("Currently the list is as follows:\n");
    print_list(ll); 
	frontChar = remove_from_list(ll);
    printf("remove from list returns: %s\n", frontChar);
	printf("Currently the list is as follows:\n");
    print_list(ll); 
	frontChar = remove_from_list(ll);
    printf("remove from list returns: %s\n", frontChar);
	printf("Currently the list is as follows:\n");
    print_list(ll); 
	frontChar = remove_from_list(ll);
    printf("remove from list returns: %s\n", frontChar);
	printf("Currently the list is as follows:\n");
    print_list(ll); 
    // printf("next, flushing list ...\n");
	// int flushCount = flush_list(ll);
    // printf("flushed: %d elements from the list\n", flushCount);
	// printf("new list is:\n");
	// print_list(ll);
	// printf("next, adding 'apple' to the list once more to demonstrate list freeing\n");
	return 0;
    
}
=======
	printf("wrote 'apple' to list, printing the list...\n");
    	print_list(ll);
    	printf("removing from the front of list ...\n");
    	char * frontChar = remove_from_list(ll);
    	printf("remove from list returns: %s\n", frontChar);
	printf("Currently the list is as follows:\n");
    	print_list(ll); 
    	printf("next, flushing list ...\n");
	int flushCount = flush_list(ll);
    	printf("flushed: %d elements from the list\n", flushCount);
	printf("next, adding 'apple' to the list once more to demonstrate list freeing");
    	add_to_list(ll, &c);
	// add_to_list(ll, &c2);
	// add_to_list(ll, &c3);
	// add_to_list(ll, &c4);
	// add_to_list(ll, &c5);
    	flush_list(ll);
    	// free_list(ll);
	print_list(ll);
}
>>>>>>> 6d0dd8496bf3f063f2140a42c8d8236991de5edc
