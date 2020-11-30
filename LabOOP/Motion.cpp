#include "motion.h"
#include <iostream>
#include "tests.h"
#include <sstream>


double motion::get_min_velocity() {
    return 0.;
}

double motion::get_max_velocity() {
    return 100.;
}


motion::motion() {
    this->velocity_ = 1.;
    this->set_time(1.);
    //print_params();
}

motion::motion(const motion &motion) {
    this->velocity_ = motion.velocity_;
    this->set_time(motion.get_time());
    //print_params();
}

motion::motion(double n_v, double t) {
    this->set_new_velocity(n_v);
    this->set_time(t);
    //print_params();
}

void motion::set_new_velocity(double n_v) {
    if (n_v > this->get_min_velocity() && n_v <= this->get_max_velocity())
            this->velocity_ = n_v;
}


const double &motion::get_velocity() const {
    return this->velocity_;
}


QString motion::print_params() const {
    QString commands = "";
    std::cout << "Velocity: " << velocity_ << " ";
    commands = "Velocity: " + QString::number(velocity_) + " ";
    std::cout << "Time: " << this->get_time() << std::endl;
    commands += "Time: " + QString::number(this->get_time()) + "\n";
    return commands;
}

void motion::read_data(const std::string &str) {
    size_t attrAmount = 2;
    size_t i = 0;
    std::string attrs[attrAmount];
    std::istringstream f(str);
    std::string s;
    while (getline(f, s, ' ')) {
        //std::cout << s << std::endl;
        attrs[i] = s;
        i++;
    }
    set_new_velocity(std::atof(attrs[0].c_str()));
    set_time(std::atof(attrs[1].c_str()));
    print_params();
}
