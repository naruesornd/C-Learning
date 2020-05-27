#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* Ex 1.11: How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any? */
/* count lines, words, and characters in input */
main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("Lines:%d\nWords:%d\nCharacters:%d\n", nl, nw, nc);

    return 0;
}

/* How would you test the word count program?
   Ans: Inserting the inputs in the console and then click ENTER key and CTRL-Z key to signal EOF. Then press ENTER key again in order to produce output of word count. */
/* What kinds of input are most likely to uncover bugs if there are any?
   Ans: tabs, newlines, blanks. */
