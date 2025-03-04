#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "utils_tree.h"

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;
int value = EOF;

struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *mystrdup(char *s){

    char *p;
 
    p = (char *) malloc(strlen(s)+1);
    if (p != NULL)
        strcpy(p, s);
    
    return p;
}

/*getword: recoge una palabra del usuario*/
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}


int getch(void)
{

	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

struct tnode *addtree(struct tnode *p, char *w){
    int cond;

    if(p==NULL){
        p=talloc();
        p->word=mystrdup(w);
        p->count=1;
        p->left=p->right=NULL;
    }else if((cond=strcmp(w,p->word)==0))
        p->count++;
    else if(cond<0)
        p->left=addtree(p->left,w);
    else
        p->right=addtree(p->right,w);
    
    return p;
}

void treeprint(struct tnode *p){
    if (p!=NULL){
        treeprint(p->left);
        printf("%4d %s", p->count, p->word);
        treeprint(p->right);
    }
}