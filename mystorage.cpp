#include "mystorage.h"

MyStorage::MyStorage(){}

MyStorage::~MyStorage(){
    for(CCircle *obj: objects){
        delete obj;
    }
    objects.clear();
}

void MyStorage::add(CCircle* obj){
    objects.push_back(obj);
}

int MyStorage::getCount()const{
    return objects.size();
}

CCircle* MyStorage::getObject(int index){
    return objects[index];
}

void MyStorage:: deleteSelected(){
    for(int i = objects.size() - 1; i >= 0; i--){
        if (objects[i]->isSelected()){
            delete objects[i];
            objects.erase(objects.begin() + i);
        }
    }
}

