/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
int power(int n1, int n2);
void no_to_str(float number, char *str, int afterdecimal);
void reverse(char*str, int len)
{
	int i = 0,j=len-1;
	int temp;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;

	}
}
int intToStr(int x, char* str)
{
	int i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	reverse(str, i);
	return i;
}

void floatToStr(int x, char* str, int afterdecimal)
{
	int i = 0;
	while (afterdecimal)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
		afterdecimal--;

	}
	reverse(str, i);
}

void number_to_str(float number, char *str,int afterdecimal){
	
	float posnumber;
	if (number < 0)
	{
		str[0] = '-';
		posnumber = number*(-1);
	}
	if (number < 0)
		no_to_str(posnumber, str + 1, afterdecimal);
	else
		no_to_str(number, str, afterdecimal);
		
}
void no_to_str(float number, char *str, int afterdecimal)
{
	int nInt = (int)number;
	float nFloat = (number - (float)nInt);
	int i = intToStr(nInt, str);


	if (afterdecimal != 0 && nFloat != 0)
	{
		str[i++] = '.';
		nFloat = nFloat*(power(10, afterdecimal));
		floatToStr((int)nFloat, str + i, afterdecimal);
	}


}

int power(int n1, int n2)
{
	int value=1;
	while (n2)
	{
		value = value*n1;
		n2--;
	}
	return value;
}
