#include "route.h"

ROUTE::ROUTE() : route_number(0) {
    std::cout << "Объект МАРШРУТ создан с использованием конструктора по умолчанию.\n";
}

ROUTE::ROUTE(const std::string& start, const std::string& end, int number)
    : start_point(start), end_point(end), route_number(number) {
    std::cout << "Объект МАРШРУТ создан с использованием конструктора с параметрами.\n";
}

ROUTE::ROUTE(const ROUTE& other)
    : start_point(other.start_point), end_point(other.end_point), route_number(other.route_number) {
    std::cout << "Объект МАРШРУТ создан с использованием конструктора копирования.\n";
}

ROUTE::~ROUTE() {
    std::cout << "Объект МАРШРУТ с номером маршрута " << route_number << " уничтожен.\n";
}

std::string ROUTE::getStartPoint() const {
    return start_point;
}

std::string ROUTE::getEndPoint() const {
    return end_point;
}

int ROUTE::getRouteNumber() const {
    return route_number;
}

void ROUTE::setStartPoint(const std::string& start) {
    start_point = start;
}

void ROUTE::setEndPoint(const std::string& end) {
    end_point = end;
}

void ROUTE::setRouteNumber(int number) {
    route_number = number;
}

std::ostream& operator<<(std::ostream& os, const ROUTE& route) {
    os << "Маршрут " << route.route_number << ": " << route.start_point << " до " << route.end_point;
    return os;
}

std::istream& operator>>(std::istream& is, ROUTE& route) {
    std::cout << "Введите начальный пункт: ";
    is >> route.start_point;

    std::cout << "Введите конечный пункт: ";
    is >> route.end_point;

    // Ввод и проверка корректности номера маршрута с использованием исключения
    while (true) {
        try {
            std::cout << "Введите номер маршрута: ";
            is >> route.route_number;

            if (route.route_number <= 0) {
                throw ROUTE::InvalidRouteNumberException();
            }

            break; // Выход из цикла в случае корректного ввода
        }
        catch (const ROUTE::InvalidRouteNumberException& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
            is.clear(); // Очистка флагов ошибок ввода
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
        }
    }

    return is;
}

const char* ROUTE::InvalidRouteNumberException::what() const noexcept {
    return "Некорректный номер маршрута. Номер маршрута должен быть больше нуля.";
}
