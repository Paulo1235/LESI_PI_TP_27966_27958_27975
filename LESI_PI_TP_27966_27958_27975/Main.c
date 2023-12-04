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

    //Pergunta 4

    // Exemplo de uso da função
    buscarPlanoNutricional("arquivo.txt", "NomeDoPaciente", "CafeDaManha", "2023-01-01", "2023-01-31");//Datainicio e data do fim

    return 0;

    //Pergunta 5
        // Defina o número real de pacientes e dias com dados
    int numPacientes = 2;
    int numDias = 3;

    // Substitua os valores abaixo pelos dados reais das calorias consumidas por refeição para cada paciente e dia
    int calorias[MAX_PACIENTES][MAX_DIAS] = {
        {800, 900, 700},
        {1000, 1100, 1200},
    };

    // Chame a função para calcular a média das calorias
    double medcal = calcularMediaCalorias(calorias, numPacientes, numDias);

    if (medcal > 0) {
        printf("Média de calorias consumidas por refeição para o Paciente %d: %.2f\n", numPacientes + 1, medcal);
    }
    else {
        printf("Nenhum dado de calorias disponível para o Paciente %d.\n", numPacientes + 1);
    }

    return 0;
}