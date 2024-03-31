#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

int main(int argc, char* argv[]){
    bdd_manager bddm = bdd_init();

    bdd s0_0 = bdd_new_var_last(bddm);
    bdd s1_0 = bdd_new_var_last(bddm);
    bdd s2_0 = bdd_new_var_last(bddm);
    bdd s3_0 = bdd_new_var_last(bddm);
    bdd x0 = bdd_new_var_last(bddm);
    bdd t1_0 = bdd_new_var_last(bddm);
    bdd t0_0 = bdd_new_var_last(bddm);
    bdd r1 = bdd_new_var_last(bddm);
    bdd x1 = bdd_new_var_last(bddm);
    
    bdd r0 = bdd_one(bddm);
    bdd s0_1 = bdd_or(bddm,r0,bdd_or(bddm,bdd_and(bddm,x0,s3_0),bdd_and(bddm,bdd_not(bddm,x0),s1_0)));
    bdd s1_1 = bdd_and(bddm,bdd_not(bddm,r0),bdd_or(bddm,bdd_and(bddm,x0,s0_0),bdd_and(bddm,bdd_not(bddm,x0),s2_0)));
    bdd s2_1 = bdd_and(bddm,bdd_not(bddm,r0),bdd_or(bddm,bdd_and(bddm,x0,s1_0),bdd_and(bddm,bdd_not(bddm,x0),s3_0)));
    bdd s3_1 = bdd_and(bddm,bdd_not(bddm,r0),bdd_or(bddm,bdd_and(bddm,x0,s2_0),bdd_and(bddm,bdd_not(bddm,x0),s0_0)));

    bdd y1_0 = bdd_and(bddm,bdd_not(bddm,r0),bdd_or(bddm,bdd_and(bddm,x0,s3_0),bdd_and(bddm,bdd_not(bddm,x0),s1_0)));

    bdd var1 = bdd_xnor(bddm,t1_0,t0_0);
    bdd var2 = bdd_xnor(bddm,t1_0,t0_0);
    bdd y2_0 = bdd_and(bddm,bdd_not(bddm,r0),bdd_or(bddm,bdd_and(bddm,x0,var2),bdd_and(bddm,bdd_not(bddm,x0),var1)));
    bdd t1_1 = bdd_and(bddm,bdd_not(bddm,r0),bdd_or(bddm,bdd_and(bddm,x0,var1),bdd_and(bddm,bdd_not(bddm,x0),var2)));
    bdd t0_1 = bdd_nor(bddm,r0,t0_0);
    bdd x0_char = bdd_xnor(bddm,y1_0,y2_0);

    printf("-------------------------------------\n");
    bdd_print_bdd(bddm,x0_char,NULL,NULL,NULL,stdout);
    printf("-------------------------------------\n");

    if(x0_char){
        printf("Outputs are equals at k=0\n");
    }
    else{
        printf("outputs are not equal at k=0 and the property fails\n");
    }
    printf("-------------------------------------\n");

    bdd var3 = bdd_xor(bddm,t1_1,t0_1);
    bdd var4 = bdd_xnor(bddm,t1_1,t0_1);
    bdd y1_1 = bdd_and(bddm,bdd_not(bddm,r1),bdd_or(bddm,bdd_and(bddm,x1,s3_1),bdd_and(bddm,bdd_not(bddm,x1),s1_1)));
    bdd y2_1 = bdd_and(bddm,bdd_not(bddm,r1),bdd_or(bddm,bdd_and(bddm,x1,var4),bdd_and(bddm,bdd_not(bddm,x1),var3)));
    bdd x1_char = bdd_xnor(bddm,y1_1,y2_1);
    printf("-------------------------------------\n");
    bdd_print_bdd(bddm,x1_char,NULL,NULL,NULL,stdout);
    printf("-------------------------------------\n");

    bdd comp_one=bdd_one(bddm);
    if(x1_char==comp_one){
        printf("Outputs are equal at k=1\n");
    }
    else{
        printf("outputs are not equal at k=1\n");
        printf("Stop checking\n");
    }
    printf("-------------------------------------\n");
    bdd_print_bdd(bddm,y2_1,NULL,NULL,NULL,stdout);
    return(0);
}
