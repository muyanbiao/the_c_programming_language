#include <stdio.h>
/* htoi函数：把16进制组成的字符串转换为与之等价的整型值 */

#define MAXLINE 1000

int htoi(char s[]);
int custom_getline(char s[], int lim);

int main(){
	int len;
	char line[MAXLINE];
	while ((len = custom_getline(line, MAXLINE)) > 0){
		printf("Hex : %s", line);
		printf("Dec : %d\n", htoi(line));
	}
	
	return 0;
}

/* htoi函数：把16进制组成的字符串转换为与之等价的整型值 */
int htoi(char s[]){
	int i, n;
	i = 0;
	n = 0;
	while (s[i] != 'x' && s[i] != 'X')
		++i;
	
	++i;
	while ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F')){
		if (s[i] >= '0' && s[i] <= '9'){
			n = 10 * n + (s[i] - '0');
		}
		
		if (s[i] >= 'a' && s[i] <= 'f'){
			n = 10 * n + (s[i] + 10 - 'a');
		}

		if (s[i] >= 'A' && s[i] <= 'F'){
			n = 10 * n + (s[i] + 10 - 'A');
		}
		
		++i;
	}
	return n;
}

/* getline函数：将一行读入到s中，并返回其长度 */
int custom_getline(char s[], int lim){
	int c, i, j;
	
	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < lim - 2){
			s[j] = c;
			++j;
		}

	if (c == '\n'){
		s[j] = c;
		++j;
		++i;
	}

	s[j] = '\0';

	return i;
}
