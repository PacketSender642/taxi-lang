#include <codegen.h>
#include <parser.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  bool assembly = false;
  bool runafter = false;
  bool c = false;
  size_t optind;
  for (optind = 1; optind < argc && argv[optind][0] == '-'; optind++) {
    switch (argv[optind][1]) {
    case 'r':
      runafter = true;
      break;
    case 'a':
      assembly = true;
      break;
    case 'c':
      c = true;
      break;
    default:
      fprintf(stderr, "Usage: %s [/rac] [file]\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }
  argv += optind;

  if (c) {
    parse_file(argv[0]);
  } else if (assembly) {
    printf("Not done\n");
  }

  return 0;
}
