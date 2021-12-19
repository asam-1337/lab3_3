//
// Created by chicha-man on 14.10.2021.
//

#ifndef LAB3_3_PCB_D_H
#define LAB3_3_PCB_D_H


#include <iostream>

namespace PCB_1 {
    template <class T>
    int get_num(T& a) {
        std::cin >> a;

        while (!std::cin.good()) {
            if (std::cin.bad()) throw std::runtime_error("Fatal error");
            if (std::cin.eof()) return 1;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Invalid input. Please, try again." << std::endl;
            std::cin >> a;
        }
        return 0;
    }

    struct contact {
        bool exist;
        bool type; ///F - out, T - in
        int connect;
        double x;
        double y;

        ///constructors
        contact() {
            exist = true;
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
        ///constructors
        PCB();

        PCB(const PCB & plate);

        PCB(PCB && plate) noexcept ;

        ~PCB() {delete[] arr;}

        ///getters
        int getSZ() const {return sz;}

        int getCurr_sz() const {return curr_sz;}

        contact * getARR() {return arr;}

        ///methods
        PCB & operator = (const PCB & pl);

        PCB & operator = (PCB && pl) noexcept ;

        PCB & operator += (const contact & src);


        int establish_connect(int name1, int name2);

        [[nodiscard]] int correction_check(int name1, int name2) const;

        [[nodiscard]] double get_track_length(int name1, int name2) const;

        [[nodiscard]] PCB & select_group(bool type) const;


        friend std::istream & operator >> (std::istream & buff, PCB & plate);

        friend std::ostream & operator << (std::ostream& buff, const PCB & plate);
    };
}

#endif //LAB3_3_PCB_D_H
