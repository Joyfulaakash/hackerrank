#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
typedef struct document doc_t;
typedef struct paragraph par_t;
typedef struct sentence sen_t;
typedef struct word wrd_t;

par_t *addpar(doc_t *doc) {
    doc->data = realloc(
        doc->data,
        ++doc->paragraph_count * sizeof(par_t)
    );
    par_t *ptr = doc->data + (doc->paragraph_count - 1);
    ptr->data = NULL;
    ptr->sentence_count = 0;
    return ptr;
}

sen_t *addsen(par_t *par) {
    par->data = realloc(
        par->data,
        ++par->sentence_count * sizeof(sen_t)
    );
    sen_t *ptr = par->data + (par->sentence_count - 1);
    ptr->data = NULL;
    ptr->word_count = 0;
    return ptr;
}

void addword(sen_t *sen, const char *buff, int len) {
    sen->data = realloc(
        sen->data,
        ++sen->word_count * sizeof(wrd_t)
    );
    char *ptr = sen->data[sen->word_count - 1].data =
        malloc(len * sizeof(char));
    strcpy(ptr, buff);
}

doc_t get_document(char* text) {
    doc_t doc = {NULL, 0};
    par_t *cur_par = addpar(&doc);
    sen_t *cur_sen = addsen(cur_par);

    char buff[MAX_CHARACTERS];
    int p = 0;

    for (char *c = text; *c != '\0'; ++c) {
        switch (*c) {
        case ' ':
            buff[p++] = '\0';
            addword(cur_sen, buff, p);
            p = 0;
            break;
        case '.':
            buff[p++] = '\0';
            addword(cur_sen, buff, p);
            p = 0;
            if (*(c + 1) && *(c + 1) != '\n')
                cur_sen = addsen(cur_par);
            break;
        case '\n':
            cur_par = addpar(&doc);
            cur_sen = addsen(cur_par);
            break;
        default:
            buff[p++] = *c;
            break;
        }
    }

    return doc;
}

wrd_t kth_word_in_mth_sentence_of_nth_paragraph(doc_t Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

sen_t kth_sentence_in_mth_paragraph(doc_t Doc, int k, int m) { 
    return Doc.data[m - 1].data[k - 1];
}

par_t kth_paragraph(doc_t Doc, int k) {
    return Doc.data[k - 1];
}


