#ifndef MAP_H
#define MAP_H

typedef struct
{
  char *grupo_vehiculo;
  float tasacion;
  float valor_pagado;
  int puertas;
} Vehiculo;

typedef struct
{
  float vehiculo_liviano;
  float carga;
  float transporte_publico;
} Map;

Map *map_tasaciones(Vehiculo vehiculos[]);
Map *map_valor_pagado(Vehiculo vehiculos[]);
Map *map_puertas(Vehiculo vehiculos[]);

#endif