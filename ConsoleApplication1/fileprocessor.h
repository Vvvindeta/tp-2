#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>

class FileProcessor {
private:
    std::string fileName;

public:
    FileProcessor();  // ����������� �� ���������
    FileProcessor(const std::string& file);  // ����������� � �����������
    ~FileProcessor();  // ����������

    void setFileName(const std::string& file);
    void processFile();

private:
    bool hasTwoDigitNumber(const std::string& line) const;
};

#endif // FILEPROCESSOR_H
