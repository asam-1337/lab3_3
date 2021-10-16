//
// Created by chicha-man on 14.10.2021.
//

#ifndef LAB3_3_PCB_D_H
#define LAB3_3_PCB_D_H


#include <iostream>

namespace PCB_1 {
    struct contact {
        bool exist;
        bool type; //F - out, T - in
        int connect;
        double x;
        double y;
        contact(){
            exist = false;
            type = false;
            connect = -1;
            x = 0;
            y = 0;
        }
    };

    class PCB {
    private:
        static const int QUOTA = 10;
        int sz;
        int curr_sz;
        contact *arr;
    public:
        PCB() :sz(QUOTA),curr_sz(0), arr(new contact[QUOTA]) {}
        ~PCB() {delete[] arr;}

        int getSZ() const {return sz;}
        int getCurr_sz() const {return curr_sz;}

        contact * getARR() {return arr;}

        void create_contact(bool type, double x, double y);
        int establish_connect(int name1, int name2);
        void operator +(const contact & src);
        int correction_check(int name1, int name2);
        int get_track_length(int name1, int name2);
        void select_group(int type);
        friend std::ostream & operator << (std::ostream& buff, const PCB & plate);
    };
}

#endif //LAB3_3_PCB_D_H
