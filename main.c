#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char **parse_args(char *line)
{
	int len = 1;
	
	int i;
	for (i = 0; i < strlen(line); i++)
	{
		if (line[i] == ' ')
		{
			len++;
		}
	}
	
	char **args = malloc(len * sizeof(char *));
	for (i = 0; i < len; i++)
	{
		char *curr = strsep(&line, " ");
		char *arg = malloc(sizeof(char) * strlen(curr));
		strcpy(arg, curr);
		
		args[i] = arg;
		//printf("%s == %s\n", arg, args[i]);
	}
	
	return args;
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		char **args = parse_args(argv[1]);
		execvp(args[0], args);
	}
	
	return 0;
}
