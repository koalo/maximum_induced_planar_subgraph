import os
import sys

import setuptools
from setuptools import setup

from distutils.extension import Extension
from Cython.Distutils import build_ext

long_description  = """
"""

classifiers = []

sourcefiles = ['maximum_induced_planar_subgraph/mips.pyx']
sourcefiles.extend(["maximum_induced_planar_subgraph/planar/"+f for f in ['main.c','linkList.c','node.c','menu.c','graph.c','addVertexAlg.c','subsetRem.c','removeVertexAlg.c','graphGen.c','genRandGraph.c','runTests.c','bollobas.c','hybridAlg.c','tree.c','H_Lau.c','K2_Alg.c','K_Alg.c','linkList2.c','node2.c','mixture.c','mixture2.c','rome.c']])

setup(
    name= 'maximum_induced_planar_subgraph',
    packages=setuptools.find_packages(),
    classifiers = classifiers,
    long_description = long_description,
    license = 'GPL',
    cmdclass = {'build_ext': build_ext},
    ext_modules = [Extension("maximum_induced_planar_subgraph.mips",
                             sourcefiles,
                             include_dirs=['maximum_induced_planar_subgraph','maximum_induced_planar_subgraph/planar/'],
                             )],
    install_requires=['setuptools','cython','planarity'],
)
