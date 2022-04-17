#include "mpc/mpc.h"
#include <codegen.h>

int main(int argc, char **argv) {
  mpc_parser_t *Taxi = mpc_new("taxi");
  mpc_parser_t *Stmt = mpc_new("stmt");
  mpc_parser_t *Variable = mpc_new("variable");
  mpc_parser_t *Function = mpc_new("function");
  mpc_parser_t *TypeDef = mpc_new("typedef");

  mpca_lang(MPCA_LANG_PREDICTIVE,
            " ident : [a-zA-Z]+ ; "
            " args : <ident> (',')? ; "
            " function : <value>   (('*' | '/')   <value>)*;    "
            " value : /[0-9]+/ | '(' <expression> ')';         "
            " taxi : /^/ <expression> /$/;                    ",
            Stmt, Variable, Function, TypeDef, Taxi, NULL);

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
    printf("Starting Taxi repl.\n");
    if (mpc_parse_pipe("<stdin>", stdin, Taxi, &r)) {
      mpc_ast_print(r.output);
      mpc_ast_delete(r.output);
    } else {
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }
  }

  mpc_cleanup(5, Stmt, Variable, Function, Taxi, TypeDef);

  return 0;
}
