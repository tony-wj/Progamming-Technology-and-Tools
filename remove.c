#include <stdio.h>
#include <string.h>

void removes(char s[],char c){
	int n=0;
	char s1[100];
	for (int i = 0; i < strlen(s); ++i)
	{
		if(s[i]==c){
			n++;
		}
	}
	if (n==0){
		printf("wrong");
	}else if(n==1){
		int j;
		for (int i = 0; i < strlen(s); ++i){
			if(s[i]!=c){
				s1[j]=s[i];
				j++;
			}
		}
		printf("%s\n", s1);
	}else{
		int j;
		int k=0;
		for (int i = 0; i < strlen(s); ++i){
			if (s[i]==c){
				k++;
			}
			if(s[i]!=c || (k!=1&&k!=n)){
				s1[j]=s[i];
				j++;
			}
		}
		printf("%s\n", s1);
	}
}
int main(){
	char s[100];
	char c;
	scanf("%s\n", s);
	scanf("%c", &c);
	removes(s,c);
}