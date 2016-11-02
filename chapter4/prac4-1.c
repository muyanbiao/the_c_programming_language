#include <stdio.h>
#define MAXLINE 1000	/* 最大输入行长度 */

int custom_getline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";	/* 待查找的模式 */

/* 找出所有与模式匹配的行 */
int main(){
	char line[MAXLINE];
	int found = 0;
	int position = 0;
	while (custom_getline(line, MAXLINE) > 0)
		if ((position = strrindex(line, pattern)) >= 0){
			printf("%s", line);
			printf("The last found postion is: %d\n", position);
			found++;
		}
	printf("found = %d\n", found);
	return found;
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

/* strrindex函数：返回t在s中最右边的位置，若未找到则返回-1 */
int strrindex(char s[], char t[]){
	int i, j, k;
	int max = -1;
	for (i = 0; s[i] != '\0'; i++){
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;

		if (k > 0 && t[k] == '\0')
			max = i;
	}

	return max;
}
