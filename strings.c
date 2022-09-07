#include "monty.h"
/**
 * _strtok - Splits str[] according to given delimiters,
 *  returns the next token.  
 *  It needs to be called in a loop to get all tokens. 
 *  It returns NULL when there are no more tokens
 *  @str:  string to search and break into tokens.
 *  @delims:  string containing the delimiter characters.
 *
 *  Return: next token or NULL when there are no more tokens.
 */

char *_strtok(char *str, const char *delims)
{
	// Returns first token
    char* token = strtok(str, delims);

    // Keep printing tokens while one of the
    // delimiters present in *str.
    while (token != NULL) {
        printf(" %s\n", token);
        token = strtok(NULL, delims);
	return (token);
    }

    return (token);
}
