#include "main.h"
/**
 * parse_line - split the line input
 * @line: string to be split
 *
 * Return: the tokens
 */

char **parse_line(char *line)
{
	int bsize = 64;
	int c = 0;
	char **toks;
	char *tok;
	char *dlim = " \t\r\n\a";

	toks = malloc(sizeof(char *) * bsize);
	if (!toks)
	{
		fprintf(stderr, "allocation error in split line\n");
		exit(EXIT_FAILURE);
	}

	tok = strtok(line, dlim);
	while (tok != NULL)
	{
		if (tok[0] == '#')
		{
			break;
		}
		toks[c] = tok;
		c++;
		if (c >= bsize)
		{
			bsize += bsize;
			toks = realloc(toks, sizeof(char *) * bsize);
				if (!toks)
				{
					fprintf(stderr, "realloction error\n");
					exit(EXIT_FAILURE);
				}
		}

		tok = strtok(NULL, dlim);
	}
	toks[c] = NULL;
	return (toks);
}
/**
 * read_line - read a line from stdin
 *
 * Return: pointer points to str
 */

char *read_line(void)
{
	size_t bsize = 0;
	char *line = NULL;

	if (getline(&line, &bsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("erorr while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);

}
