#include "collection.h"
#include "motion.h"
#include "rotation.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <iostream>
#include <float.h>
#include <iostream>
#include <fstream>
#include "tests.h"
#include <cmath>
#include <utility>
#include <math.h>

using namespace std;

action* collection::get(int pos) {
    if(emp() == false) {
        auto cur = first_;
        for(auto i = 1; i < pos && cur; i++, cur = cur->next);
        if(cur)
            return cur->obj;
        cout<<"Not enough elements\n";
        return first_->obj;
    }
    printf("Stack is empty.\n");
    return nullptr;
}

void collection::add(const action* &obj) {
    push(obj);
}

void collection::push(const action* &d) {
    auto cur = new list_element;
    action* n_d = const_cast<action*>(d);
    cur->obj = n_d;
    cur->next = first_;
    first_ = cur;
}

void collection::pop() {
    if(first_) {
        auto cur = first_;
        first_ = cur->next;
        delete cur->obj;
        delete cur;
    }
    else
        std::cout << "Stack is empty" << std::endl;
}

bool collection::del(int pos) {
    bool fg = false;
    if (first_) {
        auto cur = first_->next, cur1 = first_;
        if (pos == 1) {
            first_ = cur;
            delete cur1;
            fg = true;
        }
        else {
            for(auto i = 2; i < pos && cur; i++) {
            cur = cur->next;
            cur1 = cur1->next;
            }
            if(cur) {
            cur1->next = cur->next;
            delete cur;
            fg = true;
            }
        }
    }
    return fg;
}

void collection::del_all() {
    while(!emp()) {
        pop();
    }
}

int collection::get_count() const {
    int count = 0;
    auto cur = first_;
    while(cur) {
        count += 1;
        cur = cur->next;
    }
    return count;
}

void collection::print_collection() const {
    int i = 1;
    list_element *ptr = first_;
    std::cout<<"\nCommands:";
    while(ptr != nullptr) {
        std::cout<<"\nElement " << i;
        std::cout<<"\n";
        ptr->obj->print_params();
        i++;
        ptr = ptr->next;
    }
}

void collection::reverse() {
    if (first_ && this->get_count() != 1) {
        list_element *ptr;
        list_element *ptr1 = first_;
        list_element *ptr2 = first_->next;
        ptr1->next = nullptr;
        while (ptr2->next != nullptr) {
            ptr = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr;
        }
        ptr2->next = ptr1;
        first_ = ptr2;
    }
}

std::pair<double, double> collection::coordinates() {
    this->reverse();
    list_element *ptr1 = first_; //motion
    list_element *ptr2 = first_; //rotation
    double t, s, x_tmp, y_tmp, x = 0., y = 0.;
    double vel, vel_tmp, t_m;
    double rad, rad_tmp, t_r;
    int dir, dir_tmp;
    // Первые действия надо считать отдельно
    if (first_ && this->get_count() > 1) {
        while(ptr1->obj->class_type() != "Motion")
            if (ptr1->next != nullptr)
                ptr1 = ptr1->next;
            else {
                x = round(x * 100) / 100;
                y = round(y * 100) / 100;
                return {x, y};
            }
        motion* ptr_m = dynamic_cast<motion*>(ptr1->obj);
        vel_tmp = ptr_m->get_velocity();
        t_m = ptr_m->get_time();
        while(ptr2->obj->class_type() != "Rotation")
            if (ptr2->next != nullptr)
                ptr2 = ptr2->next;
            else {
                x = round(x * 100) / 100;
                y = round(y * 100) / 100;
                return {x, y};
            }
        rotation* ptr_r = dynamic_cast<rotation*>(ptr2->obj);
        rad_tmp = ptr_r->get_radius();
        dir_tmp = ptr_r->get_direction();
        t_r = ptr_r->get_time();
        while (ptr1 != nullptr && ptr2 != nullptr) {
            vel = vel_tmp;
            rad = rad_tmp;
            dir = dir_tmp;
            if (t_m > t_r) {
                t = t_r;
                t_m -= t;
                if (ptr2->next != nullptr) {
                    ptr2 = ptr2->next;
                    while(ptr2->obj->class_type() != "Rotation")
                        if (ptr2->next != nullptr)
                            ptr2 = ptr2->next;
                        else {
                            ptr2 = nullptr;
                            break;
                        }
                    if (ptr2 != nullptr) {
                        rotation* ptr_r = dynamic_cast<rotation*>(ptr2->obj);
                        rad_tmp = ptr_r->get_radius();
                        dir_tmp = ptr_r->get_direction();
                        t_r = ptr_r->get_time();
                    }
                }
                else
                    ptr2 = nullptr;
            }
            else if (t_r > t_m) {
                t = t_m;
                t_r -= t;
                if (ptr1->next != nullptr) {
                    ptr1 = ptr1->next;
                    while(ptr1->obj->class_type() != "Motion")
                        if (ptr1->next != nullptr)
                            ptr1 = ptr1->next;
                        else {
                            ptr1 = nullptr;
                            break;
                        }
                    if (ptr1 != nullptr) {
                        motion* ptr_m = dynamic_cast<motion*>(ptr1->obj);
                        vel_tmp = ptr_m->get_velocity();
                        t_m = ptr_m->get_time();
                    }
                }
                else
                    ptr1 = nullptr;
            }
            else {
                t = t_m;
                t_m -= t;
                t_r -= t;
                if (ptr1->next != nullptr) {
                    ptr1 = ptr1->next;
                    while(ptr1->obj->class_type() != "Motion")
                        if (ptr1->next != nullptr)
                            ptr1 = ptr1->next;
                        else {
                            ptr1 = nullptr;
                            break;
                        }
                    if (ptr1 != nullptr) {
                        motion* ptr_m = dynamic_cast<motion*>(ptr1->obj);
                        vel_tmp = ptr_m->get_velocity();
                        t_m = ptr_m->get_time();
                    }
                }
                else
                    ptr1 = nullptr;

                if (ptr2->next != nullptr) {
                    ptr2 = ptr2->next;
                    while(ptr2->obj->class_type() != "Rotation")
                        if (ptr2->next != nullptr)
                            ptr2 = ptr2->next;
                        else {
                            ptr2 = nullptr;
                            break;
                        }
                    if (ptr2 != nullptr) {
                        rotation* ptr_r = dynamic_cast<rotation*>(ptr2->obj);
                        rad_tmp = ptr_r->get_radius();
                        dir_tmp = ptr_r->get_direction();
                        t_r = ptr_r->get_time();
                    }
                }
                else
                    ptr2 = nullptr;
            }
            s = vel * t;
            x_tmp = s * sin(rad * M_PI / 180);
            y_tmp = s * cos(rad * M_PI / 180);
            if ((rad <= 90) && (dir == 1)) {
                x += x_tmp;
                y += y_tmp;
            }
            else if ((rad <= 90) && (dir == 0)) {
                x += -x_tmp;
                y += y_tmp;
            }
            else if ((rad > 90) && (dir == 0)) {
                x += -x_tmp;
                y += -y_tmp;
            }
            else if ((rad > 90) && (dir == 1)) {
                x += x_tmp;
                y += -y_tmp;
            }
        }
        x = round(x * 100) / 100;
        y = round(y * 100) / 100;
    }
    return {x, y};
}

