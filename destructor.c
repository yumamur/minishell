#include <stdlib.h>
#include "env_util.h"
#include "msh_prompt.h"

void __attribute__((destructor(101)))	destructor(void)
{
	env_deinit();
	free(*prompt());
}
