/***********************
 *                     *
 * Vigenere Encryption *
 *       09/29/16      *
 *    Coded by Lucas   *
 *        V 0.2        * 
 *                     *
 ***********************/

// lucas_branch
// commit try

#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// example : 
// key : caca
// message : tarace
// code ==> vataee

int datshitIsLower(int key_nonalpha_mod_keylength, char message, int keylength, int nonalpha);
int datshitIsHigher(int key_nonalpha_mod_keylength, char message, int keylength, int nonalpha);

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
    printf("Y U no feed me (=°.°=) ?! :");
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
            code[i]=datshitIsHigher(key[(i - nonalpha) % keylength], message[i], keylength, nonalpha);
        

	// encoding lower characters
        else if (islower(message[i]))
        // end of the day you "return" the value for code[i]
		    code[i]=datshitIsLower(key[(i - nonalpha) % keylength], message[i], keylength, nonalpha);
        

	// no up no low, increment non alpha counter
        else
        {
            code[i] = message[i];
            nonalpha++;
        }
        
    // crypto loop end
    }
    
    printf("\nEncrypted message :\n%s\n", code);
}

int datshitIsLower(int key_nonalpha_mod_keylength, char message, int keylength, int nonalpha){

	int code = 0;
	
	    // if "key" char is an upper char
            if (isupper(key_nonalpha_mod_keylength))
		// i.e. : key[0 % 4] = key[0]
		// i.e. : key[1 % 4] = key[1]
		// i.e. : key[2 % 4] = key[2]
		// i.e. : key[3 % 4] = key[3]
		// i.e. : key[4 % 4] = key[0]
		// i.e. : key[5 % 4] = key[1]
            {
                code = message + key_nonalpha_mod_keylength - 'A';
                // If above letter range
                if (code > 'z')
                    code = code - 26;
            }

	    // else the "key" char is a lower char, like in our example
            else
            {
                code = message + key_nonalpha_mod_keylength - 'a';
                //      = t + key[(0 - 0) % 4] - 'a' >> 't' + key[0] - 'a' >> 116 + 99 - 97 = 118 >> 'v'
		//      = a + key[(1 - 0) % 4] - 'a' >> 'a' + key[1] - 'a' >> 97  + 97 - 97 = 97  >> 'a'
		//      = r + key[(2 - 0) % 4] - 'a' >> 'r' + key[2] - 'a' >> 114 + 99 - 97 = 116 >> 't'
		//      = a + key[(3 - 0) % 4] - 'a' >> 'a' + key[3] - 'a' >> 97  + 97 - 97 = 97  >> 'a'
		//      = c + key[(0 - 0) % 4] - 'a' >> 'c' + key[0] - 'a' >> 99  + 99 - 97 = 101 >> 'e'
		//      = e + key[(1 - 0) % 4] - 'a' >> 'e' + key[1] - 'a' >> 101 + 97 - 97 = 101 >> 'e'

                //if ((message[i] + key[(i - nonalpha) % keylength] - 'a') > 'z')
                if (code > 'z')
                    code = code - 26;

            }

	return code;
}

int datshitIsHigher(int key_nonalpha_mod_keylength, char message, int keylength, int nonalpha)
{

	int code = 0;
	
	    // if "key" char is an upper char
            if (isupper(key_nonalpha_mod_keylength))
	
            {
                code = message + key_nonalpha_mod_keylength - 'A';
                // If above Capital letter range
                if (code > 'Z')
                    code = code - 26;
            }

	    // else the "key" char is a lower char, like in our example
            else
            {
                code = message + key_nonalpha_mod_keylength - 'a';
                //      = t + key[(0 - 0) % 4] - 'a' >> 't' + key[0] - 'a' >> 116 + 99 - 97 = 118 >> 'v'
		//      = a + key[(1 - 0) % 4] - 'a' >> 'a' + key[1] - 'a' >> 97  + 97 - 97 = 97  >> 'a'
		//      = r + key[(2 - 0) % 4] - 'a' >> 'r' + key[2] - 'a' >> 114 + 99 - 97 = 116 >> 't'
		//      = a + key[(3 - 0) % 4] - 'a' >> 'a' + key[3] - 'a' >> 97  + 97 - 97 = 97  >> 'a'
		//      = c + key[(0 - 0) % 4] - 'a' >> 'c' + key[0] - 'a' >> 99  + 99 - 97 = 101 >> 'e'
		//      = e + key[(1 - 0) % 4] - 'a' >> 'e' + key[1] - 'a' >> 101 + 97 - 97 = 101 >> 'e'

                //if ((message[i] + key[(i - nonalpha) % keylength] - 'a') > 'z')
                if (code > 'Z')
                    code = code - 26;

            }

	return code;
}
