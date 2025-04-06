#include "Book.h"
#include <malloc.h>
#include <assert.h>
#include <string.h>

/**
 * 动态分配并初始化一本书。
 * 使用calloc分配内存并初始化为0，确保所有字段都被正确初始化。
 * 
 * @return 返回一个初始化的Book结构体指针，如果分配失败则程序终止。
 */
Book* book_alloc() {
    Book* book=calloc(1,sizeof(Book));
    assert(book !=NULL);
    return book;
}

/**
 * 动态分配并初始化一本书，同时设置其属性。
 * 使用book_alloc分配内存并初始化，然后设置id、name、author、phhouse和price。
 * 
 * @param id 书的ID。
 * @param name 书的名称。
 * @param author 书的作者。
 * @param phhouse 书的出版社。
 * @param price 书的价格。
 * @return 返回一个初始化并设置好属性的Book结构体指针。
 */
Book* book_alloc_with(uint64_t id,const char* name,const char* author,const char* phhouse,float price){
    Book* book=book_alloc();
    book->id=id;
    strcpy(book->name,name);
    strcpy(book->author,author);
    strcpy(book->phhouse,phhouse);
    book->price=price;
    return book;
}

/**
 * 释放一本书占用的内存。
 * 
 * @param b 指向要释放的Book结构体的指针。
 */
void book_free(Book* b){
    free(b);
}

/**
 * 将一本书的信息打印到指定的文件流。
 * 
 * @param b 指向要打印的Book结构体的指针。
 * @param fp 文件流指针，表示要打印到的文件。
 * @return 返回fprintf的返回值，表示打印的字符数。
 */
int book_fprint(Book* b,FILE* fp){
    return fprintf(fp,"%-10llu%-15s%-15s%-15s%-15f\n",b->id,b->name,b->author,b->phhouse,b->price);
}

/**
 * 打印一本书的信息到标准输出。
 * 使用book_fprint将一本书的信息打印到stdout。
 * 
 * @param b 指向要打印的Book结构体的指针。
 */
void book_print(Book* b){
    book_fprint(b,stdout);
}

/**
 * 获取书信息的表头。
 * 用于生成一个包含id、name、author、phhouse和price字段的表头字符串。
 * 
 * @return 返回一个静态字符数组，包含格式化的表头信息。
 */
const char* book_header(){
    static char buf[BUFSIZ];
    sprintf(buf,"%-10s%-15s%-15s%-15s%-15s\n","id","name","author","phhouse","price");
    return buf;
}

/**
 * 比较两本书是否相同。
 * 通过比较id、name、author和phhouse来判断两本书是否相同。
 * 
 * @param left 第一本书的指针。
 * @param right 第二本书的指针。
 * @return 如果两本书相同返回true，否则返回false。
 */
bool book_compare(void* left,void* right){
    Book* bleft=(Book*)left;
    Book* bright=(Book*)right;

    if(bleft->id==bright->id ||
        strstr(bleft->name,bright->name)||
        strstr(bleft->author,bright->author)||
        strstr(bleft->phhouse,bright->phhouse)
    ){
        return true;
    }
    
    return false;
}