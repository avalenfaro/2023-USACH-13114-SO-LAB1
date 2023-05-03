#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "map.h"
#include "reduce.h"

#define ROW_LENGHT 1000
#define FILE_SIZE 9924

FILE *read_file()
{
  FILE *fp = fopen("./permiso-de-circulacion-2022.csv", "r");

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

void read_lines(FILE *fp, Vehiculo vehiculos[])
{
  char row[ROW_LENGHT];
  fgets(row, ROW_LENGHT, fp);

  for (int i = 0; i < FILE_SIZE - 1; i++)
  {
    fgets(row, ROW_LENGHT, fp);
    vehiculos[i].grupo_vehiculo = find_token(row, 1);
    vehiculos[i].tasacion = atof(find_token(row, 6));
    vehiculos[i].valor_pagado = atof(find_token(row, 11));
    vehiculos[i].puertas = atoi(find_token(row, 23));
  }
}

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
  FILE *c = read_file();
  Vehiculo vehiculos[FILE_SIZE];
  read_lines(c, vehiculos);
  Map *tasaciones = map_tasaciones(vehiculos);
  Map *valor_pagado = map_valor_pagado(vehiculos);
  Map *puertas = map_puertas(vehiculos);
  reduce_tasacion(tasaciones);
  reduce_valor_pagado(valor_pagado);
  reduce_puertas(puertas);
  return 0;
}
