#include <iostream>
#include <string>
#include <iomanip> // Добавляем для форматированного вывода
using namespace std;

const int MAX_PRODUCTS = 100; // Максимальное количество продуктов

int main()
{
    setlocale(LC_ALL, "Russian"); // Устанавливаем русскую локаль

    string products[MAX_PRODUCTS]; // Массив для названий товаров
    int quantities[MAX_PRODUCTS];  // Массив для количества проданных единиц
    double prices[MAX_PRODUCTS];   // Массив для цены за единицу

    int numProducts;
    cout << "Введите количество продуктов: ";
    cin >> numProducts;

    // Ввод данных о продажах
    for (int i = 0; i < numProducts; i++) {
        cout << "Введите название товара " << i + 1 << ": ";
        cin >> products[i];

        cout << "Введите количество проданных единиц: ";
        cin >> quantities[i];

        cout << "Введите цену за единицу: ";
        cin >> prices[i];
    }

    // Вычисление общей суммы и средней цены
    double totalSales = 0;
    for (int i = 0; i < numProducts; i++) {
        totalSales += quantities[i] * prices[i];
    }
    double averagePrice = totalSales / numProducts;

    // Сортировка товаров по названиям
    for (int i = 0; i < numProducts - 1; i++) {
        for (int j = 0; j < numProducts - i - 1; j++) {
            if (products[j] > products[j + 1]) {
                swap(products[j], products[j + 1]);
                swap(quantities[j], quantities[j + 1]);
                swap(prices[j], prices[j + 1]);
            }
        }
    }

    // Вывод результатов
    cout << "\nОбщая сумма продаж: " << fixed << setprecision(2) << totalSales << endl;
    cout << "Средняя цена за единицу товара: " << fixed << setprecision(2) << averagePrice << endl;

    cout << "\nОтсортированный список продуктов:\n";
    for (int i = 0; i < numProducts; i++) {
        cout << "Название: " << products[i] << ", Количество: " << quantities[i] << ", Цена: " << prices[i] << endl;
    }

    return 0;
}
