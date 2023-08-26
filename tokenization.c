#include "simple_shell.h"

/**
 * tokenization - Extracts tokens from the input string.
 *
 * @ptr: Input string to tokenize.
 * @delim: Delimiter string.
 *
 * Return: Returns an array of tokens.
 *
 * Description: This function takes an input string and a delimiter and
 * tokenizes the input string based on the delimiter. It returns an array
 * of pointers to each token.
 */
char **tokenization(char *ptr, char *delim)
{
    char **tokens = NULL;
    char **temp_tokens = NULL;  
    char **final_tokens = NULL;
    char *token;  
    int token_count = 0;  

    token = strtok(ptr, delim);  /* Get the first token */

    while (token)
    {
        /* Reallocate memory for tokens array */
        temp_tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
        if (!temp_tokens)
        {
            perror("realloc error");
            free_array(tokens); /* Free already allocated tokens */
            exit(EXIT_FAILURE);
        }

        tokens = temp_tokens;

        /* Duplicate the token and store it in tokens array */
        tokens[token_count] = strdup(token);
        if (tokens[token_count] == NULL)
        {
            perror("strdup error");
            free_array(tokens); /* Free already allocated tokens */
            exit(EXIT_FAILURE);
        }

        token_count++;
        token = strtok(NULL, delim); /* Get the next token */
    }

    /* Reallocate memory for tokens array with the final count */
    final_tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
    
    if (final_tokens == NULL)
    {
        perror("realloc error");
        free_array(tokens); /* Free already allocated tokens */
        exit(EXIT_FAILURE);
    }
    else
    {
        tokens = final_tokens; /* Update the tokens pointer only if realloc succeeded */
    }
    tokens[token_count] = NULL; /* Mark the end of the tokens array */

    return tokens;
}

