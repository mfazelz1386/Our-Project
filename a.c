#include "stdio.h"
char *find_char(char *, int);
void main()
{
char str[40], *ptr; int ch;
gets(str);
ch=getch();
ptr=find_char(str,ch);
if (*ptr)
puts(ptr);
else
printf("charachter %c NOT found", ch);
}
char *find_char(char *s, int ch)
{
for (int i=0; s[i] !='\0'; i++)
    if ((char)ch==s[i])
        return &s[i];
return NULL;
}
