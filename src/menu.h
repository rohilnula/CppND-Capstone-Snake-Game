#ifndef MENU_H
#define MENU_H

#include <string>
#include "storeinfo.h"

class Menu {
    public:
        Menu();

        void printMenu();
        void printPreviousScore();
        void printRecordScore();
        void resetScores();
        int getMenuOption();
        StoreInfo getStoreInfo();
    private:
        int menuOption;
        StoreInfo info;
};

#endif