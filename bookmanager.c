#include "bookmanager.h"
#include "Book.h"

#include <strings.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
/**
 * 分配并初始化BookManager对象的内存
 * 
 * 该函数使用calloc分配内存并初始化为0，确保新分配的对象中所有字段都是0或NULL
 * 使用assert确保内存分配成功，如果失败，程序将终止
 * 
 * 返回: 如果分配成功，返回指向新BookManager对象的指针；如果失败，程序将终止
 */
BookManager* bookManager_alloc(){
    BookManager* bm=calloc(1,sizeof(BookManager));

    assert(bm !=NULL);
    bm->books=SeqList_alloc();
    bookManager_load(bm,"books",true);

    return bm;
}

/**
 * 释放BookManager对象的内存
 * 
 * 该函数接受一个指向BookManager对象的指针，并释放其占用的内存
 * 
 * 参数 bm: 指向要释放的BookManager对象的指针
 */
void bookManager_free(BookManager* bm){
    if(bm->books){
        SeqList_free(bm->books);
    }
    free(bm);
}

enum MenuOptions{
    Quit,
    Add,
    Print,
    Find,
    Alter,
    Remove
    
};

/**
 * 运行BookManager的主循环
 * 
 * 该函数设置BookManager的运行状态为true，并进入一个while循环
 * 在循环中执行书目管理的相关操作当isRunning标志被设置为false时，循环结束
 * 
 * 参数 bm: 指向BookManager对象的指针，其主循环将被执行
 */
void bookManager_run(BookManager* bm){
    bm->isRunning=true;
    while (bm->isRunning)
    {
        // 主循环的具体操作留空，等待后续填充
        switch(bookManager_menu()){
            case Quit:
                bookManager_quit(bm);
                break;
            case Add:
                bookManager_add(bm);
                break;
            case Print:
                bookManager_print(bm);
                break;
            case Find:
                bookManager_find(bm);
                break;
            case Alter:
                bookManager_alter(bm);
                break;
            case Remove:
                bookManager_remove(bm);
                break;
            default:
                break;
    
        };
        system("pause");
        system("cls");
        // bm->isRunning=false;
    }
    
}

/**
 * 显示BookManager的菜单
 * 
 * 该函数用于显示书目管理系统的菜单，指导用户进行操作
 * 目前该函数的实现留空，等待后续根据具体需求进行实现
 */
int bookManager_menu(){
    printf("=============================================\n");
    printf("\t welcome to BookManager \t\n");
    printf("=============================================\n");
    printf("\t options:\n");
    printf("=============================================\n");
    printf("\t 1. add book\n");
    // printf("=============================================\n");
    printf("\t 2. show book\n");
    // printf("=============================================\n");
    printf("\t 5. delete book\n");
    // printf("=============================================\n");
    printf("\t 3. search book\n");
    // printf("=============================================\n");
    printf("\t 4. modify book\n");
    // printf("=============================================\n");
    printf("\t 0. exit\n");
    printf("=============================================\n");
    printf("\t please input your choice: ");
    int options=-1;
    scanf("%d",&options);
    while(getchar()!='\n');
    return options;
}

void bookManager_add(BookManager* bm){
    Book* b=book_alloc();
    printf("============================================\n");
    printf("input book id name author phhouse price: ");
    scanf("%lu %s %s %s %f",&b->id,b->name,b->author,b->phhouse,&b->price);


    SeqList_push(bm->books,b);    
    // book_print(b);
    // printf("add book\n");
    // book_free(b);
}

void bookManager_print(BookManager* bm){
    // printf("print book\n");
    puts(book_header());
    for (size_t i = 0; i < SeqList_size(bm->books); i++)
    {
        Book* book=SeqList_at(bm->books,i);
        book_print(book);
    }
}
void bookManager_find(BookManager* bm){
    printf("input the name or author of the searched book: ");
    char keyword[128];
    // gets_s(keyword,128);
    if(fgets(keyword,128,stdin)!=NULL){
        size_t len=strlen(keyword);
        if (len>0&&keyword[len-1]=='\n'){
            keyword[len-1]='\0';
        }
    }
    bool isFind=false;
    Book* fb =NULL;

    uint64_t id;
    sscanf(keyword,"%llu",&id);
    for (size_t i=0;i<SeqList_size(bm->books);i++){
        Book* book=SeqList_at(bm->books,i);
        if( id==book->id ||
            strstr(book->name,keyword) ||
            strstr(book->author,keyword) ||
            strstr(book->phhouse,keyword)
        ){
            fb=book;
            isFind=true;
        }
    }
    if(isFind)
        book_print(fb);

}
// void bookManager_remove(BookManager* bm){
//     printf("input the name or author of the searched book: ");
//     char keyword[128];

