#include <stdio.h>
#include "bookmanager.h"



// 主函数，程序的入口点
int main(int argc, char **argv[]) {
    // 分配一个 BookManager 实例
    BookManager* bm = bookManager_alloc();
    
    // 运行 BookManager 实例
    bookManager_run(bm);
    
    // 释放 BookManager 实例占用的内存
    bookManager_free(bm);
    // printf("well");
    // 返回 0 表示程序成功结束
    return 0;
}