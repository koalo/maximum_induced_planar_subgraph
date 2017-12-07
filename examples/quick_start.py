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

plt.show()
