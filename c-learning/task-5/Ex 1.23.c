/* Ex 1.23: Write a program to remove all comments from a C program.
   Don't forget to handle quoted strings and character constants properly.
   C comments do not nest. */

#include <stdio.h>

#define MAXLINE 1000 /* max input line size */

char line[MAXLINE]; /* current input line */

int getline(void);

int main()
{ 
  int c;          /* character */
  int comment;   /* comment */
  int quote;     /* quotation marks  */
  int len;       /* current line length */

  comment = quote = c = 0;

  while ((len = getline()) > 0)
  {
      c = 0;
      while (c < len)
      {
           if (line[c] == '"' || line[c] == '/'')  /* to separate quotation marks and character constants from the comment, so that they won't be re moved */
           {
               quote = 1;
           }
           if (line[c] != quote)
           {
                if (line[c] == '/' && line[c+1] == '*')  /*   c+1 means including "/"   */
                {
                    c =  c + 2;                         /*   to include both "/" and "*"   */
                    comment = 1;
                }
               /*   same as above but this time with "*" and "/"   */
                if (line[c] == '*' && line[c+1] == '/')
                {
                    c = c + 2;
                    comment = 0;
                }
               if (comment == 1)
               {
                    c++;
               }
              else
              {
                   printf("%c", line[c]);
                   c++;
              }
          }
      }
  }
  return 0;
}


/* getline:  reads a line, return line length */
int getline(void)
{
  int c, i;
  extern char line[];

  for ( i = 0;i < MAXLINE - 1 && ( c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if(c == '\n')
    {
      line[i] = c;
      ++i;
    }
  line[i] = '\0';
  return i;

}
