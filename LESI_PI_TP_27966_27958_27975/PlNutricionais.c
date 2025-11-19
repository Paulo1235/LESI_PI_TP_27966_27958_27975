/**
 * @file PlNutricionais.c
 * @author Grupo 03 / Bruno Dantas nº27958 / Diogo Abreu nº27975/ Paulo Gonçalves nº27966
 * @brief Funções para gerir dados dos planos nutricionais
 * @version 1.0
 * @date 2023-12-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Gabinete.h"
#include "Cabecalho.h"

#pragma region InicializarArrayPlNutricionais
/// <summary>
/// Inicializa um array do tipo PlNutricionais a 0
/// </summary>
/// <param name="x">Array de PlNutricionais que vai ser inicializado</param>
/// <param name="tamanho">tamanho do array</param>
/// <returns></returns>
int IniciPlNutricionais(PlNutricionais x[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {

		x[i].numPaciente = 0;
		strcpy(x[i].dataRefeicao, ""); 
		strcpy(x[i].refeicao, "");
		x[i].calMinimas = 0;
		x[i].calMax = 0;
	}
}
#pragma endregion

#pragma region ImportarPlNutricionais
/// <summary>
/// Importa Pacientes atravez de um ficheiro txt
/// </summary>
/// <param name="nomeFicheiro">Nome do ficheiro de onde vai ser importado os ficheiros</param>
/// <param name="x">Array de PlNutricionaiss para onde vai ser importado os ficheiros</param>
/// <returns>i</returns>
int ImportarPlNutricionais(char nomeFicheiro[], PlNutricionais x[]) {
	FILE* fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) {
		return -1;
	}
	int i = 0;
	while (1)
	{
		fscanf(fp, "%d;%[^;];%[^;];%d Cal;%d Cal;", &x[i].numPaciente, x[i].dataRefeicao, x[i].refeicao, &x[i].calMinimas, &x[i].calMax);
		if (feof(fp)) break;
		i++;
	}
	fclose(fp); return i;
}
#pragma endregion

#pragma region MostraArrayPlNutricionais
/// <summary>
/// Mostra o Array no Ecra
/// </summary>
/// <param name="x">Array fornecido</param>
/// <param name="tamanho">Tamanho do array</param>
void MostraArrayPlNutricionais(PlNutricionais x[], int tamanho) {

	for (int i = 0; i < tamanho; i++) {
		printf("\n//////////////////////////////////////////////\n");
		printf("array[%d].numPaciente = %d\n", i, x[i].numPaciente);
		printf("array[%d].dataRefeicao = %s\n", i, x[i].dataRefeicao);
		printf("array[%d].refeicao = %s\n", i, x[i].refeicao);
		printf("array[%d].calMinimas = %d\n", i, x[i].calMinimas);
		printf("array[%d].calMax = %d\n", i, x[i].calMax);
	}
};
#pragma endregion

#pragma region MostraPlNutricional
/// <summary>
/// Mostra o Array no Ecra
/// </summary>
/// <param name="x">Array fornecido</param>
/// <param name="tamanho">Tamanho do array</param>
void MostraPlNutricional(PlNutricionais x[], int instancia) {
		printf("\n//////////////////////////////////////////////\n");
		printf("Numero do Paciente %d\n", x[instancia].numPaciente);
		printf("Data da Refeicao = %s\n", x[instancia].dataRefeicao);
		printf("Refeicao = %s\n", x[instancia].refeicao);
		printf("Calorias Minimas = %d\n", x[instancia].calMinimas);
		printf("Calorias Maximas = %d\n", x[instancia].calMax);
};
#pragma endregion

#pragma region GuardarFicheirosPlNutricionaisBin 
/// <summary>
/// Guarda array de PlNutricionaiss num ficheiro bin�rio 
///</summary>
/// <param name="P">array fornecido</param>
/// <param name="tamanho">tamanho do array</param>
/// <returns></returns>
int GuardarFicheirosPlNutricionaisBin(PlNutricionais pl[], int tamanho) {
	FILE* fp = fopen("PlNutricionais.dat", "wb");
	if (fp != NULL) {
		for (int i = 0; i < tamanho; i++) {
			fwrite(&pl[i], 1, sizeof(PlNutricionais), fp);
		}
		fclose(fp);
		return 1;
	} return 0;

} //O ficheiros binario � so um ou 3?
#pragma endregion

#pragma region LoadFicheirosPlNutricionaisBin
/// <summary>
/// Carrega Dados de um ficheiro bin�rio
/// </summary>
/// <param name="P">array onde ir� escrever os dados do ficheiro</param>
/// <returns></returns>
int LoadFicheirosPlNutricionaisBin(PlNutricionais D[]) {
	FILE* fp = fopen("PlNutricionais.dat", "rb");
	if (fp != NULL) {
		int i = 0;
		while (fread(&D[i], 1, sizeof(PlNutricionais), fp)) {
			i++;
		}
	}
}
#pragma endregion

#pragma region buscarPlanoNutricional 
/// <summary>
/// 
/// </summary>
/// <param name="pl">Array de Planos Nutricionais</param>
/// <param name="x">Array Paciente</param>
/// <param name="d">Array de Dietas</param>
/// <param name="tamanhoDie">Tamanha do array dieta</param>
/// <param name="tamanhoPa">Tamanha do array Paciente</param>
/// <param name="tamanhoPlNut">Tamanha do array Dieta</param>
/// <param name="refeicao">Refei��o para comparar</param>
/// <param name="data1">data de inicio do periodo</param>
/// <param name="data2">data de fim do periodo</param>
void buscarPlanoNutricional(PlNutricionais pl[], Paciente x[], InfDieta d[], int tamanhoDie, int tamanhoPa, int tamanhoPlNut, char refeicao[], Data data1, Data data2) {
	for (int i = 0; i < tamanhoDie; i++) {
		Data data; data.day = 0; data.month = 0; data.year = 0;
		data = TransformaDataString(d[i].data);
		if (((data.year > data1.year || (data.year == data1.year && (data.month > data1.month || (data.month == data1.month && data.day >= data1.day)))) && (data.year < data2.year || (data.year == data2.year && (data.month < data2.month || (data.month == data2.month && data.day <= data2.day)))))) {
			for (int j = 0; j < tamanhoDietaDetalhada; j++) {
				if (d[i].numP == pl[j].numPaciente) {
					if ((strcmp(d[i].refeicao, refeicao) == 0) && (strcmp(pl[j].refeicao, refeicao) == 0)) {
						MostraPlNutricional(pl, j);
					}
				}
			}
		}
	}
}
#pragma endregion
