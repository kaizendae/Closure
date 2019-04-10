#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _FUNC_
#define _FUNC_
#include"f_graph.h"
typedef struct fonctdep {
	char* lf;
	char* rg;
}DF;
int ItemExist(char * tab, char * C);
int Catt(DF * tab, int d, char * Att);
void Calculate_Closure(char *ORIGINE, DF * tab, char *  FFF, int d, char* Clos);
void Add_FFF_DP(DF * tab, char * FFF, int d, char* Clos);
int VRF_Key(char * Rela, char* clos);
char* Getstring();
int CharSearch(char * Relation, char C);
void Show_DFs(DF* tab, int d);
void Get_DFs(DF * tab, int d,char * Relation);
void freetab(DF * tab, int d);
void printFileTXT(FILE * fp);
#endif // !1


