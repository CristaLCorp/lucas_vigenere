/***********************
 *                     *
 * Vigenere Encryption *
 *       09/29/16      *
 *    Coded by Lucas   *
 *        V 0.2        * 
 *                     *
 ***********************/

// cristal_branch

#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// example : 
// key : caca
// message : tarace
// code ==> vataee

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

    // Counter for non-alphabetic characters << in the message >> so the key isn't used on them
    int nonalpha = 0;
    
    // crypto loop start
    for (int i = 0, n = strlen(message); i < n; i++)
	    // i.e. : 6 times loop (tarace == 6 char)
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
	    // if "key" char is an upper char
            if (isupper(key[i % keylength]))
		// i.e. : key[0 % 4] = key[0]
		// i.e. : key[1 % 4] = key[1]
		// i.e. : key[2 % 4] = key[2]
		// i.e. : key[3 % 4] = key[3]
		// i.e. : key[4 % 4] = key[0]
		// i.e. : key[5 % 4] = key[1]
            {
                code[i] = message[i] + key[(i - nonalpha) % keylength] - 'A';
                // same
                if ((message[i] + key[(i - nonalpha) % keylength] - 'A') > 'z')
                    code[i] = code[i] - 26;
            }

	    // else the "key" char is a lower char, like in our example
            else
            {
                code[i] = message[i] + key[(i - nonalpha) % keylength] - 'a';
                //      = t + key[(0 - 0) % 4] - 'a' >> 't' + key[0] - 'a' >> 116 + 99 - 97 = 118 >> 'v'
		//      = a + key[(1 - 0) % 4] - 'a' >> 'a' + key[1] - 'a' >> 97  + 97 - 97 = 97  >> 'a'
		//      = r + key[(2 - 0) % 4] - 'a' >> 'r' + key[2] - 'a' >> 114 + 99 - 97 = 116 >> 't'
		//      = a + key[(3 - 0) % 4] - 'a' >> 'a' + key[3] - 'a' >> 97  + 97 - 97 = 97  >> 'a'
		//      = c + key[(0 - 0) % 4] - 'a' >> 'c' + key[0] - 'a' >> 99  + 99 - 97 = 101 >> 'e'
		//      = e + key[(1 - 0) % 4] - 'a' >> 'e' + key[1] - 'a' >> 101 + 97 - 97 = 101 >> 'e'

                //if ((message[i] + key[(i - nonalpha) % keylength] - 'a') > 'z')
                if (code[i] > 'z')
                    code[i] = code[i] - 26;

            }
		// end of the day you "return" the value for code[i]
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




















