#include <stdio.h>
#include "exit.h"
#include "utility.h"

extern

int		optparser(child_config_t *config, int argc, char** argv) {
	int option = 0;
	while ((option = getopt(argc, argv, "c:m:u:"))) {
		switch (option) {
			case 'c':
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
	}
}