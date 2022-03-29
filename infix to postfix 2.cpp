#include<conio.h>
#include<string>
#include<iostream>

using namespace std;

char stack[20];
int top=-1, size=20;

void push(char value)
{
    if(top==size-1)
    {
        printf("stackfull");
    }
   
    else
    {
    	stack[top]=value;
        top++;
    }
}

char pop()
{
    char ch;
    if(top==-1)
    {
       return 0;
    }
    else
    {
        ch=stack[top];
        stack[top]='\0';
        top--;
        return(ch);
    }
}

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

string convert(string infix)
{
    int i=0;
    string postfix = "";   
    while(infix[i]!='\0')
    {       
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')          
        {
            postfix.insert(postfix.end(),infix[i]);
            i++;
        }       
        else if(infix[i]=='(')
        {
            push(infix[i]);
            i++;
        }        
        
        else if(infix[i]==')')
        {
            if(infix[i]==')')
            {
                while(stack[top]!='(')
                {              
					postfix.insert(postfix.end(),pop());
                }
                pop();
                i++;
            }
        }
        else            
        {
            if(top==-1)
            {
                push(infix[i]);
                i++;
            }
 
            else if(precedence(infix[i]) <= precedence(stack[top])) {
                postfix.insert(postfix.end(),pop());
               
                while(precedence(stack[top]) == precedence(infix[i])){
                    postfix.insert(postfix.end(),pop());
                    if(top < 0) {
                        break;
                    }
                }
                push(infix[i]);
                i++;
            }
            else if(precedence(infix[i]) > precedence(stack[top])) {
                push(infix[i]);
                i++;
            }
        }
    }
    while(top!=-1)
    {
        postfix.insert(postfix.end(),pop());
    }
	cout<<"The converted DFS is : "<<postfix; 
    return postfix;
}

int main()
{
	string infix,postfix;
   cout<<"Enter the expression : ";
    cin>>infix;
    postfix = convert(infix);
    return 0;
}

