/*
--Trabalho de Grupo--
Bruno dantass - 27958@alunos.ipca.pt
Diogo Abreu - 27975@alunos.ipca.pt
Paulo Gonçalves - 27966@alunos.ipca.pt
DATA : HOJE
Nutricionistas
*/
#pragma once
#include <stdio.h>
#pragma warning (disable: 4996)

/*
* #define algumas
*/

#define k 200
#define N 10
#define DEBUG 1

#define MAX_PACIENTES 10
#define MAX_DIAS 7


#pragma region Paciente
typedef struct Paciente {
	int numP;
	char nome[20];
	char  tel[3];
	InfDieta dieta[k]
}Paciente;
#pragma endregion

#pragma region Informação da dieta
typedef struct InfDieta {
	int numP;
	char data[10];
	char refeicao[50];
	char alimento[50];
	char calorias[50];
}InfDieta;
#pragma endregion

#pragma region Planos nutricionais
typedef struct PlNutricionais {
	int numPaciente;
	char dataRefeicao[10];
	char refeicao[50];
	char calMinimas[15];
	char calMax[15];
}PlNutricionais;
#pragma endregion
