#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

list * create_list() {
	return (list *) malloc(sizeof(list));

}

node * makeNewNode(char * item) {
	node * newNode = (node *) malloc(sizeof(node));
	strncpy(&newNode->c, item, 1);
	return newNode;	
}

int add_to_list(list * ll, char * item) {
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

void print_list(list * ll) {
	node * tmp = NULL;
	if (ll)
		tmp = ll->head;
	while(tmp) {
		printf("%c\n", tmp->c);
		tmp = tmp->next;
	}
}

int main() {
	list * ll = create_list();
	char c = 'a';
	add_to_list(ll, &c);
	print_list(ll); 	
}
