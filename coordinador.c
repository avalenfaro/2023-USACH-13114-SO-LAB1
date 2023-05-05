/**
 * @file coordinador.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "map.h"
#include "reduce.h"
#include "coordinador.h"

#define ROW_LENGHT 1000
#define FILE_SIZE 9924

/**
 * @brief Get the flags object
 *
 * @param argc
 * @param argv
 * @param c
 */
void get_flags(int argc, char const *argv[], Coordinador *c)
{
  for (int i = 0; i < argc; i++)
  {
    if (strcmp(argv[i], "-i") == 0)
    {
      strcpy(c->nombre_archivo, argv[i + 1]);
    }

    if (strcmp(argv[i], "-c") == 0)
    {
      c->total_lineas = atoi(argv[i + 1]);
    }

    if (strcmp(argv[i], "-d") == 0)
    {
      c->verbose = 1;
    }
    else
    {
      c->verbose = 0;
    }
  }
}

/**
 * @brief
 *
 * @param nombre_archivo
 * @return FILE*
 */
FILE *read_file(char nombre_archivo[])
{
  FILE *fp = fopen((const char *)nombre_archivo, "r");
  int errnum;
  if (fp == NULL)
  {
    errnum = errno;
    printf("Error al abrir el archivo: %s\n", strerror(errnum));
    exit(-1);
  }

  return fp;
}

char *find_token(char *row, int col_number)
{
  char *row_copy = (char *)malloc(ROW_LENGHT);
  char *token;
  strcpy(row_copy, row);
  for (int i = 0; i < col_number; i++)
  {
    if (i == 0)
    {
      token = strtok(row_copy, ";");
      continue;
    }

    token = strtok(NULL, ";");
  }

  return token;
}

void read_lines(FILE *fp, Vehiculo vehiculos[], int total_lineas)
{
  char row[ROW_LENGHT];
  fgets(row, ROW_LENGHT, fp);

  for (int i = 0; i < total_lineas - 1; i++)
  {
    fgets(row, total_lineas, fp);
    vehiculos[i].grupo_vehiculo = find_token(row, 1);
    vehiculos[i].tasacion = atof(find_token(row, 6));
    vehiculos[i].valor_pagado = atof(find_token(row, 11));
    vehiculos[i].puertas = atoi(find_token(row, 23));
  }
}

/**
 * @brief
 *
 * @param n
 * @param vehiculos
 */
void head_vehiculos(int n, Vehiculo vehiculos[])
{
  for (int i = 0; i < n; i++)
  {
    printf("grupo vehiculo: %s\n", vehiculos[i].grupo_vehiculo);
    printf("tasacion: %.2f\n", vehiculos[i].tasacion);
    printf("valor pagado: %.2f\n", vehiculos[i].valor_pagado);
    printf("puertas: %d\n", vehiculos[i].puertas);
    printf("--------------------\n");
  }
}

/**
 * @brief
 *
 * @param n
 * @param map
 */
void head_mapeo(int n, Map map[])
{
  for (int i = 0; i < n; i++)
  {
    printf("grupo vehiculo: %.2f\n", map[i].vehiculo_liviano);
    printf("carga: %.2f\n", map[i].carga);
    printf("transporte publico: %.2f\n", map[i].transporte_publico);
    printf("--------------------\n");
  }
}

int main(int argc, char const *argv[])
{
  Coordinador coordinador;
  get_flags(argc, argv, &coordinador);
  FILE *c = read_file(coordinador.nombre_archivo);
  Vehiculo vehiculos[coordinador.total_lineas];
  read_lines(c, vehiculos, coordinador.total_lineas);
  Map *tasaciones = map_tasaciones(vehiculos, coordinador.total_lineas);
  Map *valor_pagado = map_valor_pagado(vehiculos, coordinador.total_lineas);
  Map *puertas = map_puertas(vehiculos, coordinador.total_lineas);
  reduce_tasacion(tasaciones, coordinador.verbose, coordinador.total_lineas);
  reduce_valor_pagado(valor_pagado, coordinador.verbose, coordinador.total_lineas);
  reduce_puertas(puertas, coordinador.verbose, coordinador.total_lineas);
  return 0;
}
