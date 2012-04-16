#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[10][1024] = {0};
void printStack()
{
    int i = 0;
    for(i = 0; i < 3; i ++)
        printf("%d: %s\n", i, (char *)&stack[i]);
}

void printLine(int level, char *path, int is_dir, int is_last)
{
    char *f1 = "    ";
    char *f2 = "|   ";
    char *s;
    char *c;
    char *head;
    if(level == 0)
    {
        head = stack[level]; 
    }
    else
    {
        head = stack[level - 1]; 
    }
    s = (char *)malloc(sizeof(char)*1024);
    c = (char *)malloc(sizeof(char)*1024);

    if(is_last == 1)
    {
	strcat(s, head);
        sprintf((char *)c, "`-- %s", path);
	strcat(s, c);
	strcpy((char *)&stack[level], (char *)&stack[level-1]);
	strcat((char *)&stack[level], f1);
    }
    else
    {
	strcat(s, head);
        sprintf((char *)c, "|-- %s", path);
	strcat(s, c);
	strcpy((char *)&stack[level], (char *)&stack[level-1]);
	strcat((char *)&stack[level], f2);
    }
    //strcpy((char *)&stack[level], head);
    printf("%s\n", s);

    //printStack();
}
int main(void)
{
    printLine(1, ".tree.c.swp", 0, 0);
    printLine(1, ".tree.p.swp", 0, 0);
    printLine(2, "main", 0, 0);
    printLine(2, "tree.c", 0, 1);
    printLine(1, "tree.c~", 0, 0);
    printLine(1, "tree.py", 0, 1);
    //printStack();
    return 0;
}
