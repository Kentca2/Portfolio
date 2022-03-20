#ifndef PARSER_H
#define PARSER_H

#include "Givens.h"

#include <stdio.h>
#include <stdbool.h>
#include <regex.h>
#include <string.h>

struct lexics * x;

_Bool term();

_Bool expression();

_Bool assignment();

_Bool returning();

_Bool whileLoop();

_Bool statement();

_Bool statementList();

_Bool body();

_Bool argDecl();

_Bool header();

_Bool function();

_Bool parser(struct lexics *someLexics, int numberOfLexics);

#endif
