#include <stdio.h>
/* 打印长度大于80格字符的所有输入行 */
#define MAXLINELEN 1000 		/* 可以输入的最长行长度 */

int custom_getline(char line[], int maxlinelen);

int main(){
	int len;			/* 当前行的长度 */
	char line[MAXLINELEN];		/* 当前的输入行 */

	while ((len = custom_getline(line, MAXLINELEN)) > 0){
		if (len > 80)
			printf("%d, %s", len, line);
	}
	
	return 0;
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
