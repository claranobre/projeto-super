#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <signal.h>

#include "estoque.h"
#include "carrinho.h"
#include "cliente.h"
#include "funcionario.h"
#include "produto.h"
#include "utils.h"
#include "globals.h"


/*
 * Inicialização do sistema.
 */
void init ();

/*
 * Encerra o programa.
 */
void sair (int signum);


int main () {
    int opcao;

    init();
    signal (SIGINT, sair);

    limpar_terminal();
    cabecalho("Bem vindo!");

    printf("[1] Cliente\n");
    printf("[2] Funcionário\n");

    rodape ();

    scanf ("%i", &opcao);

    if (opcao == 1) {
        do {
            // Lê a escolha do usuário.
            opcao = cliente_menu ();

            switch (opcao) {
                case CLIENTE_BUSCA_NOME:
                    break;
                case CLIENTE_BUSCA_FABRICANTE:
                    break;
                case CLIENTE_BUSCA_CATEGORIA:
                    break;
                case CLIENTE_CARRINHO_LISTAR:
                    break;
                case CLIENTE_CARRINHO_ADD:
                    break;
                case CLIENTE_CARRINHO_RM:
                    break;
                case CLIENTE_CARRINHO_SUBTOTAL:
                    break;
                case CLIENTE_CARRINHO_FECHAR_COMPRA:
                    break;
            }
        } while (opcao != EOF);
    } else if (opcao == 2) {
        do {
            // Lê a escolha do usuário.
            opcao = funcionario_menu ();

            // Executa a ação desejada.
            switch (opcao) {
                case FUNCIONARIO_BUSCA_NOME:
                    funcionario_busca_nome (estoque);
                    break;
                case FUNCIONARIO_BUSCA_CODIGO:
                    break;
                case FUNCIONARIO_BUSCA_FABRICANTE:
                    break;
                case FUNCIONARIO_PRODUTO_ADD:
                    break;
                case FUNCIONARIO_PRODUTO_RM:
                    break;
                case FUNCIONARIO_ESTOQUE_REPOR:
                    break;
                case FUNCIONARIO_ESTOQUE_LISTAR_NOME:
                    funcionario_listar_nome (estoque);
                    break;
            }
        } while (opcao != EOF);
    }

    return 0;
}

void init () {
    bd = fopen(BD_NAME, "r+");

    // Verifica se o arquivo abriu com sucesso.
    assert(bd != NULL);

    estoque = estoque_novo_de_arquivo (bd);
}

void sair (int signum) {
    limpar_terminal ();
    cabecalho ("Encerrando aplicação");

    rewind(bd);
    estoque_salvar (estoque, bd);

    printf("organizando o estoque...                            OK!\n");
    printf("varrendo os corredores...                           OK!\n");
    printf("contabilizando lucros...                            OK!\n");
    printf("salvando produtos...                                OK!\n");
    printf("saindo...                                           obrigado e até logo! :)\n");

    free (estoque);
    fclose (bd);

    exit (EXIT_SUCCESS);
}

