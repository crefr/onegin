#include <stdio.h>
#include <stdlib.h>

#include "onegin.h"
#include "io_onegin.h"
#include "debug.h"

void printStrsToFile(FILE * outfile, text_t * text)
{
    for (size_t index = 0; index < text->strnum; index++){
        fprintf(outfile, "%s\n", text->strings[index].start);
    }
}

void printOriginTextToFile(FILE * outfile, text_t * text)
{
    for (size_t index = 0; index < text->textlen; index++){
        if (text->text[index] == '\0')
            fputc('\n', outfile);
        else
            fputc(text->text[index], outfile);
    }
}

void readStrsFromFile(text_t * text)
{
    fseek(text->textfile, 0, SEEK_END);
    text->textlen = (size_t) ftell(text->textfile) + 1;
    fseek(text->textfile, 0, SEEK_SET);

    text->text = (char *)calloc(text->textlen + 1, sizeof(char)) + 1;
    text->textlen = fread(text->text, sizeof(char), text->textlen, text->textfile) + 1;
    text->text[text->textlen - 1] = '\0';
}
