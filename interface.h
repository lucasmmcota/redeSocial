#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "redesocial.h"

void mensagemMenu();
void mensagemSubMenu(int modulo);
void moduloUm(TRedeSocial *rede, TUsuarios user);
void moduloDois(TRedeSocial *rede, TUsuarios user);

#endif
