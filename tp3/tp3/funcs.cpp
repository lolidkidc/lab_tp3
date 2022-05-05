#include "funcs.hpp"
#include <iostream>

using namespace std;

void showall(Figure**& arr, int cnt) {
    for ( int i = 0; i < cnt; i++ ){
        cout << i + 1 << ": ";
        arr[i]->show();
    }
}

void add(Figure**& arr, int cnt, float a, float b) {
    Figure** buff = new Figure*[cnt+1];
    for ( int i = 0; i < cnt; i++ ){
        buff[i] = arr[i];
    }
    buff[cnt] = new Rectangle(a , b);
    delete[] arr;
    arr = buff;
}

void add(Figure**& arr, int cnt, float r) {
    Figure** buff = new Figure*[cnt+1];
    for (int i = 0; i < cnt; i++){
        buff[i] = arr[i];
    }
    buff[cnt] = new Circle(r);
    delete[] arr;
    arr = buff;
}

void addtr(Figure**& arr, int cnt, float a, float b) {
    Figure** buff = new Figure*[cnt+1];
    for (int i = 0; i < cnt; i++){
        buff[i] = arr[i];
    }
    buff[cnt] = new Triangle(a, b);
    delete [] arr;
    arr = buff;
}

void add(Figure**& arr, int cnt, float a, float b, float h) {
    Figure** buff = new Figure*[cnt+1];
    for (int i = 0; i < cnt; i++ ){
        buff[i] = arr[i];
    }
    buff[cnt] = new Trapezoid(a, b, h);
    delete [] arr;
    arr = buff;
}

void del(Figure**& arr, int cnt, int id) {
    Figure** buff = new Figure*[cnt-1];
    int j = 0;
    for (int i = 0; i < cnt; i++ ){
        if ( i == id )
            continue;
        buff[j] = arr[i];
        j++;
    }
    delete [] arr;
    arr = buff;
}

void swap(Figure**& arr, int cnt, int id) {
    arr[id]->edit();
}
