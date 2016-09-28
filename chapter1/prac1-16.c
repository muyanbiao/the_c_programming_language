#include <stdio.h>
/* 读入一组文本行，并把最长的文本行打印出来,不限制输入行的长度 */
#define MAXLINELEN 1000 		/* 可以输入的最长行长度 */

int custom_getline(char line[], int maxlinelen);
void custom_copy(char to[], char from[]);

int main(){
	int len;			/* 当前行的长度 */
	int max;			/* 最长行的长度 */
	char line[MAXLINELEN];		/* 当前的输入行 */
	char longest[MAXLINELEN];	/* 用于保存最长的行 */

	max = 0;
	while ((len = custom_getline(line, MAXLINELEN)) > 0){
		printf("%d, %s", len, line);
		if (len > max){
			max = len;
			custom_copy(longest, line);
		}
	}
	if (max > 0){
		for (int i = 0; i < max; ++i){
			printf("%s", longest);		
		}
		printf("\n");
	}
	
	return 0;
}

/* getline函数：将一行读入到s中，并返回其长度 */
int custom_getline(char s[], int lim){
	int c, i, j;

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

/* copy函数：将 from 复制到 to; 这里假定 to 足够大 */
void custom_copy(char to[], char from[]){
	int i;

	i = 0;
	while ((to[i] = from[i] != '\0'))
		++i;
}


