/*
--Trabalho de Grupo--
Bruno Dantas - a27958@alunos.ipca.pt
Diogo Abreu - a27975@alunos.ipca.pt
Paulo Gonçalves - a27966@alunos.ipca.pt
DATA : HOJE
Nutricionistas
*/

#include "Gabinete.h"

int main()
{
    printf("Hello world");
    return 0;

    Paciente p[k];


    //Pergunta 2

    char nomeArquivo[] = "DietaDetalhada.txt";
    int limiteCalorias = 2000;
    int resultado;

    // Chama a função para contar pacientes que ultrapassaram o limite de calorias
    resultado = contarPacientesQueUltrapassaram(nomeArquivo, limiteCalorias);

    // Apresenta o resultado
    if (resultado != -1) {
        printf("Número de pacientes que ultrapassaram %d calorias: %d\n", limiteCalorias, resultado);
    }

    return 0;


    ///Pergunta 3 

   
    int limiteInferior = 800;
    int limiteSuperior = 2000;

    // Chama a função para listar pacientes com calorias fora do intervalo
    listarPacientesForaDoIntervalo(nomeArquivo, limiteInferior, limiteSuperior);

    return 0;
}