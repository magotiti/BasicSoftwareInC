#include <stdio.h>


// Usa bitwise pra verificar cada permissão e printa no formato -rwxrwxrwx.
void exibirPermissoes(int permOctal, const char* nomeArquivo) {
 int permissoes = 0;
 
 // Converte octal em binário
 permissoes |= (permOctal / 100 % 10) << 6; // Bits do proprietário
 permissoes |= (permOctal / 10 % 10) << 3;  // Bits do grupo
 permissoes |= (permOctal % 10);            // Bits dos outros
 
 // Print do formato de permissões (read, write, execute)
 printf("%c", (permissoes & 0x100) ? 'r' : '-'); // Proprietário leitura
 printf("%c", (permissoes & 0x080) ? 'w' : '-'); // Proprietário escrita
 printf("%c", (permissoes & 0x040) ? 'x' : '-'); // Proprietário execução
 printf("%c", (permissoes & 0x020) ? 'r' : '-'); // Grupo leitura
 printf("%c", (permissoes & 0x010) ? 'w' : '-'); // Grupo escrita
 printf("%c", (permissoes & 0x008) ? 'x' : '-'); // Grupo execução
 printf("%c", (permissoes & 0x004) ? 'r' : '-'); // Outros leitura
 printf("%c", (permissoes & 0x002) ? 'w' : '-'); // Outros escrita
 printf("%c ", (permissoes & 0x001) ? 'x' : '-'); // Outros execução
 printf("%s\n", nomeArquivo);
}

int main() {
 int permOctal;
 printf("Digite as permissoes do arquivo em formato octal (ex: 123): ");
 scanf("%o", &permOctal);
 
 exibirPermissoes(permOctal, "arquivo.txt");
 return 0;
}