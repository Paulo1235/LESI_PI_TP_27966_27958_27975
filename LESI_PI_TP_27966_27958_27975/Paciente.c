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
	fclose(fp); return i;
}

//Proposta solução alínea 1 do trabalho prático

int ImportarPacientes(char nomeFicheiro[], Paciente paciente[], int maximoPaciente)
{
	FILE* fp = fopen(nomeFicheiro, "r");
	int i = 0;
	while (1 && i<maximoPaciente)
	{
		fscanf(fp, "%d;%[^;]%s", &paciente[i].numP, paciente[i].nome, paciente[i].tel);
		i++;
		if (feof(fp))break;
			
	}	fclose(fp); return i;
}

//2. Função para contar o número de pacientes que ultrapassaram uma quantidade de calorias
int contarPacientesQueUltrapassaram(char nomeArquivo, int limiteCalorias) {
	FILE* arquivo;
	int calorias, pacientesQueUltrapassaram = 0;

	// Abre o arquivo em modo de leitura
	arquivo = fopen(nomeArquivo, "r");

	// Lê os dados do arquivo e conta os pacientes que ultrapassaram o limite de calorias
	while (fscanf(arquivo, "%d", &calorias) == 1) {
		if (calorias > limiteCalorias) {
			pacientesQueUltrapassaram++;
		}
	}

	// Fecha o arquivo
	fclose(arquivo);

	return pacientesQueUltrapassaram;
}

/////3
//// Função de comparação para qsort
//int compararPacientes(const void* a, const void* b) {
//    return ((Paciente*)b)->numeroPaciente - ((Paciente*)a)->numeroPaciente;
//}
//
//// Função para listar pacientes com calorias fora do intervalo
//void listarPacientesForaDoIntervalo(char* nomeArquivo, int limiteInferior, int limiteSuperior) {
//    FILE* arquivo;
//    Paciente* pacientes;
//    int totalPacientes, i;
//
//    // Abre o arquivo em modo de leitura
//    arquivo = fopen(nomeArquivo, "r");
//
//    // Lê o total de pacientes do arquivo
//    fscanf(arquivo, "%d", &totalPacientes);
//
//    // Aloca memória para o array de pacientes
//    pacientes = (Paciente*)malloc(totalPacientes * sizeof(Paciente));
//
//    // Lê os dados dos pacientes do arquivo
//    for (i = 0; i < totalPacientes; i++) {
//        fscanf(arquivo, "%d %d", &pacientes[i].numeroPaciente, &pacientes[i].caloriasRefeicao);
//    }
//
//    // Fecha o arquivo
//    fclose(arquivo);
//
//    // Ordena os pacientes por ordem decrescente do número de paciente
//    qsort(pacientes, totalPacientes, sizeof(Paciente), compararPacientes);
//
//    // Imprime a lista de pacientes com calorias fora do intervalo
//    printf("Lista de pacientes com calorias fora do intervalo (%d - %d):\n", limiteInferior, limiteSuperior);
//    for (i = 0; i < totalPacientes; i++) {
//        if (pacientes[i].caloriasRefeicao < limiteInferior || pacientes[i].caloriasRefeicao > limiteSuperior) {
//            printf("Paciente %d: %d calorias\n", pacientes[i].numeroPaciente, pacientes[i].caloriasRefeicao);
//        }
//    }
//
//    // Libera a memória alocada
//    free(pacientes);
//}