#include "list.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Allocates and initializes a new list. */
list * create_list() {
	return (list *) malloc(sizeof(list));
}

// a helper function
node * makeNewNode(char * item) {
	node * newNode = (node *) malloc(sizeof(node));
	strncpy(&newNode->c, item, 1);
	return newNode;	
}

/* Adds item to end of the list. This function allocates a* new buffer 
and copies the string from item (use malloc,* strlen, and strncpy; or 
try strdup).* Returns 0 if successful, non-zero otherwise. */
int add_to_list(list * ll, char * item) {
	// we assume that a string is one character long
	node * newNode;
	if (!ll->head) {
		newNode = makeNewNode(item);
		if (!newNode)
			return -1;
		ll->head = newNode;
	} else {
		node * temp = ll->head;
		while (temp->next) {

			temp = temp->next;
		}
		newNode = makeNewNode(item);
		if (!newNode)
			return -1;
		temp->next = newNode;
	}
	return 0;
}

/* Removes the string from the front of the list and* returns a pointer 
to it. The caller is expected to free* the string returned when finished 
with it. Returns NULL * if the list is empty. */
char * remove_from_list(list * ll) {
	char * ret;
	if (ll == NULL || ll->head == NULL)
		return NULL;
	node * temp = ll->head;
	ll->head = ll->head->next;
	*ret = temp->c;
	free(temp);
	return ret;
}

/* Prints every string in the list, with a new line* character at the 
end of each string. */
void print_list(list * ll) {
	node * tmp = NULL;
	if (ll)
		tmp = ll->head;
	while(tmp) {
		printf("%c\n", tmp->c);
		tmp = tmp->next;
	}
}

/* Flushes (clears) the entire list and re-initializes the* list. The 
passed pointer ll should still point to a* valid, empty list when this 
function returns. Any memory* allocated to store items in the list 
should be freed. * Returns the number of items flushed from the list. */
int flush_list(list* ll) {
	if (!ll || !ll->head) 
		return 0;
	node * next;
	node * curr = ll->head;
	int count = 0;
	while (curr) {
		next = curr->next;
		free(curr);
		curr = next;
		count += 1;	
	}
	ll = create_list();
	return count;
}
/* De-allocates all data for the list. Ensure all memory* allocated for this 
list is freed, including any* allocated strings and the list itself. */
// void free_list(list *ll) {
// 	int ret = flush_list(ll);
// 	if (ret != 0 && ll != NULL) {
// 		ll = NULL;
// 	}
// 	ll = NULL;
// }