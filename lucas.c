/***********************
 *                     *
 * Vigenere Encryption *
 *       09/29/16      *
 *    Coded by Lucas   *
 *        V 0.2        * 
 *                     *
 ***********************/

// TEST FORK

#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // checking arguments count
    if (argc != 2)
    {
        printf("Add one keyword on command line as key please!\n");
        return 1;
    }
    
    // storing argument value
    string key = argv[1];

    // and size
    int keylength = strlen(argv[1]);
    
    // Make sure it's all letters...
    for(int i = 0; i < keylength; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Nope.");
            return 1;
        }
    }
    
    // input message to encode
    printf("Y U no feed me (=°.°=) ?! :\n");
    string message = GetString();

    // array size starts at 0. string length starts at 1. ex : strlength("merde") will return 5, so you need a char array[4] (array[0] = "m", array[4] = "e")
    int array_size = strlen(message) - 1;
    char code[array_size];

    // Counter for non-alphabetic characters so the key isn't used on them
    int nonalpha = 0;
    
    // crypto loop start
    for (int i = 0, n = strlen(message); i < n; i++)
    {
	// encoding upper characters    
        if (isupper(message[i]))
        {
	    // 
            if (isupper(key[i % keylength]))
            {
                code[i] = message[i] + key[(i - nonalpha) % keylength] - 'A';
                // if outside of capital letter range bring it back (I should probably use modulo)
                if ((message[i] + key[(i - nonalpha) % keylength] - 'A') > 'Z')
                    code[i] = code[i] - 26;
            }

	    // 
            else
            {
                code[i] = message[i] + key[(i - nonalpha) % keylength] - 'a';
                // same here
                if ((message[i] + key[(i - nonalpha) % keylength] - 'a') > 'Z')
                    code[i] = code[i] - 26;
            }
        }

	// encoding lower characters
        else if (islower(message[i]))
        {
	    // 
            if (isupper(key[i % keylength]))
            {
                code[i] = message[i] + key[(i - nonalpha) % keylength] - 'A';
                // same
                if ((message[i] + key[(i - nonalpha) % keylength] - 'A') > 'z')
                    code[i] = code[i] - 26;
            }

	    // 
            else
            {
                code[i] = message[i] + key[(i - nonalpha) % keylength] - 'a';
                // same
                if ((message[i] + key[(i - nonalpha) % keylength] - 'a') > 'z')
                    code[i] = code[i] - 26;
            }
        }

	// no up no low, increment non alpha counter
        else
        {
            code[i] = message[i];
            nonalpha++;
        }
        
    // crypto loop end
    }
    
    // Important part cristal: I would have used normal printf for string "code" but weird characters kept on showing up. Not sure how to fix.
    /*for (int i = 0, n = strlen(message); i < n; i++)
        printf("%c", code[i]);*/
    printf("\nEncrypted message :\n%s\n", code);
        
    //printf("\n");
}
