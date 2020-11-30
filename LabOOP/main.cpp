#include <iostream>
#include "motion.h"
#include "rotation.h"
#include "action.h"
#include "collection.h"
#include "tests.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

/*
Test::assert_validity(default_object);
for (int i = 0; i < 1; i++) {
    motion random_object(Random::real_number(MIN_VELOCITY_VALUE,
                                          MAX_VELOCITY_VALUE),
                        Random::real_number(MIN_TIME_VALUE,
                                          MAX_TIME_VALUE));
    Test::assert_validity(random_object);
    motion copy_object(random_object);
    //copy_object.print_params();
    Test::assert_validity(copy_object);
    Test::assert_equality(random_object, copy_object);
    Test::assert_stability(copy_object);
    Test::assert_validity(copy_object);
}
std::cout << "\nAll tests completed\n";
*/
