struct tnode{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *talloc(void);
char *mystrdup(char *s);

int getword(char *word, int lim);
int getch(void);
void ungetch(int c);

struct tnode *addtree(struct tnode *p, char *w);
void treeprint(struct tnode *p);