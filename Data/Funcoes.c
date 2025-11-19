/*****************************************************************//**
 * \file   Funcoes.c
 * 
 * \brief  Funcoes com Data
 * \author Grupo 03 / Bruno Dantas nº27958 / Diogo Abreu nº27975/ Paulo Gonçalves nº27966
 * \date  30 December 2023
 *********************************************************************/

#include "Data.h"

/// <summary>
/// Transforma uma string data numa struct data
/// </summary>
/// <param name="datastring">Data em string</param>
/// <returns>data em estruct</returns>
Data TransformaDataString(char datastring[]) {
	Data data;
	sscanf(datastring, "%d-%d-%d", &data.day, &data.month, &data.year);
	return data;
}

/// <summary>
/// Inicializa a data a 0
/// </summary>
/// <param name="datastring">Data a inicializar</param>
/// <returns>1</returns>
int IniciData(Data data) {
	data.day = 0;
	data.month = 0;
	data.year = 0;
	return 1;
}