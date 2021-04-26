#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#include "InfixToPostfix.h"



//HELPER FUNCTIONS
int isOperator(char a){
	int flag = 0;
	switch(a){
		case '(':flag=1;break;
		case '^':flag=1;break;
		case '*':flag=1;break;
		case '/':flag=1;break;
		case '+':flag=1;break;
		case '-':flag=1;break;
	}
	return flag;
}
int getPrecedence(char a){
	int precedence = -1;
	/*
	PRECEDENCE
	PEMDAS
	(	3
	^	2
	* / 1
	+ - 0
	*/
	switch(a){
		case '^':precedence=2;break;
		case '*':precedence=1;break;
		case '/':precedence=1;break;
		case '+':precedence=0;break;
		case '-':precedence=0;break;
	}
	
	return precedence;
}

//Infix to Postfix Code
void infixToPostfix(char infix[],char postfix[]){
	Stack s = newStack(100);
	int i;
	char item;
	char x;
	
	push(s,'(');
	strcat(infix,")");
	
	i=0;
	item = infix[i];
	
	while( item != '\0' ){
		if( item == '(' ) push(s,item);
		else if( isdigit(item) || isalpha(item) ){
			strncat(postfix,&item,1);
		}
		else if( isOperator(item) ){
				x = top(s); pop(s);
				while( isOperator(x) && getPrecedence(x) >= getPrecedence(item) ){
				strncat(postfix,&x,1);
				x = top(s); pop(s);
				}
				push(s,x);
				
				push(s,item);
			
		}
		else if( item == ')' ){
			x = top(s); pop(s);
			while( x != '(' ){
				strncat(postfix,&x,1);
				x = top(s); pop(s);
			}
		}
		i++;
		item = infix[i];
	}
	destroy(&s);
}

int postfixEvaluation(char postfix[]){
	int res = 0, i, x, y;
	char a, b, c;
	char item;
	Stack s = newStack(100);
	i=0;
	item = postfix[i];	
	while( item != '\0' ){		
		if( isdigit(item) ) push(s,item);
		else if ( isOperator(item) ){
			if( !isEmpty(s) ){
				b = top(s); pop(s);
				y = b - '0';
				a = top(s); pop(s);
				x = a - '0';
				switch(item){
				case '^':res=x^y;break;
				case '*':res=x*y;break;
				case '/':res=x/y;break;
				case '+':res=x+y;break;
				case '-':res=x-y;break;
				}
				c = res + '0';
				push(s,c);
			}			
		}
		i++;
		item = postfix[i];		
	}
	res = top(s) - '0'; pop(s);
	destroy(&s);
	return res;
}
