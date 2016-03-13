/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void reverse(char *input,int first,int last);
void str_words_in_rev(char *input, int len){

	int first = 0;
	int index;

	for (index = 0; index < len; index++)//reversing the words eg:like coding=ekil gnidoc 
	{
		if (input[index] == ' ')
		{
		
			reverse(input,first,index-1);
			first = index + 1;
		}
	}
	reverse(input, first, len - 1);//reversing last word

	reverse(input, 0, len - 1);//swapping letters
}
void reverse(char *input, int first, int last)
{
	char temp;

	while (first < last)
	{
		temp = input[first];
		input[first] = input[last];
		input[last] = temp;
		first++;
		last--;
	}
}
