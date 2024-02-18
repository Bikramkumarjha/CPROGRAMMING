#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *top = NULL;
void push(int x)
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
int pop()
{
    struct node *t;
    int x=-1;
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

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    //display();
    // while(top)
    // {
    //     pop();
        
    // };
    
    
    display();
    return 0;
}
