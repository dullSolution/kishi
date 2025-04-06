#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Book {
    uint64_t id;
    char name[64];
    char author[64];
    char phhouse[64];
    float price;
}Book;

/**
 * 分配并初始化一个新的Book结构体。
 *
 * @return 新分配的Book指针，使用后需调用book_free释放内存。
 */
Book* book_alloc();

/**
 * 使用指定参数分配并初始化一个新的Book结构体。
 *
 * @param id 书籍的唯一标识符。
 * @param name 书籍名称。
 * @param author 作者姓名。
 * @param phhouse 出版社名称。
 * @param price 书籍价格。
 * @return 新分配的Book指针，使用后需调用book_free释放内存。
 */
Book* book_alloc_with(uint64_t id,const char* name,const char* author,const char* phhouse,float price);

/**
 * 释放Book结构体占用的内存。
 *
 * @param b 需要释放的Book指针。
 */
void book_free(Book* b);

/**
 * 将Book结构体内容打印到标准输出。
 *
 * @param b 需要打印的Book指针。
 */
void book_print(Book* b);

const char* book_header();

bool book_compare(void* b1,void* b2);

int book_fprint(Book* b,FILE* fp);