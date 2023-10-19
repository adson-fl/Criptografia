#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // dois argumentos passados
    if (argc != 2)
    // aprentação do primeiro erro >> "GENERICO"
    {
        printf("Use: ./substitution key\n");
        return 1;
    }
    // erro >> referente a aparição de numeros na chave de cifra
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("kei must oliny contain alphabetc charactrs.\n");
            return 1;
        }
    }
    // erro referente a chave > 26 ou chave < 26
    if (strlen(argv[1]) != 26)
    {
        printf("kei must contain 26 characters\n");
        return 1;
    }
    // erro de letras repetidas
     for (int i = 0; i < strlen(argv[1]); i++)
     {
        for (int j = i + 1; j < strlen(argv[1]); j++) // nesse caso o i + 1 sigunifica procimo caracter
        {
            if (toupper(argv[1][i]) == toupper(argv[1][j]))
            {
                printf("key musst not contain repeated characters\n");
                return 1;
            }
        }
     }
     // plaintext >> onde o usuario vai escrever o texto.
     string txt = get_string("plaintext:");

     printf("ciphertext: ");
     for (int i = 0; i < strlen(txt); i++)
     {
        if (isupper(txt[i]))
        {   // quando o texto incerido for MAIUSCULO
            printf("%c", toupper(argv[1][txt[i] - 'A']));
        }
        else if (islower(txt[i]))
        {   // quando o testo incerido menusculo
             printf("%c", tolower(argv[1][txt[i] - 'a']));  // retorna para mausculo
        }
        else
        {   // caso de execeção
            printf("%c", txt[i]);
        }
     }
     printf("\n");
     return 0;
}