#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack newStack(int size){
	Stack s = (Stack)malloc(sizeof(struct stack));
	s->items = (stackItem*)malloc(sizeof(stackItem)*size);
	s->count = s->top = 0;
	s->size = size;
	return s;	
}

void destroy(Stack *s){
	clear(*s);
	free((*s)->items);
	free(*s);
	*s=NULL;
}

void push(Stack s,stackItem item){
	if( s->count != s->size ){
		s->top = s->count;
		s->items[s->count++] = item;		
	}
	else{		
		s->items = (stackItem**)realloc(s->items, ++s->size * sizeof(stackItem));
		s->top = s->count;
		s->items[s->count++] = item;
	}
}

void pop(Stack s){
	if( s->count != 0 ){
	s->top--;
	s->count--;
	}
	else printf("\nCannot POP from EMPTY STACK!");
}

int isEmpty(Stack s){
	return s->count == 0;
}

void clear(Stack s){
	s->count = 0;
}

stackItem top(Stack s){
	return s->items[s->top];
}

void display(Stack s){
	printf("\nElements in Stack : ");
	int i;
	for( i = s->top ; i >= 0 ; i-- ){
		printf("%c ",s->items[i]);
	}
}
