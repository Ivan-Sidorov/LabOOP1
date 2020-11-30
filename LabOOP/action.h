#pragma once
#include <iostream>
#include <fstream>
#include <QString>
class MainWindow;
class Ui_MainWindow;


class action {
private:
    double time_;
    double get_min_time();
    double get_max_time();
public:
    action();
    action(double t) {
        this->time_ = t;
    }
    action(const action &action) {
        this->time_ = action.get_time();
    }
    void set_time(double t);
    const double& get_time() const;
    virtual bool eq(const action &obj) const {
        bool t = this->get_time() == obj.get_time();
        if (t)
            return true;
        else
            return false;
    }
    virtual std::string class_type() const {
        return "Action";
    }
    virtual QString print_params() const {
        QString commands = "";
        std::cout << "Time: " << this->get_time() << std::endl;
        commands = "Time: " + QString::number(this->get_time()) + "\n";
        return commands;
    }
    virtual void read_data(const std::string &str);
};

