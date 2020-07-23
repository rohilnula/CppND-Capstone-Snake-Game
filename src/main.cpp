#include <iostream>

#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "menu.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Menu menu;
  while (true) {
    int choice = menu.getMenuOption();
    if (choice == 1) {
      std::cout << "Starting New Game ..." << std::endl;
      break;
    }
    else if (choice == 2) {
      menu.printPreviousScore();
    }
    else if (choice == 3) {
      menu.printRecordScore();
    }
    else if (choice == 4) {
      menu.resetScores();
    }
    else {
      std::cout << "Exiting Game ..." << std::endl;
      return 0;
    }
  }
  
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  menu.getStoreInfo().writeFilePreviousScore(game.GetScore(), game.GetSize());
  menu.getStoreInfo().writeFileRecordScore(game.GetScore(), game.GetSize());
  return 0;
}