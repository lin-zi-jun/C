#include <stdio.h>

int main(){
	char buf[10]="12345678";

	int len = strlen(buf);

	for(int i=len;i>0;i--){
		printf("%d ",i);
		buf[i]=buf[i-1];
	}

	printf("\n");

	buf[0]=len;
	printf("%d  - %d\n",0,buf[0]);
	for(int i=1;i<=len;i++){
		
		printf("%d  - %c \n",i,buf[i]);
	}
}
