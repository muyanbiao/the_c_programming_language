#include <stdio.h>
#define MAXLINE 1000

void squeeze(char s1[], char s2[]);		/* squeeze函数：将字符串s1中的任何与字符串s2中字符匹配的字符都删除 */

int custom_getline(char s[], int lim);

int main(){
	int c = 'a';
	int len_line1 = 0;
	int len_line2 = 0;
	char line1[MAXLINE];
	char line2[MAXLINE];

	while((len_line1 = custom_getline(line1, MAXLINE)) > 0){
		len_line2 = custom_getline(line2, MAXLINE);
		if (len_line2 > 0){
			squeeze(line1, line2);			/* 删除读取的每行字符串中的字符 'a' */
			printf("After squeeze: %s", line1);
		}
	}

	return 0;
}

/* squeeze函数：从字符串s中删除字符c */
void squeeze(char s1[], char s2[]){
	int i, j;

	for (i = j = 0; s1[i] != '\0'; i++)
		if (s1[i] != s2[j])
			s1[j++] = s1[i];

	s1[j] = '\0';
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

