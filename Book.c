#include "Book.h"
#include <malloc.h>
#include <assert.h>
#include <string.h>

Book* book_alloc() {
    Book* book=calloc(1,sizeof(Book));
    assert(book !=NULL);
    return book;
}

Book* book_alloc_with(uint64_t id,const char* name,const char* author,const char* phhouse,float price){
    Book* book=book_alloc();
    book->id=id;
    strcpy(book->name,name);
    strcpy(book->author,author);
    strcpy(book->phhouse,phhouse);
    book->price=price;
    return book;
}

void book_free(Book* b){
    free(b);
}

int book_fprint(Book* b,FILE* fp){
    return fprintf(fp,"%-10llu%-15s%-15s%-15s%-15f\n",b->id,b->name,b->author,b->phhouse,b->price);
}

void book_print(Book* b){
    // printf("============================================\n");
    // printf("id: %-10llu \n",b->id);
    // printf("name:%-15s\n",b->name);
    // printf("author:%-15s\n",b->author);
    // printf("phhouse:%-15s\n",b->phhouse);
    // printf("price:%f\n",b->price);

    book_fprint(b,stdout);
}

const char* book_header(){
    static char buf[BUFSIZ];
    sprintf(buf,"%-10s%-15s%-15s%-15s%-15s\n","id","name","author","phhouse","price");
    return buf;
}

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