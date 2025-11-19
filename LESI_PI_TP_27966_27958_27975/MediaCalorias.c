/**
 * @file MediaCalorias.c
 * @author Grupo 03 / Bruno Dantas nº27958 / Diogo Abreu nº27975/ Paulo Gonçalves nº27966
 * @brief Função no qual calcula a MNedia de Calorias de um paciente num determinado periodo
 * @version 1.0
 * @date 2023-12-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <locale.h>
#include "Gabinete.h"
#include "Cabecalho.h"

#pragma region IniciMediaCalorias
/// <summary>
/// Inicializar array de Mediacalorias a 0
/// </summary>
/// <param name="x">Array de Mediacalorias Fornecido</param>
/// <param name="tamanho">Tamanho do array</param>
/// <returns>1</returns>
int IniciMediaCalorias(Mediacalorias x[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        x[i].numP = 0;
        x[i].media = 0;
    }return 1;
}
#pragma endregion

#pragma region calcularMediaCaloria
/// <summary>
/// Calcular a media de calorias de refei�oes de um paciente num determinado periodo.
/// </summary>
/// <param name="pl">Array de Planos Nutricionais Fornecido</param>
/// <param name="d">Array de Dietas Fornecido</param>
/// <param name="data1">inicio do intervalo</param>
/// <param name="data2">fim do intervalo</param>
/// <param name="tamanhoDie">Tamanho do Array Dieta</param>
/// <param name="tamanhoPlNut">Tamanho do Array Planos Nutricionais</param>
/// <param name="mediac">Array de medias a preencher</param>
/// <returns>1</returns>
int calcularMediaCaloria(PlNutricionais pl[], InfDieta d[], Data data1, Data data2, int tamanhoDie, int tamanhoPlNut, Mediacalorias mediac[]) {
    Data data; data.day = 0; data.month = 0; data.year = 0;
    int soma = 0;
    int nRefeicoes = 0;
    int count = 0;
    for (int i = 0; i < tamanhoDie; i++) {
        soma = 0;
        nRefeicoes = 0;
        data = TransformaDataString(d[i].data);
        if ((data.year > data1.year || (data.year == data1.year && (data.month > data1.month || (data.month == data1.month && data.day >= data1.day)))) && (data.year < data2.year || (data.year == data2.year && (data.month < data2.month || (data.month == data2.month && data.day <= data2.day))))) {
            for (int j = 0; j < tamanhoDie; j++) {
                if (d[i].numP == d[j].numP) {
                    data = TransformaDataString(d[j].data);
                    if ((data.year > data1.year || (data.year == data1.year && (data.month > data1.month || (data.month == data1.month && data.day >= data1.day)))) && (data.year < data2.year || (data.year == data2.year && (data.month < data2.month || (data.month == data2.month && data.day <= data2.day))))) {
                        soma += d[j].calorias;
                        nRefeicoes++;
                        mediac[count].numP = d[i].numP;
                    }
                }
                if (j == tamanhoDie - 1) {
                    mediac[count].media = (float)soma / nRefeicoes;
                    count++;
                }
            }
        }
    }return 1;
}
#pragma endregion

#pragma region MostraArrayMediacalorias
/// <summary>
/// Mostra o Array no Ecra
/// </summary>
/// <param name="x">Array fornecido</param>
/// <param name="tamanho">Tamanho do array</param>
void MostraArrayMediacalorias(Mediacalorias x[], int tamanho) {

    for (int i = 0; i < tamanho; i++) {
        printf("\n//////////////////////////////////////////////\n");
        printf("array[%d].numP = %d\n", i, x[i].numP);
        printf("array[%d].data = %.2f\n", i, x[i].media);
    }
};
#pragma endregion
