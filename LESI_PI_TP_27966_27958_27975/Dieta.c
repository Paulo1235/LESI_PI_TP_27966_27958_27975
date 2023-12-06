/*
--Trabalho de Grupo--
Bruno Dantas - a27958@alunos.ipca.pt
Diogo Abreu - a27975@alunos.ipca.pt
Paulo Gonçalves - a27966@alunos.ipca.pt
DATA : HOJE
Funcoes InfDieta
*/

#include "Gabinete.h"
#include "Gerirficheiros.h"

#pragma region ImportarInfDieta
int ImportarInfDieta(char nomeFicheiro[], InfDieta x[]) {
	FILE* fp = fopen(nomeFicheiro, "r");
	int i = 0;
	while (1)
	{
		fscanf(fp, "%d;%[^;]%s;%s;%s", &x[i].numP, x[i].data, x[i].refeicao, x[i].alimento, x[i].calorias); // erro ;988768565
		i++;
		if (feof(fp))break;

	}	fclose(fp); return i;
}
#pragma endregion

#pragma region MostrarArray
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
		printf("array[%d].calorias = %s\n", i, x[i].calorias);
	}
};
#pragma endregion
