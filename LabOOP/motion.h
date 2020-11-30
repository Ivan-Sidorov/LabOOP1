#pragma once
#include "action.h"


class motion : public action {
private:
    double velocity_;
    double get_min_velocity();
    double get_max_velocity();
public:
    motion();
    motion(const motion &motion);
    motion(double n_v, double t);
    void set_new_velocity(double n_v);
    const double& get_velocity() const;
    QString print_params() const;
    std::string class_type() const {
        return "Motion";
    }
    void read_data(const std::string &str);
    bool eq(const action &obj) const {
        motion* new_obj= dynamic_cast<motion*>(const_cast<action*>(&obj));
        bool t = this->get_time() == new_obj->get_time();
        bool v = this->get_velocity() == new_obj->get_velocity();
        if (t && v)
            return true;
        else
            return false;
    }
};
