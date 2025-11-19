/**
 * @file Tabela.c
 * @author Grupo 03 / Bruno Dantas nº27958 / Diogo Abreu nº27975/ Paulo Gonçalves nº27966
 * @brief Mostra uma Tabela com todos os dados pretendidos
 * @version 1.0
 * @date 2023-12-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <locale.h>
#include "Gabinete.h"
#include "Cabecalho.h"


//Pergunta 6
#pragma region IniTabela
/// <summary>
/// Inicialisa a tabela
/// </summary>
/// <param name="Npac">Numero de Pacientes</param>
/// <param name="tbpacientes">Tabela de Pacientes</param>
/// <returns>1</returns>
int IniTabela(int Npac, TabelaPacientes tbpacientes[]) {
     for (int i = 0; i < Npac; i++) {
        tbpacientes[i].numeroPaciente = i + 1;
        sprintf(tbpacientes[i].nome, "");
        sprintf(tbpacientes[i].tipoRefeicao, "");
        sprintf(tbpacientes[i].dataInicio, "");
        sprintf(tbpacientes[i].dataFim, "");
        tbpacientes[i].caloriasMinimo = 0;
        tbpacientes[i].caloriasMaximo = 0;
        tbpacientes[i].consumoRealizado = 0;//FALTA COLOCAR ESTE CAMPO A FUNCIONAR
    }
     return 1;
}
#pragma endregion

#pragma region GerarTabela
/// <summary>
/// Gerar os dados para a tabela 
/// </summary>
/// <param name="Npac">Numero de Pacientes</param>
/// <param name="tbpacientes">Tabela de Pacientes</param>
/// <param name="pa">Array dos Pacientes </param>
/// <param name="die">Array da Dieta</param>
/// <param name="pln">Array do Planoi Nutricional</param>
/// <returns>1</returns>
int GerarTabela(int Npac, TabelaPacientes tbpacientes[],Paciente pa[], InfDieta die[], PlNutricionais pln[]) {
    int consumo;
    for (int i = 0; i < tamanhoDietaDetalhada; i++) {
         consumo = 0;
        for (int j = 0; j < tamanhoDieta; j++) {
            tbpacientes[i].numeroPaciente = i + 1;
            sprintf(tbpacientes[i].nome, "%s", pa[i].nome);
            sprintf(tbpacientes[i].tipoRefeicao, "%s", pln[i].refeicao);
            sprintf(tbpacientes[i].dataInicio, "%s", pln[i].dataRefeicao);
            sprintf(tbpacientes[i].dataFim, "%s", die[i].data);
            tbpacientes[i].caloriasMinimo = pln[i].calMinimas;
            tbpacientes[i].caloriasMaximo = pln[i].calMax;
            
            if (pln[i].numPaciente == die[j].numP) {
                if (strcmp(pln[i].refeicao, die[j].refeicao) == 0) {
                    consumo += die[j].calorias;
                }
            }
            tbpacientes[i].consumoRealizado = consumo;
        }
    }
}
#pragma endregion

#pragma region MostraTabela
/// <summary>
/// Mostra os dados na linha de comados
/// </summary>
/// <param name="Npac">Numero de Pacientes</param>
/// <param name="tbpacientes">Tabela de Pacientes</param>
void MostrarTabela(int Npac, TabelaPacientes tbpacientes[]) {
    printf("\n");
    printf("| %-15s | %-20s | %-15s | %-12s | %-12s | %-15s | %-15s | %-20s |\n",
        "Num Paciente", "Nome", "Tipo Refeicao", "Data Inicio", "Data Fim", "Cal Minimo", "Cal Maximo", "Consumo Realizado");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < Npac; i++) {

        printf("| %-15d | %-20s | %-15s | %-12s | %-12s | %-15d | %-15d | %-20d |\n",
            tbpacientes[i].numeroPaciente, tbpacientes[i].nome, tbpacientes[i].tipoRefeicao,
            tbpacientes[i].dataInicio, tbpacientes[i].dataFim, tbpacientes[i].caloriasMinimo,
            tbpacientes[i].caloriasMaximo, tbpacientes[i].consumoRealizado);
    }
}
#pragma endregion 
