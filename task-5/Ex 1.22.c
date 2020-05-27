/* Ex 1.22: Write a program to "fold" long input lines into two or more shorter lines 
after the last non-blank character that occues befire the n-th column of input. 
Make sure your progeam does something intelligent with very long lines, 
and if there are no blanks or tabs before the specified column. */

#include <stdio.h>

#define MAXLINE 1000 /* max input line size */
#define FOLDLENGTH 100  /* The max length of a line */

char line[MAXLINE]; /*current input line*/

int getline(void);  

int main()
{
  int b;   /* variable for blanks */
  int len; /* current line length */
  int pos; /* position of characters in line */
  int spaceholder;

  while (( len = getline()) > 0 )
    {
      if( len < FOLDLENGTH )
	{
	    /* do nothing */
	}
     /* if the line is very long,
        then we loop through
        to replace a space nearest to the fold area
        with a newline. */
	else
	{

	  b = 0;
	  pos = 0;

	  while(b < len)
	    {
	      if(line[b] == ' ')
		spaceholder = b;

	      if(pos == FOLDLENGTH)
		{
		  line[spaceholder] = '\n';
		  pos = 0;  /* reset position */
		}
	      pos++;
	      b++;
	    }
	}
      printf("\n");  /* to separate Fold version from the inputs */
      printf("Fold version: %s", line);
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
