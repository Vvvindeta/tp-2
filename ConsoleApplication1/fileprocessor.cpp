#include "fileprocessor.h"
#include <fstream>
#include <iostream>
#include <sstream>

FileProcessor::FileProcessor() {
    std::cout << "Объект FileProcessor создан с использованием конструктора по умолчанию.\n";
}

FileProcessor::FileProcessor(const std::string& file) : fileName(file) {
    std::cout << "Объект FileProcessor создан с использованием конструктора с параметрами.\n";
}

FileProcessor::~FileProcessor() {
    std::cout << "Объект FileProcessor уничтожен.\n";
}

void FileProcessor::setFileName(const std::string& file) {
    fileName = file;
}

void FileProcessor::processFile() {
    std::ifstream inputFile(fileName);

    if (!inputFile) {
        throw std::runtime_error("Не удалось открыть файл " + fileName);
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        if (!hasTwoDigitNumber(line)) {
            std::cout << line << '\n';
        }
    }

    inputFile.close();
}

bool FileProcessor::hasTwoDigitNumber(const std::string& line) const {
    std::istringstream stream(line);
    int number;
    while (stream >> number) {
        if (number >= 10 && number <= 99) {
            return true;
        }
    }
    return false;
}
