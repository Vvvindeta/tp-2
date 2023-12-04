#include <vector>
#include <algorithm>
#include "fileprocessor.h"
#include "route.h"

int displayMenu() {
    int choice;
    std::cout << "\nМЕНЮ:\n";
    std::cout << "1. Ввод данных о маршрутах\n";
    std::cout << "2. Вывод данных о маршрутах\n";
    std::cout << "3. Просмотр данных о конкретном маршруте\n";
    std::cout << "4. Изменение данных о конкретном маршруте\n";
    std::cout << "5. Добавление нового маршрута\n";
    std::cout << "6. Удаление маршрута\n";
    std::cout << "7. Работа с файлами\n";
    std::cout << "8. Выйти\n";
    std::cout << "Введите ваш выбор: ";
    std::cin >> choice;
    return choice;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    std::vector<ROUTE> routes; // Используем вектор для удобства добавления/удаления
    const int ARRAY_SIZE = 8;

    do {
        choice = displayMenu();

        switch (choice) {
        case 1: {
            // Ввод данных маршрутов
            for (int i = 0; i < ARRAY_SIZE; ++i) {
                ROUTE newRoute;
                std::cin >> newRoute;
                routes.push_back(newRoute);
            }

            // Сортировка по номерам маршрутов
            std::sort(routes.begin(), routes.end(),
                [](const ROUTE& a, const ROUTE& b) {
                    return a.getRouteNumber() < b.getRouteNumber();
                });
            break;
        }

        case 2: {
            // Вывод данных
            for (const auto& route : routes) {
                std::cout << route << '\n';
            }
            break;
        }

        case 3: {
            // Просмотр данных о конкретном маршруте
            int routeNumber;
            std::cout << "Введите номер маршрута для просмотра: ";
            std::cin >> routeNumber;

            // Поиск маршрута с указанным номером
            bool found = false;
            for (const auto& route : routes) {
                if (route.getRouteNumber() == routeNumber) {
                    std::cout << "Найден маршрут:\n" << route << '\n';
                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cout << "Маршрут с номером " << routeNumber << " не найден.\n";
            }

            break;
        }

        case 4: {
            // Изменение данных о конкретном маршруте
            int routeNumber;
            std::cout << "Введите номер маршрута для изменения: ";
            std::cin >> routeNumber;

            // Поиск маршрута с указанным номером
            auto it = std::find_if(routes.begin(), routes.end(),
                [routeNumber](const ROUTE& route) {
                    return route.getRouteNumber() == routeNumber;
                });

            if (it != routes.end()) {
                std::cout << "Текущие данные маршрута:\n" << *it << '\n';
                std::cin >> *it;
                std::cout << "Данные маршрута изменены:\n" << *it << '\n';
            }
            else {
                std::cout << "Маршрут с номером " << routeNumber << " не найден.\n";
            }

            break;
        }

        case 5: {
            // Добавление нового маршрута на любую позицию
            int position;
            std::cout << "Введите позицию для добавления нового маршрута: ";
            std::cin >> position;

            if (position >= 1 && position <= routes.size() + 1) {
                ROUTE newRoute;
                std::cin >> newRoute;
                routes.insert(routes.begin() + position - 1, newRoute);
                std::cout << "Новый маршрут добавлен на позицию " << position << ".\n";
            }
            else {
                std::cout << "Некорректная позиция. Маршрут не добавлен.\n";
            }

            break;
        }

        case 6: {
            // Удаление маршрута по номеру
            int routeNumber;
            std::cout << "Введите номер маршрута для удаления: ";
            std::cin >> routeNumber;

            auto it = std::remove_if(routes.begin(), routes.end(),
                [routeNumber](const ROUTE& route) {
                    return route.getRouteNumber() == routeNumber;
                });

            if (it != routes.end()) {
                routes.erase(it, routes.end());
                std::cout << "Маршрут с номером " << routeNumber << " удален.\n";
            }
            else {
                std::cout << "Маршрут с номером " << routeNumber << " не найден.\n";
            }

            break;
        }

        case 7: {
            FileProcessor fileProcessor;

            try {
                std::string fileName;
                std::cout << "Введите имя файла: ";
                std::cin >> fileName;
                fileProcessor.setFileName(fileName);
                fileProcessor.processFile();
            }
            catch (const std::exception& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
            }

            break;
        }

        case 8:
            std::cout << "Программа завершена.\n";
            break;

        default:
            std::cout << "Некорректный выбор. Пожалуйста, введите допустимую опцию.\n";
        }

    } while (choice != 8);

    return 0;
}
