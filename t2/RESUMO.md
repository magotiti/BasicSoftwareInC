# Operadores Bitwise em C

Este é um resumo a respeito dos operadores bitwise na linguagem de programação C. Esses operadores permitem manipulações de bits diretamente, sendo muito úteis em contextos de baixo nível, como programação de sistemas embarcados, manipulação de bandeiras (flags), operações de criptografia, otimização de desempenho em cálculos e controle de permissões.

---

## Por que usar máscaras?

Máscaras são valores que isolam ou alteram bits específicos em um número, aplicando operações como AND, OR e XOR para modificar ou verificar apenas partes específicas de um valor sem interferir nos outros bits. O uso de máscaras é particularmente comum em programação de sistemas, onde é preciso acessar e manipular bits individuais para configurar estados de hardware, permissões, ou outros atributos de controle em um sistema. Por exemplo, com máscaras, é possível ativar, desativar ou verificar estados específicos dentro de um registro de controle, algo essencial em desenvolvimento de drivers e interfaces de comunicação.

No programa apresentado, as máscaras são usadas para verificar ou alterar bits que correspondem a permissões específicas (leitura, escrita e execução) em diferentes categorias (proprietário, grupo e outros). Por exemplo, operações como `permissoes & (1 << 8)` aplicam máscaras para verificar se o bit de leitura do proprietário está ativo, enquanto `*permissoes |= (1 << bit)` ativa bits correspondentes a permissões.

## Representação binária e hexadecimal

A representação binária (base 2) exibe cada bit individualmente como 0 ou 1, tornando-a ideal para visualização precisa de cada bit. No entanto, a leitura de números binários longos pode ser difícil. Em contrapartida, a representação hexadecimal (base 16) oferece uma maneira mais compacta de representar números binários, usando dígitos de 0 a F, onde cada dígito hexadecimal representa quatro bits. Em programação de sistemas, a notação hexadecimal é amplamente usada para definir máscaras, endereços de memória e valores binários de maneira mais legível e concisa, enquanto a notação binária é útil para operações bitwise ao nível mais detalhado.

No programa, as permissões são manipuladas em um formato binário para acesso direto aos bits, enquanto os valores numéricos das permissões podem ser definidos em formatos como octal, frequentemente utilizados em sistemas Unix/Linux para simplificar a configuração.

## Operadores Bitwise

A linguagem C fornece um conjunto de operadores lógicos bitwise, que incluem:

- **NOT (~)**: inverte todos os bits de um valor.
- **AND (&)**: realiza uma operação E lógico em cada bit, retornando 1 somente se ambos os bits forem 1.
- **OR (|)**: realiza uma operação OU lógico em cada bit, retornando 1 se pelo menos um dos bits for 1.
- **XOR (^)**: realiza uma operação OU exclusivo em cada bit, retornando 1 somente se os bits comparados forem diferentes.
- **Shift Left (<<)**: desloca os bits para a esquerda, multiplicando o valor por 2 para cada deslocamento.
- **Shift Right (>>)**: desloca os bits para a direita, dividindo o valor por 2 para cada deslocamento.

Esses operadores são amplamente usados para manipular bits específicos dentro de um valor numérico, o que pode ser essencial em sistemas que exigem alta eficiência ou controle preciso sobre dados binários.

## Operador NOT(~)

**Aplicação:**

- O operador NOT é utilizado para inverter todos os bits, transformando 1 em 0 e vice-versa. Pode ser usado em operações para encontrar o complemento de um número, útil em cálculos de subtração em nível de bits.

**Exemplo em binário:**
Este exemplo inverte os bits de um valor binário.

```
int a = 0b1100; // Binário (12 em decimal)
int result = ~a; // Resulta em -13 em sistemas de 2 complementos (invertendo todos os bits)
```

**Exemplo com máscara:**
Neste exemplo, a máscara 0x0F é invertida para isolar os bits mais altos, sendo útil para zerar os quatro bits mais baixos.

```
int mask = 0x0F;  // Hexadecimal (15 em decimal, 00001111 em binário)
int result = ~mask; // Resulta em 0xF0 (240 em decimal em sistemas de 8 bits)
```

## Operador AND(&)

**Aplicação:**

- O operador AND é utilizado para "limpar" bits específicos de um número ou verificar se certos bits estão ativados. Por exemplo, em sistemas de flags, ele pode ajudar a verificar se um bit específico está ativo.

**Exemplo em binário:**
Neste exemplo, AND é aplicado entre dois valores binários para preservar apenas os bits onde ambos são 1, útil em cálculos binários de permissões.

```
int a = 0b1100; // Binário (12 em decimal)
int b = 0b1010; // Binário (10 em decimal)
int result = a & b; // Resulta em 0b1000 (8 em decimal)
```

**Exemplo com máscara:**
Aqui, uma máscara de 0x0F é aplicada a flags para limpar (zerar) os bits superiores, mantendo apenas os bits mais baixos.

