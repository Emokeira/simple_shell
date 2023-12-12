#include "main.h"

/**
 * updatePWD - updates the 'PWD' environment variable
 * with the current workinf directory
 */

void updatePWD(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("PWD", cwd, 1);
	}
}
