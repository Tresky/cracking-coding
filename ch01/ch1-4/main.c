#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* ReplaceSpace(char* _str)
{
    int len = strlen(_str), spaces = 0;
    for (int i = 0; i < len; i++)
        if (_str[i] == ' ')
            spaces++;

    char* str = (char*)malloc(sizeof(char) * len + sizeof(char) * (spaces * 2) + 1);
    int i = 0;
    for (int j = 0; j < len; j++)
    {
        if (_str[j] == ' ')
        {
            str[i++] = '%';
            str[i++] = '2';
            str[i++] = '0';
        }
        else
            str[i++] = _str[j];
    }
    return str;
}

int main()
{
    char str[] = "This is my program";
    printf("%s\n", ReplaceSpace(str));
    return 0;
}