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
#include "menu.h"

#define MAX 80	/* maximum read in an input line from stdin */

/******************************************************************************
** Function:	displayMenu
** Description: Displays menu options
** Inputs:	none
** Return Value:none
** Side Effects:
** Created:	Kerri Morgan	3rd March, 2005
** Modified:
** Comments:	
** Acknowledgements:
******************************************************************************/
void displayMenu(void)
{
	printf("Select one of the following options:\n");
	printf("%d: Quit\n", QUIT);
	printf("%d: Read graph from user-specified file\n", READ_GRAPH);
//	printf("%d: Randomly generate a d-regular graph\n", RAND_REG_GRAPH);
	//printf("%d: Randomly generate a d-regular graph using modified Wormald-Stegar algorithm\n", RAND_REG_GRAPH2);
	printf("%d: Randomly generate a d-regular graph using Steger Wormald algorithm\n", RAND_REG_GRAPH3);
	printf("%d: Randomly generate a d-regular graph using Bollobas algorithm\n", RAND_REG_GRAPH4);
	printf("%d: Randomly generate a graph of average degree d using Erdos algorithm\n", RAND_AVG_GRAPH);
	//printf("%d: Planarise - Removal of Vertices Algorithm\n", REMOVE_VERT_PLANARISE);
	printf("%d: Planarise - VR Algorithm\n", REMOVE_VERT_PLANARISE);
	printf("%d: Planarise - VA Algorithm\n", ADD_VERT_PLANARISE);
	//printf("%d: Planarise - Adding Vertices Algorithm\n", ADD_VERT_PLANARISE);
	printf("%d: Planarise - Hybrid Algorithm\n", HYBRID);
	printf("%d: Planarise - HL Algorithm\n", H_LAU);
	//printf("%d: Planarise - Halldorsson and Lau Algorithm\n", H_LAU);
	printf("%d: Planarise - OP1+EPS\n", KM_MIPS);
	//printf("%d: Planarise - M_MIPS\n", KM_MIPS);
	printf("%d: Planarise - PT\n", KM2_MIPS);
	//printf("%d: Planarise - Palm Trees\n", KM2_MIPS);
	printf("%d: Planarise - PT+EPS\n", KM3_MIPS);
	//printf("%d: Planarise - M_MIPS_III(Palm Trees + Extend Algorithm)\n", KM3_MIPS);
	printf("%d: Planarise - VSR+EPS\n", MIX);
	//printf("%d: Planarise - Mixed Method\n", MIX);
	printf("%d: Planarise - VSR Algorithm\n", SUBSET_REMOVE);
	//printf("%d: Planarise - Subset Removal Algorithm\n", SUBSET_REMOVE);
	printf("%d: Planarise - Grow Singletons Algorithm\n", GROW_SINGLES);
	printf("%d: Planarise - Grow Tree Algorithm\n", GROW_TREE);
	printf("%d: Planarise - IS\n", CLEVER_SINGLES);
	//printf("%d: Planarise - Selective Growth of Singletons Algorithm\n", CLEVER_SINGLES);
	printf("%d: Planarise - T Algorithm\n", CLEVER_TREES);
	//printf("%d: Planarise - Selective Growth of Trees Algorithm\n", CLEVER_TREES);
	printf("%d: Planarise - OP1 Algorithm\n", OUTER_PLANAR);
	//printf("%d: Planarise - Outerplanar Graph\n", OUTER_PLANAR);
	printf("%d: Planarise - OP2 Algorithm\n", PT_NEW);
	//printf("%d: Planarise - 2006 Version of Palm Trees Graph (Outerplanar Algorithm 2)\n", PT_NEW);
	printf("%d: Planarise - Mixed Method 2\n", MIX2);
	printf("%d: Create Test Graphs\n", CREATE_TEST_GRAPH);
	printf("%d: Run Tests\n", RUN_TESTS);
	printf("%d: Print Graph\n", PRINT_GRAPH);
	printf("%d: Run Rome Tests\n", ROME);

}

/******************************************************************************
** Function:	getCommand
** Description: Function gets a choice entered by user responding to menu 
**		displayed by displayMenu function.
** Inputs:	none
** Return Value:action - integer indicating choice made by user
** Side Effects: If choice is invalid, function prints error message to screen
** Created:	Kerri Morgan	3rd March, 2005
** Modified:
** Comments:	
** Acknowledgements:
******************************************************************************/
int getCommand(void)
{
	char temp[MAX];
	int command;	
	
	fgets(temp, MAX, stdin);
	if(sscanf(temp, "%d", &command) !=1)
	{
		printf("WARNING 1.1: Invalid command: %s\n", temp);
		command = INVALID;
	}
	else if(command < QUIT || command > INVALID)
	{
		printf("WARNING 1.1: Invalid command: %s\n", temp);
		command = INVALID;
	}
	return command;

}
