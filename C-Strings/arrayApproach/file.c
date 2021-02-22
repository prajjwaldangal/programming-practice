#include "file.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* Allocates and initializes a new list. */
list* create_list() {
    
    list * myList = (list *) malloc(sizeof(list));
    myList->string = (char *) malloc(64);
    myList->size = 64;
    myList->currIndx = 0;
    return myList;
}

list * _expandListAndCopy(list *ll) {
    list * newList = (list *) malloc(sizeof(list));
    if (!newList)
        return NULL;
    newList->string = (char *) malloc(ll->size * 2);
    if (!newList->string)
        return NULL;
    strncpy(newList->string, ll->string, ll->size);
    newList->currIndx = ll->currIndx;
    newList->size = ll->size * 2;
    free(ll);
    return newList;
}

int _add_to_list(list *ll, char *item, size_t len) {
    if (ll->currIndx + len >= ll->size) {
        ll = _expandListAndCopy(ll);
    }
    size_t i;
    for (i = ll->currIndx; i < len; i ++) {
        ll->string[i] = item[i];
    }
    ll->currIndx += (len-1);
    // can also try, strncpy(ll->string[ll->currIndx], item, len)
}

int add_to_list(list* ll, char* item) {
    if (!ll || !ll->string)
        return -1;
    size_t l = strlen(item);
    _add_to_list(ll, item, l);
}

/* Prints every string in the list, with a new line* character at the 
end of each string. */
void print_list(list * ourList) {
    size_t i;
    printf("Currently the list is:\n");
    for (i=0; i<= ourList->currIndx; i++) {
        printf("%c\n", ourList->string[i]);
    }
}

int main() {
    list * ourList = create_list();
    char c = 'a';
	char c2 = 'p';
	char c3 = 'p';
	char c4 = 'l';
	char c5 = 'e';
	printf("%d\n", add_to_list(ourList, &c));
    print_list(ourList);
    return 0;
}