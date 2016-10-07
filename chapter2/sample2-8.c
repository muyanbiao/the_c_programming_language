#include <stdio.h>
#define MAXLINE 1000

void squeeze(char s[], int c);		/* squeeze函数：从字符串s中删除字符c */
void custom_strcat(char s[], char t[]);	/* strcat函数：将字符串t连接到字符串s的尾部。s必须有足够大的空间 */

int custom_getline(char s[], int lim);

int main(){
	int c = 'a';
	int len_line = 0;
	int len_end = 0;
	char line[MAXLINE/2];
	char end[MAXLINE/2];

	len_end = custom_getline(end, MAXLINE/2);	/* 读取尾部字符串 */

	while((len_line = custom_getline(line, MAXLINE/2)) > 0){
		squeeze(line, c);			/* 删除读取的每行字符串中的字符 'a' */
		printf("After squeeze: %s", line);
		custom_strcat(line, end);
		printf("After strcat: %s", line);
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

/* strcat函数：将字符串t连接到字符串s的尾部。s必须有足够大的空间 */
void custom_strcat(char s[], char t[]){
	int i, j;

	i = j = 0;

	while (s[i] != '\n')			/* 判断是否伪字符串s的尾部 */
		i++;

	while ((s[i++] = t[j++]) != '\0')	/* 拷贝t */
		;
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

