#ifndef HZHZ_DYNAMIC_ARRAY_H
#define HZHZ_DYNAMIC_ARRAY_H
#include <iostream>
using namespace std;

template <class T>
class DynamicArray {
private:
    T* array;
    int len; //длина массива
    int size; //на сколько элементов массив расчитан - кол-во ячеек
public:
    class IndexOutOfRange{};

    //Создание объекта
    DynamicArray(T* items, int count){
        array = nullptr;
        size = 0;
        len = count;

        Resize(count);
        for (int i = 0; i < count; i++){
            array[i] = items[i];
        }
    }; //создает пустой массив и копирует элементы из переданного массива (получается идентичный по размеру массив)
    explicit DynamicArray(int newSize){
        if (newSize < 0){
            cout << "Size was changed to 0, due to it being <0 \n";
            newSize = 0;}

        array = nullptr;
        size = 0;
        len = 0;
        Resize(newSize);
    }; //создает пустой массив заданой длины
    DynamicArray(DynamicArray<T> const &dynamicArray){
        array = nullptr;
        size = 0;
        len = dynamicArray.len;
        Resize(dynamicArray.size);

        for (int i = 0; i < len; i++){
            array[i] = dynamicArray.array[i];
        }
    }; //создание копии исходного масива
    DynamicArray(){
        array = nullptr;
        len = 0;
        size = 0;
    }; //создание пустого массива

    //Удаление объекта
    ~DynamicArray(){
        delete[] array;
        array = nullptr;
        size = 0;
        len = 0;
    };//деструктор
    void Delete_DynamicArray(){
        delete[] array;
        array = nullptr;
        size = 0;
        len = 0;
    };//операция удаления массива

    //Декомпозиция
    T& Get(int index){
        if (index < 0 || index >= len){throw IndexOutOfRange();}

        return array[index];
    };//возвращает элемент по индексу
    int GetSize(){
        return size;
    }; //возвращает длину массива(кол-во всех ячеек)
    int GetLen(){
    return len;
};//возвращает длину массива (кол-во заполненных ячеек)

    //Операции над параметрами массивов
    void Set(int index, T value){
        if (index < 0 || index>= len){throw IndexOutOfRange();}

        array[index] = value;
    }; //Задает элемент по индексу
    void Resize(int newSize){
        if (newSize < 0){throw IndexOutOfRange();}// неправильный размер массива

        if (newSize == 0){
            delete[] array;
            array = nullptr;
            size = 0;
            len = 0;
            return;
        }// удаление массива

        if (newSize == size){return;}// длина не изменится

        if (newSize < size){
            T *new_array = new T[newSize];
            for (int i = 0; i < newSize; i++){
                new_array[i] = array[i];
            }
            delete[] array;
            size = newSize;
            if (len > newSize){len = newSize;}
            array = new_array;
            return;
        }// укорачивание массива

        if (newSize > 0 && size == 0){
            T *new_array = new T[newSize];
            delete[] array;
            size = newSize;
            array = new_array;
        }//увеличение размера массива 0 длины

        if (newSize > size){
            T *new_array = new T[newSize];
            for (int i = 0; i < len; i++){
                new_array[i] = array[i];
            }
            delete[] array;
            size = newSize;
            array = new_array;
            return;
        }// увеличение длины
    }; //изменяет размерность массива
    void Relen(int newLen){
        if (newLen > size || newLen < 0 || newLen < len){throw IndexOutOfRange();}
        len = newLen;
    }; //Изменяет длину массива

    //Перегрузка операторов
    DynamicArray<T> &operator = (DynamicArray<T> dynamicArray) {
        Resize(dynamicArray.GetSize());
        size = dynamicArray.GetSize();
        len = dynamicArray.GetLen();
        for (int i = 0; i < len; i++){
            array[i] = dynamicArray.array[i];
        }
        return *this;
    }
};

#endif