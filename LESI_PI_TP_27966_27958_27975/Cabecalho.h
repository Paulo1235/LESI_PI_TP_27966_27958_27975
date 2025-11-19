/**
 * @file Cabeçalho.h
 * @author Grupo 03 / Bruno Dantas nº27958 / Diogo Abreu nº27975/ Paulo Gonçalves nº27966
 * @brief Header file no qual estão declaradas as funções (Data, Mediacalorias)
 * @version 1.0
 * @date 2023-12-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#pragma once
#include <stdio.h>
#include <string.h>
#include "Gabinete.h"
#pragma warning (disable: 4996)
#pragma warning (disable: 6031)
#pragma comment(lib, "Data.lib")

/**
 * @brief Struct Data (year, month, day)
 * 
 */
typedef struct Data {
	int year;
	int month;
	int day;
}Data;

/**
 * @brief Struct Media das Calorias (numP, media)
 * 
 */
typedef struct Mediacalorias {
	int numP;
	double media;
}Mediacalorias; 



#pragma region Funcoes Paciente
int IniciPaciente(InfDieta x[], int tamanho);
int ImportarPacientes(char nomeFicheiro[], Paciente paciente[]);
void MostraArrayPaciente(Paciente x[], int tamanho);
void MostrarPaciente(Paciente x[], int posicao);
int GuardarFicheirosBin(Paciente P[], int tamanho);
int LoadFicheirosBin(Paciente P[]);
int contarPacientesQueUltrapassaram(int limiteCalorias, InfDieta x[], Data date1, Data date2, int tamanho);
int OrdenarPacienteDescrescente(Paciente x[], int tamanho);
int PacientesForaDoIntervalo(Paciente x[], PlNutricionais pl[], InfDieta d[], int tamanhoDie, int tamanhoPa, int tamanhoPlNut, Data data1, Data data2);
#pragma endregion

#pragma region Funcoes Dieta
int IniciInfDieta(InfDieta x[], int tamanho);
void MostraArrayInfDieta(InfDieta x[], int tamanho);
int ImportarInfDieta(char nomeFicheiro[], InfDieta x[]);
int GuardarFicheirosDietaBin(InfDieta D[], int tamanho);
int LoadFicheirosDietaBin(InfDieta D[]);
#pragma endregion

#pragma region Funcoes Plano Nutricional
int IniciPlNutricionais(PlNutricionais x[], int tamanho);
void MostraPlNutricional(PlNutricionais x[], int instancia);
int ImportarPlNutricionais(char nomeFicheiro[], PlNutricionais x[]);
void MostraArrayPlNutricionais(PlNutricionais x[], int tamanho);
int GuardarFicheirosPlNutricionaisBin(PlNutricionais D[], int tamanho);
int LoadFicheirosPlNutricionaisBin(PlNutricionais D[]);
void buscarPlanoNutricional(PlNutricionais pl[], Paciente x[], InfDieta d[], int tamanhoDie, int tamanhoPa, int tamanhoPlNut, char refeicao[], Data data1, Data data2);
#pragma endregion

#pragma region Funcoes com Data
Data TransformaDataString(char datastring[]);
int IniciData(Data data);
#pragma endregion

#pragma region Funcoes com Tabela
int GerarTabela(int Npac, TabelaPacientes tbpacientes[], Paciente pa[], InfDieta die[], PlNutricionais pln[]);
void MostrarTabela(int Npac, TabelaPacientes tbpacientes[]);
int IniTabela(int Npac, TabelaPacientes tbpacientes[]);
#pragma endregion

#pragma region Funcoes com MediaCalorias
int calcularMediaCaloria(PlNutricionais pl[], InfDieta d[], Data data1, Data data2, int tamanhoDie, int tamanhoPlNut, Mediacalorias mediac[]);
int IniciMediaCalorias(Mediacalorias x[], int tamanho);
void MostraArrayMediacalorias(Mediacalorias x[], int tamanho);
#pragma endregion

#pragma region Funcoes com arrays
#pragma endregion



