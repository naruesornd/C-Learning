/* Ex 1.24: Write a program to check a C program
   for rudimentary syntax errors like
   unbalanced parentheses, brackets and braces.
   Don't forget about quotes, both single
   and double, escape sequences, and comments.
   (This program is hard if you do it in full generality.) */

#include <stdio.h>

#define MAXLINE 1000 /* max input line size */

char line[MAXLINE]; /*current input line*/

int getline(void);


int main()
{
    int c = 0;         /* character */
    int len = 0;       /* current line length */
    int paren = 0;     /* parenthesis */
    int bracket = 0;
    int brace = 0;
    int squote = 1;    /* single quotation mark */
    int dquote = 1;    /* double quotation mark */
    int escp = 1;      /*  escape sequences */
    int comment = 0;   /* comment */

    while ((len = getline()) > 0)
    {
        //c=0;
        while (c < len)
        {
            if (line[c] == '(')
            {
                paren++;
            }
            if (line[c] == ')')
            {
                paren--;
            }
            if (line[c] == '[')
            {
                bracket++;
            }
            if (line[c] == ']')
            {
                bracket--;
            }
            if (line[c] == '{')
            {
                brace++;
            }
            if (line[c] == '}')
            {
                brace--;
            }
            if (line[c] == '\'')
            {
                squote = 0;
            }
            if (line[c] == '"')
            {
                dquote = 0;
            }
            if (line[c] == '\\')
            {
                escp = 0;
            }
            if (line[c] == '/' && line[c+1] == '*')
            {
                c =  c + 2;
                comment++;
            }
            if (line[c] == '*' && line[c+1] == '/')
            {
                c =  c + 2;
                comment--;
            }
            c++;
        }
    }
    printf("----------------------------------------\n");
    if (paren != 0)
    {
        printf("Unbalanced parenthes(es) found\n");
    }
    if (bracket != 0)
    {
        printf("Unbalanced bracket(s) found\n");
    }
    if (brace != 0)
    {
        printf("Unbalanced brace(s) found\n");
    }
    if (squote != 1)
    {
        printf("Unbalanced single quotation mark(s) found\n");
    }
    if (dquote != 1)
    {
        printf("Unbalanced double quotation mark(s) found\n");
    }
    if (escp != 1)
    {
        printf("Unbalanced escape sequence(s) found\n");
    }
    if (comment != 0)
    {
        printf("Unbalanced comment(s) found\n");
    }
    if (paren == 0 && bracket == 0 && brace == 0 && squote == 1 && dquote == 1 && escp == 1 && comment == 0)
    {
        printf("No rudimentary syntax error(s) found.\n");
    }
    return 0;
}

/* getline: reads a line, return line length */
int getline(void)
{
  int c, i;
  extern char line[];

  for ( i = 0;i < MAXLINE-1 && ( c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if(c == '\n')
    {
      line[i] = c;
      ++i;
    }
  line[i] = '\0';
  return i;

}
