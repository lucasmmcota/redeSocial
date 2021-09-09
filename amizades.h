#ifndef AMIZADES_H_INCLUDED
#define AMIZADES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "redesocial.h"

void cadastrarAmizades(TRedeSocial *rede, TUsuarios user1, TUsuarios user2);
int pesquisarAmizades(TRedeSocial rede, TUsuarios user1, TUsuarios user2);
void excluirAmizades(TRedeSocial *rede, TUsuarios user1, TUsuarios user2);
void imprimirAmizades(TRedeSocial rede, TUsuarios user);

#endif
