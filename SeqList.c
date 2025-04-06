#include "SeqList.h"
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

/**
 * 创建一个顺序表
 * 为顺序表分配内存并初始化
 * 返回: 指向新创建顺序表的指针
 */
SeqList* SeqList_alloc(){
    SeqList* list=calloc(1,sizeof(SeqList));
    assert(list!=NULL);
    return list;
}

/**
 * 释放顺序表资源
 * 参数 sl: 指向顺序表的指针
 * 释放顺序表的数据区以及顺序表结构本身
 */
void SeqList_free(SeqList* sl){
    if(sl->data){
        free(sl->data);
    }
    free(sl);
}

/**
 * 扩展顺序表容量
 * 参数 sl: 指向顺序表的指针
 * 返回: 成功扩展返回true，否则返回false
 * 当顺序表容量满时，通过此函数扩展容量
 */
static bool SeqList_grow(SeqList* sl){
    if(sl->capacity==0)
        sl->capacity=1;
    data* tmp=realloc(sl->data,sizeof(data)*sl->capacity*2);
    if (!tmp){
        return false;
    }
    sl->capacity*=2;
    sl->data=tmp;
    return true;
}

/**
 * 在顺序表末尾添加元素
 * 参数 sl: 指向顺序表的指针
 * 参数 d: 要添加的数据元素
 * 当顺序表容量满时，调用SeqList_grow函数进行扩展
 */
void SeqList_push(SeqList* sl,data d){
    if(sl->size==sl->capacity&& !SeqList_grow(sl)){
        //满栈
        printf("full");
        abort();
    }
    sl->data[sl->size++]=d;
}

/**
 * 获取顺序表中指定位置的元素
 * 参数 sl: 指向顺序表的指针
 * 参数 index: 元素的索引
 * 返回: 指定索引处的元素
 * 如果顺序表为空或索引越界，返回NULL
 */
data SeqList_at(SeqList* sl,size_t index){
    if(SeqList_empty(sl)){
        return NULL;
    }
    assert(index<sl->size&&index>=0);
    return sl->data[index];
}

/**
 * 获取顺序表的第一个元素
 * 参数 sl: 指向顺序表的指针
 * 返回: 第一个元素
 * 如果顺序表为空，返回NULL
 */
data SeqList_front(SeqList* sl){
    if(SeqList_empty(sl)){
        return NULL;
    }
    return sl->data[0];
}

/**
 * 获取顺序表的最后一个元素
 * 参数 sl: 指向顺序表的指针
 * 返回: 最后一个元素
 * 如果顺序表为空，返回NULL
 */
data SeqList_back(SeqList* sl){
    if(SeqList_empty(sl)){
        return NULL;
    }
    return sl->data[sl->size-1];
}

/**
 * 检查顺序表是否为空
 * 参数 sl: 指向顺序表的指针
 * 返回: 如果顺序表为空返回true，否则返回false
 */
bool SeqList_empty(SeqList* sl){
    return sl->size==0;
}

/**
 * 获取顺序表的元素数量
 * 参数 sl: 指向顺序表的指针
 * 返回: 顺序表的元素数量
 */
size_t SeqList_size(SeqList* sl){
    return sl->size;
}

/**
 * 在顺序表中查找指定元素
 * 参数 sl: 指向顺序表的指针
 * 参数 fc: 比较函数回调
 * 参数 right: 用于比较的参考数据
 * 返回: 找到的元素，如果未找到返回NULL
 * 使用回调函数fc比较元素，找到第一个匹配的元素并返回
 */
data SeqList_find(SeqList* sl,FIND_CALLBACK fc,data right){
    for(size_t i=0;i<sl->size;i++){
        if(fc(sl->data[i],right)){
            return sl->data[i];
        }
    }
    return NULL;
}

/**
 * 从顺序表中移除指定元素
 * 参数 sl: 指向顺序表的指针
 * 参数 v: 要移除的元素
 * 返回: 成功移除返回true，否则返回false
 * 移除第一个找到的匹配元素，然后将后续元素前移以填充空位
 */
bool SeqList_remove(SeqList* sl,data v){
    for(size_t i=0;i < sl->size; i++){
        if(sl->data[i]==v){
            for(size_t k = i;k < sl->size-1; k++){
                sl->data[k]=sl->data[k+1];
            }
            sl->size--;
            return true;
        }
    }
    return false;
}