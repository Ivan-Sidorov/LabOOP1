#include <motion.h>
#include <iostream>
#include "collection.h"

#include <float.h>
#include <QRandomGenerator>
#include <QDateTime>
#include <QStringList>


namespace test {

    void assert_validity(const motion &object);
    void assert_stability(motion &object);
    bool equal(motion &first, motion &second);

    void assert_copy_constructor(const collection &fir, const collection &sec);
    void assert_equality(const collection &fir, const collection &sec);
    void assert_full_deletion(collection &q);
    void assert_access(collection &q);
    void assert_files(collection q, collection q_copy);
    void assert_adding(collection &q, const action* &i);
    void assert_deletion(collection &q, int index);
    void skip_spaces(const std::string &str, size_t *i);
    void display(collection &path);


}

namespace Random {

    double real_number(double from = -DBL_MAX/2, double to = DBL_MAX/2);

}

int display(collection &q);

