#include <stdio.h>
/* squeeze函数：从字符串s中删除字符c */
#define MAXLINE 1000

void squeeze(char s[], int c);

int custom_getline(char s[], int lim);

int main(){
	int c = 'a';
	int len = 0;
	char line[MAXLINE];
	while((len = custom_getline(line, MAXLINE)) > 0){
		squeeze(line, c);
		printf("%s", line);
	}
	
	return 0;
}

/* squeeze函数：从字符串s中删除字符c */
void squeeze(char s[], int c){
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];

	s[j] = '\0';
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

