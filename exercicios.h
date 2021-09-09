#ifndef EXERCICIOS_H_INCLUDED
#define EXERCICIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "redesocial.h"

int maisPopular(TRedeSocial rede); // Letra A
int amizadesEmComum(TRedeSocial rede, int id1, int id2); // Letra B
void matrizDeAmigosEmComum(TRedeSocial *rede); // Letra C
int nenhumAmigoEmComum(TRedeSocial *rede, TUsuarios user1, TUsuarios user2); // Letra D
int amizadeIndiretaNivelUm(TRedeSocial *rede, TUsuarios user1, TUsuarios user2); // Letra E
int amizadeIndiretaNivelDois(TRedeSocial *rede, TUsuarios user1, TUsuarios user2); // Letra F

#endif // EXERCICIOS_H_INCLUDED
