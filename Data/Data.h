/*****************************************************************//**
 * \file   Funcoes.c
 *
 * \brief  Header File com a struct de Data e as suas funcoes
 * \author Grupo 03 / Bruno Dantas nº27958 / Diogo Abreu nº27975/ Paulo Gonçalves nº27966
 * \date  30 December 2023
 *********************************************************************/
#pragma once
#pragma warning (disable: 4996)
#pragma warning (disable: 6031)
#include "stdio.h"
typedef struct Data {
	int year;
	int month;
	int day;
}Data;

Data TransformaDataString(char datastring[]);
int IniciData(Data data);
