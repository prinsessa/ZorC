#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "cui.h"
#include "util.h"

int promptYesNoQuestion(const char question[128], const char exp[64], const char succ[128], const char fail[128])
{
	char answer[16];
	printf("Q: %s (yes/no)\nA: ",question);
	scanf("%15s",answer);
	// cc: free the buffer
	while(getchar() != '\n');
	char *t = toLowerCase(answer, sizeof answer/sizeof *answer);
	if(strcmp(t,exp) == 0)
	{
		printf("%s\n",succ);
		return 1;
	}
	printf("%s\n",fail);
	return 0;
}
