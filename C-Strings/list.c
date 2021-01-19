#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

list * create_list() {
	return (list *) malloc(sizeof(list));	
}
/*
int add_to_list(list * ll, char * item) {
	list * tmp = ll;// char * item = {'a','b'}
	if (!tmp) 
		ll->head = 	
	while (tmp) {
		
		tmp = tmp->next;
	}
	tmp = (list
}
*/
int main() {
	char * item = (char *) malloc(2);
	printf("item before: %s\n", item);	
	strncpy(item, "abz", 2);
	printf("item after: %s\n", item);	
	return 0;
}
