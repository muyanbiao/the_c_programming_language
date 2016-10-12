#include <stdio.h>
#define MAXLINE 1000

int any(char s1[], char s2[]);		/* 将字符串s2中的任一字符在字符串s1中第一次出现的位置作为结果返回 */ 

int custom_getline(char s[], int lim);

int main(){
	int c = 'a';
	int len_line1 = 0;
	int len_line2 = 0;
	char line1[MAXLINE];
	char line2[MAXLINE];
	int start = -1;

	while((len_line1 = custom_getline(line1, MAXLINE)) > 0){
		len_line2 = custom_getline(line2, MAXLINE);
		if (len_line2 > 0){
			start = any(line1, line2);			/* 删除line1中任何与字符串line2中字符匹配的字符 */
			printf("The start position of char from s2 in s1 is: %d\n", start);
		}
	}

	return 0;
}

/* 将字符串s2中的任一字符在字符串s1中第一次出现的位置作为结果返回 */ 
int any(char s1[], char s2[]){
	int i, k;
	int start = MAXLINE;		/* s2中任一字符在s1中出现的第一次位置，默认为-1，即未找到字符 */

	for (k = 0; s2[k] != '\0'; k++){
		for (i =  0; s1[i] != '\0'; i++)
			if (s1[i] == s2[k])
				if (i < start)
					start = i;
	}

	if (start == MAXLINE)
		start = -1;

	return start;
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

