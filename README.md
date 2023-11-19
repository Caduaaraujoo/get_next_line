# GNL

<p align="center">
  <img src="./get_next_linem.png" alt="Logo da libftm">
</p>

O projeto get_next_line tem como objetivo criar uma função em linguagem C, chamada get_next_line(), capaz de ler uma linha de um arquivo descrito por um descritor de arquivo (file descriptor) fornecido como parâmetro. A função deve ser capaz de lidar com diferentes valores do sinalizador -D BUFFER_SIZE, permitindo compilar o projeto com diferentes tamanhos de buffer.

## Compilando o Projeto
Para compilar o projeto, você pode usar o seguinte comando, ajustando o valor de BUFFER_SIZE conforme necessário:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <arquivos>.c
# caso você não passe o tamanho do buffer, ele será definido com o valor de 80 bytes.
```
*Substitua **arquivos**.c pelos arquivos-fonte necessários para o projeto incluindo a **gnl**.*

## Especificações da Função

- **Deve funcionar corretamente mesmo se o valor de BUFFER_SIZE for ajustado para diferentes valores, como 9999, 1 ou 10000000.**

- **A leitura deve ser feita de forma eficiente, evitando a leitura do arquivo inteiro e processando linha por linha.**

- **A função deve retornar a linha atual quando uma nova linha for encontrada.**

- **É importante notar que o comportamento da função é considerado indefinido se o arquivo associado ao descritor de arquivo tiver sido alterado desde a última chamada à função.**

- **A função também é considerada indefinida ao lidar com arquivos binários.**



# Bônus

Bem-vindo à parte de bônus do projeto get_next_line!.

## Requisitos do Bônus

- **Desenvolvimento com Apenas uma Variável Estática.**
- **Suporte a Múltiplos Descritores de Arquivo.**
- **Estender a funcionalidade do get_next_line() para gerenciar vários descritores de arquivo simultaneamente. Isso significa que a função deve ser capaz de ler de diferentes descritores de arquivo em chamadas consecutivas, mantendo o estado de leitura para cada um.**

#### Por exemplo, o seguinte cenário deve ser possível:

- **Chamar get_next_line() para ler do descritor de arquivo 3.**
- **Em seguida, chamar get_next_line() para ler do descritor de arquivo 4.**
- **Posteriormente, chamar get_next_line() para ler do descritor de arquivo 5.**
- **Retornar a leitura do descritor de arquivo 3 sem perder o estado.**

## Contribuindo

Sinta-se à vontade para contribuir para o desenvolvimento da gnl. Se encontrar bugs ou tiver melhorias para sugerir, abra uma issue ou envie uma pull request.

### Divirta-se programando em C com a gnl!