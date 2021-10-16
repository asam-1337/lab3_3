//
// Created by chicha-man on 14.10.2021.
//

#include "menu.h"

using namespace std;
using namespace PCB_1;

void d_create_PCB(PCB & plate, int size)
{
    int i = 0;
    bool type;
    double x, y;
    while (i < size) {
        cout << "enter type: ";
        get_num(type);
        cout << "enter x: ";
        get_num(x);
        cout << "enter y: ";
        get_num(y);
        plate.create_contact(type, x ,y);
        i++;
    }
}

void d_create_contact(PCB &plate)
{
    bool type;
    double x, y;
    cout << "enter type: ";
    get_num(type);
    cout << "enter x: ";
    get_num(x);
    cout << "enter y: ";
    get_num(y);
    plate.create_contact(type, x, y);
}

void d_add_contact(PCB &plate)
{
    contact cnt;
    cnt.exist = true;
    cout << "enter type: ";
    get_num(cnt.type);
    cout << "enter x: ";
    get_num(cnt.x);
    cout << "enter y: ";
    get_num(cnt.y);
    plate + cnt;
}

void d_select_group(PCB plate)
{
    bool type;
    cout << "enter type: ";
    get_num(type);
    plate.select_group(type);
}

int dialog()
{
    int res;
    PCB plate;
    while (true) {
        cout
            << "1. create plate\n"
            << "2. create 1 contact\n"
            << "3. show plate\n"
            << "4. add contact\n"
            << "5. establish connect\n"
            << "6. select a group\n"
            << "7. get track distance"
            << endl;
        get_num(res);
        switch (res) {
            case 1:
                int size;
                cout << "how many contacts do you want to create: ";
                get_num(size);
                d_create_PCB(plate, size);
                break;
            case 2:
                d_create_contact(plate);
                break;
            case 3:
                cout << plate;
                break;
            case 4:
                d_add_contact(plate);
                break;
            case 5:
                int name1, name2;
                cout << "enter 1st name: ";
                get_num(name1);
                cout << "enter 2nd name: ";
                get_num(name2);
                if (plate.establish_connect(name1, name2))
                    cout << "contacts of the same type" << endl;
                break;
            case 6:
                d_select_group(plate);
                break;
            case 7:
                int name3, name4;
                cout << "enter 1st name: ";
                get_num(name3);
                cout << "enter 2nd name: ";
                get_num(name4);
                if (plate.get_track_length(name3, name4))
                    cout << "contacts of the same type" << endl;
                break;
            default:
                return 0;
        }
    }
}