#include <stdio.h>
#include <ctype.h>

int stack[20];
int top = -1,size=20; 

void push(int item)
{

    if (top >= size - 1) {
        printf("stack over flow");
        return;
    }
    else {
        top = top + 1;
        stack[top] = item;
    }
}


int pop()
{
    int item;
    if (top < 0) {
        return 0;
    }
    else {
        item = stack[top];
        top = top - 1;
        return item;
    }
}


int EvalPostfix(char postfix[])
{

    int i;
    char ch;
    int val;
    int A, B;

    for (i = 0; postfix[i] != ')'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {

            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<') 
		{

            A = pop();
            B = pop();

            switch (ch) 
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
                
            case '>':
                val = B > A;
                break;
                
            case '<':
                val = B < A;
                break;
            }

            push(val);
        }
    }
    printf(" \n Result of expression evaluation : %d \n", pop());
}

int main()
{

    int i;

    char postfix[size];

    printf("Enter your postfix expression in ( ): ");


    for (i = 0; i <= size - 1; i++) {
        scanf("%c", &postfix[i]);

        if (postfix[i] == ')') 
        {
            break;
        }
    }

    EvalPostfix(postfix);

    return 0;
}
