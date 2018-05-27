#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the cost function below.
int cost(int B_count, int* B) {
    int k;
    struct entry {
        int count;
        char * strng;
    };
    typedef struct entry entry;
    entry T[B_count][B_count];
    for (int i=0; i<B_count; i++) {
        for (int j = 0; j<B_count; j++) {
            T[i][j].count = 0;
            T[i][j].strng = malloc(sizeof(char)*(j+1));
            T[i][j].strng = "";
        }
    }
    for (int i=0; i<B_count; i++) {
        for (int j = 0; j<B_count; j++) {
            //if (T[i][j] == T[i+1, j])
        }
    }
    char * a = 'a';
    char * b = 'b';
    if (a==b) {
	printf("Works like that");
    } else {
	printf("Doesn't work like that");
    }
    return k; 
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* n_endptr;
        char* n_str = readline();
        int n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        char** B_temp = split_string(readline());

        int* B = malloc(n * sizeof(int));

        for (int B_itr = 0; B_itr < n; B_itr++) {
            char* B_item_endptr;
            char* B_item_str = *(B_temp + B_itr);
            int B_item = strtol(B_item_str, &B_item_endptr, 10);

            if (B_item_endptr == B_item_str || *B_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(B + B_itr) = B_item;
        }

        int B_count = n;

        int result = cost(B_count, B);

        fprintf(fptr, "%d\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}


