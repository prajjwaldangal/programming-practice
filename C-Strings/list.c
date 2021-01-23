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

list * makeNewList() {
	list * newList = (list *) malloc(sizeof(list));
	return newList;
}

int add_to_list(list * ll, char * item) {
	node * newNode = NULL;
	if (!ll) {
		list * newList = makeNewList();
		if (!newList)
			return -1;
		ll = newList;
		if (item) {
			newNode = makeNewNode(item);
			if (!newNode)
				return -1;
			else
				ll->head = newNode;				
		}
		return 0;
	}
	/*
	node * tmp = ll->head; // char * item = {'a','b', 'c'}
	while (tmp->next) {
		
		tmp = tmp->next;
	}
	for (int i = 0; i < (int) itemLen; i++) {
		
		tmp->next = makeNewNode(item[i]);
		tmp = tmp->next;
	}
	*/
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
	list * ll  = NULL;
	char c = 'a';
	add_to_list(ll, &c);
	print_list(ll); 	
}
