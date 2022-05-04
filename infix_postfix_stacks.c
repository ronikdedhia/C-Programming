#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 500
char stack[SIZE];
double stack_int[SIZE];
long int TopOfPost = -1;
long int Top = -1;
void push(char item)
{
    if (Top == SIZE - 1)
    {
        printf("STACK OVERFLOW");
        exit(1);
    }
    else
    {
        Top++;
        stack[Top] = item;
    }
}
char pop()
{
    char item;
    if (Top < 0)
    {
        printf("STACK UNDER FLOW: INVALID INFIX EXPRESSION");
    }
    else
    {
        item = stack[Top];
        Top = Top - 1;
        return (item);
    }
}
int is_operator(char sym)
{
    if (sym == '^' || sym == '*' || sym == '/' || sym == '+' || sym == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char sym)
{
    if (sym == '^')
    {
        return (3);
    }
    else if (sym == '*' || sym == '/')
    {
        return (2);
    }
    else if (sym == '+' || sym == '-')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
void Infix_to_Postfix(char Infix_exp[], char Postfix_exp[])
{
    int i, j;
    char item;
    char x;
    push('(');
    strcat(Infix_exp, ")");
    i = 0;
    j = 0;
    item = Infix_exp[i];
    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            Postfix_exp[j] = item;
            j++;
        }
        else if (item == '^')
        {
            push(item); // pushing
        }
        else if (is_operator(item) == 1)
        {
            x = pop();
            while (is_operator(x) == 1 && precedence(x) >= precedence(item))
            {
                Postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                Postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            printf("\nInvalid infix Expression.\n");
            getchar();
            exit(1);
        }
        i++;
        item = Infix_exp[i];
    }
    if (Top > 0)
    {
        printf("\nInvalid infix Expression.\n");
        getchar();
        exit(1);
    }
    Postfix_exp[j] = '\0';
}
void push_Postfix(int item)
{
    if (TopOfPost == SIZE - 1)
    {
        printf("STACK OVERFLOW");
        exit(1);
    }
    else
    {
        TopOfPost++;
        stack_int[TopOfPost] = item;
    }
}
float pop_Post()
{
    float item;
    item = stack_int[TopOfPost];
    TopOfPost = TopOfPost - 1;
    return item;
}
float Evaluate(char item, float op1, float op2)
{
    float n = 1.0;
    switch (item)
    {
    case '+':
        return (op1 + op2);
    case '-':
        return (op1 - op2);
    case '*':
        return (op1 * op2);
    case '/':
        return (op1 / op2);
    case '^':
        for (int i = op2; i > 0; i--)
        {
            n *= op1;
        }
        return n;
    }
}
void Postfix_Evaluate(char Postfix_exp[])
{
    float x, op1, op2, result = 0;
    char item;
    for (int i = 0; Postfix_exp[i] != '\0'; i++)
    {
        if (isalpha(Postfix_exp[i]))
        {
            printf("Enter the value of %c:", Postfix_exp[i]);
            scanf("%f", &x);
            push_Postfix(x);
        }
        else if (is_operator(Postfix_exp[i]))
        {
            op2 = pop_Post();
            op1 = pop_Post();
            item = Postfix_exp[i];
            result = Evaluate(item, op2, op1);
            push_Postfix(result);
        }
    }
}
int main()
{
    char Infix[SIZE], Postfix[SIZE];
    printf("Enter the infix expression:");
    gets(Infix);
    Infix_to_Postfix(Infix, Postfix);
    printf("postfix expression is :");
    puts(Postfix);
    Postfix_Evaluate(Postfix);
    printf("\nTHE RESULT OF EVALUATION IS:%0.2f", stack_int[0]);
    return 0;
}
