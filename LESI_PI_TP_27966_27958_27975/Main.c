/*
--Trabalho de Grupo--
Bruno dantass - 27958@alunos.ipca.pt
Diogo Abreu - 27975@alunos.ipca.pt
Paulo Gonçalves - 27966@alunos.ipca.pt
DATA : HOJE
Nutricionistas
*/



#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura da dieta
struct Dieta {
    int numero_paciente;
    char data[11]; // String para armazenar a data (YYYY-MM-DD)
    char refeicao[20];
    char alimento[50];
    int calorias;
};

int main() {
    // Nome do segundo arquivo a ser lido
    char nome_arquivo_dieta[] = "dieta_pacientes.txt";

    // Tentativa de abrir o segundo arquivo
    FILE* arquivo_dieta = fopen(nome_arquivo_dieta, "r");

    // Verifica se o segundo arquivo foi aberto com sucesso
    if (arquivo_dieta == NULL) {
        perror("Erro ao abrir o arquivo de dieta");
        return 1;
    }

    // Array para armazenar as informações da dieta
    struct Dieta dieta[100]; // Supondo um número máximo de 100 entradas de dieta

    int num_dieta = 0; // Contador de entradas de dieta

    // Lendo o segundo arquivo linha por linha
    while (fscanf(arquivo_dieta, "%d,%10[^;],%19[^;],%49[^;],%d\n",
        &dieta[num_dieta].numero_paciente, dieta[num_dieta].data, dieta[num_dieta].refeicao,
        dieta[num_dieta].alimento, &dieta[num_dieta].calorias) == 5) {
        num_dieta++;

        // Verifica se atingiu o limite máximo de entradas de dieta
        if (num_dieta == 100) {
            printf("Atingido o número máximo de entradas de dieta. Aumente o tamanho do array.\n");
            break;
        }
    }

    // Fechando o segundo arquivo após a leitura
    fclose(arquivo_dieta);

    // Exibindo informações da dieta
    for (int i = 0; i < num_dieta; i++) {
        printf("Número Paciente: %d, Data: %s, Refeição: %s, Alimento: %s, Calorias: %d\n",
            dieta[i].numero_paciente, dieta[i].data, dieta[i].refeicao, dieta[i].alimento, dieta[i].calorias);
    }

    return 0;
}
