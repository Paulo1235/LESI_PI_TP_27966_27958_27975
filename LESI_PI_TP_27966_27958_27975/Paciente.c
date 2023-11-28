/*
--Trabalho de Grupo--
Bruno Dantas - a27958@alunos.ipca.pt
Diogo Abreu - a27975@alunos.ipca.pt
Paulo Gonçalves - a27966@alunos.ipca.pt
DATA : HOJE
Nutricionistas
*/

#include "Gabinete.h"
/*
* devolve quantos pacientes leu
*/
int LeDadosPaciente(char nomeFicheiro[], Paciente pacientes[], int maximoPaciente) {
	FILE* fp = fopen(nomeFicheiro, "r");
	int i = 0;
	while (1)
	{
		fscanf(fp, "%d;%[^;]%s", &pacientes->numP, pacientes[i].nome, pacientes[i].tel);
		i++;
		if (feof(fp)) break;
	}
	fclose(fp); return i
}