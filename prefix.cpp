#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>     /* for isdigit(char ) */
#include<string.h>

char stack[20];
int top = -1,size=20;

//push function
void push(char item)
{
	if(top >= size-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}

//pop function  
char pop()
{
	char value ;

	if(top <0)
	{
		printf("stack under flow");
		getchar();

		exit(1);
	}
	else
	{
		value = stack[top];
		top = top-1;
		return(value);
	}
}
//operator function
int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-'|| symbol == '='|| symbol == '>' || symbol == '<'|| symbol == '|'|| symbol == '!'|| symbol == '&')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}
//priority function
int precedence(char opperator)
{
	switch(opperator)
{
	case '|': return 1;
	case '&': return 2;
	case '>': return 3;
	case '<': return 3;
	case '!': return 3;
	case '=': return 3;
	case '+': return 4;
	case '-': return 4;
	case '*': return 5;
	case '/': return 5;
	case '^': return 6;
	case '(': return 7;
	case ')': return 7;
}
return 0;
}

void InfixToPrefix(char infix[], char prefix[])
{
	int i, j, k, pos, len;
	char item, x, rev[size];
	
	pos=0;
	len=strlen(infix);
	
	for(k=len-1;k>=0;k--)
	{
		rev[pos]=infix[k];
		pos++;
	}
	rev[pos]='\0';
	strcpy(infix,rev);
	for(i=0; infix[i]!='\0'; i++)
	{
		if(infix[i] == ')')
		infix[i] = '(';
		else if(infix[i] == '(')
		infix[i] = ')';
	}	
	push('(');
	strcat(infix,")");
	i=0;
	j=0;
	item=infix[i];
	
	while(item != '\0')
	{
		if(item == '(')
		{	
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			prefix[j] = item;
			j++;
		}
		else if(is_operator(item) == 1)
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				prefix[j] = x;
				j++;
				x = pop();
			}
			push(x);

			push(item);
		}
		else if(item == ')')
		{
			x = pop();
			while(x != '(')
			{
				prefix[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
		printf("\nInvalid infix Expression.\n");
		break;
		}
		i++;
		item = infix[i];
	}
	if(top > 0)
	printf("\n Invalid infix Expression.");
	prefix[j] = '\0';
	
	// Reverse the prefix expression.
	pos=0;
	len=strlen(prefix);
	for(k=len-1;k>=0;k--)
		{
		rev[pos]=prefix[k];
		pos++;
		}
		rev[pos]='\0';
		strcpy(prefix,rev);
}
int main()
{
	char infix[size], prefix[size];      

	printf("Enter the Infix expression : ");
	gets(infix);

	InfixToPrefix(infix,prefix);             
	printf("Prefix Expression: ");
	puts(prefix);             

	return 0;
}

