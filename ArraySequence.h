#ifndef HZHZ_ARRAYSEQUENCE_H
#define HZHZ_ARRAYSEQUENCE_H
#include "Sequence.h"
#include "DynamicArray.h"

template <class T>
class ArraySequence : Sequence<T>{
private:
    DynamicArray<T> dynamicArray;
public:
    class IndexOutOfRange : DynamicArray<T> :: IndexOutOfRange{};

    //Создание объекта
    ArraySequence (T* items, int count){
        dynamicArray = DynamicArray<T>(items, count);
    }//Создает последовательность с элементами из исходного массива
    ArraySequence (){
        dynamicArray = DynamicArray<T>(0);
    }//Создает пустую последовательность
    explicit ArraySequence (const DynamicArray<T> & dynamicArray){
        dynamicArray = DynamicArray<T>(dynamicArray);
    }//Копирующий конструктор

    //Удаление объекта
    ~ArraySequence(){
        dynamicArray.Delete_DynamicArray();
    }//деструктор
    void Delete_ArraySequence(){
        dynamicArray.Delete_DynamicArray();
    }//функция удаления послдовательности

    //Декомпозиция
    T GetFirst(){
        return dynamicArray.Get(0);
    }//Возвращает первый элемент
    T GetLast(){
        return dynamicArray.Get(dynamicArray.GetLen() - 1);
    }//Возвращает последний элемент
    T& Get(int index){
        return dynamicArray.Get(index);
    }//Возвращает элемент по индексу
    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex){
        if (startIndex >= dynamicArray.GetLen() || endIndex >= dynamicArray.GetLen() || startIndex < 0 || endIndex < 0){
            throw IndexOutOfRange();
        }

        auto *new_arraySequence = new ArraySequence<T>;
//        new_arraySequence = ArraySequence<T>();
        int iter;
        if (startIndex < endIndex){
            iter = 1;
        }else{
            iter = -1;
        }

        for (int i = startIndex; i != endIndex; i += iter){
            new_arraySequence->Append(dynamicArray.Get(i));
        }

        return new_arraySequence;
    }//Получить список из всех элементов, начиная с startIndex и заканчивая endIndex
    int GetLength(){
        return dynamicArray.GetLen();
    }//Возвращает длину последовательности

    //Операции
    void Append(T item){
        int free_cells = dynamicArray.GetSize() - dynamicArray.GetLen();
        if (free_cells == 0){
            dynamicArray.Resize(dynamicArray.GetSize() + 200);
        }
        dynamicArray.Relen(dynamicArray.GetLen() + 1);
        dynamicArray.Set(dynamicArray.GetLen() - 1, item);
    }//дабавляет элемент в конец последовательности(при необходимости выделяет доп. ячейки)
    void Prepend(T item){
        dynamicArray.Resize(dynamicArray.GetLen() + 1);
        dynamicArray.Relen(dynamicArray.GetLen() + 1);
        T saved_cell = dynamicArray.Get(0);
        T this_cell;
        dynamicArray.Set(0, item);

        for(int i = 1; i < dynamicArray.GetLen(); i++){
            this_cell = dynamicArray.Get(i);
            dynamicArray.Set(i, saved_cell);
            saved_cell = this_cell;
        }
    }//Добавляет элемент в начало строки
    void InsertAt(T item, int index){
        if (index < 0 || index >= this->GetLength()){throw IndexOutOfRange();}

        dynamicArray.Resize(dynamicArray.GetLen() + 1);
        dynamicArray.Relen(dynamicArray.GetLen() + 1);
        T this_cell;
        T saved_cell = dynamicArray.Get(index);
        dynamicArray.Set(index, item);
        for (int i = index + 1; i < dynamicArray.GetLen(); i++){
            this_cell = dynamicArray.Get(i);
            dynamicArray.Set(i, saved_cell);
            saved_cell = this_cell;
        }
    }//Вставляет элемент по заданному индексу
    ArraySequence<T>* Concat(Sequence<T> *list){
        auto *new_arraySequence = new ArraySequence<T>;
        //new_arraySequence = ArraySequence<T>();

        for (int i = 0; i < dynamicArray.GetLen(); i++){
            new_arraySequence->Append(dynamicArray.Get(i));
        }
        for (int i = 0; i < list->GetLength(); i++){
            new_arraySequence->Append(list->Get(i));
        }

        return new_arraySequence;
    }//Сцепляет две последовательности

    //Перегрузка операторов
    ArraySequence<T> &operator = (ArraySequence<T> n_dynamicArray){
        dynamicArray = n_dynamicArray.dynamicArray;
        return *this;
    }
};

#endif