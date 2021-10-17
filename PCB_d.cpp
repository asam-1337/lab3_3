//
// Created by chicha-man on 14.10.2021.
//

#include "PCB_d.h"
#include <cmath>

namespace PCB_1
{
    //constructors
    PCB::PCB() :sz(QUOTA),curr_sz(0), arr(new contact[QUOTA]) {}

    PCB::PCB(const PCB & plate) : sz(plate.sz), curr_sz(plate.curr_sz)
    {
        arr = new contact[plate.sz];
        for (int i = 0; i < curr_sz; i++)
            arr[i] = plate.arr[i];
    }

    PCB::PCB(PCB && plate) noexcept : sz(plate.sz), curr_sz(plate.curr_sz), arr(plate.arr)
    {
        plate.arr = nullptr;
    }

    //methods
    PCB & PCB::operator = (const PCB & plate)
    {
        if (this != &plate)
        {
            sz = plate.sz;
            curr_sz = plate.curr_sz;
            delete[] arr;
            arr = new contact[sz];
            for (int i = 0; i < curr_sz; i++)
                arr[i] = plate.arr[i];
        }
        return *this;
    }

    PCB & PCB::operator = (PCB && plate) noexcept
    {
        int tmp = curr_sz;
        curr_sz = plate.curr_sz;
        plate.curr_sz = tmp;

        tmp = sz;
        sz = plate.sz;
        plate.sz = tmp;

        contact *ptr = arr;
        arr = plate.arr;
        plate.arr = ptr;

        return *this;
    }

    void PCB::create_contact(bool type, double x, double y)
    {
        if (curr_sz == sz)
        {
            sz += QUOTA;
            contact *old = arr;
            arr = new contact[sz];
            for (int i = 0; i < curr_sz; ++i)
                arr[i] = old[i];
            delete[] old;
        }
        arr[curr_sz].exist = true;
        arr[curr_sz].type = type;
        arr[curr_sz].x = x;
        arr[curr_sz].y = y;
        curr_sz++;
    }

    PCB & PCB::operator += (const contact &src)
    {
        if (curr_sz == sz)
        {
            sz += QUOTA;
            contact *old = arr;
            arr = new contact[sz];
            for (int i = 0; i < curr_sz; ++i)
                arr[i] = old[i];
            delete[] old;
        }
        arr[curr_sz] = src;
        curr_sz++;
        return *this;
    }

    int PCB::establish_connect(int name1, int name2)
    {
        if ((arr[name1].exist && arr[name2].exist) && (arr[name1].connect < 0 && arr[name2].connect < 0))
            if (arr[name1].type != arr[name2].type)
            {
                arr[name1].connect = name2;
                arr[name2].connect = name1;
                return 0;
            }
        return 1;
    }

    int PCB::correction_check(int name1, int name2)
    {
        if (arr[name1].exist && arr[name2].exist)
            if (arr[name1].type != arr[name2].type)
                return 0;
        return 1;

    }

    int PCB::get_track_length(int name1, int name2)
    {
        if (!correction_check(name1, name2))
        {
            std::cout
                    << "d = "
                    << sqrt(pow(arr[name1].x - arr[name2].x,2) + pow(arr[name1].x - arr[name2].y, 2));
            return 0;
        }
        return 1;
    }

    void PCB::select_group(int type)
    {
        int j = 0;
        PCB plate;

        for (int i = 0; i < sz && this->arr[i].exist; i++)
            if (this->arr[i].type == type) {
                plate.arr[j] = this->arr[i];
                j++;
            }

        std::cout << plate;
    }

    std::ostream & operator << (std::ostream& buff, const PCB & plate){
        buff << "number\t|\ttype\t|\tconnect\t|\tcoords" << std:: endl;
        for (int i = 0; plate.arr[i].exist && i < plate.sz; i++)
        {
            buff
                    << i
                    << "\t\t|\t" << plate.arr[i].type
                    << "\t\t|\t" << plate.arr[i].connect
                    << "\t\t|\t" << "(" << plate.arr[i].x << ", " << plate.arr[i].y << ")"
                    << std::endl;
        }
        return buff;
    }
}