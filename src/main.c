#include "optparser.h"

int		main(int argc, char** argv) {
	child_config_t	config = { 0 };
	optparser(&config, argc, argv);
	return 0;
}