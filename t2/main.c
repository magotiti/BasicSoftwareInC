#include <stdio.h>


// Usa bitwise pra verificar cada permissão e printa no formato -rwxrwxrwx.
void exibirPermissoes(int permissoes, const char *arquivoNome) {
    // Mudando permissoes de int para string, p/ permitir perms individuais
    char defPerms[10] = "---------";
    defPerms[0] = '-';

    // Implementação de bitwise para verificar cada permissão de cada grupo
    if (permissoes & (1 << 8)) defPerms[1] = 'r'; // Leitura do Proprietário
    if (permissoes & (1 << 7)) defPerms[2] = 'w'; // Escrita do Proprietário
    if (permissoes & (1 << 6)) defPerms[3] = 'x'; // Execução do Proprietário

    if (permissoes & (1 << 5)) defPerms[4] = 'r'; // Leitura do Grupo
    if (permissoes & (1 << 4)) defPerms[5] = 'w'; // Escrita do Grupo
    if (permissoes & (1 << 3)) defPerms[6] = 'x'; // Execução do Grupo

    if (permissoes & (1 << 2)) defPerms[7] = 'r'; // Leitura de Outros
    if (permissoes & (1 << 1)) defPerms[8] = 'w'; // Escrita de Outros
    if (permissoes & (1 << 0)) defPerms[9] = 'x'; // Execução de Outros

    printf("%s %s\n", defPerms, arquivoNome);
}

void defPermissoes(int *permissoes, int bit, int valor) {
    if (valor)
        *permissoes |= (1 << bit);
    else
        *permissoes &= ~(1 << bit);
}

int main() {
    int permissoes;
    char arquivoNome[50] = "arquivo.txt";

    // Entrada inicial em octal para atender ao enunciado
    printf("Insira as permissões do arquivo em formato octal (ex: 764): ");
    scanf("%o", &permissoes);

    printf("Permissões iniciais: ");
    exibirPermissoes(permissoes, arquivoNome);

    int opcao, grupo, tipo;

    do {
        printf("\nSelecione uma opção:\n");
        printf("1. Adicionar permissão\n");
        printf("2. Remover permissão\n");
        printf("3. Exibir permissões\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1 || opcao == 2) {
            printf("Escolha o grupo:\n");
            printf("1. Proprietário (User)\n");
            printf("2. Grupo (grupo)\n");
            printf("3. Outros (Others)\n");
            printf("Escolha: ");
            scanf("%d", &grupo);

            printf("Escolha o tipo de permissão:\n");
            printf("1. Leitura (r)\n");
            printf("2. Escrita (w)\n");
            printf("3. Execução (x)\n");
            printf("Escolha: ");
            scanf("%d", &tipo);

            int posicaoBit = 8 - 3 * (grupo - 1) - (tipo - 1);

            if (opcao == 1) {
                set_permission(&permissoes, posicaoBit, 1);
            } else if (opcao == 2) {
                set_permission(&permissoes, posicaoBit, 0);
            }

            printf("Permissões atualizadas: ");
            exibirPermissoes(permissoes, arquivoNome);
        } else if (opcao == 3) {
            printf("Permissões atuais: ");
            exibirPermissoes(permissoes, arquivoNome);
        }
    } while (opcao != 0);

    return 0;
}