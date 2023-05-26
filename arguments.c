#include "shell.h"

/**
 * mek_arrgz - create array of pointer arguments
 *
 * @inputt: User inputt to be converted into arguments
 *
 * Return: the argument list
 */

char **mek_arrgz(char *inputt)
{
	char **arrgz, *arg, *postn, *delimie;
	int i, wc;

	postn = NULL;
	delimie = "\n\t \r\a";
	i = 0;
	wc = wedcount(inputt);
	arrgz = space_alloc(sizeof(char *) * (wc + 1));
	arg = tokenaiz(inputt, delimie, &postn);
	while (arg != NULL)
	{
		arrgz[i] = arg;
		if (arrgz[i][0] == '#')
			break;
		arg = tokenaiz(NULL, delimie, &postn);
		i++;
	}
	arrgz[i] = NULL;
	return (arrgz);
}

/**
 * chek_argzz - Associate the original first argument to a likely new argument
 *
 *
 * @fst_arg: The initial first argument
 * @arg0: possible argument to have changed
 *
 * Return: 0 if the same, 1 if they are dissimilar
 */

int chek_argzz(char *fst_arg, char *arg0)
{
	int strsize;

	strsize = 0;
	while (fst_arg[strsize] != '\0')
		strsize++;
	if (_stricpr(fst_arg, arg0, strsize) == 0)
		return (0);
	return (1);
}

/**
 * wedcount - count words in a given string
 *
 * @stri: the inputted string
 *
 * Return: size of words found in @stri
 */

int wedcount(char *stri)
{
	int wc, position, i;

	i = wc = 0;
	position = OUT;
	while (stri[i] != '\0')
	{
		switch (stri[i])
		{
		case '\0':
		case ' ':
		case '\t':
		case '\n':
			if (position == IN)
			{
				position = OUT;
				wc++;
			}
			i++;
			break;
		default:
			position = IN;
			i++;
		}
	}
	return (wc);
}
