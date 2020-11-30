#pragma once
#include "action.h"


class rotation : public action {
private:
    double radius_;
    bool direction_; // 0 - left, 1 - right
    double get_min_radius();
    double get_max_radius();
public:
    rotation();
    rotation(const rotation &rotation);
    rotation(double t, double n_r, double n_dir);
    void set_new_radius(double n_r);
    void set_new_direction(bool n_dir);
    const double& get_radius() const;
    const bool& get_direction() const;
    QString print_params() const;
    void read_data(const std::string &str);
    std::string class_type() const {
        return "Rotation";
    }
    bool eq(const action &obj) const {
        rotation* new_obj= dynamic_cast<rotation*>(const_cast<action*>(&obj));
        bool t = this->get_time() == new_obj->get_time();
        bool r = this->get_radius() == new_obj->get_radius();
        bool d = this->get_direction() == new_obj->get_direction();
        if (t && r && d)
            return true;
        else
            return false;
    }
};

