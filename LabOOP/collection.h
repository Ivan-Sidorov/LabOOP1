#pragma once
#include "motion.h"
#include "action.h"
#include <utility>

class collection {
public:
    collection();
    collection(const collection&); // Конструктор копирования
    ~collection(); // Деструктор
    void add(const action* &obj); // Добавление элемента в начало стека
    bool del(int pos);  // Удаление элемента с позиции
    void del_all(); // Удаление всех элементов
    action* get_head() const; // Получение первого элемента стека
    action* get(int pos); // Получение элемента на позиции
    int get_count() const; // Получение количества элементов
    void print_collection() const;
    void reverse(); // Разворот стека
    std::pair<double, double> coordinates(); // Нахождение координат
    void iter_begin(); // Итератор на начала стека
    void iter_end(); // Итератор на конец стека
    void next(); // Перемещение итератора вперед
    void prev(); // Перемещение итератора назад
    bool emp() const; // Проверка на наличие элементов в стэке
    action* cur() const; // Разыменование значения текущего элемента итератора
    bool eq(const collection &coll) const; // Сравнение на равенство
    struct list_element { // Стек
        action* obj;
        list_element *next;
    };
    //motion get_head_del();// Получение и удаление первого элемента стека
    const list_element &get_first() const; // геттер для first
    void write_data(const char *path) const; // Запись в файл
    bool read_data(const char *path); // Чтение из файла
  private:
    action* top() const;
    list_element* first_ = nullptr;
    list_element* iter_;
    void push(const action* &d); // Добавление элемента на 1 место
    void pop(); // Удаление 1го лемента
};

