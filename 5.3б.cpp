////2.4
//#include <iostream>
//#include <forward_list>
//#include <list>
//#include <algorithm>
//
//// Функция для создания списка общих элементов
//std::list<char> getCommonElements(
//    const std::forward_list<char>& L1,
//    const std::list<char>& L2) {
//
//    std::list<char> result; // Результирующий список
//
//    // Проходим по каждому элементу L1
//    for (char elem : L1) {
//        // Проверяем, есть ли элемент в L2 и нет ли его уже в result
//        if (std::find(L2.begin(), L2.end(), elem) != L2.end() &&
//            std::find(result.begin(), result.end(), elem) == result.end()) {
//            result.push_back(elem); // Добавляем в результат
//        }
//    }
//
//    return result;
//}
//
//int main() {
//    std::forward_list<char> L1 = { 'a', 'b', 'c', 'd', 'e', 'a', 'f' };
//    std::list<char> L2 = { 'b', 'd', 'e', 'g', 'h', 'b' };
//
//    // Получаем общие элементы
//    std::list<char> commonElements = getCommonElements(L1, L2);
//
//    std::cout << "common elements: ";
//    for (char elem : commonElements) {
//        std::cout << elem << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}


//2.6
#include <iostream>
#include <forward_list>
#include <list>
#include <cmath> 

double calculateProduct(int n, const std::forward_list<double>& nums) {
    // Создаем список из forward_list 
    std::list<double> lst(nums.begin(), nums.end());

    double product = 1.0;
    auto it_front = lst.begin();
    auto it_back = lst.end();
    --it_back; // Перемещаемся на последний элемент

    for (int i = 0; i < n; ++i) {
        // (a_{n-i} - a_{n+i+1})
        double diff = *std::next(it_front, n - i - 1) - *std::next(it_front, n + i);
        product *= diff;
    }

    return product;
}

int main() {
    int n;
    std::cout << "enter n: ";
    std::cin >> n;

    std::forward_list<double> values;
    std::cout << "enter " << 2 * n << " numbers: ";

    // Заполняем forward_list с конца 
    for (int i = 0; i < 2 * n; ++i) {
        double num;
        std::cin >> num;
        values.push_front(num);
    }

    // Разворачиваем список, чтобы получить правильный порядок
    values.reverse();

    double result = calculateProduct(n, values);
    std::cout << "result: " << result << std::endl;

    return 0;
}