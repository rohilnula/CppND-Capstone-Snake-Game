#include <iostream>
#include <string>

#include "menu.h"
#include "storeinfo.h"

Menu::Menu() : menuOption(-1) {
    printMenu();
}

void Menu::printMenu() {
    std::cout << "Please Choose from the options below:" << "\n";
    std::cout << "1. Start New Game" << "\n";
    std::cout << "2. Get Previous Game Score" << "\n";
    std::cout << "3. Get Record Score" << "\n";
    std::cout << "4. Reset Score" << "\n";
    std::cout << "5. Exit" << std::endl;

    int choice;
    while (std::cin >> choice) {
        if (choice < 1 || choice > 5) {
            std::cout << "Invalid Option. Please choose between 1 and 4" << std::endl;
        }
        else {
            menuOption = choice;
            break;
        }

    }
}

void Menu::printPreviousScore() {
    auto previousScore = info.readFilePreviousScore();
    std::cout << "**************** PREVIOUS SCORE ****************" << std::endl;
    std::cout << "Score: " << std::to_string(previousScore[0]) << std::endl;
    std::cout << "Length: " << std::to_string(previousScore[1]) << std::endl;
    std::cout << "**************** PREVIOUS SCORE ****************" << std::endl;
    printMenu();
}

void Menu::printRecordScore() {
    auto recordScore = info.readFileRecordScore();
    std::cout << "**************** RECORD SCORE ****************" << std::endl;
    std::cout << "Score: " << std::to_string(recordScore[0]) << std::endl;
    std::cout << "Length: " << std::to_string(recordScore[1]) << std::endl;
    std::cout << "**************** RECORD SCORE ****************" << std::endl;
    printMenu();
}

void Menu::resetScores() {
    info.resetScores();
    printMenu();
}

int Menu::getMenuOption() {
    return menuOption;
}

StoreInfo Menu::getStoreInfo() {
    return info;
}


