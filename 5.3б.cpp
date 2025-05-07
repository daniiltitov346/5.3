////2.4
//#include <iostream>
//#include <forward_list>
//#include <algorithm>
//
//std::forward_list<char> getCommonElements(
//    const std::forward_list<char>& L1,
//    const std::forward_list<char>& L2) {
//
//    std::forward_list<char> result;
//    auto result_end = result.before_begin();
//
//    // Проходим по каждому элементу L1
//    for (char elem : L1) {
//        // Проверяем, есть ли элемент в L2
//        bool found_in_L2 = std::find(L2.begin(), L2.end(), elem) != L2.end();
//
//        // Проверяем, нет ли элемента уже в result
//        bool not_in_result = std::find(result.begin(), result.end(), elem) == result.end();
//
//        if (found_in_L2 && not_in_result) {
//            result_end = result.insert_after(result_end, elem);
//        }
//    }
//
//    return result;
//}
//
//int main() {
//    std::forward_list<char> L1 = { 'a', 'b', 'c', 'd', 'e', 'a', 'f' };
//    std::forward_list<char> L2 = { 'b', 'd', 'e', 'g', 'h', 'b' };
//
//    // Получаем общие элементы
//    std::forward_list<char> commonElements = getCommonElements(L1, L2);
//
//    std::cout << "Common elements: ";
//    for (char elem : commonElements) {
//        std::cout << elem << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}

//2.6
#include <iostream>
#include <list>

double calculateProduct(const std::list<double>& lst) {
    double product = 1.0;
    auto it_begin = lst.begin();
    auto it_end = --lst.end();  // Последний элемент

    while (it_begin != it_end && std::next(it_begin) != it_end) {
        product *= (*it_begin - *it_end);
        ++it_begin;
        --it_end;
    }

    // Если количество элементов нечётное, обрабатываем центральный элемент
    if (it_begin == it_end) {
        product *= *it_begin;  // Или просто пропускаем, если нужно только попарное умножение
    }
    else {
        product *= (*it_begin - *it_end);  // Последняя пара
    }

    return product;
}

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    std::list<double> values;
    std::cout << "Enter " << 2 * n << " numbers: ";

    for (int i = 0; i < 2 * n; ++i) {
        double num;
        std::cin >> num;
        values.push_back(num);
    }

    double result = calculateProduct(values);
    std::cout << "Result: " << result << std::endl;

    return 0;
}