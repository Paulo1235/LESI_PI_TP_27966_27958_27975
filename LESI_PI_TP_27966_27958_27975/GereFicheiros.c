/*
--Trabalho de Grupo--
Bruno Dantas - a27958@alunos.ipca.pt
Diogo Abreu - a27975@alunos.ipca.pt
Paulo Gonçalves - a27966@alunos.ipca.pt
DATA : 28/11/2023 18:00 horas
Nutricionistas
*/


#include <stdio.h>
#include "Gabinete.h"
#pragma warning (disable: 4996)


int Binarios()
{
#pragma region FICHEIROS_BIN

	FILE* fp;
	Paciente p1 = { 12, "Joao", 123 };

	fp = fopen("Paciente.dat", "wb");
	if (fp != NULL) {
		fwrite(&p1, sizeof(Paciente), 1, fp);
	}
	fclose(fp);

	Paciente p2;

	fp = fopen("Paciente.dat", "rb");
	if (fp != NULL) {
		fread(&p2, 1, sizeof(Paciente), fp);
	}
	fclose(fp);

}
#pragma endregion


#pragma region GuardarFicheirosBin
int GuardarFicheirosBin(char NomeFicheiro, Paciente P[]) {

	FILE* fp = fopen("Paciente.dat", "wb"); //em qual ficheiro escreve? no Paciente.dat criado nos ficheiros BIN??
	if (fp != NULL) {
		for (int i = 0; i < 2; i++) {
			fwrite(&P[i], 1, sizeof(Paciente), fp);
		}
	}
	fclose(fp);
}
#pragma endregion


#pragma region LoadFicheirosBin
int LoadFicheirosBin(char NomeFicheiro, Paciente P[]) {

	Paciente P[N];
	FILE* fp = fopen("Turma.dat", "rb");
	if (fp != NULL) {
		int i = 0;

		while (fread(&P[i], 1, sizeof(Paciente), fp)) {
			i++;
		}
	}
}
#pragma endregion





