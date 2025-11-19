
/**
 * @file Main.c
 * @author Grupo 03 / Bruno Dantas nº27958 / Diogo Abreu nº27975/ Paulo Gonçalves nº27966
 * @brief Ficheiro que executa as Funções
 * @version 1.0
 * @date 2023-12-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <locale.h>
#include "Gabinete.h"
#include "Cabecalho.h"
int main()
{
    setlocale(LC_ALL, "Portuguese");
    
#pragma region Pergunta 1
#pragma region teste de Paciente

    Paciente p[k],b[k];
    int a = ImportarPacientes("Pacientes.txt", p); //Importa os Pacientes do ficheiro para o array p e diz quantos pacientes s�o para a variavel a
    GuardarFicheirosBin(p, a);                     //Guarda os dados do array p para um ficheiro binario
    LoadFicheirosBin(b);                           //Carrega os dados a partir do ficheiro bin�rio
    printf("Foram importados %d pacientes\n", a);
    //MostraArrayPaciente(b,6);                      //Mostra o array no ecra

#pragma endregion

#pragma region teste de InfDieta
    
    InfDieta d[k];
    IniciInfDieta(d, k);
    a = ImportarInfDieta("Dieta.txt", d);
    GuardarFicheirosDietaBin(d, a);
    LoadFicheirosDietaBin(d);
    printf("Foram importados %d dietas\n", a);
    //MostraArrayInfDieta(d,4);

#pragma endregion

#pragma region teste de PlNutricionais

    PlNutricionais pl[k];
    IniciPlNutricionais(pl, 3);
    a = ImportarPlNutricionais("DietaDetalhada.txt", pl);
    GuardarFicheirosPlNutricionaisBin(pl,a);
    LoadFicheirosPlNutricionaisBin(pl);
    printf("Foram importados %d planos nutricionais\n", a);
    //MostraArrayPlNutricionais(pl,3);

#pragma endregion
#pragma endregion

#pragma region Pergunta 2
    IniciInfDieta(d, tamanhoDieta); //inicializa a 0
    LoadFicheirosDietaBin(d);       //carrega os dados do ficheiro
    Data data1, data2;
    data1.day = 01; data1.month = 01; data1.year = 2023;
    data2.day = 10; data2.month = 02; data2.year = 2023;
    int cp = 2;//contarPacientesQueUltrapassaram(LimiteCalorias, d, data1, data2, tamanhoDieta);
    if (cp < 1) {
        printf("Nao houve nenhum paciente que ultrapacou %d calorias de %d/%d/%d a %d/%d/%d", LimiteCalorias, data1.day, data1.month, data1.year, data2.day, data2.month, data2.year);
    }
    if (cp == 1) {
        printf("Houve %d paciente que ultrapacou %d calorias de %d/%d/%d a %d/%d/%d", cp, LimiteCalorias, data1.day, data1.month, data1.year, data2.day, data2.month, data2.year);
    }
    if(cp > 1) {
        printf("Houve %d pacientes que ultrapassaram %d calorias de %d/%d/%d a %d/%d/%d ", cp, LimiteCalorias, data1.day, data1.month, data1.year, data2.day, data2.month, data2.year);
    }
#pragma endregion

#pragma region Pergunta 3
    
    IniciData(data1);
    IniciData(data2);

    IniciPlNutricionais(pl, tamanhoDietaDetalhada);
    IniciPaciente(p,tamanhopaciente);
    IniciInfDieta(d, tamanhoDieta);

    LoadFicheirosPlNutricionaisBin(pl);
    LoadFicheirosBin(p);
    LoadFicheirosDietaBin(d);

    data1.day = 01; data1.month = 01; data1.year = 2023;
    data2.day = 15; data2.month = 02; data2.year = 2023;
    
    printf("\n\nO Numero dos Pacientes que fizeram uma refeicao fora do intervalo de %d/%d/%d a %d/%d/%d e:\n", data1.day, data1.month, data1.year, data2.day, data2.month, data2.year);
    PacientesForaDoIntervalo(p, pl, d, tamanhoDieta, tamanhopaciente, tamanhoDietaDetalhada, data1, data2);
    
    #pragma endregion

#pragma region Pergunta 4

    IniciData(data1);
    IniciData(data2);

    IniciPlNutricionais(pl, tamanhoDietaDetalhada);
    IniciPaciente(p, tamanhopaciente);
    IniciInfDieta(d, tamanhoDieta);

    LoadFicheirosPlNutricionaisBin(pl);
    LoadFicheirosBin(p);
    LoadFicheirosDietaBin(d);

    data1.day = 01; data1.month = 01; data1.year = 2023;
    data2.day = 15; data2.month = 02; data2.year = 2023;
buscarPlanoNutricional(pl, p , d, tamanhoDieta, tamanhopaciente, tamanhoDietaDetalhada, "pequeno almoco", data1,data2);//Datainicio e data do fim


#pragma endregion
   
#pragma region Pergunta 5
    IniciPlNutricionais(pl, tamanhoDietaDetalhada);
    IniciInfDieta(d, tamanhoDieta);

    LoadFicheirosPlNutricionaisBin(pl);
    LoadFicheirosDietaBin(d);
    IniciData(data1);
    IniciData(data2);
    data1.day = 01; data1.month = 01; data1.year = 2023;
    data2.day = 15; data2.month = 02; data2.year = 2023;
    Mediacalorias mediap[k]; 

    calcularMediaCaloria(pl, d, data1, data2, tamanhoDieta, tamanhoDietaDetalhada,mediap);
    MostraArrayMediacalorias(mediap,tamanhoMediacalorias);
#pragma endregion

#pragma region Pergunta 6 

    
    Paciente pa[k];
    IniciPaciente(pa, tamanhopaciente);
    LoadFicheirosBin(pa);

    InfDieta die[k];
    IniciInfDieta(die, tamanhoDieta);
    LoadFicheirosDietaBin(die);

    PlNutricionais pln[k];
    IniciPlNutricionais(pln, tamanhoDietaDetalhada);
    LoadFicheirosPlNutricionaisBin(pln);

    TabelaPacientes tbpacientes[3];

    IniTabela(tamanhoDietaDetalhada, tbpacientes);
    GerarTabela(tamanhoDietaDetalhada, tbpacientes, pa, die, pln);
    MostrarTabela(tamanhoDietaDetalhada, tbpacientes);
    
#pragma endregion
}
            