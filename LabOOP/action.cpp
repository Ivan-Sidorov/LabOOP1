#include "action.h"
#include "tests.h"
#include "sstream"


double action::get_min_time() {
    return 0.;
}

double action::get_max_time() {
    return 60.;
}

action::action() {
    this->set_time(1.);
}

void action::set_time(double t) {
    if (t > this->get_min_time() && t <= this->get_max_time())
        this->time_ = t;
}

const double &action::get_time() const {
    return this->time_;
}

void action::read_data(const std::string &str) {
    size_t attrAmount = 1;
    size_t i = 0;
    std::string attrs[attrAmount];
    std::istringstream f(str);
    std::string s;
    while (getline(f, s, ' ')) {
        //std::cout << s << std::endl;
        attrs[i] = s;
        i++;
    }
    set_time(std::atof(attrs[0].c_str()));
    print_params();
}
