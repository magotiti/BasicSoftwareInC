#include <stdio.h>
#include <string.h>

// Usa bitwise pra verificar cada permissao e printa no formato -rwxrwxrwx.
void exibirPermissoes(int permissoes, const char *arquivoNome)
{
    // Mudando permissoes de int para string, p/ permitir perms individuais
    char defPerms[10] = "---------";
    defPerms[0] = '-';

    // Implementacao de bitwise para verificar cada permissao de cada grupo
    if (permissoes & (1 << 8))
        defPerms[1] = 'r'; // Leitura do Proprietario
    if (permissoes & (1 << 7))
        defPerms[2] = 'w'; // Escrita do Proprietario
    if (permissoes & (1 << 6))
        defPerms[3] = 'x'; // Execucao do Proprietario

    if (permissoes & (1 << 5))
        defPerms[4] = 'r'; // Leitura do Grupo
    if (permissoes & (1 << 4))
        defPerms[5] = 'w'; // Escrita do Grupo
    if (permissoes & (1 << 3))
        defPerms[6] = 'x'; // Execucao do Grupo

    if (permissoes & (1 << 2))
        defPerms[7] = 'r'; // Leitura de Outros
    if (permissoes & (1 << 1))
        defPerms[8] = 'w'; // Escrita de Outros
    if (permissoes & (1 << 0))
        defPerms[9] = 'x'; // Execucao de Outros

    printf("%s %s\n", defPerms, arquivoNome);
}

void defPermissoes(int *permissoes, int bit, int valor)
{
    if (valor)
        *permissoes |= (1 << bit);
    else
        *permissoes &= ~(1 << bit);
}

int main()
{
    int permissoes = 0;
    char comandos[50];
    char arquivoNome[16] = "arquivo.txt";
    char executa[10], alvo[10], permissaoTipo[10];
    int permissaoOctal;

    printf("Simulacao de Terminal de Permissoes de Arquivo\n");
    printf("Digite 'help' para ver os comandos disponiveis.\n\n");

    while (1)
    {
        // Simula um terminal
        printf("> ");
        fgets(comandos, sizeof(comandos), stdin);

        // Remove o newline final da string de comandos
        comandos[strcspn(comandos, "\n")] = 0;

        // Terminal
        // strcmp -> comparacao de strings (ASCII). Retorna 0 se iguais. <string.h>
        // sscanf -> le a string e armazena em variaveis.

        if (sscanf(comandos, "%s %s %s", executa, alvo, permissaoTipo) == 1)
        {
            if (strcmp(executa, "exit") == 0)
            {
                printf("Saindo...\n");
                break;
            }
            else if (strcmp(executa, "show") == 0)
            {
                exibirPermissoes(permissoes, arquivoNome);
            }
            else if (strcmp(executa, "help") == 0)
            {
                printf("Comandos disponiveis:\n");
                printf("set [octal]        - Define as permissoes usando um numero octal (ex: set 764)\n");
                printf("add u/g/o r/w/x    - Adiciona permissao de leitura, escrita ou execucao\n");
                printf("remove u/g/o r/w/x - Remove permissao de leitura, escrita ou execucao\n");
                printf("show               - Exibe as permissoes atuais\n");
                printf("exit               - Sai do programa\n");
            }
            else
            {
                printf("Comando invalido. Digite 'help' para ajuda.\n");
            }
        }
        else if (sscanf(comandos, "%s %o", executa, &permissaoOctal) == 2 && strcmp(executa, "set") == 0)
        {
            permissoes = permissaoOctal;
            printf("Permissoes definidas para ");
            exibirPermissoes(permissoes, arquivoNome);
        }
        else if (sscanf(comandos, "%s %s %s", executa, alvo, permissaoTipo) == 3)
        {
            int grupo = -1, type = -1;
            int addPerm = strcmp(executa, "add") == 0;
            int removePerm = strcmp(executa, "remove") == 0;

            if (strcmp(alvo, "u") == 0)
                grupo = 0;
            else if (strcmp(alvo, "g") == 0)
                grupo = 1;
            else if (strcmp(alvo, "o") == 0)
                grupo = 2;

            if (strcmp(permissaoTipo, "r") == 0)
                type = 0;
            else if (strcmp(permissaoTipo, "w") == 0)
                type = 1;
            else if (strcmp(permissaoTipo, "x") == 0)
                type = 2;

            if (grupo != -1 && type != -1 && (addPerm || removePerm))
            {
                int posicaoBit = 8 - 3 * grupo - type;
                defPermissoes(&permissoes, posicaoBit, addPerm);
                printf("Permissoes atualizadas: ");
                exibirPermissoes(permissoes, arquivoNome);
            }
            else
            {
                printf("Comando invalido. Use 'add u/g/o r/w/x' ou 'remove u/g/o r/w/x'.\n");
            }
        }
        else
        {
            printf("Comando nao reconhecido. Digite 'help' para ajuda.\n");
        }
    }

    return 0;
}
