#!/usr/bin/env python3

import maximum_induced_planar_subgraph as mips
import networkx
import planarity
import matplotlib.pyplot as plt

G = networkx.fast_gnp_random_graph(10,0.7)
networkx.draw(G,with_labels=True)
plt.show()

for method in mips.planarise_methods():
    print("Planarisation with method "+method)
    M = mips.MIPSGraph(G)
    P = M.planarise(method)
    nodes = M.member_nodes()
    print(P,nodes)

    if len(nodes) > 0:
        K = G.copy()
        for n in list(K.nodes()):
            if n not in nodes:
                K.remove_node(n)

        P = planarity.PGraph(K)
        plt.figure()
        try:
            planarity.draw(P)
        except RuntimeError:
            print("Graph not planar")
            networkx.draw(K,with_labels=True)
        plt.show()

