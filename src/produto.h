#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdio.h>
#include "data.h"

#define PRODUTO_CABECALHO "[produto]"

struct _produto {
    char *nome;
    char *categoria;
    int codigo;
    float preco;
    int quantidade;
    char *fabricante;
    char *descricao;
    Data* validade;
    int corredor;
    int prateleira;

};

typedef struct _produto Produto;

/*
 * Retorna um objeto do tipo produto.
 */
Produto* produto_novo(char *nome, char *categoria, int codigo, float preco, int quantidade,
                     char *fabricante, char *descricao, Data* validade, int corredor,
                     int prateleira);

/*
 * Salva um produto no banco de dados.
 */
int produto_salvar (Produto *prod, FILE *bd);

/*
 * Imprime o produto na saída padrão.
 */
void produto_listar (Produto *prod);

#endif
