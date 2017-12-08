#!/usr/bin/env python3

import maximum_induced_planar_subgraph as mips
import networkx
import planarity
import matplotlib.pyplot as plt

# Generate a graph
G = networkx.fast_gnp_random_graph(10,0.7)

# Plot the graph
plt.figure()
networkx.draw(G,with_labels=True)

# Find an approximate MIPS
(P,K) = mips.approximate_mips(G)

# If found, plot
if P > 0:
    plt.figure()
    planarity.draw(K)

    plt.figure()
    K.embed_drawplanar()
    J = planarity.networkx_graph(K)

    pos = {}
    for node, data in J.nodes(data=True):
        print(data)
        y = data['pos']
        xb = data['start']
        xe = data['end']
        x = int((xe+xb)/2)
        pos[node] = (x,y)

    pos = networkx.spring_layout(J,pos=pos)
    networkx.draw(J, pos=pos, with_labels=True)

plt.show()
