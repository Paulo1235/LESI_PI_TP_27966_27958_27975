/**
 * @file Gabinete.h
 * @author Grupo 03 / Bruno Dantas nº27958 / Diogo Abreu nº27975/ Paulo Gonçalves nº27966
 * @brief Header file no qual estão declaradas as estruturas dos dados (InfDieta, Paciente, PlNutricionais, TabelaPacientes)
 * @version 1.0
 * @date 2023-12-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <stdio.h>
#pragma warning (disable: 4996)


#define k 20
#define N 10
#define DEBUG 1
#define LimiteCalorias 100
#define tamanhoDieta 5
#define tamanhopaciente 6
#define tamanhoDietaDetalhada 3
#define tamanhoMediacalorias 3

#define MAX_PACIENTES 10
#define MAX_DIAS 7

#pragma region Informacao da dieta
/**
 * @brief Dados da dieta
 * 
 */
typedef struct InfDieta {
	int numP;
	char data[11];
	char refeicao[50];
	char alimento[50];
	int calorias;
}InfDieta;
#pragma endregion

#pragma region Paciente
/**
 * @brief Dados do paciente
 * 
 */
typedef struct Paciente {
	int numP;
	char nome[20];
	int  tel;
}Paciente;
#pragma endregion

#pragma region Planos nutricionais
/**
 * @brief Struct dos Dados dos Planos Nutricionais
 * 
 */
typedef struct PlNutricionais {
	int numPaciente;
	char dataRefeicao[11];
	char refeicao[50];
	int calMinimas;
	int calMax;
}PlNutricionais;
#pragma endregion

#pragma region TabelaPacientes
/**
 * @brief Struct das Tabelas dos Pacientes
 * 
 */
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



