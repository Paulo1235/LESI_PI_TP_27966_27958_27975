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
// Função de comparação para qsort
//int compararPacientes( void a, void b) {
//    return ((Paciente*)b)->numeroPaciente - ((Paciente*)a)->numeroPaciente;
//}
//
// Função para listar pacientes com calorias fora do intervalo
void listarPacientesForaDoIntervalo(char nomeArquivo, int limiteInferior, int limiteSuperior) {
    FILE* arquivo;
    InfDieta* pacientes;
    int totalPacientes, i;

    // Abre o arquivo em modo de leitura
    arquivo = fopen(nomeArquivo, "r");

    // Lê o total de pacientes do arquivo
    fscanf(arquivo, "%d", &totalPacientes);

    // Aloca memória para o array de pacientes
    pacientes = (Paciente*)malloc(totalPacientes * sizeof(Paciente));

    // Lê os dados dos pacientes do arquivo
    for (i = 0; i < totalPacientes; i++) {
        fscanf(arquivo, "%d %d", &pacientes[i].numP, &pacientes[i].calorias);
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Ordena os pacientes por ordem decrescente do número de paciente
    //qsort(pacientes, totalPacientes, sizeof(Paciente), compararPacientes);

    // Imprime a lista de pacientes com calorias fora do intervalo
    //printf("Lista de pacientes com calorias fora do intervalo (%d - %d):\n", limiteInferior, limiteSuperior);
    //for (i = 0; i < totalPacientes; i++) {
    //    if (pacientes[i].calorias < limiteInferior || pacientes[i].calorias > limiteSuperior) {
    //        printf("Paciente %d: %d calorias\n", pacientes[i].numP, pacientes[i].calorias);
    //    }
    //}

    // Libera a memória alocada
    free(pacientes);
}

//Resposta à alinea 4           Ver a questão se é sugerido a data de inicio e fim
// Função para buscar o plano nutricional de um paciente para uma refeição em um determinado período
void buscarPlanoNutricional(char nomeArquivo, char paciente, char refeicao, char dataInicio, char dataFim) {
    FILE* arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    PlNutricionais plano;

    // Lê o arquivo linha por linha
    while (fscanf(arquivo, "%19s %49s %[^\n]s", plano.dataRefeicao, plano.refeicao, plano.plano) == 3) {
        // Verifica se a linha pertence ao paciente e se está no período desejado
        if (strcmp(plano.refeicao, refeicao) == 0 &&
            strcmp(plano.dataRefeicao, dataInicio) >= 0 &&
            strcmp(plano.dataRefeicao, dataFim) <= 0) {
            // Exibe o plano nutricional encontrado
            printf("%s - %s: %s\n", plano.dataRefeicao, plano.refeicao, plano.plano);
        }
    }

    fclose(arquivo);
}


//Resposta à questão 5
// Função para calcular a média das calorias consumidas por refeição por cada paciente ao longo de um período
double calcularMediaCalorias(int calorias[MAX_PACIENTES][MAX_DIAS], int numPacientes, int numDias) {
    for (int paciente = 0; paciente < numPacientes; paciente++) {
        int totalCalorias = 0;
        for (int dia = 0; dia < numDias; dia++) {
            // Somar as calorias consumidas por refeição para cada paciente e dia
            // Aqui você deve ter a lógica para obter as calorias consumidas por refeição para cada paciente e dia
            totalCalorias += calorias[paciente][dia];
        }

        // Calcular a média das calorias consumidas por refeição para o paciente atual
        if (numDias > 0) {
            float media = (float)totalCalorias / numDias;
            return media;
        }
        else {
            return 0;
        }
    }
}