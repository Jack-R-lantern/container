#include <stdio.h>
#include <stdlib.h>
#include "exit.h"

void exit_usage(char** argv) {
	fprintf(stderr, "Usage: %s -u 1 -m ./ -c /bin/sh ~\n", argv[0]);
	exit(1);
}