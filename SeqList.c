#include "SeqList.h"
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

SeqList* SeqList_alloc(){
    SeqList* list=calloc(1,sizeof(SeqList));
    assert(list!=NULL);
    return list;
}

void SeqList_free(SeqList* sl){
    if(sl->data){
        free(sl->data);
    }
    free(sl);
}
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
void SeqList_push(SeqList* sl,data d){
    if(sl->size==sl->capacity&& !SeqList_grow(sl)){
        //满栈
        printf("full");
        abort();
    }
    sl->data[sl->size++]=d;
}

data SeqList_at(SeqList* sl,size_t index){
    if(SeqList_empty(sl)){
        return NULL;
    }
    assert(index<sl->size&&index>=0);
    return sl->data[index];
}
data SeqList_front(SeqList* sl){
    if(SeqList_empty(sl)){
        return NULL;
    }
    return sl->data[0];
}
data SeqList_back(SeqList* sl){
    if(SeqList_empty(sl)){
        return NULL;
    }
    return sl->data[sl->size-1];
}

bool SeqList_empty(SeqList* sl){
    return sl->size==0;
}

size_t SeqList_size(SeqList* sl){
    return sl->size;
}

data SeqList_find(SeqList* sl,FIND_CALLBACK fc,data right){
    for(size_t i=0;i<sl->size;i++){
        if(fc(sl->data[i],right)){
            return sl->data[i];
        }
    }
    return NULL;

}

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