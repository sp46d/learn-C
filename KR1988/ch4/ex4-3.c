#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 5

// global variables
// 1. stack
int sp = 0; // next free stack position
double val[MAXVAL]; // value stack

// 2. buffer
char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf

// function prototypes
int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void clear_stack(void);

int main(void)
{
    int type, n;
    int command_entered = 0;
    double op2, tmp, tmp1, tmp2;
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
            op2 = pop();
            if (op2 != 0) {
                n = pop();
                push(n - (int)(n / op2) * op2);
            } else
                printf("error: modulus not allowed for zero divisor\n");
            break;
        // Exercise 4-4: Print the top element of the stack without popping
        case 'p':
            if (sp < 1)
                printf("stack empty\n");
            else {
                printf("The most top element is: %g\n", pop());
                ++sp;
            }
            command_entered = 1;
            break;
        // Exercise 4-4: Duplicate the top element of the stack
        case 'd':
            if (sp < 1)
                printf("stack empty\n");
            else {
                tmp = pop();
                for (int i = 0; i < 2; i++)
                    push(tmp);
                printf("Top element has been duplicated\n");
            }
            command_entered = 1;
            break;
        // Exercise 4-4: Swap the top two elements
        case 's':
            if (sp < 1) {
                printf("stack empty\n");
            } else if (sp < 2) {
                printf("Can't swap elements when only one element is available "
                       "in stack\n");
            } else {
                tmp1 = pop();
                tmp2 = pop();
                push(tmp1);
                push(tmp2);
                printf("Top two elements have been swapped\n");
            }
            command_entered = 1;
            break;
        // Exercise 4-4: Clear the stack
        case 'c':
            sp = 0;
            printf("Stack has been cleared\n");
            command_entered = 1;
            break;
        // utility command for view: View all the values in the stack
        case 'v':
            if (sp < 1)
                printf("stack empty\n");
            else {
                printf("Top: ");
                for (int i = sp - 1; i > 0; --i)
                    printf("%g\n", val[i]);
                printf("Bottom: %g\n", val[0]);
            }
            command_entered = 1;
            break;
        case '\n':
            if (command_entered)
                command_entered = 0;
            else
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
    if (c == '-') {
        while (isdigit(s[++i] = c = getch()))
            ;
        if (!isdigit(s[1]) && c != EOF) {
            s[i] = '\0';
            ungetch(c);
            return '-';
        }
    } // allow for negative numbers
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
