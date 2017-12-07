cdef extern from "planar/graph.h":
    cdef struct VertexRec:
        int* adjVerts
        int member
        int degree
    ctypedef VertexRec Vertex

    cdef Vertex* readGraph(int* size, int* d)
    cdef Vertex* initGraph(int size)
    cdef void initAdjLists(Vertex* G, int size)
    cdef void initMembers(Vertex* G, int size)
    cdef void killGraph(Vertex* G, int size)
    cdef int addEdge(Vertex* G, int size, int v, int w) 
    cdef int addEdge2(Vertex* G, int size, int v, int w) 
    cdef void printGraph(Vertex* G, int size) 

cdef extern from "planar/removeVertexAlg.h":
    cdef int removeVertAlg(Vertex* G, int size, int save)

cdef extern from "planar/addVertexAlg.h":
    cdef int addVertAlg(Vertex* G, int size, int save)

cdef extern from "planar/hybridAlg.h":
    cdef int hybrid(Vertex* G, int size, int save)

cdef extern from "planar/H_Lau.h":
    cdef int H_L_alg(Vertex* G, int size, int save)

cdef extern from "planar/K_Alg.h":
    cdef int M_MIPS(Vertex* G, int size, int save)
    cdef int growCleverSingleTreeAlg(Vertex* G, int size, int save)
    cdef int GrowCleverTrees(Vertex* G, int size, int save)
    cdef int CreateOPGraph(Vertex* G, int size, int save)

cdef extern from "planar/K2_Alg.h":
    cdef int M_MIPS_II(Vertex* G, int size, int save)
    cdef int M_MIPS_III(Vertex* G, int size, int save)
    cdef int PT_2006(Vertex* G, int size, int save)

cdef extern from "planar/mixture.h":
    cdef int mixture_Alg(Vertex* G, int size, int save)

cdef extern from "planar/subsetRem.h":
    cdef int subsetRemove(Vertex* G, int size, int save)

cdef extern from "planar/tree.h":
    cdef int growSingleTreeAlg(Vertex* G, int size, int save)
    cdef int growTreeAlg(Vertex* G, int size, int save)

cdef extern from "planar/mixture2.h":
    cdef int mixture2_Alg(Vertex* G, int size, int save)

