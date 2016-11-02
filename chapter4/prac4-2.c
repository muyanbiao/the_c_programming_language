#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int custom_getline(char line[], int max);

/* atof函数：把字符串s转换成相应的双精度浮点数，可以处理形如123.45e-6 */
double atof(char s[]);

int main(){
	double sum;
	char line[MAXLINE];

	sum = 0;
	while (custom_getline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));

	return 0;
}

double atof(char s[]){

	double val, power;
	int i, sign, j, psign;

	for (i = 0; isspace(s[i]); i++)		/* 跳过空白符 */
		;
	sign  = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	
	if (s[i] == 'e')
		i++;

	if(s[i] == '-'){
		i++;
		for (j = 0; j < (s[i] - '0'); j++)
			power *= 10.0;
	} else if(s[i] == '+'){
		i++;
		for (j = 0; j < (s[i] - '0'); j++)
			power /= 10.0;
	}
	return sign * val / power;
}

/* getline()函数：将行保存到s中，并返回该行的长度 */
int custom_getline(char s[], int lim){
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;

	if (c == '\n')
		s[i++] = c;
	
	s[i] = '\0';
	return i;
}
