#include <stdlib.h>
#include "data.h"

Data* data_novo(int ano, int mes, int dia){
    Data *nova_data;

    nova_data = (Data *) malloc(sizeof(Data));
    nova_data->ano = ano;
    nova_data->mes = mes;
    nova_data->dia = dia;

    return nova_data;
 }

/*Data* data_atual() {
    return data_novo(2013,12,30);
}*/
