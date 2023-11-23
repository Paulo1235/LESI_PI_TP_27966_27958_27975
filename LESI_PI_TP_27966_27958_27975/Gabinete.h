/*
--Trabalho de Grupo--
Bruno dantass - 27958@alunos.ipca.pt
Diogo Abreu - 27975@alunos.ipca.pt
Paulo Gonçalves - 27966@alunos.ipca.pt
DATA : HOJE
Nutricionistas
*/
#pragma once


#pragma region Paciente
typedef struct Paciente {
	int num;
	char nome[20];
	int tel;
}Paciente;
#pragma endregion

#pragma region Informação da dieta
typedef struct InfDieta {
	int numPaciente;
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
