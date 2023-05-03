#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "map.h"

#define ROW_LENGHT 1000
#define FILE_SIZE 9924

const char *VEHICULO_LIVIANO_KEY = "Vehiculo Liviano";
const char *CARGA_KEY = "Carga";
const char *TRANSPORTE_PUBLICO_KEY = "Transporte Publico";

Map *map_tasaciones(Vehiculo vehiculos[])
{
  Map *map_tasacion = (Map *)malloc(sizeof(Map) * FILE_SIZE);
  for (int i = 0; i < FILE_SIZE - 1; i++)
  {
    if (strcmp(vehiculos[i].grupo_vehiculo, VEHICULO_LIVIANO_KEY) == 0)
    {
      map_tasacion[i].vehiculo_liviano = vehiculos[i].tasacion;
    }

    if (strcmp(vehiculos[i].grupo_vehiculo, CARGA_KEY) == 0)
    {
      map_tasacion[i].carga = vehiculos[i].tasacion;
    }

    if (strcmp(vehiculos[i].grupo_vehiculo, TRANSPORTE_PUBLICO_KEY) == 0)
    {
      map_tasacion[i].transporte_publico = vehiculos[i].tasacion;
    }
  }

  return map_tasacion;
}

Map *map_valor_pagado(Vehiculo vehiculos[])
{
  Map *map_valor_pagado = (Map *)malloc(sizeof(Map) * FILE_SIZE);
  for (int i = 0; i < FILE_SIZE - 1; i++)
  {
    if (strcmp(vehiculos[i].grupo_vehiculo, VEHICULO_LIVIANO_KEY) == 0)
    {
      map_valor_pagado[i].vehiculo_liviano = vehiculos[i].valor_pagado;
    }

    if (strcmp(vehiculos[i].grupo_vehiculo, CARGA_KEY) == 0)
    {
      map_valor_pagado[i].carga = vehiculos[i].valor_pagado;
    }

    if (strcmp(vehiculos[i].grupo_vehiculo, TRANSPORTE_PUBLICO_KEY) == 0)
    {
      map_valor_pagado[i].transporte_publico = vehiculos[i].valor_pagado;
    }
  }

  return map_valor_pagado;
}

Map *map_puertas(Vehiculo vehiculos[])
{
  Map *map_puertas = (Map *)malloc(sizeof(Map) * FILE_SIZE);
  for (int i = 0; i < FILE_SIZE - 1; i++)
  {
    if (strcmp(vehiculos[i].grupo_vehiculo, VEHICULO_LIVIANO_KEY) == 0)
    {
      map_puertas[i].vehiculo_liviano = vehiculos[i].puertas;
    }

    if (strcmp(vehiculos[i].grupo_vehiculo, CARGA_KEY) == 0)
    {
      map_puertas[i].carga = vehiculos[i].puertas;
    }

    if (strcmp(vehiculos[i].grupo_vehiculo, TRANSPORTE_PUBLICO_KEY) == 0)
    {
      map_puertas[i].transporte_publico = vehiculos[i].puertas;
    }
  }

  return map_puertas;
}
