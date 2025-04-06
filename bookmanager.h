#pragma once
#include "SeqList.h"
#include <stdbool.h>



typedef struct BookManager {
    bool isRunning;
    SeqList* books;
} BookManager;

BookManager* bookManager_alloc();
void bookManager_add(BookManager* bm);
void bookManager_print(BookManager* bm);
void bookManager_find(BookManager* bm);
void bookManager_remove(BookManager* bm);
void bookManager_alter(BookManager* bm);
void bookManager_quit(BookManager* bm);
void bookManager_free(BookManager* bm);

void bookManager_run(BookManager* bm);
int bookManager_menu();

bool bookManager_load(BookManager* bm,const char* filename,bool isBin);
bool bookManager_save(BookManager* bm,const char* filename,bool isBin);