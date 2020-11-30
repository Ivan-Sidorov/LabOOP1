#include "collection.h"
#include "motion.h"
#include "rotation.h"
#include <iostream>
#include <float.h>
#include <iostream>
#include <fstream>
#include "tests.h"
#include <assert.h>

#include <QRandomGenerator>
#include <QDateTime>
#include <QStringList>

#define MIN_VELOCITY_VALUE 0.
#define MAX_VELOCITY_VALUE 100.
#define MIN_TIME_VALUE 0.
#define MAX_TIME_VALUE 60.

double Random::real_number(double from, double to) {
    return from + (to - from) * QRandomGenerator::global()->generateDouble();
}

void test::assert_validity(const motion &object) {
    assert(object.get_velocity() > MIN_VELOCITY_VALUE);
    assert(object.get_velocity() < MAX_VELOCITY_VALUE);

    assert(object.get_time() > MIN_TIME_VALUE);
    assert(object.get_time() < MAX_TIME_VALUE);
}

void test::assert_stability(motion &object) {
    double value = Random::real_number(MIN_VELOCITY_VALUE, MAX_VELOCITY_VALUE);
    object.set_new_velocity(value);
    assert(object.get_velocity() == value);
    double error = Random::real_number(MAX_VELOCITY_VALUE);
    object.set_new_velocity(error);
    assert(object.get_velocity() != error);
    assert(object.get_velocity() == value);
}

bool test::equal(motion &first, motion &second){
    if(first.get_velocity() == second.get_velocity() && first.get_time() == second.get_time())
        return true;
    else
        return false;
}

void test::assert_full_deletion(collection &q){
    q.del_all();
    assert(q.get_count() == 0);
}

void test::assert_access(collection &q){
    test::display(q);
}

void test::assert_files(collection q, collection q_copy) {
    q_copy.write_data("C:\\Users\\Ivan\\Documents\\C progs\\LabOOP\\commands2.txt");
    q.read_data("C:\\Users\\Ivan\\Documents\\C progs\\LabOOP\\commands2.txt");
    q.reverse();
    assert(q_copy.eq(q));
}

void test::assert_adding(collection &q, const action* &i){
    int bef = q.get_count();
    q.add(i);
    assert(bef != q.get_count());
}

void test::assert_deletion(collection &q, int index){
    assert(q.del(index));

}

void test::skip_spaces(const std::string &str, size_t *i) {
    while (*i < str.size() && str[*i] && str[*i] == ' ') // skip spaces
        (*i)++;
}

void test::display(collection &path) {
//    path.print_collection();
// Вывод всех элементов коллекции
    path.reverse();
    int i = 1;
    path.iter_begin();
    std::cout<<"\nCommands:";
    while(path.cur() != nullptr) {
        std::cout<<"\nElement " << i;
        std::cout<<"\n";
        path.cur()->print_params();
        i++;
        path.next();
    }
    path.reverse();
}

void test::assert_equality(const collection &fir, const collection &sec) {
    assert(fir.eq(sec));
}

void test::assert_copy_constructor(const collection &fir, const collection &sec) {
    assert_equality(fir, sec);
}
