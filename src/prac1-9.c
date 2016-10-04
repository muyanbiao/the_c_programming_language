#include <stdio.h>
/* 将输入复制到输出，并将其中连续的多个空格用一个空格代替 */
int main(){
	int c, prev;
	while ((c = getchar()) != EOF){
		if (prev == ' ' && c == ' '){
			continue;
		}
		prev = c;
		putchar(prev);
	}
	printf("\n");
	return 0;
}
