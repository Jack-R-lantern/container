#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <unistd.h>

typedef struct	child_config_s {
	uid_t	uid;
	char*	mount_dir;
}				child_config_t;

#endif