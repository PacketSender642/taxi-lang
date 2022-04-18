#include "parser.h"

int parse_file(char *file) {
  mpc_parser_t *Types = mpc_new("types");
  mpc_parser_t *Call = mpc_new("call");
  mpc_parser_t *ident = mpc_new("ident");
  mpc_parser_t *Args = mpc_new("arg");
  mpc_parser_t *Stmt = mpc_new("stmt");
  mpc_parser_t *Function = mpc_new("function");
  mpc_parser_t *TypeDef = mpc_new("typedef");
  mpc_parser_t *Variable = mpc_new("variable");
  mpc_parser_t *Taxi = mpc_new("taxi");

  mpc_err_t *err = mpca_lang(
      MPCA_LANG_PREDICTIVE,
      " ident     : /[a-zA-Z_][a-zA-Z0-9_]*/ ;\n"
      " types : (\"text\" | \"number\" | \"none\"); \n"
      " arg : (<ident> \"as\" <types>)* ;\n"
      " stmt : <function> | <typedef> | <variable> | <call>;                   "
      "      \n"
      " call : \"call\" <ident> \"with\" (/\"(\\\\.|[^\"])*\"/ | /[0-9]+/)*;   "
      "                      \n"
      " function : \"function\" <ident> (\"with\" <arg>)? \"->\" "
      "((<stmt>)*)? \"end\";    \n"
      " typedef : \"type\" <ident> \"as\" <ident> ;\n"
      " variable : \"variable\" <ident>  \"is\" <types> \"with\" "
      "(/\"(\\\\.|[^\"])*\"/ | /[0-9]+/);\n"
      " taxi : /^/ <stmt>* /$/;",
      Stmt, Variable, Types, ident, Function, Call, Args, TypeDef, Taxi, NULL);

  if (err != NULL) {
    mpc_err_print(err);
    mpc_err_delete(err);
    exit(1);
  }
  mpc_result_t r;
  if (mpc_parse_contents(file, Taxi, &r)) {
    mpc_ast_print(r.output);
    mpc_ast_delete(r.output);
  } else {
    mpc_err_print(r.error);
    mpc_err_delete(r.error);
  }

  mpc_cleanup(9, Stmt, Call, Variable, Types, ident, Function, Args, TypeDef,
              Taxi);

  return 0;
}