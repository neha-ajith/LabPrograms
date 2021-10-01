#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[100];
int top=-1;

void push(char item){
    top++;
    stack[top] = item;    
}

void pushint(int item){
    top++;
    stack[top] = item;    
}

int isOperator(char symbol){
    if(symbol == '^' || symbol == '/'  || symbol == '*'  || symbol == '+'  || symbol == '-')
        return 1;
    else 
        return 0;
}

int isOperand(char item){
    if(item>='A' && item<='Z' || item>='a' && item<='z')
        return 1;
    else
        return 0;
}

char pop(){
    char item;
    item = stack[top];
    top--;
    return item;
}

int popint(){
    int item;
    item = stack[top];
    top--;
    return item;
}

int precedence(char symbol){
    if(symbol == '^')
        return 3;
    else if(symbol == '/' || symbol == '*')
        return 2;
    else if(symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

void main(){
    int r,ch,i=0,j=0,n,op1,op2,res;
    char infix[100],postfix[100],item,temp;
    do{
        printf("1. Infix To Postfix Coversion\n2. Postfix Evaluation\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                printf("Enter the infix expression: ");
                scanf("%s",infix);
                while(infix[i]!='\0'){
                    item = infix[i];
                    if(item == '('){
                        push(item);
                    }
                    else if(item>='A' && item<='Z' || item>='a' && item<='z'){
                        postfix[j] = item;
                        j++;
                    }
                    else if(isOperator(item) == 1){
                        temp=pop();
                        while(isOperator(temp)==1 && precedence(temp)>precedence(item)){
                            postfix[j] = temp;
                            j++;
                            temp = pop();
                        }
                        push(temp);
                        push(item);
                    }
                    else if(item == ')'){
                        temp = pop();
                        while(temp!='('){
                            postfix[j] = temp;
                            j++;
                            temp = pop();
                        }
                    }
                    else{
                        printf("Invalid expression.");
                        exit(0);
                    }
                    i++;
                }
                while(top>-1){
                    postfix[j] = pop();
                    j++;
                }
                postfix[j] = '\0';
                printf("Postfix expression: ");
                printf("%s",postfix);
                break;

            case 2: 
                printf("Enter the postfix expression: ");
                scanf("%s",postfix);
                while(postfix[i]!='\0'){
                    item = postfix[i];
                    if(isOperand(item) == 1){
                        printf("Enter the value of %c: ",item);
                        scanf("%d",&n);
                        pushint(n);
                    }
                    else{
                        op2 = popint();
                        op1 = popint();
                        switch(item){
                            case '+': 
                                res = op1+op2;
                                push(res);
                                break;
                            case '-': 
                                res = op1-op2;
                                push(res);
                                break;
                            case '*': 
                                res = op1*op2;
                                push(res);
                                break;
                            case '/': 
                                res = op1/op2;
                                push(res);
                                break;
                            case '^': 
                                res = op1^op2;
                                push(res);
                                break;
                        }
                    }
                    i++;
                }
                res = popint();
                printf("The value of the given expression is: %d",res);
                break;
        }
        printf("\nDo you want to continue? (1 for yes & 0 for no)");
        scanf("%d",&r);
    }while(r==1);
}