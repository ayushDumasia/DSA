#include<stdio.h>
#include<string.h>
#include<time.h>
#define size 50

void push(char arr[], int *top, char infix){
    if((*top) > size){
        printf("Stack Overflow\n");
        return;
    }
    else{
        arr[++(*top)] = infix;
    }
}

void pop(int *top){
    if((*top) < 0){
        printf("Stack Underflow\n");
        return;
    }
    else{
        (*top)--;
    }
}

char peep(char arr[], int *top){
    return arr[*top];
}

int precedence(char c){
    if (c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/' || c == '%'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return 0; 
    }
}

int ifOperator(char c){
    if(c == '^' || c == '*' || c == '/' || c == '%' || c == '+' || c == '-' || c == '(' || c == ')'){
        return 1;
    }
    else{
        return 0;
    }
}

void main(){
    char infix[] = "((a+1)%n)";
    strcat(infix, ")");
    char postfix[size], st[size];
    int top = -1, temp, i = 0, j = -1;
    push(st, &top, '(');

    for(i = 0; infix[i] != '\0'; i++){
        if(ifOperator(infix[i]) == 0){
            push(postfix, &j, infix[i]);
        }
        else{
            push(st, &top, infix[i]);
            if(st[top] == ')'){
                pop(&top);
                while(st[top] != '('){
                    push(postfix, &j, peep(st, &top));
                    pop(&top);
                }
                pop(&top);
            }
            else if(st[top] == '('){
                continue;
            }
            else if(precedence(st[top]) <= precedence(st[top - 1])){
                while(precedence(st[top]) <= precedence(st[top - 1])){
                    temp = peep(st, &top);
                    pop(&top);
                    push(postfix, &j, st[top]);
                    pop(&top);
                    push(st, &top, temp);
                }
            }
        }
    }
    
    printf("%s\n", postfix);
}