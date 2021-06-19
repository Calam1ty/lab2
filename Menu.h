#ifndef HZHZ_MENU_H
#define HZHZ_MENU_H
#include <iostream>
#include "Vector.h"
#include <complex>

using namespace std;

int chooseType();
int chooseFunction();
template<class T>
void saveVector(ArraySequence<Vector<T>> *Arr, Vector<T> *n_vector);

void menu();
//1
void inputAndSaveVector(ArraySequence<Vector<int>> *intArr,
                        ArraySequence<Vector<float>> *floatArr,
                        ArraySequence<Vector<complex<int>>> *complexArr);
template <class T>
void inputVectorTyped(ArraySequence<Vector<T>> *Arr, int count);
//2
void functionWithVector(ArraySequence<Vector<int>> *intArr,
                         ArraySequence<Vector<float>> *floatArr,
                         ArraySequence<Vector<complex<int>>> *complexArr);
template<class T>
void functionVectorTyped(ArraySequence<Vector<T>> *Arr);

//3
void outputVector(ArraySequence<Vector<int>> *intArr,
                  ArraySequence<Vector<float>> *floatArr,
                  ArraySequence<Vector<complex<int>>> *complexArr);

template<class T>
void outputTypedVector(ArraySequence<Vector<T>> *Arr, int index);












#endif //LABORATORY_WORK_2_MENU_H
