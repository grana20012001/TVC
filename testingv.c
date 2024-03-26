#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

int main (int argc, char* argv[])
{
	// Create the universe..
	bdd_manager bddm = bdd_init();	

	// make 3 variables x0,x1,x2 (in that order)
	bdd x1 = bdd_new_var_last(bddm);
	bdd x2 = bdd_new_var_last(bddm);
	bdd x3 = bdd_new_var_last(bddm);
	bdd x4 = bdd_new_var_last(bddm);
	bdd x5 = bdd_new_var_last(bddm);
	bdd x6 = bdd_new_var_last(bddm);

	// compute y = (x2.x1)+x0
	bdd a  = bdd_and (bddm,x2,x1);	
	bdd b  = bdd_not (bddm,a);	
	bdd c = bdd_and(bddm,x3,x4);
	bdd d = bdd_not(bddm,c);
	bdd e = bdd_and(bddm,x5,x6);
	bdd f = bdd_not(bddm,e);

	bdd g = bdd_and(bddm,b,d);
	bdd y = bdd_and(bddm,g,f);

	printf("----------------------------------------------------\n");

	// print y
	bdd_print_bdd(bddm,y,NULL, NULL,NULL, stdout);


	printf("----------------------------------------------------\n");

	return(0);
}
