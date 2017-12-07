/**
 * Copyright (C) 2005, 2009  Kerri Morgan
 *
 * This file is part of the planar program package.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "runTests.h"
#include "linkList.h"
#include "rome.h"
#include "graph.h"
#include "menu.h"
#include "addVertexAlg.h"
#include "removeVertexAlg.h"
#include "graphGen.h"
#include "genRandGraph.h"
#include "bollobas.h"
#include "hybridAlg.h"
#include "tree.h"
#include "H_Lau.h"
#include "K_Alg.h"
#include "K2_Alg.h"
#include "linkList2.h"
#include "subsetRem.h"
#include "mixture.h"
#include "mixture2.h"

#define MAX 80
Vertex* G=NULL;
int main()
{
	char temp[MAX];
	int choice=1;
	int size;
	int degree;
	int P;
	int type;
	
	srand48(time(NULL));
	printf("Welcome to Version I of Kerri's Project\n");

	while(choice != 0)
        {
		displayMenu();
		choice = getCommand();
		switch(choice)
		{
			case READ_GRAPH:
				/* if we have already something read in G */
				if(G!=NULL)
				{
					killGraph(G, size);
					size=0;
				}
				G=readGraph(&size, &degree);
				if(G == NULL)
				{
					printf("Read from file failed.\n\n");
				}
				else
				{
					printGraph(G, size);
				}
				break;

			case RAND_REG_GRAPH:
				if(G!=NULL)
				{
					killGraph(G, size);
					G=NULL;
				}
				printf("Please enter the number of vertices required in the graph\n");
				fgets(temp, MAX, stdin);
				if((sscanf(temp, "%d", &size)!=1) || (size <= 0))
				{
					printf("Invalid number of vertices - unable to create graph\n");
					break;
				}
				printf("Please enter a positive integer d (the maximum degree of the graph)\n");
				fgets(temp, MAX, stdin);
				if((sscanf(temp, "%d", &degree)!=1) || (degree <0))
				{
					printf("Invalid degree entered - unable to create graph\n");
					break;
				}
				printf("Graph with size %d and degree %d\n", size, degree);
				G=genGraph(size, degree);
				printGraph(G, size);
				break;

			case RAND_REG_GRAPH2:
				if(G!=NULL)
				{
					killGraph(G, size);
					G=NULL;
				}
				printf("Please enter the number of vertices required in the graph\n");
				fgets(temp, MAX, stdin);
				if((sscanf(temp, "%d", &size)!=1) || (size <= 0))
				{
					printf("Invalid number of vertices - unable to create graph\n");
					break;
				}
				printf("Please enter a positive integer d (the maximum degree of the graph)\n");
				fgets(temp, MAX, stdin);
				if((sscanf(temp, "%d", &degree)!=1) || (degree <0))
				{
					printf("Invalid degree entered - unable to create graph\n");
					break;
				}
				printf("Graph with size %d and degree %d\n", size, degree);
				G=genGraph2(size, degree);
				printGraph(G, size);
				break;

			
			case RAND_REG_GRAPH3:
				if(G!=NULL)
				{
					killGraph(G, size);
					G=NULL;
				}
				printf("Please enter the number of vertices required in the graph\n");
				fgets(temp, MAX, stdin);
				if((sscanf(temp, "%d", &size)!=1) || (size <= 0))
				{
					printf("Invalid number of vertices - unable to create graph\n");
					break;
				}
				printf("Please enter a positive integer d (the maximum degree of the graph)\n");
				fgets(temp, MAX, stdin);
				if((sscanf(temp, "%d", &degree)!=1) || (degree <0))
				{
					printf("Invalid degree entered - unable to create graph\n");
					break;
				}
				printf("Graph with size %d and degree %d\n", size, degree);
				G=genGraph3(size, degree);
				printGraph(G, size);
				break;
		
			case RAND_REG_GRAPH4:	/* Bollobas */
				if(G!=NULL)
				{
					killGraph(G, size);
					G=NULL;
				}
				printf("Please enter the number of vertices required in the graph\n");
				fgets(temp, MAX, stdin);
				if((sscanf(temp, "%d", &size)!=1) || (size <= 0))
				{
					printf("Invalid number of vertices - unable to create graph\n");
					break;
				}
				printf("Please enter a positive integer d (the maximum degree of the graph)\n");
				fgets(temp, MAX, stdin);
				if((sscanf(temp, "%d", &degree)!=1) || (degree <0))
				{
					printf("Invalid degree entered - unable to create graph\n");
					break;
				}
				printf("Graph with size %d and degree %d\n", size, degree);
				//G=createRandomGraph(size, degree);
				G=createB_graph(size, degree);
				printGraph(G, size);
				break;


			case RAND_AVG_GRAPH:
				if(G!=NULL)
				{
					killGraph(G, size);
					G=NULL;
				}
				printf("Please enter the number of vertices required in the graph\n");
				fgets(temp, MAX, stdin);
				if((sscanf(temp, "%d", &size)!=1) || (size <= 0))
				{
					printf("Invalid number of vertices - unable to create graph\n");
					break;
				}
				printf("Please enter a positive integer d (the average degree of the graph)\n");
				fgets(temp, MAX, stdin);
				if((sscanf(temp, "%d", &degree)!=1) || (degree <0))
				{
					printf("Invalid degree entered - unable to create graph\n");
					break;
				}
				printf("Graph with size %d and degree %d\n", size, degree);
				G=classicalGen(size, degree);
				printGraph(G, size);
				break;

			case	REMOVE_VERT_PLANARISE:
				if(G!=NULL)
				{
					initMembers(G, size);
					initAdjLists(G, size);
					P=removeVertAlg(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;
			
			case	SUBSET_REMOVE:
				if(G!=NULL)
				{
					initMembers(G, size);
					initAdjLists(G, size);
					P=subsetRemove(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;

			case ADD_VERT_PLANARISE:
				if(G!=NULL)
				{
					initMembers(G,size);
					/* save graph for testing*/	
					P=addVertAlg(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;
			case HYBRID:
				if(G!=NULL)
				{
					initMembers(G,size);
					/* save graph for testing*/	
					P=hybrid(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;
			case GROW_SINGLES:
				if(G!=NULL)
				{
					initMembers(G, size);
					P=growSingleTreeAlg(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;

			case CLEVER_SINGLES:
				if(G!=NULL)
				{
					initMembers(G, size);
					P=growCleverSingleTreeAlg(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;

			case GROW_TREE:
				if(G!=NULL)
				{
					initMembers(G, size);
					P=growTreeAlg(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;
			case H_LAU:
				if(G!=NULL)
				{
					initMembers(G, size);
					P=H_L_alg(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;
			case CLEVER_TREES:
				if(G!=NULL)
				{
					initMembers(G, size);
					P=GrowCleverTrees(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;
			case OUTER_PLANAR:
				if(G!=NULL)
				{
					initMembers(G, size);
					P=CreateOPGraph(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;
			case PT_NEW:
				if(G!=NULL)
				{
					initMembers(G, size);
					P=PT_2006(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;
			case KM_MIPS:
				if(G!=NULL)
				{
					initMembers(G, size);
					initAdjLists(G, size);
					P=M_MIPS(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;

			case KM2_MIPS:
				if(G!=NULL)
				{
					initMembers(G, size);
					initAdjLists(G, size);
					P=M_MIPS_II(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;
			
			case KM3_MIPS:
				if(G!=NULL)
				{
					initMembers(G, size);
					initAdjLists(G, size);
					P=M_MIPS_III(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;

			case MIX2:
				if(G!=NULL)
				{
					initMembers(G, size);
					initAdjLists(G, size);
					P=mixture2_Alg(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;

			case MIX:
				if(G!=NULL)
				{
					initMembers(G, size);
					initAdjLists(G, size);
					P=mixture_Alg(G,size, 1);
					printf("Size is %d\n", P);
				}
				else
				{
					printf("No graph currently read in system to planarise\n");
				}
				break;

			case CREATE_TEST_GRAPH:
				if(G!=NULL)
				{
					killGraph(G, size);
					G=NULL;
				}
				printf("Please enter the number of vertices required in the graph\n");
				fgets(temp, MAX, stdin);
				if((sscanf(temp, "%d", &size)!=1) || (size <= 0))
				{
					printf("Invalid number of vertices - unable to create graph\n");
					break;
				}
				printf("Please enter a positive integer d (the degree of the graph)\n");
				fgets(temp, MAX, stdin);
				if((sscanf(temp, "%d", &degree)!=1) || (degree <0) || (degree >= size))
				{
					printf("Invalid degree entered - unable to create graph\n");
					break;
				}
				printf("Enter choice of method 1:Bollobas, 2: Steger-Wormald, 3: Erdos\n");
				fgets(temp, MAX, stdin);
				if((sscanf(temp, "%d", &type)!=1) || (type <1) || (type>3))
				{
					printf("Invalid choice of method\n");
					break;
				}
				createTestGraphs(size, degree, type);

				//printf("%d %d %d\n", size, degree, type);
				break;
			
			case RUN_TESTS:
				//runTests(); 
				printf("This option is now deactivated to avoid overwriting test results\n");
				break;

			case ROME:
				//runRomeTests(); 
				//exit(1);
				//runRomeTestsI();
				printf("This option is now deactivated\n");
				break;
			case PRINT_GRAPH:
				printGraph(G, size);
				break;
			
			default:
				break;	
		}
        }
	killGraph(G, size);
	return 0;
}
