#include <iostream>
#include <cmath>
#include <stdlib.h>


struct Node
{
    int data; //data
    struct Node* Next; //next link
    struct Node* Prev; //prev link
};
//3 global variables
struct Node* start1 = NULL; 
struct Node* start2 = NULL; 
struct Node* start3 = NULL; 

int Digits(int num)
{
    int digits;
    while (num!=0)
    {
        num = num / 10;
        digits += 1;
    }
    return digits;
}
//1st time insert
void insert1(int number)
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=number;
    temp->Next=NULL;
    temp->Prev=NULL;

    if (start1 == NULL)
    {
        start1 = temp;
    }
    else
    {
        struct Node* curr = start1; 
        while(curr->Next!=NULL)
        {
            curr = curr->Next;
        }
        curr->Next=temp;
        temp->Prev=curr;
    }
}
//1st time print
void PrintList1()
{
    if(start1==NULL)
    {
        printf("list empty");
    }
    else
    {
        int a = 0;
        printf("\nyour list is... ");
        struct Node* curr = start1; 
        do
        {
            printf("%d", curr->data);
            printf(" ");
            curr = curr->Next;
            a = a + 1;
        }
        while(curr!=NULL);
    }
}
//2nd insert
void insert2(int number)
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=number;
    temp->Next=NULL;
    temp->Prev=NULL;

    if (start2 == NULL)
    {
        start2 = temp;
    }
    else
    {
        struct Node* curr = start2; 
        while(curr->Next!=NULL)
        {
            curr = curr->Next;
        }
        curr->Next=temp;
        temp->Prev=curr;
    }
}
//2 printing
void PrintList2()
{
    if(start2==NULL)
    {
        printf("list empty");
    }
    else
    {
        int a = 0;
        printf("\nyour list is... ");
        struct Node* curr = start2; //declare node type pointer variable curr with assigned value of start
        do
        {
            printf("%d", curr->data);
            printf(" ");
            curr = curr->Next;
            a = a + 1;
        }
        while(curr!=NULL);
    }
}
//3rd insert
void insert3(int number)
{
    struct Node* temp;// declare temp node type pointer variable
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=number;
    temp->Next=NULL;
    temp->Prev=NULL;

    if (start3 == NULL)
    {
        start3 = temp;
    }
    else
    {
        struct Node* curr = start3; //declare node type pointer variable curr with assigned value of start
        while(curr->Next!=NULL)
        {
            curr = curr->Next;
        }
        curr->Next=temp;
        temp->Prev=curr;
    }
}
//3rd print
void PrintList3()
{
    if(start3==NULL)
    {
        printf("list empty");
    }
    else
    {
        printf("\nyour added list is... ");
        struct Node* curr = start3; //declare node type pointer variable curr with assigned value of start
        if(start3==NULL)
        {
            printf("list empty");
        }
        else
        {
            while(curr->Next!=NULL)
            {
                curr = curr->Next;
                if(curr->Next==NULL)
                {
                    while(curr!=NULL)
                    {
                        printf("%d", curr->data);
                        printf(" ");
                        curr = curr->Prev;
                    }
                    break;
                }
            }
        }
    }
}

void AddList()
{
     printf("\n");
     
     struct Node* curr1 = start1; 
     struct Node* curr2 = start2;
     int num, carry=0;

    if(start1==NULL ||  start2==NULL)
    {
        printf("1st list is empty");
    }
    else
    {
        while(curr1->Next!=NULL && curr2->Next!=NULL)
        {
            curr1 = curr1->Next;
            curr2 = curr2->Next;

            if(curr1->Next==NULL && curr2->Next==NULL)
            {
                while(curr1!=NULL && curr2!=NULL)
                {
                    num = curr1->data + curr2->data + carry;
                    if (Digits(num)>1 && curr1->Prev!=NULL && curr2->Prev!=NULL)
                    {
                            int numcopy, mod;
                            numcopy = num;
                            carry = numcopy / 10;
                            mod = numcopy % 10;
                            printf("%d", mod);
                            printf(" ");
                            insert3(mod);
                    }
                    else
                    {
                            printf("%d", num);
                            printf(" ");
                            insert3(num);
                            carry=0;
                    }
                    curr1 = curr1->Prev;
                    curr2 = curr2->Prev;
                }
                break;
            }
        }
    }
}

int main()
{
    int num1;
    do
    {
        printf("1st number: ");
        scanf ("%d", &num1);
    }
    while (num1>99999);
    int digits1 = Digits(num1);
    printf ("number of digits are %d", digits1);

    // to separate digits
    int num1copy, mod1;
    int w = 1 , b =1 , i = 0;
    int arr1[digits1];
    num1copy = num1;
    while(w<digits1+1)
    {
        mod1 = num1copy / int(pow(10, digits1-w));
        w = w + 1;
        mod1 = mod1 % 10;
        printf ("\ndigit %d = %d", b,mod1);
        arr1[i] = mod1;
        i++;
        b++;
    }
    printf("\n\n");
    printf ("\narray ");
    for (int i = 0; i<digits1 ; i++)
    {
        printf("%d ", arr1[i]);
    }
    for (int i = 0; i<digits1 ; i++)
    {
        insert1(arr1[i]);
    }
    PrintList1();

    //for the second number
    printf("\n\n");
    int num2, digits2;
    do
    {
        printf("2nd number: ");
        scanf ("%d", &num2);
        digits2 = Digits(num2);
    }
    while (digits1!=digits2);

    printf ("number of digits are %d", digits2);

// to separate digits
    int num2copy, mod2;
    int v = 1 , a =1 , x = 0;
    int arr2[digits2];
    num2copy = num2;
    while(v<digits2+1)
    {
        mod2 = num2copy / int(pow(10, digits2-v));
        v = v + 1;
        mod2 = mod2 % 10;
        printf ("\ndigit %d = %d", a,mod2);
        arr2[x] = mod2;
        x++;
        a++;
    }
    printf("\n\n");
    printf ("\narray ");
    for (int i = 0; i<digits2 ; i++)
    {
        printf("%d ", arr2[i]);
    }
    for (int i = 0; i<digits2 ; i++)
    {
        insert2(arr2[i]);
    }
    PrintList2();
    AddList();
    PrintList3();
}
