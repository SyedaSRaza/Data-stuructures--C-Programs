#include <iostream>
#include <conio.h>
 
using namespace std;
 
struct node
{
        char data;
        node *left;
        node *right;
};
 
char postfix[35];
int top = -1;
node *arr[35];
 
int returnfunc(char inputchar)
{
	 
    if (inputchar == '+' || inputchar == '-' || inputchar == '*' || inputchar== '/' || inputchar=='<'|| inputchar=='|' || inputchar=='&' || inputchar=='=' || inputchar=='!' || inputchar=='>' || inputchar=='^')
        return (-1);
    else if (inputchar >= 'a' || inputchar <= 'z')
        return (1);
    else if (inputchar >= 'A' || inputchar <= 'Z')
        return (1);
    else
        return (-99); //for error
}
 
void push(node *tree)
{
    top++;
    arr[top] = tree;
}
 
node *pop()
{
    top--;
    return (arr[top + 1]);
}
 
void expression(char *suffix)
{
    char symbol;
    node *newl, *ptr1, *ptr2;
    int flag; //flag=-1 when operator and flag=1 when operand
    
    symbol = suffix[0]; 
    for (int i = 1; symbol != NULL; i++)
    { 
        flag = returnfunc(symbol); 
        if (flag == 1)
        {
            newl = new node;
            newl->data = symbol;
            newl->left = NULL;
            newl->right = NULL;
            push(newl);
        }
        else
        { //If the symbol is operator//pop two top elements.
            ptr1 = pop();
            ptr2 = pop();
            newl = new node;
            newl->data = symbol;
            newl->left = ptr2;
            newl->right = ptr1;
            push(newl);
        }
        symbol = suffix[i];
    }
}
 
void prefixOrder(node *tree)
{
    if (tree != NULL)
    {
        cout << tree->data;
        prefixOrder(tree->left);
        prefixOrder(tree->right);
    }
}
 
void infixOrder(node *tree)
{
    if (tree != NULL)
    {
        infixOrder(tree->left);
        cout << tree->data;
        infixOrder(tree->right);
    }
}
 
void postfixOrder(node *tree)
{
    if (tree != NULL)
    {
        postfixOrder(tree->left);
        postfixOrder(tree->right);
        cout << tree->data;
    }
}
 
int main(int argc, char **argv)
{
    cout << "Enter Postfix Expression : ";
    cin >> postfix;
 
   expression(postfix);
 
    cout << "\nInfix expression :   ";
    infixOrder(arr[0]);
 
    cout << "\nPrefix expression :  ";
    prefixOrder(arr[0]);
 
    cout << "\nPostfix expression : ";
    postfixOrder(arr[0]);
    return 0;
}

