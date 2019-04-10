/*
============================================================================
Name        : Closure.c
Author      : elasri
Version     :
Copyright   : Your copyright notice
Description : Hello World in C, Ansi-style
============================================================================
*/
#include"f_graph.h"
#include"func.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(void) {
    system("mode 120,35");
    system("color 3");

    FILE * fp = NULL;
    fp = fopen("Elasri.txt","r");
    printFileTXT(fp);

    system("pause>NULL");
	/*Relation Input *****************/
	gf.clrscr();
    gf.headerLine("Good Morning Every body");
    system("pause>NULL");
    gf.headerLine(" Mini Project : Closure calculator ");

	char * Relation;
	do {
        gf.footerLine("Enter Your Relation.Attribues Separated By ( , )   >");
		Relation = Getstring();
	} while (strlen(Relation) == 0);
	gf.showRightSide("Relation is :");
	gf.showRightSide(Relation);
	int d;
	gf.footerLine("How Many Func Dep u Got  >");
	scanf("%d", &d);
	while (getchar() != '\n');

	DF *tab = NULL;
	tab = (DF *)malloc(d*sizeof(DF));

	/*DF Input ********/
	Get_DFs(tab, d,Relation);
	/* ********** Input *********/
	Show_DFs(tab, d);
	char *clos = NULL;
	char* FFF = NULL;
     char MM ;


	OTHER_ATT:


	retry:
        while (getchar() != '\n');
		gf.footerLine(" >>Enter Attribue To calculate Closure  >");
		FFF = Getstring();
		if (!ItemExist(Relation, FFF) || strcmp(FFF," ")== 0 )
		{
			gf.warning("Input Orror !!!! Retry ");
			goto retry;
		}


		/********** calcule closure poour FFF**********/

		clos = (char *)calloc(strlen(FFF), sizeof(char));
		strcpy(clos, FFF);
		Calculate_Closure(FFF, tab, FFF, d, clos);

		/********** calcule closure poour FFF**********/

		/* if an attribue is in right side of dep */
		int i;
		for (i = 0; i < d; i++)
			if (ItemExist(clos, tab[i].lf))
				Add_FFF_DP(tab, tab[i].lf, d, clos);

		/************** Verify Key ***********/
		if (VRF_Key(Relation, clos)){
                gf.showRightSide("",0);
                printf("{ %s } + = { %s }",FFF,clos);
                printf("\t%s is KEY ",FFF);
		}
		else {
            gf.showRightSide("",0);
            printf("{ %s } + = { %s }",FFF,clos);
            printf("\t%s is NOT KEY ",FFF);
		}


         gf.footerLine("To calculate other candidate press....(y/n)  >");
         do{
        scanf("%c",&MM);
         }while(MM == '\n');
    if(MM == 'y')
        goto OTHER_ATT;

	free(FFF);
	freetab(tab,d);
	//free(clos);
	FILE * fm = NULL;
	system("cls");
    fm = fopen("goodbye.txt","r");
    printFileTXT(fm);
	/*****   Memory FREE   ******/

	return EXIT_SUCCESS;
}




