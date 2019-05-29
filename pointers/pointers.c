#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    int counter = 0;
    while (*(y + counter) != '\0')
    {
        x[counter] = *(y + counter);
        counter++;
    }
    x[counter] = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, char c)
{
    int counter = 0;
    while (*(str + counter) != '\0')
    {
        if (*(str + counter) == c)
        {
            return (str + counter);
        }
        else
        {
            counter++;
        }
    }
    return 0;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    // char *ptr;
    int counter1 = 0;
    while (*(haystack + counter1) != '\0')
    {
        // printf("Outer While Haystack Char %c\n", *(haystack + counter1));
        if (*(haystack + counter1) == *needle)
        {
            int counter2 = 0;
            int position = counter1;
            while (*(haystack + counter1) != '\0')
            {
                // printf("Inner While Haystack Char %c\n", *(haystack + counter1));
                // printf("Inner While Needle Char %c\n", *(needle + counter2));

                if (*(haystack + counter1) != *(needle + counter2))
                {
                    break;
                }
                else if (*(needle + counter2+1) == '\0')
                {
                    // printf("Found It!\n");
                    return (haystack + position);
                }
                counter1++;
                counter2++;
            }
        }
        counter1++;
    }
    return 0;
}

#ifndef TESTING
int main(void)
{
    // char buffer[1024];

    // string_copy(buffer, "Hello!");
    // printf("%s\n", buffer); // Prints "Hello!"

    char *found_char = find_char("hello", 'e');
    printf("Found char: %s\n", found_char);

    char *found_string = find_string("world", "or");
    printf("Found string: %s\n", found_string);

    // char *str = "LambdaSchool";
    // char *found = find_string("LambdaSchool", "School");
    // printf("Found string: %s\n", found);

    return 0;
}
#endif