collection::collection() {
    first_ = nullptr;
    iter_ = nullptr;
}

collection::collection(const collection &d) {
    list_element cur_c = d.get_first();
    list_element* cur_c_n = cur_c.next;
    list_element* cur_1;
    list_element* cur_2;
    cur_1 = new list_element;
    first_ = cur_1;
    cur_1->obj = cur_c.obj;
    while(cur_c_n) {
        cur_2 = new list_element;
        cur_2->obj = cur_c_n->obj;
        cur_1->next = cur_2;
        cur_1 = cur_2;
        cur_c_n = cur_c_n->next;
    }
}

collection::~collection() {
    while(!emp()) {
        pop();
    }
}

bool collection::emp() const {
    if (first_ == nullptr)
        return true;
    else
        return false;

}

//motion collection::get_head_del(){
//    if(!emp()) {
//        motion a = top();
//        pop();
//        return a;
//    }
//    printf("%s", "Stack is empty.\n");
//}

void collection::iter_begin() {
    iter_ = first_;
}

void collection::iter_end() {
    auto cur = first_;
    while(cur->next)
        cur = cur->next;
    iter_ = cur;
}

action* collection::cur() const {
    if (iter_)
        return iter_->obj;
    else
        return nullptr;
}

void collection::next(){
    if (iter_)
        iter_ = iter_->next;
}

void collection::prev() {
    auto cur = first_;
    while(cur->next != iter_)
        cur = cur->next;
    iter_ = cur;
}

bool collection::eq(const collection &coll) const {
    bool equal = (get_count() && coll.get_count());
    auto cur1 = first_;
    auto cur2 = coll.first_;
    while(cur1 && cur2 && equal){
        equal = cur1->obj->eq(*cur2->obj);
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return equal;
}

action* collection::get_head() const {
    if(!emp())
        return top();
    else
        printf("%s", "Stack is empty.\n");
    return nullptr;
}

const collection::list_element &collection::get_first() const {
    return *first_;
}

void collection::write_data(const char *path) const {
    if(!emp()) {
        std::ofstream file;
        file.open(path);
        file << get_count() << std::endl;
        list_element* prev = nullptr;
        list_element* cur = first_;
        while(prev != first_){
            while(cur->next != prev)
                cur = cur->next;
            motion* cur_motion = dynamic_cast<motion*>(cur->obj);
            if (cur_motion) {
                file << "Motion" << std::endl;
                file <<(cur_motion)->get_velocity() << " " << (cur_motion)->get_time() << std::endl;
            }
            else {
                rotation* cur_rot = dynamic_cast<rotation*>(cur->obj);
                if (cur_rot) {
                    file << "Rotation" << std::endl;
                    file << (cur_rot)->get_radius() << " " << (cur_rot)->get_direction() << " " << (cur_rot)->get_time() << std::endl;
                }
            }
            prev = cur;
            cur = first_;
        }
        file.close();
    }
};

bool collection::read_data(const char *path) {
    std::ifstream file;
    file.open(path);
    if (!file) {
        std::cout << "Can't open file: " << path << std::endl;
        return false;
    }
    del_all();
    action* cur_action;
    std::string action_type;
    std::string input;
    int cnt;
    file >> cnt;
    while(cnt) {
        file >> action_type;
        std::cout << action_type << std::endl;
        std::getline(file, input);
        std::getline(file, input);
        if (action_type == "Motion") {
            cur_action = new motion;
            cnt--;
        }
        else if (action_type == "Rotation") {
            cur_action = new rotation;
            cnt--;
        }
        cur_action->read_data(input);
        const action* cur = const_cast<const action*>(cur_action);
        push(cur);
    }
    file.close();
    return true;
}

action* collection::top() const {
    return first_->obj;
}
