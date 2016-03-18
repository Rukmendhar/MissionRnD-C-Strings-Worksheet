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

	if (str1 == NULL || str2 == NULL)
		return NULL;


	int i = 0, j = 0, k = 0, l = 0, arr[SIZE / 2], len = 0, resI = 0, Index = 0;

	char **str3 = NULL;

	str3 = (char **)calloc(SIZE / 2, sizeof(char *));


	if (str1[i] != ' ' &&i == 0)
	{
		arr[k] = i;
		k++;
	}


	for (i = 0; str1[i]; i++)
	{


		if (str1[i] != ' ' && str1[i - 1] == ' ')
		{
			arr[k] = i; k++;
		}

	}

	// Comparing str1 ,str2
	while (str2[j])
	{
		int count = 0;

		for (i = 0; i < k; i++){

			if (str1[arr[i]] == str2[j]){
				Index = arr[i];

				while (str1[Index] != ' ' && str2[j] != ' ')
				{


					if (str1[Index++] != str2[j++]){
						Index = -1; break;
					}
				}printf("  ");

				if (Index != -1)     // if any word matches then it will be stored in the "str3" 
				{
					int len = Index - arr[i];

					str3[resI] = (char *)calloc(len + 1, sizeof(char));


					Index = arr[i];

					while (len--){// to store result in str3
						str3[resI][l++] = str1[Index++];
					}


					str3[resI][l] = '\0';
					resI++;
					l = 0;

					break;

				}

			}
		}

		j += ++len;
		len = 0;



	}

	if (resI == 0)
	{
		free(str3);
		return NULL;
	}


	return str3;

}