#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "Givens.h"

#include <stdio.h>
#include <stdbool.h>
#include <regex.h>
#include <string.h>

_Bool isCharacter(char x);

_Bool isWhiteSpace(char y);

_Bool tokenizer(struct lexics *aLex, int *numLex, FILE *inf);

#endif