//     if(fgets(keyword,128,stdin)!=NULL){
//         size_t len=strlen(keyword);
//         if (len>0&&keyword[len-1]=='\n'){
//             keyword[len-1]='\0';
//         }
//     }
//     bool isFind=false;
//     Book* fb =NULL;

//     uint64_t id;
//     sscanf(keyword,"%llu",&id);
//     for (size_t i=0;i<SeqList_size(bm->books);i++){
//         Book* book=SeqList_at(bm->books,i);
//         if( id==book->id ||
//             strstr(book->name,keyword) ||
//             strstr(book->author,keyword) ||
//             strstr(book->phhouse,keyword)
//         ){
//             fb=book;
//             isFind=true;
//         }
//     }
//     if(isFind){
//         book_print(fb);
//         printf("cofirm to delete? y/n");
//         char s;
//         scanf("%c",&s);
//         if(toupper(s)=='Y'){
//             SeqList_remove(bm->books,fb);
//         }
//     }else{
//         printf("not found:%s\n",keyword);
//     }
// }
void bookManager_remove(BookManager* bm){
    printf("input the name or author of the searched book: ");
    Book b;
    char keyword[128];
    if(fgets(keyword,128,stdin)!=NULL){
        size_t len=strlen(keyword);
        if (len>0&&keyword[len-1]=='\n'){
            keyword[len-1]='\0';
        }

    }
    strcpy(b.name,keyword);
    strcpy(b.author,b.name);
    strcpy(b.phhouse,b.name);
    sscanf(b.name,"%llu",&b.id);

    Book * book=SeqList_find(bm->books,book_compare,&b);

    if(book){
        book_print(book);
        printf("cofirm to delete? y/n");
        char s;
        scanf("%c",&s);
        if(toupper(s)=='Y'){
            SeqList_remove(bm->books,book);
        }    
    }
    else
        printf("not found:%s\n",keyword);    
}

void bookManager_alter(BookManager* bm){
    printf("input the id of your wanted book: ");
    Book b;
    scanf("%llu",&b.id);
    Book* book=SeqList_find(bm->books,book_compare,&b.id);
    if(!book){
        printf("not found:%llu\n",b.id);
        return;
    }
    book_print(book);
    printf("input the new price of your wanted book: ");
    if(1==scanf("%f",&book->price)){
        printf("alter success\n");
        // book_print(book);
    }else{
        printf("alter failed\n");
    }
}
void bookManager_quit(BookManager* bm){
    bookManager_save(bm,"books",true);
    bm->isRunning=false;
}

bool bookManager_load(BookManager* bm,const char* filename,bool isBin){
    if(!filename || filename[0]=='\0')
        return false;
    
    char newFileName[128];
    strcpy(newFileName,filename);
    char* p=strrchr(filename,'.');
    if(!p){
        p=newFileName+strlen(newFileName);
    }
    
    if(isBin){
        strcpy(p,".data");
    }else{
        strcpy(p,".txt");
    }

    FILE* fp=fopen(newFileName,"rb");
    if(!fp){
        return false;
    }
    if(isBin){
        while(!feof(fp)){
            Book* b=book_alloc();
            if(1 != fread(b,sizeof(Book),1,fp)){
                book_free(b);
                fclose(fp);
                break;
            }
            else{
                SeqList_push(bm->books,b);
            }
        }
    }
    else{
        while(!feof(fp)){
        
            Book* b=book_alloc();
            if(fscanf(fp,"%lu %s %s %s %f\n",&b->id,b->name,b->author,b->phhouse,&b->price)!=5){
                book_free(b);
                fclose(fp);
                break;
            }else{
                SeqList_push(bm->books,b);
            }
        }
    }
    fclose(fp);
    return true;
}
bool bookManager_save(BookManager* bm,const char* filename,bool isBin){
    if(!filename || filename[0]=='\0')
        return false;
    char newFileName[128];
    strcpy(newFileName,filename);
    char* p=strrchr(filename,'.');
    if(!p){
        p=newFileName+strlen(newFileName);
    }
    
    if(isBin){
        strcpy(p,".data");
    }else{
        strcpy(p,".txt");
    }
    printf("save to %s\n",newFileName);
    FILE* fp=fopen(newFileName,"wb");
    if(!fp){
        return false;
    }
    if(isBin){
        for (int i= 0;i< SeqList_size(bm->books); i++){
            if(1 != fwrite(SeqList_at(bm->books,i),sizeof(Book),1,fp)){
                // fclose(fp);
                // printf("save failed");
                return false;
            }
        }
    }else{
        for(int i=0;i<SeqList_size(bm->books);i++){
            Book* book=SeqList_at(bm->books,i);
            if(book_fprint(book,fp) == 0){
                book_free(book);
                // printf("save failed");
                break;
            }
        }
    }
    fclose(fp);
    return true;
}