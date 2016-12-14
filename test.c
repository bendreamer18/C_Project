#include <stdio.h>
#include <stdlib.h>

int main()
{
	const MAX = 100;
    FILE *file;
    int k[MAX];
    char mas[400];
    file = fopen("C:\Users\—ергей\Desktop\OP Project.txt", "rt");
    for(int i=0; i<MAX i++)
    {
         fscanf(file, "%s %d", mas, &k[i]);
         fgets(file,mas,399); // надо дочитать строку до конца
    }
    for(int i=0;i<MAX;i++)
         printf(" %d", k[i]);
 
    getch();
    return 0;
}
