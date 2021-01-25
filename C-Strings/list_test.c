// test functionality as well as error codes
#include "list.h"
#include <stdio.h>

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
	printf("new list is:\n");
	print_list(ll);
	printf("next, adding 'apple' to the list once more to demonstrate list freeing\n");
    
}
