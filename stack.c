/*C implementation of stack*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stack{
	int value;
	struct stack *next;
};
typedef struct stack stack;
stack *pop(stack *node){
	if(node==NULL){
		printf("empty stack\n");
	}else{
		stack *s=node;
		if(s->next!=NULL){
			printf("%d\n",node->value);
			node=node->next;
			free(s);
		}else{
			printf("%d\n",node->value);
			node=NULL;
			free(s);
		}
	}
	return node;
}
stack *push(stack *node, int x){
	stack *s = (stack*)malloc(sizeof(stack));
	s->value =x;
	s->next =node;
	node=s;
	return node;
}
int main(){
	char str[20];
	int x;
	stack *node =NULL;
	while(scanf("%s",str)!=EOF){
		if(strcmp(str,"push")==0){
			scanf("%d\n",&x);
			node = push(node,x);
		}else if(strcmp(str,"pop")==0){
			node = pop(node);
		}else{
			return 0;
		}
	}

}