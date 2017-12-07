#ifndef	MENU_H
#define MENU_H

/************** Constants *******************************/

/*** Note: INVALID is always the last item in this 'list' ****/
enum {QUIT, READ_GRAPH, RAND_REG_GRAPH3, RAND_REG_GRAPH4, RAND_AVG_GRAPH,  REMOVE_VERT_PLANARISE, ADD_VERT_PLANARISE,HYBRID, H_LAU, KM_MIPS, KM2_MIPS, KM3_MIPS, MIX,  SUBSET_REMOVE,  GROW_SINGLES,  GROW_TREE,  CLEVER_SINGLES, CLEVER_TREES, OUTER_PLANAR, PT_NEW,  MIX2, CREATE_TEST_GRAPH, RUN_TESTS, PRINT_GRAPH, RAND_REG_GRAPH, RAND_REG_GRAPH2, ROME,  INVALID};

/************** Function Prototypes *********************/
void displayMenu(void);
int getCommand(void);

#endif

