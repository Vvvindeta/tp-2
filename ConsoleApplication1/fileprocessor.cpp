#include "fileprocessor.h"
#include <fstream>
#include <iostream>
#include <sstream>

FileProcessor::FileProcessor() {
    std::cout << "������ FileProcessor ������ � �������������� ������������ �� ���������.\n";
}

FileProcessor::FileProcessor(const std::string& file) : fileName(file) {
    std::cout << "������ FileProcessor ������ � �������������� ������������ � �����������.\n";
}

FileProcessor::~FileProcessor() {
    std::cout << "������ FileProcessor ���������.\n";
}

void FileProcessor::setFileName(const std::string& file) {
    fileName = file;
}

void FileProcessor::processFile() {
    std::ifstream inputFile(fileName);

    if (!inputFile) {
        throw std::runtime_error("�� ������� ������� ���� " + fileName);
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
