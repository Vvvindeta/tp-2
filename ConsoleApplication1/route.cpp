#include "route.h"

ROUTE::ROUTE() : route_number(0) {
    std::cout << "������ ������� ������ � �������������� ������������ �� ���������.\n";
}

ROUTE::ROUTE(const std::string& start, const std::string& end, int number)
    : start_point(start), end_point(end), route_number(number) {
    std::cout << "������ ������� ������ � �������������� ������������ � �����������.\n";
}

ROUTE::ROUTE(const ROUTE& other)
    : start_point(other.start_point), end_point(other.end_point), route_number(other.route_number) {
    std::cout << "������ ������� ������ � �������������� ������������ �����������.\n";
}

ROUTE::~ROUTE() {
    std::cout << "������ ������� � ������� �������� " << route_number << " ���������.\n";
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
    os << "������� " << route.route_number << ": " << route.start_point << " �� " << route.end_point;
    return os;
}

std::istream& operator>>(std::istream& is, ROUTE& route) {
    std::cout << "������� ��������� �����: ";
    is >> route.start_point;

    std::cout << "������� �������� �����: ";
    is >> route.end_point;

    // ���� � �������� ������������ ������ �������� � �������������� ����������
    while (true) {
        try {
            std::cout << "������� ����� ��������: ";
            is >> route.route_number;

            if (route.route_number <= 0) {
                throw ROUTE::InvalidRouteNumberException();
            }

            break; // ����� �� ����� � ������ ����������� �����
        }
        catch (const ROUTE::InvalidRouteNumberException& e) {
            std::cerr << "������: " << e.what() << std::endl;
            is.clear(); // ������� ������ ������ �����
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������ �����
        }
    }

    return is;
}

const char* ROUTE::InvalidRouteNumberException::what() const noexcept {
    return "������������ ����� ��������. ����� �������� ������ ���� ������ ����.";
}
