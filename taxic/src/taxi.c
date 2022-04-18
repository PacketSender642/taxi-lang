#include "mpc/mpc.h"
#include <codegen.h>

int main(int argc, char **argv) {
  mpc_parser_t *Types = mpc_new("types");
  mpc_parser_t *Args = mpc_new("args");
  mpc_parser_t *Stmt = mpc_new("stmt");
  mpc_parser_t *Function = mpc_new("function");
  mpc_parser_t *TypeDef = mpc_new("typedef");
  mpc_parser_t *Variable = mpc_new("variable");
  mpc_parser_t *Taxi = mpc_new("taxi");

  mpc_err_t* err = mpca_lang(MPCA_LANG_DEFAULT,
            " types : (\"text\" | \"number\"); \n"
            " arg : [a-zA-Z]+ \"as\" <types>;\n"
            " stmt : (function | typedef | variable)*;                         \n"
            " function : \"function\" [a-zA-Z]+ \"with\" (<arg> | \"no args\") \"that does\" <stmt> \"done\" )*;    \n"
            " typedef : \"define type\" [a-zA-Z]+ \"as\" [a-zA-Z]+;\n"
            " variable : \"define variable\" [a-zA-Z]+ \"as\" [a-zA-Z]+;\n"
            " taxi : /^/ <stmt> /$/;",
            Stmt, Variable, Types, Function, Args, TypeDef, Taxi, NULL);

  if (err != NULL) {
    mpc_err_print(err);
    mpc_err_delete(err);
    exit(1);
  }

  if (argc > 1) {

    mpc_result_t r;
    if (mpc_parse_contents(argv[1], Taxi, &r)) {
      mpc_ast_print(r.output);
      mpc_ast_delete(r.output);
    } else {
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }

  } else {

    mpc_result_t r;
    if (mpc_parse_pipe("stdin", stdin, Taxi, &r)) {
      mpc_ast_print(r.output);
      mpc_ast_delete(r.output);
    } else {
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }
  }

  mpc_cleanup(7, Stmt, Variable, Args, Types, Function, TypeDef, Taxi);

  return 0;
}
