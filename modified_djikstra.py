from collections import defaultdict

class Graph:
    def __init__(self):
        self.nodes = set()
        self.edges = defaultdict(list)
        self.distances = {}

    def add_node(self, value):
        self.nodes.add(value)

    def add_edge(self, from_node, to_node, distance):
        self.edges[from_node].append(to_node)
        # self.edges[to_node].append(from_node)
        self.distances[(from_node, to_node)] = distance

jj2 = Graph()
jj2.add_node((0, 'R'))
jj2.add_node((1, 'B'))
jj2.add_node((2, 'R'))
jj2.add_node((3, 'B'))
jj2.add_node((4, 'B'))
jj2.add_node((5, 'R'))
   
jj2.add_edge(0, 1, 5)
jj2.add_edge(1, 2, 4)
jj2.add_edge(2, 3, 6)
jj2.add_edge(1, 4, 2)
jj2.add_edge(2, 4, 6)
jj2.add_edge(0, 5, 2)
jj2.add_edge(5, 4, 7)
jj2.add_edge(5, 1, 8)
jj2.add_edge(4, 3, 1)

print(jj2.nodes)
# let's say: in order for you to move from one node to another,
#            the dest. node has to have different colority
def dijsktra(graph, initial):
    visited = {initial: 0}
    path = {}
    nodes = set(graph.nodes)
    while nodes: # why not have just visited
        min_node = None
        col = None
        for node in nodes:
            if node[0] in visited:
                if min_node is None or visited[node[0]] < visited[min_node]:
                    min_node = node[0]
                    col = node[1]
        if min_node is None:
            break
        nodes.remove((min_node, col))
        current_weight = visited[min_node]

        for edge in graph.edges[min_node]:
            weight = current_weight + graph.distances[(min_node, edge)]
            if edge not in visited or weight < visited[edge]:
                visited[edge] = weight
                path[edge] = min_node
    return visited, path
vis, pa = dijsktra(jj2, 0)
print("Vis: {0}\npa: {1}".format(vis, pa))
