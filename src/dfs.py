import networkx
import numpy as np

G = diGraph();

marked = np.empty(shape=(len(nx.nodes(G)),), dtype=int)
edgeTo = np.empty(shape=(len(nx.nodes(G)),), dtype=int)

def dfs(G, v_node):
    marked[v_node] = True;
    for (w_node in G.neighbors(v_node)):
        if (marked[w_node] == 0):
            dfs(G, w_node)
            edgeTo[w_node] = v_node
