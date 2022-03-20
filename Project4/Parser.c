#include "Parser.h"

//checks if term is valid, if it is, returns true, if not returns false
_Bool term(){
  if(x->token == NUMBER){
    x++;
    return TRUE;
  } else if(x->token == IDENTIFIER){
    x++;
    return TRUE;
  }
  return FALSE;
}
//checks if expression is valid, if it is, returns true, if not returns false
_Bool expression(){
  if(term()){
    if(x->token == BINOP){
      x++;
      return expression();
    } else {
      return TRUE;
    }
  } else if(x->token == LEFT_PARENTHESIS){
    x++;
    if(expression()){
      if(x->token == RIGHT_PARENTHESIS){
        x++;
        return TRUE;
      }
    }
  }
  return FALSE;
}
//checks if term is assignment, if it is, returns true, if not returns false
_Bool assignment(){
  if(x->token == IDENTIFIER){
    x++;
    if(x->token == EQUAL){
      x++;
      if(expression()){
        if(x->token == EOL){
          x++;
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}
//checks if term is return, if it is, returns true, if not returns false
_Bool returning(){
  if(x->token == RETURN_KEYWORD){
    x++;
    if(expression()){
      if(x->token == EOL){
        x++;
        return TRUE;
      }
    }
  }
  return FALSE;;
}
//checks if while-loop is valid, if it is, returns true, if not returns false
_Bool whileLoop(){
  if(x->token == WHILE_KEYWORD){
    x++;
    if(x->token == LEFT_PARENTHESIS){
      x++;
      if(expression()){
        if(x->token == RIGHT_PARENTHESIS){
          x++;
          if(statement()){
            return TRUE;
          }
        }
      }
    }
  }
  return FALSE;
}
//checks if statement is valid, if it is, returns true, if not returns false
_Bool statement(){
  if(whileLoop() || returning() || assignment() || body()){
    return TRUE;
  }
  return FALSE;
}
//checks if statement-list is valid, if it is, returns true, if not returns false
_Bool statementList(){
  if(statement()){
    if(x->token != RIGHT_BRACKET){
      return statementList();
    }
    return TRUE;
  }
  return FALSE;
}
//checks if body is valid, if it is, returns true, if not returns false
_Bool body(){
  if(x->token == LEFT_BRACKET){
    x++;
    if(x->token != RIGHT_BRACKET){
      if(statementList()){
        if(x->token == RIGHT_BRACKET){
          x++;
          return TRUE;
        }
      }
    } else if (x->token == RIGHT_BRACKET){
      x++;
      return TRUE;
    }
  }
  return FALSE;
}
//checks if arg-decl is valid, if it is, returns true, if not returns false
_Bool argDecl(){
  if(x->token == VARTYPE){
    x++;
    if(x->token == IDENTIFIER){
      x++;
      if(x->token == COMMA){
        x++;
        return argDecl();
      } else {
        return TRUE;
      }
    }
  }
  return FALSE;
}
//checks if header is valid, if it is, returns true, if not returns false
_Bool header(){
  if(x->token == VARTYPE){
    x++;
    if(x->token == IDENTIFIER){
      x++;
      if(x->token == LEFT_PARENTHESIS){
        x++;
        if(x->token != RIGHT_PARENTHESIS){
          if(argDecl()){
            if(x->token == RIGHT_PARENTHESIS){
              x++;
              return TRUE;
            }
          }
        } else if (x->token == RIGHT_PARENTHESIS){
          x++;
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}
//checks if function is valid, if it is, returns true, if not returns false
_Bool function(){
  if(header() && body()){
    if(strcmp(x->lexeme, "") == 0){
      return TRUE;
    }
  }
  return FALSE;
}
//assigns the struct to a pointer and calls function to see if input is valid
_Bool parser(struct lexics *someLexics, int numberOfLexics){
  x = someLexics;
  return function();
}
