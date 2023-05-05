#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "map.h"
#define ROW_LENGHT 1000
#define FILE_SIZE 9924

void reduce_tasacion(Map *tasaciones, int verbose)
{
  int v_liviano = 0;
  int carga = 0;
  int transporte_publico = 0;
  for (int i = 0; i < FILE_SIZE - 1; i++)
  {
    v_liviano += tasaciones[i].vehiculo_liviano;
    carga += tasaciones[i].carga;
    transporte_publico += tasaciones[i].transporte_publico;
  }
  if (verbose == 1)
  {
    printf("Total de tasaciones para vehiculo liviano:%d\n", v_liviano);
    printf("Total de tasaciones para vehiculo de carga:%d\n", carga);
    printf("Total de tasaciones para vehiculo de transporte:%d\n\n", transporte_publico);
  }
}

void reduce_valor_pagado(Map *valor_pagado, int verbose)
{
  int v_liviano = 0;
  int carga = 0;
  int transporte_publico = 0;
  for (int i = 0; i < FILE_SIZE - 1; i++)
  {
    v_liviano += valor_pagado[i].vehiculo_liviano;
    carga += valor_pagado[i].carga;
    transporte_publico += valor_pagado[i].transporte_publico;
  }

  if (verbose == 1)
  {
    printf("Valor pagado total para vehiculo liviano:%d\n", v_liviano);
    printf("Valor pagado total para vehiculo de carga:%d\n", carga);
    printf("Valor pagado total para vehiculo de transporte:%d\n\n", transporte_publico);
  }
}

void reduce_puertas(Map *valor_pagado, int verbose)
{
  int v_liviano_2 = 0;
  int v_liviano_4 = 0;
  int carga_2 = 0;
  int carga_4 = 0;
  int trans_publico_2 = 0;
  int trans_publico_4 = 0;
  int trans_publico_5 = 0;
  for (int i = 0; i < FILE_SIZE - 1; i++)
  {
    if (valor_pagado[i].vehiculo_liviano == 2)
    {
      v_liviano_2 += 1;
    }

    if (valor_pagado[i].vehiculo_liviano == 4)
    {
      v_liviano_4 += 1;
    }

    if (valor_pagado[i].carga == 2)
    {
      carga_2 += 1;
    }
    if (valor_pagado[i].carga == 4)
    {
      carga_4 += 1;
    }

    if (valor_pagado[i].transporte_publico == 2)
    {
      trans_publico_2 += 1;
    }
    if (valor_pagado[i].transporte_publico == 4)
    {
      trans_publico_4 += 1;
    }
    if (valor_pagado[i].transporte_publico == 5)
    {
      trans_publico_5 += 1;
    }
  }

  if (verbose == 1)
  {
    printf("Total de vehiculos con 2 puertas para Vehiculos Livianos: %d\n", v_liviano_2);
    printf("Total de vehiculos con 4 puertas para Vehiculos Livianos: %d\n", v_liviano_4);
    printf("Total de vehiculos con 2 puertas para carga: %d\n", carga_2);
    printf("Total de vehiculos con 4 puertas para carga: %d\n", carga_4);
    printf("Total de vehiculos con 2 puertas para Transporte Publico: %d\n", trans_publico_2);
    printf("Total de vehiculos con 4 puertas para Transporte Publico: %d\n", trans_publico_4);
    printf("Total de vehiculos con 5 puertas para Transporte Publico: %d\n", trans_publico_5);
  }
}