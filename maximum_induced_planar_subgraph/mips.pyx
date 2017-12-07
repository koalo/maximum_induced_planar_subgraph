#!python
#cython: embedsignature=True

cimport maximum_induced_planar_subgraph.cplanar as cplanar
from libc.stdlib cimport malloc
import planarity

def planarise_methods():
    return ['VR','VA','Hybrid','HL','OP1+EPS','PT','PT+EPS','VSR+EPS','VSR','Grow Singletons','Grow Tree','IS','T','OP1','OP2','Mixed']

cdef class MIPSGraph:
    cdef cplanar.Vertex* G
    cdef int size

    def __init__(self,graph):
        if not hasattr(graph,'embed_planar'):
            pgraph = planarity.PGraph(graph)
        else:
            pgraph = graph

        nodes = pgraph.nodes()
        edges = pgraph.edges()
        self.size = len(nodes)
        self.G = cplanar.initGraph(len(nodes))
        for v in nodes:
            # generate unique list of neighbors (in both directions!)
            neighbors = list(set([b for (a,b) in edges if a == v] + [a for (a,b) in edges if b == v]))
            self.G[v].degree = len(neighbors)
            self.G[v].adjVerts = <int*>malloc(sizeof(int)*self.G[v].degree)
            for i in range(len(neighbors)):
                self.G[v].adjVerts[i] = neighbors[i]

    def __dealloc__(self):
        cplanar.killGraph(self.G, self.size)

    def print_graph(self):
        cplanar.printGraph(self.G,self.size)

    def planarise(self,method):
        cplanar.initMembers(self.G,self.size)
        cplanar.initAdjLists(self.G,self.size)

        if method == 'VR':
            P = cplanar.removeVertAlg(self.G,self.size,False)
        elif method == 'VA':
            P = cplanar.addVertAlg(self.G,self.size,False)
        elif method == 'Hybrid':
            P = cplanar.hybrid(self.G,self.size,False)
        elif method == 'HL':
            P = cplanar.H_L_alg(self.G,self.size,False)
        elif method == 'OP1+EPS':
            P = cplanar.M_MIPS(self.G,self.size,False)
        elif method == 'PT':
            P = cplanar.M_MIPS_II(self.G,self.size,False)
        elif method == 'PT+EPS':
            P = cplanar.M_MIPS_III(self.G,self.size,False)
        elif method == 'VSR+EPS':
            P = cplanar.mixture_Alg(self.G,self.size,False)
        elif method == 'VSR':
            P = cplanar.subsetRemove(self.G,self.size,False)
        elif method == 'Grow Singletons':
            P = cplanar.growSingleTreeAlg(self.G,self.size,False)
        elif method == 'Grow Tree':
            P = cplanar.growTreeAlg(self.G,self.size,False)
        elif method == 'IS':
            P = cplanar.growCleverSingleTreeAlg(self.G,self.size,False)
        elif method == 'T':
            P = cplanar.GrowCleverTrees(self.G,self.size,False)
        elif method == 'OP1':
            P = cplanar.CreateOPGraph(self.G,self.size,False)
        elif method == 'OP2':
            P = cplanar.PT_2006(self.G,self.size,False)
        elif method == 'Mixed':
            P = cplanar.mixture2_Alg(self.G,self.size,False)
        else:
            print("Method not available")
            assert(False)

        return P

    def member_nodes(self):
        return [i for i in range(self.size) if self.G[i].member]
