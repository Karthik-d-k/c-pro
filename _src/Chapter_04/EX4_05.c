/* Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in Appendix B, Section 4. */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h> /* for strcmp() */
#include <math.h> /* for sin, exp, pow */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define FUNCTION '1' /* signal that a function was found */

int getop(char []);
void push(double);
double pop(void);
double top(void);
void duplicate_top(void);
void swap_top2(void);
void clear(void);
void view_stack(void);
double math_func(char []);

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    
    while ((type = getop(s)) != EOF) 
    {
        switch (type)
        {
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
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;              
            case '\n':
                printf("\t%.8g\n", pop());
                break;
/*             case 't':
                printf("Top element in a stack = %g\n", top());
                break;  
            case 'v':
                view_stack();
                break;  
            case 's':
                swap_top2();
                break;      
            case 'd':
                duplicate_top();
                break;  
            case 'c':
                clear();
                break;  */  
            case FUNCTION:
                push(math_func(s));
                break;                
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    
    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else 
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* print the top element of the stack without popping */
double top(void)
{
    if (sp > 0)
        return val[sp - 1];
    else 
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* duplicate the top element of the stack */
void duplicate_top(void)
{
    if (sp > 0)
        val[sp++] = val[sp - 1];
    else 
        printf("error: stack empty\n");
}

/* swap the top two elements of the stack*/
void swap_top2(void)
{
    double tmp;
    if (sp > 1)
    {
        tmp = val[sp - 2];
        val[sp - 2] = val[sp - 1];
        val[sp - 1] = tmp;
    }
    else 
        printf("error: stack contains less than 2 elements\n");
}

/* clear the stack*/
void clear(void)
{
    sp = (sp > 0) ? 0 : sp;
}

/* print stack elements */
void view_stack(void)
{
    int vp = sp;
    while(--vp >= 0)
        printf("%g\n", val[vp]);
}

/* Access to math functions available in math.h */
double math_func(char s[])
{
    if (strcmp(s, "sin") == 0)
        return (sin(pop()));
    else 
    {   
        printf("error: Function not in math.h \n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/*
ERROR :
-----
$ gcc EX4_05.c
/usr/bin/ld: /tmp/cc82gGCH.o: in function `main':
EX4_05.c:(.text+0x1bd): undefined reference to `sin'
collect2: error: ld returned 1 exit status

SOLUTION :
--------
The error you are seeing: error: ld returned 1 exit status is from the linker ld (part of gcc that combines the object files) 
because it is unable to find where the function pow is defined.

Including math.h brings in the declaration of the various functions and not their definition. 
The def is present in the math library libm.a. You need to link your program with this library so that the calls to functions like pow() are resolved.

$ gcc EX4_05.c -lm

SOURCE :
------
https://stackoverflow.com/a/12824148
*/
