#include "rotation.h"
#include <iostream>
#include "tests.h"
#include "sstream"

double rotation::get_min_radius() {
    return 0.;
}

double rotation::get_max_radius() {
    return 180.;
}

rotation::rotation() {
    this->radius_ = 1.;
    this->set_time(1.);
    this->direction_ = 0;
    //print_params();
}

rotation::rotation(const rotation &rotation) {
    this->set_time(rotation.get_time());
    this->radius_ = rotation.get_radius();
    this->direction_ = rotation.direction_;
    //print_params();
}

rotation::rotation(double t, double n_r, double n_dir) {
    this->set_time(t);
    this->set_new_radius(n_r);
    this->set_new_direction(n_dir);
    //print_params();
}

void rotation::set_new_radius(double n_r) {
    if (n_r > this->get_min_radius() && n_r <= this->get_max_radius())
        this->radius_ = n_r;
}

void rotation::set_new_direction(bool n_dir) {
    this->direction_ = n_dir;
}

const double &rotation::get_radius() const {
    return this->radius_;
}

const bool &rotation::get_direction() const {
    return this->direction_;
}

QString rotation::print_params() const {
    QString commands = "";
    std::cout << "Radius: " << this->radius_ << " ";
    commands = "Radius: " + QString::number(this->radius_) + " ";
    std::cout << "Direction: " << this->direction_ << " (0 - left, 1 - right) ";
    commands += "Direction: " + QString::number(this->direction_) + " (0 - left, 1 - right) ";
    std::cout << "Time: " << this->get_time() << std::endl;
    commands += "Time: " + QString::number(this->get_time()) + "\n";
    return commands;
}

void rotation::read_data(const std::string &str) {
    size_t attrAmount = 3;
    size_t i = 0;
    std::string attrs[attrAmount];
    std::istringstream f(str);
    std::string s;
    while (getline(f, s, ' ')) {
        //std::cout << s << std::endl;
        attrs[i] = s;
        i++;
    }
    set_new_radius(std::atof(attrs[0].c_str()));
    set_new_direction(std::atoi(attrs[1].c_str()));
    set_time(std::atof(attrs[2].c_str()));
    print_params();
}
