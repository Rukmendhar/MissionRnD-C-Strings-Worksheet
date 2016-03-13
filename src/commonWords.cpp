/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {

	int i, j=0, k=0,words,flag=0,l,m=0;
	char s1[81][81];
	char s2[81][81];
	char res[81][81];
	
	for (i = 0; str1[i]; i++)
	{
		if (str1[i] != ' ' || str1[i] != '\0')
			s1[j][k++] = str1[i];
		else{
			s1[j][k] = '\0';
			j = j + 1;
			k = 0;
		}
	}
	words = i;
	j = 0;
	k = 0;
	for (i = 0; str2[i]; i++)
	{
		if (str2[i] != ' ' || str2[i] != '\0')
			s2[j][k++] = str2[i];
		else{
			s2[j][k] = '\0';
			j = j + 1;
			k = 0;
		}
	}
	j = 0;
	k = 0;

	for (i = 0; words > i; i++)
	{
		while (s1[i][j] != '\0')
		{
			if ((s1[i][j] == s2[k][j]) && (flag == 0))
				flag = 0;
	
			else
				flag = 1;
			j = j + 1;
		}
		if (flag == 0)
		{
			for (l = 0; l < j; l++)
			{
				res[m][l] = s1[i][l];
			}
			m = m + 1;
		}
	}

	return NULL;
}