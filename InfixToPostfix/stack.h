#ifndef STACK_H
#define STACK

typedef char stackItem;

typedef struct stack{
	stackItem* items;
	int top;
	int count;
	int size;
}*Stack;

Stack newStack(int size);
void destroy(Stack *s);
void push(Stack s, stackItem item);
void pop(Stack s);
int isEmpty(Stack s);
void clear(Stack s);
stackItem top(Stack s);
void display(Stack s);


#endif
