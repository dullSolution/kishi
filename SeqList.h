#pragma once
#include <stdio.h>
#include <stdbool.h>
typedef void* data;

typedef struct SeqList {
    data* data;
    size_t size;
    size_t capacity;
} SeqList;

SeqList* SeqList_alloc();

void SeqList_free(SeqList* sl);

void SeqList_push(SeqList* sl,data d);

data SeqList_at(SeqList* sl,size_t index);
data SeqList_front(SeqList* sl);
data SeqList_back(SeqList* sl);
bool SeqList_empty(SeqList* sl);
size_t SeqList_size(SeqList* sl);
typedef bool (*FIND_CALLBACK)(data left,data right);
data SeqList_find(SeqList* sl,FIND_CALLBACK fc,data right);
bool SeqList_remove(SeqList* sl,data v);