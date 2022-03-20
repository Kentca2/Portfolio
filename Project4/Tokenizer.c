#include "Tokenizer.h"

//Checks if a character is one of the character delimiters
_Bool isCharacter(char x){
  if(x == '(' || x == ')' || x == '{' || x == '}' || x == '=' || x == ',' || x == ';' || x == '+' || x == '*' || x == '!' || x == '%') {
    return TRUE;
  } else {
    return FALSE;
  }
}
//Checks if a character is one of the white space delimiters
_Bool isWhiteSpace(char y){
  if(y == ' ' || y == '\t' || y =='\n'){
    return TRUE;
  } else {
    return FALSE;
  }
}

_Bool tokenizer(struct lexics *aLex, int *numLex, FILE *inf){

  struct lexics newLexic;
  char c;
  int k = 0;
  int p = 0;
  char arrayFile[MY_CHAR_MAX];
  char l[LEXEME_MAX];

  //Reads in the values from the file and populates an array with the characters
  c = fgetc(inf);
  while (c!= EOF){
    arrayFile[k] = c;
    k++;
    c = fgetc(inf);
  }
  //For loop to iterate through the array
  for(int m = 0; m < k; m++){

    //checks if a character is not a delimiter
    if(!isWhiteSpace(arrayFile[m]) && !isCharacter(arrayFile[m])){
      //loops through array untill a delimiter is reached
      while((!isWhiteSpace(arrayFile[m]) && !isCharacter(arrayFile[m])) && m < k){
        l[p] = arrayFile[m];
        m++;
        p++;
      }
      m--;
      //assigns the lexeme to the struct along with the corresponding token
      if(strcmp(l, "while") == 0){
        strcpy(newLexic.lexeme, l);
        newLexic.token = WHILE_KEYWORD;
      } else if(strcmp(l, "return") == 0){
        strcpy(newLexic.lexeme, l);
        newLexic.token = RETURN_KEYWORD;
      } else if(strcmp(l, "int") == 0 || strcmp(l, "void") == 0){
        strcpy(newLexic.lexeme, l);
        newLexic.token = VARTYPE;
      } else if(validNumber(l)){
        strcpy(newLexic.lexeme, l);
        newLexic.token = NUMBER;
      } else if(validIdentifier(l)){
        strcpy(newLexic.lexeme, l);
        newLexic.token = IDENTIFIER;
      }
      //assigns the struct to the given struct
      *aLex = newLexic;
      aLex++;
      (*numLex)++;
      //clears the data
      memset(newLexic.lexeme,0,strlen(newLexic.lexeme));
      memset(l, 0, strlen(l));
      p = 0;
    }

    if(isCharacter(arrayFile[m])){
      //assigns the lexeme to the struct along with the corresponding token
      if(arrayFile[m] == '=' && m < k){
        if(arrayFile[m + 1] == '='){
          strcpy(newLexic.lexeme, "==");
          newLexic.token = BINOP;
          m++;
        } else {
          strcpy(newLexic.lexeme, "=");
          newLexic.token = EQUAL;
        }
      } else if(arrayFile[m] == '!' && m < k){
        if(arrayFile[m + 1] == '='){
          strcpy(newLexic.lexeme, "!=");
          newLexic.token = BINOP;
          m++;
        }
      } else if(arrayFile[m] == '+'){
        strcpy(newLexic.lexeme, "+");
        newLexic.token = BINOP;
      } else if(arrayFile[m] == '*'){
        strcpy(newLexic.lexeme, "*");
        newLexic.token = BINOP;
      } else if(arrayFile[m] == '%'){
        strcpy(newLexic.lexeme, "%");
        newLexic.token = BINOP;
      } else if(arrayFile[m] == '('){
        strcpy(newLexic.lexeme, "(");
        newLexic.token = LEFT_PARENTHESIS;
      } else if (arrayFile[m] == ')'){
        strcpy(newLexic.lexeme, ")");
        newLexic.token = RIGHT_PARENTHESIS;
      } else if (arrayFile[m] == '{'){
        strcpy(newLexic.lexeme, "{");
        newLexic.token = LEFT_BRACKET;
      } else if (arrayFile[m] == '}'){
        strcpy(newLexic.lexeme, "}");
        newLexic.token = RIGHT_BRACKET;
      } else if (arrayFile[m] == ','){
        strcpy(newLexic.lexeme, ",");
        newLexic.token = COMMA;
      } else if (arrayFile[m] == ';'){
        strcpy(newLexic.lexeme, ";");
        newLexic.token = EOL;
      }
      //assigns the struct to the given struct
      *aLex = newLexic;
      aLex++;
      (*numLex)++;
      //clears the data
      memset(newLexic.lexeme,0,strlen(newLexic.lexeme));
    }
  }
  fclose(inf);
  return TRUE;
}
