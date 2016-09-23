#include <stdio.h>
/* 将输入复制到输出，并将其中连续的多个空格用一个空格代替 */
int main(){
	int c;
	while ((c = getchar()) != EOF){
		if (c == '\t'){
			printf("\\t");
		} else if (c == '\b'){
			printf("\\b");
		} else if (c == '\\'){
			printf("\\\\");
		} else {
			putchar(c);
		}
	}
	return 0;
}
