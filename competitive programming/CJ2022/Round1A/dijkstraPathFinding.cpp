#include <cstdio>
#include <iostream>

class Graph {

    Graph() {}
    Graph(int num_verts) {
        n = num_verts;
        graph = new int *[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new int[n];
        }
    }

    ~Graph() {
        for (int i = 0; i < n; i++) {
            delete [] graph[i];
        }
        delete [] graph;
    }

    private:
        int n;
        int ** graph;
};

int main() {

    return 0;
}