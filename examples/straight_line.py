#!/usr/bin/env python3

# Utilizes an algorithm for drawing a planar graph
# with straight lines by M. Chrobak, T. Payne
#
# Requires the installation of graph-tools
# https://graph-tool.skewed.de/download

import maximum_induced_planar_subgraph as mips
import networkx
from networkx.drawing.nx_agraph import graphviz_layout
import matplotlib.pyplot as plt
import graph_tool as gt
import graph_tool.generation
import graph_tool.draw
import planarity

# Generate a graph
G = networkx.fast_gnp_random_graph(10,0.4)

# Plot the graph
plt.figure()
networkx.draw(G,with_labels=True)

# Find an approximate MIPS
(P,K) = mips.approximate_mips(G)

# If found, plot
if P > 0:
    g = gt.Graph(directed=False)
    for (v,w) in K.edges():
        g.add_edge(v,w)
    pos = gt.draw.planar_layout(g)
    J = planarity.networkx_graph(K)

    plt.figure()
    networkx.draw(J, pos=pos, with_labels=True)

    plt.figure()
    pos = {n: tuple(pos[n]) for n in K.nodes()}
    ppos = networkx.spring_layout(J,pos=pos)
    networkx.draw(J, pos=ppos, with_labels=True)

plt.show()

