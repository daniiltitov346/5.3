//2.4
#include <iostream>
#include <forward_list>
#include <algorithm>

std::forward_list<char> getCommonElements(
    const std::forward_list<char>& L1,
    const std::forward_list<char>& L2) {

    std::forward_list<char> result;
    auto result_end = result.before_begin();

    // Проходим по каждому элементу L1
    for (char elem : L1) {
        // Проверяем, есть ли элемент в L2
        bool found_in_L2 = std::find(L2.begin(), L2.end(), elem) != L2.end();

        // Проверяем, нет ли элемента уже в result
        bool not_in_result = std::find(result.begin(), result.end(), elem) == result.end();

        if (found_in_L2 && not_in_result) {
            result_end = result.insert_after(result_end, elem);
        }
    }

    return result;
}

int main() {
    std::forward_list<char> L1 = { 'a', 'b', 'c', 'd', 'e', 'a', 'f' };
    std::forward_list<char> L2 = { 'b', 'd', 'e', 'g', 'h', 'b' };

    // Получаем общие элементы
    std::forward_list<char> commonElements = getCommonElements(L1, L2);

    std::cout << "Common elements: ";
    for (char elem : commonElements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}


////2.6
//#include <iostream>
//#include <forward_list>
//#include <list>
//#include <cmath> 
//
//double calculateProduct(int n, const std::forward_list<double>& nums) {
//    // Конвертируем односвязный список в двусвязный
//    std::list<double> lst(nums.begin(), nums.end());
//
//    double product = 1.0;
//    auto first = lst.begin();
//    auto last = lst.end();
//    --last;  
//
//    for (int i = 0; i < n; ++i) {
//        auto current_first = first;
//        std::advance(current_first, n - i - 1);  // Перемещаемся к (n-i-1)-му элементу
//
//        auto current_last = last;
//        std::advance(current_last, -i);  // Перемещаемся к (n+i+1)-му элементу с конца
//
//        product *= (*current_first - *current_last);
//    }
//
//    return product;
//}
//int main() {
//    int n;
//    std::cout << "enter n: ";
//    std::cin >> n;
//
//    std::forward_list<double> values;
//    std::cout << "enter " << 2 * n << " numbers: ";
//
//    // Заполняем forward_list с конца 
//    for (int i = 0; i < 2 * n; ++i) {
//        double num;
//        std::cin >> num;
//        values.push_front(num);
//    }
//
//    // Разворачиваем список, чтобы получить правильный порядок
//    values.reverse();
//
//    double result = calculateProduct(n, values);
//    std::cout << "result: " << result << std::endl;
//
//    return 0;
//}