#ifndef MYSTORAGE_H
#define MYSTORAGE_H
#include "ccircle.h"
#include <vector>

class MyStorage
{
private:
    std::vector<CCircle*> objects;
public:
    MyStorage();
    ~MyStorage();

    void add(CCircle* obj);
    int getCount() const;
    CCircle* getObject(int index);
    void deleteSelected();
};
#endif // MYSTORAGE_H
