#include <iostream>
#include <string>

class ROUTE {
private:
    std::string startLocation;
    std::string endLocation;
    int routeNumber;

public:
    // Конструкторы
    ROUTE() : startLocation(""), endLocation(""), routeNumber(0) {
        std::cout << "Default constructor called." << std::endl;
    }

    ROUTE(std::string start, std::string end, int number) : startLocation(start), endLocation(end), routeNumber(number) {
        std::cout << "Parameterized constructor called." << std::endl;
    }

    ROUTE(const ROUTE& other) : startLocation(other.startLocation), endLocation(other.endLocation), routeNumber(other.routeNumber) {
        std::cout << "Copy constructor called." << std::endl;
    }

    // Деструктор
    ~ROUTE() {
        std::cout << "Destructor called for Route " << routeNumber << "." << std::endl;
    }

    // Методы доступа
    std::string getStartLocation() const {
        return startLocation;
    }

    std::string getEndLocation() const {
        return endLocation;
    }

    int getRouteNumber() const {
        return routeNumber;
    }

    void setStartLocation(const std::string& start) {
        startLocation = start;
    }

    void setEndLocation(const std::string& end) {
        endLocation = end;
    }

    void setRouteNumber(int number) {
        routeNumber = number;
    }

    friend std::ostream& operator<<(std::ostream& os, const ROUTE& route) {
        os << "Route " << route.routeNumber << ": " << route.startLocation << " to " << route.endLocation;
        return os;
    }
};

int main() {
    try {
        int routeCount;
        std::cout << "Enter the number of routes: ";
        std::cin >> routeCount;

        // Динамическое выделение памяти для массива объектов ROUTE
        ROUTE* routes = new ROUTE[routeCount];

        // Заполнение данных о маршрутах
        for (int i = 0; i < routeCount; ++i) {
            std::string start, end;
            int number;

            std::cout << "Enter start location for Route " << i + 1 << ": ";
            std::cin >> start;

            std::cout << "Enter end location for Route " << i + 1 << ": ";
            std::cin >> end;

            std::cout << "Enter route number for Route " << i + 1 << ": ";
            std::cin >> number;

            routes[i] = ROUTE(start, end, number);
        }

        // Вывод информации о маршрутах
        std::string location;
        std::cout << "Enter location to search: ";
        std::cin >> location;

        bool found = false;
        for (int i = 0; i < routeCount; ++i) {
            if (routes[i].getStartLocation() == location || routes[i].getEndLocation() == location) {
                std::cout << routes[i] << std::endl;
                found = true;
            }
        }

        if (!found) {
            std::cout << "No routes found for the specified location." << std::endl;
        }

        // Освобождение выделенной памяти
        delete[] routes;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
