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

        //constructors
        contact(){
            exist = false;
            type = false;
            connect = -1;
            x = 0;
            y = 0;
        }

        explicit contact(bool v_type, int v_x = 1, int v_y = 1)
                : exist (true), type(v_type), connect(-1), x(v_x), y(v_y) {}
    };

    class PCB {
    private:
        static const int QUOTA = 10;
        int sz;
        int curr_sz;
        contact *arr;
    public:
        //constructors
        PCB();
        PCB(const PCB & plate);
        PCB(PCB && plate) noexcept ;
        ~PCB() {delete[] arr;}

        //getters
        int getSZ() const {return sz;}
        int getCurr_sz() const {return curr_sz;}
        contact * getARR() {return arr;}

        //methods
        PCB & operator = (const PCB & pl);
        PCB & operator = (PCB && pl) noexcept ;
        PCB & operator += (const contact & src);

        void create_contact(bool type, double x, double y);
        int establish_connect(int name1, int name2);
        int correction_check(int name1, int name2);
        int get_track_length(int name1, int name2);
        void select_group(int type);
        friend std::ostream & operator << (std::ostream& buff, const PCB & plate);
    };
}

#endif //LAB3_3_PCB_D_H
