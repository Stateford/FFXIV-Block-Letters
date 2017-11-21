#include <stdlib.h>
#include <string.h>
#include "translate.h"

const int MIN_UPPERCASE = 65;
const int MAX_UPPERCASE = 90;
const int MAX_SIZE = 80;


const wchar_t english[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

const wchar_t block[26] = {
    L'', L'', L'', L'', L'', L'', L'', L'',
    L'', L'', L'', L'', L'', L'', L'', L'',
    L'', L'', L'', L'', L'', L'', L'', L'',
    L'', L''
};

wchar_t *toLower(wchar_t *string)
{

    int index = 0;
    wchar_t *newStr = (wchar_t *)malloc(80);

    while (string[index] != '\0')
    {
        if(string[index] >= MIN_UPPERCASE && string[index] <= MAX_UPPERCASE)
        {
            wchar_t temp = string[index] + 32;
            newStr[index] = temp;
        }
        else
        {
            newStr[index] = string[index];
        }
        index++;
    }
    newStr[index] = '\0';
    return newStr;
}


wchar_t* translate(wchar_t *string)
{
    int index = 0;
    // convert string to lowercase
    wchar_t *lower = toLower(string);
    // create new string
    wchar_t *newStr = (wchar_t *)malloc(80);

    // loop until end of string
    while(lower[index] != '\0')
    {
        int guard = 1;
        for(int i = 0; i < 26; i++)
        {
            if(english[i] == lower[index])
            {
                guard = 0;
                newStr[index] = block[i];
            }
        }
        if(guard == 1)
        {
            newStr[index] = lower[index];
        }

        index++;
    }

    newStr[index] = '\0';
    // deallocate memory
    free(lower);

    return newStr;
}

