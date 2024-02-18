#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node *next;
} *top = NULL;
void push(char x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
char pop()
{
    struct node *t;
    char x=-1;
    if(top==NULL)
    printf("stack is empty\n");
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void display()
{
    struct node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int pre(char x)
{
    if(x=='+'||x=='-')
    return 1;
    else if(x=='*' || x=='/')
    return 2;
    return 0;

}
int isoperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
    return 0;
    else 
    return 1;
}
char *intopost(char *infix)
{
    int i=0,j=0;
    char *postfix;
    long int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));
    while(infix[i]!='\0')
    {
        if(isoperand(infix[i]))
        postfix[j++]=infix[i++];
        else{
            if(pre(infix[i])>pre(top->data))
            push(infix[i++]);
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL)
    postfix[j++]=pop();
    postfix[j]='\0';
    
}


int main()
{
  char *infix="a+b*c";
  push('#');
  char *postfix=intopost(infix);
  printf("%s",postfix);
    return 0;
}
