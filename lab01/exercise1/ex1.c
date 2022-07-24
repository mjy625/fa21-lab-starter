#include <string.h>
#include "ex1.h"

/* Returns the number of times LETTER appears in STR.
There are two different ways to iterate through a string.
1st way hint: strlen() may be useful
2nd way hint: all strings end in a null terminator */
int num_occurrences(char *str, char letter) {
    char* p=str;
    int cnt=0;
    while(*p){
        if(*p==letter)++cnt;
        ++p;
    }
    /* TODO: implement num_occurances */
    return cnt;
}

/* Populates DNA_SEQ with the number of times each nucleotide appears.
Each sequence will end with a NULL terminator and will have up to 20 nucleotides.
All letters will be upper case. */
void compute_nucleotide_occurrences(DNA_sequence *dna_seq) {
    /* TODO: implement compute_nucleotide_occurances */
    char*p=dna_seq->sequence;
    dna_seq->A_count=dna_seq->C_count=dna_seq->G_count=dna_seq->T_count=0;
    while (*p)
    {
        switch (*p)
        {
        case 'A':
            dna_seq->A_count++;
            break;
        case 'C':
            dna_seq->C_count++;
            break;
        case 'G':
            dna_seq->G_count++;
            break;
        case 'T':
            dna_seq->T_count++;
            break;
        }
        ++p;
    }
    
    return;
}
