#include"func.h"
#include"f_graph.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>


/* this fucntion verify if an item already is in table*/
int ItemExist(char* Relation, char *ATT)
{
	/* search for ATT on relation*/
	size_t i;
	for (i = 0; i < strlen(ATT); i++) {
		if (CharSearch(Relation, ATT[i]))break;
	}
	if (i != strlen(ATT))return 0;/* does not exist*/
	else return 1;/* it exists */
}
/* this fucntion for an attribue in DF* */
int Catt(DF * tab, int d, char* Att) {
	int i;
	for (i = 0; i < d; i++)
		if (strcmp(tab[i].lf, Att) == 0) {
			break;
		}
	if (i != d)return i; /* attribue exist in left side*/
	else return -1; /* attribue doesn't exist in left side*/
}
void Calculate_Closure(char* ORIGINE, DF * tab, char* FFF, int d, char* Clos) {
	Add_FFF_DP(tab, FFF, d, Clos);
	int lev = Catt(tab, d, FFF);
	if (lev != -1 && strcmp(tab[lev].rg,ORIGINE) != 0)
	{
			Add_FFF_DP(tab, tab[lev].rg, d, Clos);
			Calculate_Closure(ORIGINE, tab, tab[lev].rg, d, Clos);
	}
}
void Add_FFF_DP(DF * tab, char* FFF, int d, char* Clos) {
	int i;
	for (i = 0; i < d; i++)
		if (strcmp(tab[i].lf , FFF) == 0)
			if (!ItemExist(Clos, tab[i].rg)) {
				Clos = strcat(Clos, ",");
				Clos = strcat(Clos, tab[i].rg);
			}
}
int VRF_Key(char * Relation, char * clos){
	if (ItemExist(clos,Relation))
		return 1; /* it's a KEY  */
	return 0; /*  it's Not a KEY  */
}
char* Getstring(){
	int i = 0, j = 1;
	char c;
	char* string = NULL;
	string = (char*)malloc(sizeof(char));
	if (string == NULL)
	{
		printf("err allocation\n");
		exit(EXIT_FAILURE);
	}
	do {
        RE :
		c = getc(stdin);
		if(i == 0 && c == '\n')goto RE;
		string = (char*)realloc(string, j*sizeof(char));
		if (string == NULL)
		{
			printf("err allocation\n");
			exit(EXIT_FAILURE);
		}
		string[i] = c;
		i++; j++;
	} while (c != '\n');
	string[i - 1] = '\0';
	return string;

}
int CharSearch(char * Relation, char C) {
	for (; *Relation != C; Relation++)
		if ( *Relation == '\0')return 1; /* if C is not there*/
	return 0;/*  if C is there  */
}
void Show_DFs(DF* tab, int d) {

gf.showLeftSide("",1); std::cout << "FUNCTIONAL DEPENDANCIES :\n";
	for (int i = 0; i < d; i++){
                gf.showLeftSide("");printf("%s  -- >  %s", tab[i].lf, tab[i].rg);
	}
}
void Get_DFs(DF * tab, int d,char * Relation) {
	int i;
	for (i = 0; i<d; i++) {
		/*printf("\t   DF : %d ", i + 1);
		printf("\n\tEntrer Le champ Left  >");
		tab[i].lf = Getstring();

		printf("\n\tEntrer Le champ Right  >");
		tab[i].rg = Getstring();*/
        retry1:
        gf.footerLine("");std::cout<<i+1<<" Left side  -> : ";
        tab[i].lf = Getstring();
        if (!ItemExist(Relation,tab[i].lf) || strcmp(tab[i].lf,",")==0)
		{
			gf.warning("Input Orror !!!! Retry ");
			goto retry1;
		}
		retry2 :
        gf.footerLine("");std::cout<<i+1<<" Right side  -> : ";
        tab[i].rg = Getstring();
        if (!ItemExist(Relation, tab[i].rg) || strcmp(tab[i].rg,",")==0)
		{
			gf.warning("Input Orror !!!! Retry ");
			goto retry2;
		}
	}
	gf.footerLine("----> press Enter <---- ");
}
void freetab(DF * tab,int d) {
	for (int i = 0; i < d; i++)
	{
		free(tab[i].rg);
		free(tab[i].lf);
	}
	free(tab);
}
void printFileTXT(FILE * fp){
     char CH;
    do{
        CH = fgetc(fp);
        printf("%c",CH);
        gf.wait(0.9);
    }while(CH != EOF);
}
