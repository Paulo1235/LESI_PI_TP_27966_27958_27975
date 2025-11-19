/**
 * @file Dieta.c
 * @author Grupo 03 / Bruno Dantas nº27958 / Diogo Abreu nº27975/ Paulo Gonçalves nº27966
 * @brief Funções para gerir dados das dietas
 * @version 1.0
 * @date 2023-12-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Gabinete.h"
#include "Cabecalho.h"
	
#pragma region InicializarArrayDieta
/// <summary>
/// Inicializa um array do tipo InfDieta a 0
/// </summary>
/// <param name="x">Array de InfDieta que vai ser inicializado</param>
/// <param name="tamanho">tamanho do array</param>
/// <returns></returns>
int IniciInfDieta(InfDieta x[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		x[i].numP = 0;
		strcpy(x[i].data, ""); // Copia uma string vazia para o campo data
		strcpy(x[i].refeicao, ""); 
		strcpy(x[i].alimento, ""); 
		x[i].calorias = 0;
	}
	return 1;
}
#pragma endregion

#pragma region ImportarInfDieta
/// <summary>
/// Importa Pacientes atravez de um ficheiro txt
/// </summary>
/// <param name="nomeFicheiro">Nome do ficheiro de onde vai ser importado os ficheiros</param>
/// <param name="x">Array de Dietas para onde vai ser importado os ficheiros</param>
/// <returns></returns>
int ImportarInfDieta(char nomeFicheiro[], InfDieta x[]) {
	FILE* fp = fopen(nomeFicheiro, "r");
	if (fp == NULL) {
		return -1; 
	}
	int i = 0;
	while (1)
	{
		fscanf(fp, "%d;%[^;];%[^;];%[^;];%d cal", &x[i].numP, x[i].data, x[i].refeicao, x[i].alimento, &x[i].calorias);
		if (feof(fp))break;
		i++;
	}	
	fclose(fp); return i;
}
#pragma endregion

#pragma region MostraArrayInfDieta
/// <summary>
/// Mostra o Array no Ecra
/// </summary>
/// <param name="x">Array fornecido</param>
/// <param name="tamanho">Tamanho do array</param>
void MostraArrayInfDieta(InfDieta x[], int tamanho) {

	for (int i = 0; i < tamanho; i++) {
		printf("\n//////////////////////////////////////////////\n");
		printf("array[%d].numP = %d\n", i, x[i].numP);
		printf("array[%d].data = %s\n", i, x[i].data);
		printf("array[%d].refeicao = %s\n", i, x[i].refeicao);
		printf("array[%d].alimento = %s\n", i, x[i].alimento);
		printf("array[%d].calorias = %d cal\n", i, x[i].calorias);
	}
};
#pragma endregion

#pragma region GuardarFicheirosDietaBin 
/// <summary>
/// Guarda array de Dietas num ficheiro bin�rio 
///</summary>
/// <param name="P">array fornecido</param>
/// <param name="tamanho">tamanho do array</param>
/// <returns></returns>
int GuardarFicheirosDietaBin(InfDieta D[], int tamanho) {
	FILE* fp = fopen("InfDieta.dat", "wb");
	if (fp != NULL) {
		for (int i = 0; i < tamanho; i++) {
			fwrite(&D[i], 1, sizeof(InfDieta), fp);
		}
		fclose(fp);
		return 1;
	} return 0;

} //O ficheiros binario � so um ou 3?
#pragma endregion

#pragma region LoadFicheirosDietaBin
/// <summary>
/// Carrega Dados de um ficheiro bin�rio
/// </summary>
/// <param name="P">array onde ir� escrever os dados do ficheiro</param>
/// <returns></returns>
int LoadFicheirosDietaBin(InfDieta D[]) {
	FILE* fp = fopen("InfDieta.dat", "rb");
	if (fp != NULL) {
		int i = 0;
		while (fread(&D[i], 1, sizeof(InfDieta), fp)) {
			i++;
		}
	}
}
#pragma endregion
