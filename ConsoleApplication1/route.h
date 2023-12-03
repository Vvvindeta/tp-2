#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>

class ROUTE {
private:
    std::string start_point;
    std::string end_point;
    int route_number;

public:
    ROUTE();  // Конструктор по умолчанию
    ROUTE(const std::string& start, const std::string& end, int number);  // Конструктор с параметрами
    ROUTE(const ROUTE& other);  // Конструктор копирования
    ~ROUTE();  // Деструктор

    // Методы доступа
    std::string getStartPoint() const;
    std::string getEndPoint() const;
    int getRouteNumber() const;
    void setStartPoint(const std::string& start);
    void setEndPoint(const std::string& end);
    void setRouteNumber(int number);

    // Перегрузка операции вставки
    friend std::ostream& operator<<(std::ostream& os, const ROUTE& route);

    // Перегрузка операции извлечения
    friend std::istream& operator>>(std::istream& is, ROUTE& route);

    // Исключение для проверки корректности номера маршрута
    class InvalidRouteNumberException : public std::exception {
    public:
        const char* what() const noexcept override;
    };
};

#endif // ROUTE_H
