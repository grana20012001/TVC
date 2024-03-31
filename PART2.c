#include <bdduser.h>

int main(int argc, char*,argv[])
{
    bdd_manager bddm = bdd_init();
    bdd u0 = bdd_new_var_last(bddm);
    bdd u1 = bdd_new_var_last(bddm);
    bdd u2 = bdd_new_var_last(bddm);
    bdd u3 = bdd_new_var_last(bddm);

    bdd a1 = bdd_and(bddm,u1,u0);
    bdd a2 = bdd_and(bddm,u3,u2);
    bdd a3 = bdd_and(bddm,u1,u2);
    bdd a4 = bdd_and(bddm,u2,u0);
    bdd a5 = bdd_and(bddm,u1,u3);
    bdd a6 = bdd_and(bddm,u3,u0);

    bdd sum1 = bdd_or(bddm,a1,a2);
    bdd sum2 = bdd_or(bddm,a3,sum1);
    bdd sum3 = bdd_or(bddm,sum2,a4);
    bdd sum4 = bdd_or(bddm,sum3,a5);

    bdd fdc= bdd_or(bddm,a1,bdd_or(bddm,a2,bdd_or(bddm,a3,bdd_or(bddm,a4,bdd_or(bddm,a5,a6)))));

    bdd ei = bdd_or(bddm,u3,bdd_or(bddm,u2,bdd_or(bddm,u1,u0)));
    bdd c1i = bdd_or(bddm,u3,u3);
    bdd c0i = bdd_or(bddm,u3,u1);

    bdd var2 = bdd_and(bddm,bdd_and(bddm,bdd_not(bddm,u3),bdd_not(bddm,u2)),bdd_and(bddm,bdd_not(bddm,u1),u0));
    bdd var3 = bdd_and(bddm,bdd_and(bddm,bdd_not(bddm,u3),bdd_not(bddm,u2)),bdd_and(bddm,u1,bdd_not(bddm,u0)));
    bdd var4 = bdd_and(bddm,bdd_and(bddm,bdd_not(bddm,u3),u2),bdd_and(bddm,bdd_not(bddm,u1),bdd_not(bddm,u0)));
    bdd var5 = bdd_and(bddm,bdd_and(bddm,u3,bdd_not(bddm,u2)),bdd_and(bddm,bdd_not(bddm,u1),bdd_not(bddm,u0)));
    bdd es  = bdd_or(bddm,var5,bdd_or(bddm,var4,bdd_or(bddm,var3,var2)));
    bdd c1s = bdd_or(bddm,var4,var5);
    bdd c0s = bdd_or(bddm,var3,var5);

    bdd eq1 = bdd_xnor(bddm,ei,es);
    bdd eq2 = bdd_xnor(bddm,c1i,c1s);
    bdd eq3 = bdd_xnor(bddm,c01,c0s);
    bdd eq_and = bdd_and(bddm,eq1,bdd_and(bddm,eq2,eq3));

    bdd x_char=bdd_or(bddm,fdc,eq_and);

    printf("-----------------------------------\n");

    bdd_print_bdd(bddm,x_char,NULL,NULL,NULL,stdout);
    if(x_char){
        printf("Implementation and specification are equal\n");
    }
    else{
        printf("Implementation and specification are not equal\n");
    }
    printf("------------------------------------\n");
    return(0);
}
