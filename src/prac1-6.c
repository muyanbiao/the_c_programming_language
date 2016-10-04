#include <stdio.h>
/* 验证表达式 getchar() != EOF 的值是0还是1 */
int main(){
	int c = getchar();
	while ((c = getchar())){
		printf("(getchar() != EOF) =  %d\t", c != EOF);
		if (c != EOF){
			putchar(c);
			printf("\n");
		} else {
			printf("End of File\n");
			break;
		}
	}
}
