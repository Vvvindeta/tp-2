#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class ROUTE {
private:
    std::string start_point;
    std::string end_point;
    int route_number;

public:
    ROUTE() : route_number(0) {}

    friend std::istream& operator>>(std::istream& is, ROUTE& route) {
        std::cout << "Введите название начального пункта маршрута: ";
        is >> route.start_point;

        std::cout << "Введите название конечного пункта маршрута: ";
        is >> route.end_point;

        std::cout << "Введите номер маршрута: ";
        is >> route.route_number;

        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const ROUTE& route) {
        os << "Маршрут " << route.route_number << ": " << route.start_point << " - " << route.end_point;
        return os;
    }

    const std::string& getStartPoint() const {
        return start_point;
    }

    const std::string& getEndPoint() const {
        return end_point;
    }
};

int main() {
    const int ROUTE_COUNT = 8;
    std::vector<ROUTE> routes;

    // Ввод маршрутов с клавиатуры и сортировка
    std::cout << "Введите данные для маршрутов:\n";
    for (int i = 0; i < ROUTE_COUNT; ++i) {
        ROUTE route;
        std::cin >> route;
        routes.push_back(route);
    }

    // Вывод на экран информации о маршрутах по названию пункта
    std::string target_point;
    std::cout << "Введите название пункта: ";
    std::cin >> target_point;

    bool found = false;
    for (const auto& route : routes) {
        if (route.getStartPoint() == target_point || route.getEndPoint() == target_point) {
            std::cout << route << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Маршруты не найдены.\n";
    }

    // Использование файловых и строковых потоков для чтения из файла
    std::ifstream inputFile("example.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл.\n";
        return 1;
    }

    std::cout << "\nСтроки из файла, не содержащие двузначные числа:\n";
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        bool containsTwoDigitNumber = false;

        // Проверка строки на наличие двузначных чисел
        std::string word;
        while (iss >> word) {
            if (word.size() == 2 && std::isdigit(word[0]) && std::isdigit(word[1])) {
                containsTwoDigitNumber = true;
                break;
            }
        }

        // Вывод строки, если не содержит двузначные числа
        if (!containsTwoDigitNumber) {
            std::cout << line << std::endl;
        }
    }

    inputFile.close();

    return 0;
}
