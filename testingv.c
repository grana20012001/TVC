#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

int main (int argc, char* argv[])
{
	bdd_manager bddm = bdd_init();

	bdd x0 = bdd_new_var_last(bddm);//0
	bdd x1 = bdd_new_var_last(bddm);//1
	bdd x2 = bdd_new_var_last(bddm);//2
	bdd x3 = bdd_new_var_last(bddm);//3
	bdd y0 = bdd_new_var_last(bddm);//4
	bdd y1 = bdd_new_var_last(bddm);//5
	bdd y2 = bdd_new_var_last(bddm);//6
	bdd y3 = bdd_new_var_last(bddm);//7	

	bdd s3 = bdd_new_var_last(bddm);//8
	bdd s2 = bdd_new_var_last(bddm);//9
	bdd s1 = bdd_new_var_last(bddm);//10
	bdd s0 = bdd_new_var_last(bddm);//11
	bdd cout =bdd_new_var_last(bddm);//12

	bdd s0_tmp  = bdd_xor (bddm, x0, y0);
	bdd c1 = bdd_and (bddm, x0, y0);

	bdd s1_tmp  = bdd_xor (bddm, x1, bdd_xor (bddm, y1, c1));
	bdd c2 = bdd_or(bddm, bdd_and (bddm, x1, y1), bdd_and(bddm, c1, bdd_xor(bddm, x1, y1)));

	bdd s2_tmp  = bdd_xor (bddm, x2, bdd_xor (bddm, y2, c2));
	bdd c3 = bdd_or(bddm, bdd_and (bddm, x2, y2), bdd_and(bddm, c2, bdd_xor(bddm, x2, y2)));

	bdd s3_tmp  = bdd_xor (bddm, x3, bdd_xor (bddm, y3, c3));
	bdd c0_tmp = bdd_or(bddm, bdd_and (bddm, x3, y3), bdd_and(bddm, c3, bdd_xor(bddm, x3,y3)));
	
	
	bdd term1 = bdd_xnor(bddm, s0, s0_tmp);
	bdd term2 = bdd_xnor(bddm, s1, s1_tmp);
	bdd term3 = bdd_xnor(bddm, s2, s2_tmp);
	bdd term4 = bdd_xnor(bddm, s3, s3_tmp);
	bdd term5 = bdd_xnor(bddm,cout,c0_tmp);

	bdd Xf = bdd_and(bddm, term1, bdd_and(bddm, term2, bdd_and(bddm, term3, bdd_and(bddm,term4,term5))));

	bdd inp_t1 = bdd_and(bddm, bdd_xor(bddm, x0, x1), bdd_xnor(bddm, x2, x3));
	bdd inp_t2 = bdd_and(bddm, bdd_xor(bddm, x2, x3), bdd_xnor(bddm, x0, x1));
	bdd inp1 = bdd_or(bddm, inp_t1, inp_t2);

	bdd inp_t3 = bdd_and(bddm, bdd_xor(bddm, y0, y1), bdd_xnor(bddm, y2, y3));
	bdd inp_t4 = bdd_and(bddm, bdd_xor(bddm, y2, y3), bdd_xnor(bddm, y0, y1));
	bdd inp2 = bdd_or(bddm, inp_t3, inp_t4);
	
	bdd inp = bdd_and(bddm,inp1,inp2);


	//Existentially quantification
	bdd Qrmv[9];
	Qrmv[0] = x0; Qrmv[1] = x1; Qrmv[2] = x2; Qrmv[3] = x3;
	Qrmv[4] = y0; Qrmv[5] = y1; Qrmv[6] = y2; Qrmv[7] = y3; Qrmv[8] = NULL;

	int exist_assoc = bdd_new_assoc(bddm,Qrmv,0);

	bdd Inp_and_Xf = bdd_and(bddm, inp, Xf);
	bdd_assoc(bddm, exist_assoc);
	bdd out_image = bdd_exists(bddm, Inp_and_Xf);

	printf("\n-----------------\nBDD of Possible Outputs\n-----------------\n");
	bdd_print_bdd(bddm, out_image, NULL, NULL,NULL, stdout);
	printf("\n-----------------\n");
	return(0);
}
