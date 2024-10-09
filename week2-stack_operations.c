#include <stdio.h>
#include <string.h>
int stack[10];
int top=-1;
void push (int item)
{
    if(top==10-1)
    {
        printf("stack overflow");
    }
    else{
        top++;
        stack[top]=item;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("stack underflow \n");
        return -1;
    }
    else{
        int item=stack[top];
        top--;
        return item;
    }
}
void  display()
{
    if (top==-1)
    {
        printf("stack is empty \n");
    }
    else{
            for(int i=top;i>=0;i--)
            printf("%d",stack[i]);
        }
    }


int main()
{
    int choice,item;
    while(1){
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. display\n");
        printf("4. exit\n");
        printf(" enter your choice\n");
        scanf("%d",&choice);

        switch (choice){
        case 1:
            printf("enter the element to push:");
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            item=pop();
            if (item ==-1){
                printf("popped=%d \n",item);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            printf("exiting");

            return 0;
        default: printf("invalid output");

    }
}
}
