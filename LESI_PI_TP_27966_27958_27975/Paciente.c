/**
 * @file Paciente.c
 * @author Grupo 03 / Bruno Dantas nº27958 / Diogo Abreu nº27975/ Paulo Gonçalves nº27966
 * @brief Funções para gerir dados dos pacientes
 * @version 0.1
 * @date 2023-12-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <locale.h>
#include "Gabinete.h"
#include "Cabecalho.h"

#pragma region InicializarArraypaciente
/// <summary>
/// Inicializa um array do tipo Paciente a 0
/// </summary>
/// <param name="x">Array de Paciente que vai ser inicializado</param>
/// <param name="tamanho">tamanho do array</param>
/// <returns></returns>
int IniciPaciente(Paciente x[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        x[i].numP = 0;
        strcpy(x[i].nome, "");
        x[i].tel = 0;
    }return 1;
}
#pragma endregion

#pragma region ImportarPacientes
/// <summary>
/// Importa Pacientes atravez de um ficheiro txt
/// </summary>
/// <param name="nomeFicheiro">Nome do ficheiro de onde vai ser importado os ficheiros</param>
/// <param name="paciente">Array de Pacientes para onde vai ser importado os ficheiros</param>
/// <returns></returns>
int ImportarPacientes(char nomeFicheiro[], Paciente paciente[]) {
	FILE* fp = fopen(nomeFicheiro, "r");
	int i = 0;
	while (1)
	{
		fscanf(fp, "%d;%[^;];%d", &paciente[i].numP, paciente[i].nome, &paciente[i].tel);
		i++;
		if (feof(fp))break;
	}	fclose(fp); return i;
}
#pragma endregion

#pragma region MostrarArraPaciente
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
        printf("array[%d].tel = %d\n", i, x[i].tel);
    }
}
#pragma endregion

#pragma region MostrarPaciente
/// <summary>
/// Mostra o Paciente no Ecra
/// </summary>
/// <param name="x">Array fornecido</param>
/// <param name="tamanho">Posicao do Paciente</param>
void MostrarPaciente(Paciente x[],int posicao) {
        printf("\n//////////////////////////////////////////////\n");
        printf("array[%d].numP = %d\n", posicao, x[posicao].numP);
        printf("array[%d].nome = %s\n", posicao, x[posicao].nome);
        printf("array[%d].tel = %d\n", posicao, x[posicao].tel);
}
#pragma endregion

#pragma region GuardarFicheirosBin 
/// <summary>
/// Guarda array de pacientes num ficheiro bin�rio 
///</summary>
/// <param name="P">array fornecido</param>
/// <param name="tamanho">tamanho do array</param>
/// <returns></returns>
int GuardarFicheirosBin(Paciente P[], int tamanho) {
    FILE* fp = fopen("Paciente.dat", "wb"); //em qual ficheiro escreve? no Paciente.dat criado nos ficheiros BIN??
    if (fp != NULL) {
        for (int i = 0; i < tamanho; i++) {
            fwrite(&P[i], 1, sizeof(Paciente), fp);
        }
        fclose(fp);
        return 1;
    } return 0;
}
#pragma endregion

#pragma region LoadFicheirosBin
/// <summary>
/// Carrega Dados de um ficheiro bin�rio
/// </summary>
/// <param name="P">array onde ir� escrever os dados do ficheiro</param>
/// <returns></returns>
int LoadFicheirosBin(Paciente P[]) {
    FILE* fp = fopen("Paciente.dat", "rb");
    if (fp != NULL) {
        int i = 0;
        while (fread(&P[i], 1, sizeof(Paciente), fp)) {
            i++;
        }
        return 1;
    }
}
#pragma endregion

#pragma region LoadFicheirosBin
/// <summary>
/// Carrega Dados de um ficheiro bin�rio
/// </summary>
/// <param name="P">array onde ir� escrever os dados do ficheiro</param>
/// <returns></returns>
int contarPacientesQueUltrapassaram(int limiteCalorias, InfDieta x[], Data data1, Data data2,int tamanho) {
    int pacientesQueUltrapassaram = 0;
    Data data; 
    data.day = 0;
    data.month = 0;
    data.year = 0;
    for (int i = 0; i < tamanho; i++) {
        data = TransformaDataString(x[i].data);
        if ((data.year > data1.year || (data.year == data1.year && (data.month > data1.month || (data.month == data1.month && data.day >= data1.day)))) && (data.year < data2.year || (data.year == data2.year && (data.month < data2.month || (data.month == data2.month && data.day <= data2.day))))) {
            if(x[i].calorias> limiteCalorias)
            pacientesQueUltrapassaram++; // A data de teste est� dentro do intervalo
        }
    }
    return pacientesQueUltrapassaram;
}
#pragma endregion
// Pergunta 3
// Mostrar os Pacientes em ordem decrescente que, num determinado Periodo, tenham feito uma refei��o fora do intervalo.
/// <summary>
/// Ordena os Pacientes por ordem decrescente de acordo com o numero de Paciente
/// </summary>
/// <param name="x">Array de Pacientes Fornecido</param>
/// <param name="tamanho">Tamanho do Array</param>
/// <returns></returns>
int OrdenarPacienteDescrescente(Paciente x[], int tamanho) {
    Paciente aux;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (x[i].numP < x[j].numP) {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
        }
    }
    return 1;
}

/// <summary>
/// Mostra os Pacientes que, num determinado Periodo, tenham feito uma refei��o fora do intervalo.
/// </summary>
/// <param name="x">Array de Pacientes Fornecido</param>
/// <param name="pl">Array de Dietas Fornecido</param>
/// <param name="d">Array de Planos Nutricionais Fornecido</param>
/// <param name="tamanhoDie">Tamanho do Array Dieta</param>
/// <param name="tamanhoPa">Tamanho do Array Pacientes</param>
/// <param name="tamanhoPlNut">Tamanho do Array Planos Nutricionais</param>
/// <param name="data1">inicio do intervalo</param>
/// <param name="data2">fim do intervalo</param>
/// <returns></returns>
int PacientesForaDoIntervalo(Paciente x[], PlNutricionais pl[], InfDieta d[], int tamanhoDie, int tamanhoPa, int tamanhoPlNut, Data data1, Data data2) {
    Data data; data.day = 0; data.month = 0; data.year = 0;
    OrdenarPacienteDescrescente(x, tamanhopaciente);
    for (int i = 0; i < tamanhoPa; i++) {
        for (int j = 0; j < tamanhoDie; j++) {
            if (x[i].numP == d[j].numP) {
                data = TransformaDataString(d[j].data);
                if ((data.year > data1.year || (data.year == data1.year && (data.month > data1.month || (data.month == data1.month && data.day >= data1.day)))) && (data.year < data2.year || (data.year == data2.year && (data.month < data2.month || (data.month == data2.month && data.day <= data2.day))))) {
                    for (int c = 0; c < tamanhoPlNut; c++) {
                        if (x[i].numP == pl[c].numPaciente) {
                            if (((d[j].calorias >= pl[c].calMinimas) && (d[j].calorias <= pl[c].calMax)) == 0) {
                                MostrarPaciente(x,i);

                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}

