#include <stdio.h>

/*
    Swaps the integer values being pointed at by a and b. Keep in
    mind when you need to access a pointer's actual value (the 
    address it's referring to) or the value at the address it's 
    pointing at.
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
    Given a character pointer s, returns the number of characters
    it is pointing to. Think about how pointer arithmetic can 
    help you with this.
    
    Do not just use the `strlen` function from the standard library.
*/
int string_length(char *s)
{
    int length = 0;
    //while dereferenced s, length++ and pointer s++
    while (*s)
    {
        length++;
        s++;
    }
    return length;
}

/*
    Given an empty (NULL) character pointer x and a character pointer y,
    copies the character contents of y over to x. Again, pointer arithmetic
    is necessary here. Also, make sure x points to a null character at its 
    end to terminate it properly. 
    
    Do not just use the `strcpy` function from the standard library.
*/
void string_copy(char *x, char *y)
{
    int i = 0;
    while (*y)
    {
        *x = *y;
        y++;
        x++;
    }
    *x = '\0';
}

void string_copy2(char *x, char *y)
{
    while ((*x = *y))
    {
        x++;
        y++;
    }
    *x = '\0';
}

void string_copy3(char *x, char *y)
{
    while ((*x++ = *y++))
        ;
    *x = '\0';
}

/* 
    Compares the character strings m and n and returns negative,
    0, or positive if n is lexicographically less than, equal to,
    or greater than n. To calculate lexicographic difference, find
    the difference between the first characters in m and n that differ.
    
    For example, given matching strings, this function should 
    return 0. Given strings m = "hello world" and n = "goodbye",
    this function should return a positive value. Given strings
    m = "aardvark" and n = "zebra", should return a negative
    value.
    
    Do not just use the `strcmp` function from the standard library.
*/
int string_compare(char *m, char *n)
{
    int i = 0;
    while (m[i] == n[i])
    {
        if (m[i] == '\0')
        {
            return 0;
        }
        i++;
    }
    return m[i] - n[i];
}

int sean_string_compare(char *m, char *n)
{
    for (; *m == *n; m++, n++)
    {
        if (*m == '\0')
        {
            return 0;
        }
    }
    return *m - *n;
}

int recursive_string_compare(char *m, char *n)
{
    if (*m > *n)
    {
        return 1;
    }
    else if (*m < *n)
    {
        return -1;
    }
    else if (*m == '\0' && *n == '\0')
    {
        return 0;
    }
    return string_compare(++m, ++n);
}

#ifndef TESTING
int main(void)
{
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);

    char *hello = "Hello";
    char *world = "World";

    char buffer[1024];
    string_copy(buffer, hello);

    printf("Buffer is %s\n", buffer);
    printf("Length is %d\n", string_length(buffer));
    printf("Comparison is %d\n", string_compare(hello, world));

    return 0;
}
#endif
