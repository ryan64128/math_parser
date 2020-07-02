#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[])
{
	char keywords[4][12] = {"if", "else", "function", "var"};
	int i;
	int flag = 0;

	for (i = 0; i<4; i++)
	{
		if (strcmp(keywords[i], buffer) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

int isAlphaNumeric(char ch)
{
	char table[62] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
					  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
					  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int i;
	int flag = 0;

	for (i=0; i<62; i++)
	{
		if (table[i] == ch)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

int main()
{
	char ch;
	char buffer[15];
	char operators[] = "+-*/%=";
	char delimiters[] = "{}[]()";
	FILE *fp;
	int i;
	int j=0;

	fp = fopen("lexer.c", "r");

	if(fp == NULL)
	{
		printf("Error opening file");
		exit(0);
	}

	while((ch = fgetc(fp)) != EOF)
	{
		for (i=0; i<6; i++)
		{
			if (ch == operators[i])
			{
				printf("%c is an operator\n", ch);
			}
		}

		for (i=0; i<6; i++)
		{
			if (ch == delimiters[i])
			{
				printf("%c is a delimiter\n", ch);
			}
		}

		if (isAlphaNumeric(ch))
		{
			buffer[j++] = ch;
		}
		else if ((ch == ' ' || ch == '\n') && (j != 0))
		{
			buffer[j] = '\0';
			j = 0;

			if (isKeyword(buffer) == 1)
			{
				printf("%s is a keyword\n", buffer);
			}
			else
			{
				printf("%s is an identifier\n", buffer);
			}
		}
	}
	fclose(fp);

	return 0;
}