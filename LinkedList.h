#ifndef HZHZ_LINKEDLIST_H
#define HZHZ_LINKEDLIST_H
template <class T>
class LinkedList {
private:
    struct element{
        T value;
        struct element* next_element;
    };
    int len = 0;
    struct element* head_element = nullptr;
    struct element* end_element = nullptr;

public:
    class IndexOutOfRange{};

    //Создание объекта
    LinkedList (T* items, int count){
        len = 0;
        head_element = nullptr;
        end_element = nullptr;

        for (int i = 0; i < count; i++){
            Append(items[i]);
        }
    }; //Копирует элементы из переданного списка
    LinkedList (){
        len = 0;
        head_element = nullptr;
        end_element = nullptr;
    }; //Создает пустой список
    LinkedList (const LinkedList <T> & list){
        len = 0;
        head_element = nullptr;
        end_element = nullptr;
        struct element *cell = list.head_element;
        for (int i = 0; i < list.len; i++, cell = cell->next_element){
            Append(cell->value);
        }
    }; //Копирующий конструктор

    //удаление объекта
    ~LinkedList(){
        Delete_LinkedList();
    };//деструктор
    void Delete_LinkedList(){
        struct element* this_cell;
        while(head_element != nullptr){
            this_cell = head_element;
            head_element = head_element->next_element;
            delete this_cell;
        }
        end_element = nullptr;
        len = 0;
    }; //удаление списка

    //декомпозиция
    T GetFirst() {
        if (head_element == nullptr){throw IndexOutOfRange();}

        return head_element->value;
    };//Возвращает первый элемент
    T GetLast(){
        if (end_element == nullptr){throw IndexOutOfRange();}

        return end_element->value;
    };//Возвращает последний элемент
    T& Get(int index){
        if (index < 0 || index >= len){throw IndexOutOfRange();}

        struct element *cell = head_element;
        for (int i = 0; i < index; i++, cell = cell->next_element);

        return cell->value;
    };//Возвращает элемент по индексу
    LinkedList<T> GetSubList(int startIndex, int endIndex){
        if (startIndex >= len || endIndex >= len || startIndex < 0 || endIndex < 0){
            throw IndexOutOfRange();
        }

        LinkedList<T> new_list = LinkedList<T>();
        auto *cell = new struct element;
        cell = head_element;
        for (int i = 0; i < startIndex; i++, cell = cell->next_element);
        for (int i = startIndex; i <= endIndex; i++, cell = cell->next_element){
            new_list.Append(cell->value);
        }

        return new_list;
    };//Возваращет список элементов в исходных пределах
    int GetLength(){
        return len;
    };//Возвращает длину

    //Операции
    void Append(T item){
        auto *new_cell = new struct element;
        new_cell->value = item;
        new_cell->next_element = nullptr;

        if (head_element == nullptr){ //случай, когда список пустой
            head_element = new_cell;
            end_element = new_cell;
            len = 1;
            return;
        }

        end_element->next_element = new_cell;
        end_element = new_cell;
        len++;
    }; //Добавление элемента в конец списка
    void Prepend(T item){
        auto *new_cell = new struct element;
        new_cell->value = item;

        if (head_element == nullptr){
            end_element = new_cell;
        }

        new_cell->next_element = head_element;
        head_element = new_cell;
        len++;
    }; //Добавление элемента в начало списка
    void InsertAt(T item, int index){
        if (index >= len || index < 0){throw IndexOutOfRange();}

        if (index == 0){Append(item); return;}
        else if (index == len - 1){Prepend(item); return;}
        else{
            auto *new_cell = new struct element;
            new_cell->value = item;
            struct element *previous_cell = head_element;
            for (int i = 0; i < index - 1; i++, previous_cell = previous_cell->next_element);
            new_cell->next_element = previous_cell->next_element;
            previous_cell->next_element = new_cell;
            len++;
        }
    }; //Вставка элемента в заданную позицию
    LinkedList<T> Concat(LinkedList<T> *list){
        LinkedList<T> new_list = LinkedList<T>();

        struct element *new_cell = head_element;
        for (int i = 0; i < len; i++, new_cell = new_cell->next_element){
            new_list.Append(new_cell->value);
        }

        new_cell = list->head_element;
        for (int i = 0; i < list->len; i++, new_cell = new_cell->next_element){
            new_list.Append(new_cell->value);
        }

        return new_list;
    }; //Сцепляет два списка

    //Перегрузка операторов
    LinkedList<T> &operator = (LinkedList<T> linkedlist) {
        Delete_LinkedList();

        //head_element = linkedlist.head_element;
        //end_element = linkedlist.end_element;
        //len = linkedlist.GetLength();

        struct element *cell = linkedlist.head_element;
        for (int i = 0; i < linkedlist.len; i++, cell = cell->next_element){
            Append(cell->value);
        }
        return *this;
    }
};


#endif