import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.animation as animation

def mst(graph_edges, vertices):
    G = nx.Graph()
    for edge in graph_edges:
        G.add_edge(edge[0], edge[1], weight=edge[2])
    p = nx.spring_layout(G)
    fig, ax = plt.subplots()

    def update(frame):
        ax.clear()
        ax.set_title(f"Frame {frame + 1}")

        edges_to_highlight = graph_edges[:frame + 1]

        nx.draw_networkx_nodes(G, p, ax=ax)
        nx.draw_networkx_edges(G, p, edgelist=edges_to_highlight, edge_color='r', ax=ax)
        nx.draw_networkx_labels(G, p, ax=ax)
        nx.draw_networkx_edge_labels(G, p, edge_labels={(u, v): G[u][v]['weight'] for u, v in edges_to_highlight}, ax=ax)
    anim = animation.FuncAnimation(fig, update, frames=len(graph_edges), repeat=False)
    plt.show()


graph_edges = []
mst(graph_edges, vertices=0)
