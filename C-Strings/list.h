struct node {
	char c;
	struct node * next;
};
typedef struct node node;
struct list {
	node * head;
};

typedef struct list list;
list * create_list();
int add_to_list(list * ll, char * item);
char * remove_from_list(list * ll);
void print_list(list * ll);
int flush_list(list* ll);
void free_list(list *ll);
