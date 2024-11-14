# Descrição

Este estudo dirigido consiste em uma série de atividades teóricas e práticas que visam explorar os operadores bitwise em C. Os alunos deverão realizar leituras, resolver exercícios e desenvolver pequenos programas que utilizem operadores bitwise, demonstrando a aplicação desses conceitos em cenários reais.

# Atividades

### Atividade 1: Leitura e Resumo

Ler o material disponível no Moodle e na internet e fazer um resumo explicativo sobre cada operador bitwise em C.
Entrega: Documento com o resumo
### Atividade 2: Programação Prática

Desenvolver um programa em C que utilize operadores bitwise para resolver o problema de manipulação de flags em um sistema de permissões de arquivos. As permissões de um arquivo no estilo Unix são representadas por 9 bits divididos em três grupos:

* Proprietário (User): 3 bits (leitura, escrita, execução)
* Grupo (Group): 3 bits (leitura, escrita, execução)
* Outros (Others): 3 bits (leitura, escrita, execução)

Por exemplo, o conjunto de permissões `-rw-r--r--` é representado em binário como `110100100`, onde:

`r` (read), `w` (write), e `x` (execute) indicam permissões ativas, e `-` indica permissões desativadas.
Objetivo do Programa: Criar um programa que permita ao usuário definir permissões para um arquivo fictício e exibi-las em um formato que imita o comando `ls -l` do Unix.

### Especificações:

Entrada do Usuário: Solicitar que o usuário insira as permissões como um número octal (por exemplo, 764).
Processamento dos Bits: Converter o número octal para um formato binário de 9 bits, onde cada trio representa permissões para o proprietário, grupo e outros usuários.
Exibição das Permissões: Exibir as permissões em uma interface similar ao comando ls -l, incluindo:
Permissões em formato -rwxrwxrwx.
Nome do Arquivo (por exemplo, "arquivo.txt").
Exemplo de Entrada e Saída:

Entrada: `764`
Saída:
`-rwxrw-r-- arquivo.txt`

# Entrega
Pacote zip no moodle contendo os fontes dos programas e o resumo sobre a leitura
Avaliação
A avaliação será baseada nos seguintes critérios:

Clareza e precisão do resumo sobre operadores bitwise
Correção e qualidade das respostas dos exercícios teóricos
Funcionamento correto e eficiência do programa desenvolvido
Qualidade das explicações sobre a utilização dos operadores bitwise nos programas
Recursos
Editor de texto e compilador C (recomenda-se o uso de IDEs como Code::Blocks, Dev-C++, ou Visual Studio Code)
Livros e artigos recomendados pelo professor