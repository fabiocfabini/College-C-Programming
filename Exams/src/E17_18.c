#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../includes/E17_18.h"

// Helper functions
Palavras newPalavra(char *palavra, int comp, Palavras rest)
{
    Palavras new = malloc(sizeof(struct celula));

    if (new)
    {
        new->palavra = palavra;
        new->comp = comp;
        new->prox = rest;
    }

    return new;
}

void printPalavras(Palavras p)
{
    while (p)
    {
        for (int i = 0; i < p->comp; i++)
        {
            printf("%c", *(p->palavra + i));
        }
        printf(",%d", p->comp);
        p = p->prox;
        printf(" -> ");
    }
    printf("NULL\n");
}

void freePalavras(Palavras p)
{
    while (p)
    {
        Palavras temp = p->prox;
        free(temp);
        p = temp;
    }
}

// Exam Questions
int daPalavra(char *s, int *e)
{
    int space_count = 0;
    while (*s && isspace(*s))
    {
        space_count++;
        s++;
    }
    *e = space_count;

    int word_count = 0;
    while (*s && !isspace(*s))
    {
        word_count++;
        s++;
    }

    return word_count;
}

Palavras words(char *texto)
{
    Palavras out = NULL;
    Palavras *ad = &out;
    int space_count, word_length;

    while (*texto)
    {
        word_length = daPalavra(texto, &space_count);
        if (word_length > 0)
        {
            Palavras new = newPalavra(texto + space_count, word_length, *ad);
            *ad = new;
            ad = &(*ad)->prox;
        }
        texto += space_count + word_length;
    }

    return out;
}

Palavras daLinha(Palavras t, int n)
{
    Palavras out = NULL;
    Palavras *ad = &t;
    if (*ad && (*ad)->comp >= n)
    {
        out = (*ad)->prox;
        (*ad)->prox = NULL;
        n = 0;
    }
    while (*ad && n > 0)
    {
        n -= (*ad)->comp + 1 /*for extra space char*/;
        if (n < 0)
        {
            out = *ad;
            *ad = NULL;
        }
        else if (n == 0)
        {
            ad = &(*ad)->prox;
            out = *ad;
            *ad = NULL;
        }
        else
        {
            ad = &(*ad)->prox;
        }
    }
    return out;
}

int countWordsAndChars(Palavras p, int *nChars)
{
    int c = 0;
    *nChars = 0;
    while (p)
    {
        *nChars += p->comp;
        p = p->prox;
        c++;
    }
    return (c == 1)? c+1: c;;
}

void escreveLinha(Palavras p, int n)
{
    int total_chars, total_words, total_spaces, spaces_per_word, remainder;
    total_words = countWordsAndChars(p, &total_chars);
    total_spaces = n - total_chars;
    spaces_per_word = total_spaces / (total_words - 1);
    remainder = total_spaces % (total_words - 1);

    // As long as there are words in p
    while (p)
    {
        // print the words
        for (int i = 0; i < p->comp; i++)
        {
            printf("%c", *(p->palavra + i));
        }
        // if next word exists
        if (p->prox)
        {
            // print the spaces
            for (int i = 0; i < spaces_per_word + (0 < remainder); i++)
            {
                printf(" ");
            }
            remainder--;
        }
        // free the printed word
        Palavras temp = p->prox;
        free(p);
        p = temp;
    }
    printf("\n");
}

void formata(char texto[], int largura)
{
    Palavras p = words(texto);
    while (p)
    {
        Palavras aux = daLinha(p, largura);
        escreveLinha(p, largura);
        p = aux;
    }
}
