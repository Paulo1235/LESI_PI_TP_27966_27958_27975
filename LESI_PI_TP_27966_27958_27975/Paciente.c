/*
--Trabalho de Grupo--
Bruno Dantas - a27958@alunos.ipca.pt
Diogo Abreu - a27975@alunos.ipca.pt
Paulo Gon�alves - a27966@alunos.ipca.pt
DATA : HOJE
Funcoes do Paciente
*/

#include "Gabinete.h"
#include "Gerirficheiros.h"
#pragma region ImportarPacientes
int ImportarPacientes(char nomeFicheiro[], Paciente paciente[]) {
	FILE* fp = fopen(nomeFicheiro, "r");
	int i = 0;
	while (1)
	{
		fscanf(fp, "%d;%[^;];%s", &paciente[i].numP, paciente[i].nome, paciente[i].tel); // erro ;988768565
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
void MostraArrayPaciente(Paciente x[], int tamanho) {

    for (int i = 0; i < tamanho; i++) {
        printf("\n//////////////////////////////////////////////\n");
        printf("array[%d].numP = %d\n", i, x[i].numP);
        printf("array[%d].nome = %s\n", i, x[i].nome);
        printf("array[%d].tel = %s\n", i, x[i].tel);
    }
};
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
} //O ficheiros binario � so um ou 3?
#pragma endregion


#pragma region LoadFicheirosBin
int LoadFicheirosBin(char NomeFicheiro, Paciente P[]) {
    FILE* fp = fopen("Turma.dat", "rb");
    if (fp != NULL) {
        int i = 0;

        while (fread(&P[i], 1, sizeof(Paciente), fp)) {
            i++;
        }
    }
}
#pragma endregion





/*
//2. Fun��o para contar o n�mero de pacientes que ultrapassaram uma quantidade de calorias
int contarPacientesQueUltrapassaram(char nomeArquivo, int limiteCalorias) {
	FILE* arquivo = fopen(nomeArquivo, "r"); // Abre o arquivo em modo de leitura
	int calorias, pacientesQueUltrapassaram = 0;


	// L� os dados do arquivo e conta os pacientes que ultrapassaram o limite de calorias
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
// Fun��o de compara��o para qsort
//int compararPacientes( void a, void b) {
//    return ((Paciente*)b)->numeroPaciente - ((Paciente*)a)->numeroPaciente;
//}
//
// Fun��o para listar pacientes com calorias fora do intervalo
void listarPacientesForaDoIntervalo(char nomeArquivo, int limiteInferior, int limiteSuperior) {
    FILE* arquivo;
    InfDieta* pacientes;
    int totalPacientes, i;

    // Abre o arquivo em modo de leitura
    arquivo = fopen(nomeArquivo, "r");

    // L� o total de pacientes do arquivo
    fscanf(arquivo, "%d", &totalPacientes);

    // Aloca mem�ria para o array de pacientes
    pacientes = (Paciente*)malloc(totalPacientes * sizeof(Paciente));

    // L� os dados dos pacientes do arquivo
    for (i = 0; i < totalPacientes; i++) {
        fscanf(arquivo, "%d %d", &pacientes[i].numP, &pacientes[i].calorias);
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Ordena os pacientes por ordem decrescente do n�mero de paciente
    //qsort(pacientes, totalPacientes, sizeof(Paciente), compararPacientes);

    // Imprime a lista de pacientes com calorias fora do intervalo
    //printf("Lista de pacientes com calorias fora do intervalo (%d - %d):\n", limiteInferior, limiteSuperior);
    //for (i = 0; i < totalPacientes; i++) {
    //    if (pacientes[i].calorias < limiteInferior || pacientes[i].calorias > limiteSuperior) {
    //        printf("Paciente %d: %d calorias\n", pacientes[i].numP, pacientes[i].calorias);
    //    }
    //}

    // Libera a mem�ria alocada
    free(pacientes);
}

//Resposta � alinea 4           Ver a quest�o se � sugerido a data de inicio e fim
// Fun��o para buscar o plano nutricional de um paciente para uma refei��o em um determinado per�odo
void buscarPlanoNutricional(char nomeArquivo,  char refeicao, char dataInicio, char dataFim) {
    FILE* arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    PlNutricionais plano;

    // L� o arquivo linha por linha
    while (fscanf(arquivo, "%19s %49s %[^\n]s", plano.dataRefeicao, plano.refeicao, plano.plano) == 3) {
        // Verifica se a linha pertence ao paciente e se est� no per�odo desejado
        if (strcmp(plano.refeicao, refeicao) == 0 &&
            strcmp(plano.dataRefeicao, dataInicio) >= 0 &&
            strcmp(plano.dataRefeicao, dataFim) <= 0) {
            // Exibe o plano nutricional encontrado
            printf("%s - %s: %s\n", plano.dataRefeicao, plano.refeicao, plano.plano);
        }
    }

    fclose(arquivo);
}


//Resposta � quest�o 5
// Fun��o para calcular a m�dia das calorias consumidas por refei��o por cada paciente ao longo de um per�odo
double calcularMediaCalorias(int calorias[MAX_PACIENTES][MAX_DIAS], int numPacientes, int numDias) {
    for (int paciente = 0; paciente < numPacientes; paciente++) {
        int totalCalorias = 0;
        for (int dia = 0; dia < numDias; dia++) {
            // Somar as calorias consumidas por refei��o para cada paciente e dia
            // Aqui voc� deve ter a l�gica para obter as calorias consumidas por refei��o para cada paciente e dia
            totalCalorias += calorias[paciente][dia];
        }

        // Calcular a m�dia das calorias consumidas por refei��o para o paciente atual
        if (numDias > 0) {
            float media = (float)totalCalorias / numDias;
            return media;
        }
        else {
            return 0;
        }
    }
}

//Exercicio 6

//Contar Pacientes
int contarPacientes(char nomeArquivo)
{
    FILE* arquivo= fopen(nomeArquivo, "r");// Abre o arquivo para leitura
    char nomeArquivo[] = nomeArquivo;  // Substitua pelo nome do seu arquivo
    int contador = 0;
    char caractere;

    

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    // Percorre o arquivo contando as linhas
    while ((caractere = fgetc(arquivo)) != EOF) {
        if (caractere == '\n') {
            contador++;
        }
    }

    // Verifica se a �ltima linha n�o termina com quebra de linha
    rewind(arquivo);  // Volta para o in�cio do arquivo
    if (contador > 0) {
        fseek(arquivo, -1, SEEK_END);  // Move para o pen�ltimo caractere
        if (fgetc(arquivo) != '\n') {
            contador++;
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    return contador;
}


// Fun��o para exibir a tabela
//void exibirTabela(Paciente* pacientes, int numPacientes) {
//    for (int i = 0; i < numPacientes; i++) {
//        printf("| %-15d | %-20s | %-15s | %-12s | %-12s | %-15d | %-15d | %-20d |\n",
//            pacientes[i].numeroPaciente, pacientes[i].nome, pacientes[i].tipoRefeicao,
//            pacientes[i].dataInicio, pacientes[i].dataFim, pacientes[i].caloriasMinimo,
//            pacientes[i].caloriasMaximo, pacientes[i].consumoRealizado);
//    }
//}*/