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
#include "Gerirficheiros.h"
#pragma warning (disable: 4996)

#define k 20
#define N 10
#define DEBUG 1

#define MAX_PACIENTES 10
#define MAX_DIAS 7

#pragma region Informação da dieta
typedef struct InfDieta {
	int numP;
	char data[10];
	char refeicao[50];
	char alimento[50];
	char calorias[50];
}InfDieta;
#pragma endregion

#pragma region Paciente
typedef struct Paciente {
	int numP;
	char nome[20];
	char  tel[3];
	//InfDieta dieta[k];
}Paciente;
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

#pragma region TabelaPacientes
typedef struct TabelaPacientes {
	int numeroPaciente;
	char nome[50];
	char tipoRefeicao[20];
	char dataInicio[12];
	char dataFim[12];
	int caloriasMinimo;
	int caloriasMaximo;
	int consumoRealizado;
} TabelaPacientes;
#pragma endregion

#pragma region Funcoes
int ImportarPacientes(char nomeFicheiro[], Paciente paciente[]);
void MostraArrayPaciente(Paciente x[], int tamanho);
#pragma endregion