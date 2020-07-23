#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "storeinfo.h"

std::vector<int> StoreInfo::readFilePreviousScore() {
    return genericRead(previousScoreFile);
}

std::vector<int> StoreInfo::readFileRecordScore() {
    return genericRead(recordScoreFile);
}

void StoreInfo::writeFilePreviousScore(int score, int length) {
    genericWrite(previousScoreFile, score, length);
    std::cout << "Recorded Current Score!" << std::endl;
}

void StoreInfo::writeFileRecordScore(int score, int length) {
    auto recordScore = readFileRecordScore();
    if (score > recordScore[0] && length > recordScore[1]) {
        genericWrite(recordScoreFile, score, length);
        std::cout << "Recorded the new Record Score!" << std::endl;
    }
}

void StoreInfo::resetScores() {
    genericWrite(previousScoreFile, 0, 0);
    genericWrite(recordScoreFile, 0, 0);
    std::cout << "Previous and Record Scores set to zero!" << std::endl;
}

std::vector<int> StoreInfo::genericRead(std::string fileName) {
    std::string line, key, value;
    int score, length;
    std::ifstream fileStream(fileName); 
    if (fileStream.is_open()) {
        while (std::getline(fileStream, line)) {
            std::istringstream linestream(line);
            while (linestream >> key >> value) {
                if (key == "score:") {
                    score = std::stoi(value);
                }

                if (key == "length:") {
                    length = std::stoi(value);
                }
            }
        }
        return {score, length};
    }
    std::cout << "Unable to Read File ....." << std::endl;
    return {0, 0};
}

void StoreInfo::genericWrite(std::string fileName, int score, int length) {
    std::ofstream writer (fileName, std::ofstream::out);
    writer << "score: " << std::to_string(score) << "\n";
    writer << "length: " << std::to_string(length) << "\n";
}