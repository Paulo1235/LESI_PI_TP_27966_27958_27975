/*
--Trabalho de Grupo--
Bruno Dantas - a27958@alunos.ipca.pt
Diogo Abreu - a27975@alunos.ipca.pt
Paulo Gonçalves - a27966@alunos.ipca.pt
DATA : HOJE
Nutricionistas
*/

#include "Gabinete.h"
#include "Gerirficheiros.h"
int main()
{
    printf("Hello world");
    Paciente p[k];

    int a = ImportarPacientes("Pacientes.txt", p);
    
    MostraArrayPaciente(p, a);



















    /*
    //Pergunta 2

    char nomeArquivo[] = "DietaDetalhada.txt";
    int limiteCalorias = 2000;

    // Chama a função para contar pacientes que ultrapassaram o limite de calorias
    int resultado = contarPacientesQueUltrapassaram(nomeArquivo, limiteCalorias);

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

    //Pergunta 6 

        // Defina o número de pacientes lendo as linhas que o ficheiro tem 

    int numPacientes = contarPacientes("Pacientes.txt");
    int c = 3;


    printf("| %-15s | %-20s | %-15s | %-12s | %-12s | %-15s | %-15s | %-20s |\n",
        "Num Paciente", "Nome", "Tipo Refeicao", "Data Inicio", "Data Fim", "Cal Minimo", "Cal Maximo", "Consumo Realizado");
    printf("|-----------------|----------------------|------------------|------------------|------------------|----------------------|----------------------|-------------------------|\n");


    FILE* arquivo;
    char nomeArquivo[] = "Pacientes.txt";  // Substitua pelo nome do seu arquivo

    // Abre o arquivo para leitura
    arquivo = fopen(nomeArquivo, "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    // Crie um array de pacientes
    //Paciente pacientes[c];

    // Carrega os dados do arquivo para o array de pacientes

    // Popule o array com dados fictícios (substitua isso pelos dados reais do seu sistema)

    /////ALTERAR PARA IR BUSCAR AO FICHEIRO
    //pacientes[0] = (Paciente){ 1, "Paciente1", "Almoco", "01/01/2023", "01/01/2023", 500, 800, 700 };
    //pacientes[1] = (Paciente){ 2, "Paciente2", "Jantar", "01/01/2023", "01/01/2023", 600, 900, 750 };
    //pacientes[2] = (Paciente){ 3, "Paciente3", "Cafe da Manha", "01/01/2023", "01/01/2023", 400, 700, 500 };



    // Exiba a tabela
    //exibirTabela(pacientes, numPacientes);//função exibir clientes

    //    for (int i = 0; i < numPacientes; i++) {
    //    printf("| %-15d | %-20s | %-15s | %-12s | %-12s | %-15d | %-15d | %-20d |\n",
    //        pacientes[i].numeroPaciente, pacientes[i].nome, pacientes[i].tipoRefeicao,
    //        pacientes[i].dataInicio, pacientes[i].dataFim, pacientes[i].caloriasMinimo,
    //        pacientes[i].caloriasMaximo, pacientes[i].consumoRealizado);
    //}*/
return 0;
}