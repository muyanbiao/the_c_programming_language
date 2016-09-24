#include <stdio.h>
/* 以每行一个单词打印输入 */
#define IN 1	/* 在单词内 */
#define OUT 2	/* 在单词外 */
int main(){ 
	int c, state;
	state = OUT;
	while ((c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n'){
			if (state == IN){
				printf("\n");
			}
			state = OUT;
		} else {
			state = IN;
			putchar(c);
		}
	}
	return 0;
}
