#include <stdio.h>
/* 编写函数reverse(s),将字符串s中的字符顺序颠倒过来。使用该函数编写一个程序，每次颠倒一个输入行中的字符顺序 */
#define MAXLINELEN 1000 		/* 可以输入的最长行长度 */

void custom_reverse(char s[], int len);
int custom_getline(char line[], int maxlinelen);

int main(){
	int len;			/* 当前行的长度 */
	char line[MAXLINELEN];		/* 当前的输入行 */

	while ((len = custom_getline(line, MAXLINELEN)) > 0){
		custom_reverse(line, len);
		printf("%s", line);
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

void custom_reverse(char s[], int len){
	int i;
	char temp;
	for (i = 0; i < len / 2; ++i){
		temp = s[i];
		s[i] = s[len - 2 - i];
		s[len - 2 - i] = temp;
	}	
}
