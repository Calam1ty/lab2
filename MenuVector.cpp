#include "MenuVector.h"
#include "DynamicArray.h"

int chooseType(){
    int type;
    cout << "Choose data type: \n"
         << "\t1: int\n"
         << "\t2: float\n"
         << "\t3: complex\n"
         << "Input: ";
    cin >> type;

    return type;
}

int chooseFunction(){
    int func;
    cout << "Choose whatever you want to do with vectors: \n"
         << "\t1: Sum vectors\n"
         << "\t2: Subtract one vector from another\n"
         << "\t3: Norm a vector\n"
         << "\t4: Scalar multiplication of vectors\n"
         << "Input: ";
    cin >> func;

    return func;
}
template<class T>
void saveVector(ArraySequence<Vector<T>> *Arr, Vector<T> *n_vector){
    Arr->Append(n_vector);
}

template<class T>
void outputTypedVector(ArraySequence<Vector<T>> *Arr) {
    int len = Arr->GetLength();
    for (int i = 0; i < len; i++) {
        auto k = Arr->Get(i);
        cout << i << ": " << k << endl;
    }
}

void menuVector(){
    auto *intArr = new ArraySequence<Vector<int>>;
    auto *floatArr = new ArraySequence<Vector<float>>;
    auto *complexArr = new ArraySequence<Vector<complex<int>>>;

    int oper;
    while(true){
        cout << "Choose an operation: \n"
             << "\t1: Input and save a vector \n"
             << "\t2: Perform an operation on vectors\n"
             << "\t3: Show vectors\n"
             << "\t4: Exit program\n"
             << "Input: ";
        cin >> oper;

        if (oper == 4)
            break;

        switch(oper){
            case 1: inputAndSaveVector(intArr, floatArr, complexArr); break;
            case 2: functionWithVector(intArr, floatArr, complexArr); break;
            case 3: outputVector(intArr, floatArr, complexArr); break;
            default: break;
        }
    }
}

void inputAndSaveVector(ArraySequence<Vector<int>> *intArr,
                        ArraySequence<Vector<float>> *floatArr,
                        ArraySequence<Vector<complex<int>>> *complexArr){

    int type = chooseType();
    int count;
    cout << "Input vector's length:";
    cin >> count;

    switch(type){
        case 1: inputVectorTyped(intArr, count); break;
        case 2: inputVectorTyped(floatArr, count); break;
        case 3: inputVectorTyped(complexArr, count); break;
        default: break;
    }
}

template<class T>
void inputVectorTyped(ArraySequence<Vector<T>> *Arr, int count){
    cout << "Input vector coordinates: ";
    ArraySequence<T> n_arr;
    T item;
    for (int i = 0; i < count; i++){
        cin >> item;
        n_arr.Append(item);
    }
    Vector<T> n_vector(n_arr);
    Arr->Append(n_vector);
}

void functionWithVector(ArraySequence<Vector<int>> *intArr,
                        ArraySequence<Vector<float>> *floatArr,
                        ArraySequence<Vector<complex<int>>> *complexArr){

    int type = chooseType();

    switch(type){
        case 1: functionVectorTyped(intArr); break;
        case 2: functionVectorTyped(floatArr); break;
        case 3: functionVectorTyped(complexArr); break;
        default: break;
    }
}

template<class T>
void functionVectorTyped(ArraySequence<Vector<T>> *Arr){
    int func = chooseFunction();
    int len = Arr->GetLength();
    int indexOfArr1 = -1;
    int indexOfArr2 = -1;

    if (func == 3 || func == 4){
        if (len==1){
            cout << "There is only "<< len << " vector stored in memory" << endl;}
        else{
        cout << "There are "<< len << " vectors stored in memory" << endl;
        }
        cout << "Input the index of the vector you want to work with:";
        cin >> indexOfArr1;
        if (indexOfArr1 >= len || indexOfArr1 < 0){
            cout << "The vector with this index doesnt exist" << endl;
            func = -1;
        }
    }else{
        if (len==1){
            cout << "There is only "<< len << " vector stored in memory" << endl;}
        else{
            cout << "There are "<< len << " vectors stored in memory" << endl;
        }
        cout << "Input the index of the vector you want to work with:";
        cin >> indexOfArr1;
        cin >> indexOfArr2;
        if (indexOfArr1 >= len || indexOfArr1 < 0 || indexOfArr2 >= len || indexOfArr2 < 0){
            cout << "The vector with this index doesnt exist" << endl;
            func = -1;
        }
    }

    T scalar;
    switch(func){
        default:
            break;
        case 1:
            Arr->Append(Arr->Get(indexOfArr1).SumOfVectors(Arr->Get(indexOfArr2)));
            break;
        case 2:
            Arr->Append(Arr->Get(indexOfArr1).SubOfVectors(Arr->Get(indexOfArr2)));
            break;
        case 3:
            cout << "Input the scalar by which you will multiply :";
            cin >> scalar;
            Arr->Append(Arr->Get(indexOfArr1).MulOfVectors(scalar));
            break;
        case 4:
            Arr->Append(Arr->Get(indexOfArr1).Normalization());
            break;
        case 5:
            T result;
            result = Arr->Get(indexOfArr1).ScalarMulOfVectors(Arr->Get(indexOfArr2));
            cout <<"Multiplication results:" << result << endl;
            break;
    }//результат записывается в последнюю ячейку памяти массива

    if (func != 5){
        Vector<T> resultVector (Arr->Get(Arr->GetLength() - 1));
        cout << resultVector << endl;
    }
}

void outputVector(ArraySequence<Vector<int>> *intArr,
                  ArraySequence<Vector<float>> *floatArr,
                  ArraySequence<Vector<complex<int>>> *complexArr){

    int type = chooseType();

    cout << "Here are your vectors. They are printed like this: 'index: {vector}' \n";


    switch (type){
        case 1: outputTypedVector(intArr); break;
        case 2: outputTypedVector(floatArr); break;
        case 3: outputTypedVector(complexArr); break;
        default: break;
    }

}

