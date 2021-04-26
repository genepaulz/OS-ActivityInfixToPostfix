#include <stdio.h>
#include <stdlib.h>
#include "InfixToPostfix.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	printf("\ninfix to postfix conversion");
	char infix[] = "a+b*c-d";
	char postfix[] = "";
	printf("\n	Infix string : %s",infix);
	infixToPostfix(infix,postfix);
	printf("\n	Postfix string : %s",postfix);


	printf("\n\ninfix to postfix evaluation");
	char postfix2[] = "123*+4-";
	printf("\n	Postfix string : %s",postfix2);
	int res = postfixEvaluation(postfix2);
	printf("\n	Result : %d",res);
	return 0;
}
