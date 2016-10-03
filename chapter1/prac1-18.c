#include <stdio.h>
/* 删除每个输入行末尾的空格及制表符，并删除完全时空格的行 */
#define MAXLINELEN 1000 		/* 可以输入的最长行长度 */

int custom_getline(char line[], int maxlinelen);

int main(){
	int len;			/* 当前行的长度 */
	char line[MAXLINELEN];		/* 当前的输入行 */

	while ((len = custom_getline(line, MAXLINELEN)) > 0){
		int i = len - 3;
		//for (i = len - 1; i >= 0 && line[i] == ' '; --i);
		while (i > 0 && line[i] == ' ' || line[i] == '\t'){
			--i;
		}
		if (i != 0){
			len = i + 2;
			line[i+1] = '\n';
			line[i+2] = '\0';
			printf("%d, %s", len, line);
		}
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
