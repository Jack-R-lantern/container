#include <stdio.h>
#include "exit.h"
#include "optparser.h"

extern

int		optparser(child_config_t *config, int argc, char** argv) {
	int option = 0;
	int	last_optind = 0;
	while ((option = getopt(argc, argv, "c:m:u:"))) {
		if (option == -1)
			break;
		switch (option) {
			case 'c':
				config->argc = argc - last_optind - 1;
				config->argv = &argv[argc - config->argc];
				break;
			case 'm':
				config->mount_dir = optarg;
				break;
			case 'u':
				if (sscanf(optarg, "%d", &config->uid) != 1) {
					fprintf(stderr, "badly-formatted uid: %s\n", optarg);
					exit_usage(argv);
				}
				break;
			default:
				exit_usage(argv);
		}
		last_optind = optind;
	}
	if (!config->argc || !config->mount_dir)
		exit_usage(argv);
}