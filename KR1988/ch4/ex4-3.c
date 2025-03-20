#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 5

// function prototypes
int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

// global variables
// 1. stack
int sp = 0; // next free stack position
double val[MAXVAL]; // value stack

// 2. buffer
char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf

int main(void)
{
    int type, op2_int, n;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        // Exercise 4-3: Add modulo operator
        case '%':
            op2_int = pop();
            if (op2_int != 0) {
                n = pop();
                push(n - (int)(n / op2_int) * op2_int);
            } else
                printf("error: modulus not allowed for zero divisor\n");
            break;
        case '\n':
            printf(" -> %.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

// push: push f onto value stack
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void)
{
    if (sp <= 0) {
        printf("error: stack empty\n");
        return 0.0;
    }

    return val[--sp];
}

// getop: get next character or numeric operand
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    // Exercise 4-3: provision for negative numbers
    if (!isdigit(c) && c != '.'
        && c != '-') // negative sign is now allowed as a part of number
        return c; // not a number
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') // collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;
    // Exercise 4-3: provision for negative numbers
    if (c == '-') // allow for negative numbers
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
