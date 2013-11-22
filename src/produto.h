#include <stdio.h>
#include "data.h"

struct _produto {
    char *nome;
    char *categoria;
    int codigo;
    float preco;
    int quantidade;
    char *fabricante;
    char *descricao;
    Data validade;
    int corredor;
    int prateleira;

};

typedef struct _produto Produto;

/*
 * Salva um produto no banco de dados.
 */
int produto_salvar (Produto prod, FILE *bd);

/*
 * Retorna um objeto do tipo produto.
 */
Produto produto_novo(char *nome, char *categoria, int codigo, float preco, int quantidade,
                     char *fabricante, char *descricao, Data validade, int corredor,
                     int prateleira);
