#ifndef STOREINFO_H
#define STOREINFO_H

#include <vector>
#include <string>

class StoreInfo {
    public:
        StoreInfo() {};
        std::vector<int> readFilePreviousScore();
        std::vector<int> readFileRecordScore();
        void writeFilePreviousScore(int score, int length);
        void writeFileRecordScore(int score, int length);
        void resetScores();
    private:
        const std::string previousScoreFile {"../dataStore/previous.txt"};
        const std::string recordScoreFile {"../dataStore/record.txt"};
        std::vector<int> genericRead(std::string fileName);
        void genericWrite(std::string fileName, int score, int length);
};

#endif