```
int flags = 0xF0; // Hexadecimal (240 em decimal, 11110000 em binário)
int mask = 0x0F;  // Hexadecimal (15 em decimal, 00001111 em binário)
int result = flags & mask; // Resulta em 0x00 (0 em decimal)
```

## Operador OR(|)

**Aplicação:**
Usado para "ativar" bits específicos, ou configurar múltiplos bits como 1. Em sistemas de flags, ele é útil para definir permissões ou opções.

**Exemplo em binário:**
Neste exemplo, OR é aplicado para ativar qualquer bit que esteja em 1 em ambos os valores, útil para configurar flags.

```
int a = 0b1100; // Binário (12 em decimal)
int b = 0b1010; // Binário (10 em decimal)
int result = a | b; // Resulta em 0b1110 (14 em decimal)
```

**Exemplo com máscara:**
Neste exemplo, OR é usado para ativar todos os bits de flags e mask, resultando em todos os bits como 1.

```
int flags = 0x0F; // Hexadecimal (15 em decimal, 00001111 em binário)
int mask = 0xF0;  // Hexadecimal (240 em decimal, 11110000 em binário)
int result = flags | mask; // Resulta em 0xFF (255 em decimal)
```

## Operador XOR(^)

**Aplicação:**
O operador XOR é usado para inverter bits específicos ou verificar diferenças entre valores. Em criptografia, é usado para embaralhar dados (por exemplo, aplicar uma chave de encriptação).

**Exemplo em binário:**
Aqui, XOR é aplicado entre dois valores para retornar 1 onde os bits são diferentes, o que é útil para detectar diferenças ou para operações de controle.

```
int a = 0b1100; // Binário (12 em decimal)
int b = 0b1010; // Binário (10 em decimal)
int result = a ^ b; // Resulta em 0b0110 (6 em decimal)
```

**Exemplo com máscara:**
Neste exemplo, XOR é usado com uma máscara para inverter apenas os quatro bits mais baixos do valor flags.

```
int flags = 0b11001100; // 204 em decimal
int mask = 0b00001111;  // Máscara para inverter os quatro bits à direita
int result = flags ^ mask; // Resultado: 0b11000011 (195 em decimal)
```

## Operador Shift Left (<<)

**Aplicação:**
Desloca todos os bits para a esquerda, multiplicando o número por 2 para cada deslocamento. Usado em cálculos eficientes, como multiplicações rápidas.

**Exemplo em binário:**
Neste exemplo, o valor a é deslocado para a esquerda em um bit, multiplicando-o por 2.

```
int a = 5; // 0101 em binário
int result = a << 1; // Resulta em 1010 (10 em decimal)
```

**Exemplo com máscara:**
Aqui, value é deslocado para a esquerda, e OR é aplicado para ativar bits adicionais definidos pela máscara, útil em configurações de controle.

```
int value = 0b00000101; // 5 em decimal
int mask = 0b00001100;  // Máscara para ativar bits 2 e 3
int result = (value << 1) | mask; // Desloca value para a esquerda e ativa bits 2 e 3
```

## Operador Shift Right (>>)

**Aplicação:**
Desloca os bits para a direita, dividindo o número por 2 para cada deslocamento. Útil para divisões rápidas ou para manipular estruturas de dados compactadas.

**Exemplo em binário:**
Neste exemplo, a é deslocado para a direita em um bit, dividindo o valor por 2.

```
int a = 10; // 1010 em binário
int result = a >> 1; // Resulta em 0101 (5 em decimal)
```

**Exemplo com máscara:**
Aqui, value é deslocado para a direita em dois bits, e uma máscara é aplicada para isolar os bits mais baixos após o deslocamento.

```
int value = 0b11001010; // 202 em decimal
int mask = 0b00001111;  // Máscara para limpar os quatro bits mais à esquerda
int result = (value >> 2) & mask; // Desloca value para a direita e limpa os quatro bits mais à esquerda
```

## Aplicações no Programa

No programa, os operadores bitwise foram usados principalmente para:

1. **Verificar permissões**: O operador AND (`&`) em combinação com `1 << bit` é utilizado para verificar se uma permissão específica está ativa. 
2. **Ativar permissões**: O operador OR (`|`) ativa um bit correspondente a uma permissão, como em `*permissoes |= (1 << bit)`.
3. **Desativar permissões**: O operador AND (`&`) e NOT (`~`) são usados juntos para limpar bits específicos, desativando permissões.
4. **Exibir permissões**: As permissões são exibidas no formato `-rwxrwxrwx`, baseando-se nos bits ativados.

O programa aceita comandos para adicionar, remover e definir permissões em formato octal, mostrando a aplicação prática dos operadores bitwise em um cenário realista de manipulação de permissões.

**Exemplo de uso no programa:**

Entrada:
```
add u r
add u w
show
```
Saída:
```plaintext
-rw------- arquivo.txt
