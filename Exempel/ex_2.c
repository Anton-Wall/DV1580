#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *TEST_STRING = "Hello, this is a test string";
const int TEST_INT = 123;

void countChars();

int main(void)
{
    int characters['z' - 'a'] = {0}; // 26 elements, all initialized to 0

    for (size_t i = 0; i < strlen(TEST_STRING); ++i)
    {
        char c = TEST_STRING[i];
        if (c >= 'a' && c <= 'z')
        {
            characters[c - 'a']++;
        }
    }

    countChars();

    return 0;
}

void countChars()
{
    int characters['z' - 'a'] = {0};
    for (size_t i = 0; i < strlen(TEST_STRING); ++i)
    {
        if (isspace(TEST_STRING[i]))
        {
            continue;
        }

        int current = tolower(TEST_STRING[i]);
        characters[current - 'a']++;
    }

    // printf("chars: %i:\n", characters);

    for (size_t i = 0; i < 'z' - 'a'; ++i)
    {
        printf("%c: %d\n", i + 'a', characters[i]);
    }
}