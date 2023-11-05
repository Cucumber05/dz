#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

void vector_output(std::vector<std::string>* names, std::vector<int>* marks, int size) {
    if ((names != nullptr) && (marks != nullptr)) {
        for (int i = 0; i < size; ++i) {
            std::cout << (*names)[i] << "-" << (*marks)[i] << std::endl;
        }
    }

}

template <typename T>
std::vector<T> file_to_vector(std::string filename, int length_of_sample) {
    std::vector<T> vec;
    T line;
    int i = 0;
    std::locale::global(std::locale(".utf8"));
    std::ifstream vec_list(filename);
    if (!vec_list.is_open()) {
        std::cout << "The file could not be opened" << std::endl;
    }
    else {
        while ((vec_list >> line) && i < length_of_sample) {
            vec.push_back(line);
            i++;
        }
    }
    vec_list.close();
    return vec;
}


void Mean(std::vector <int>* marks, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += (*marks)[i];
    }
    std::cout << "Mean:" << sum / size << std::endl;
}

void Median(std::vector <int>* marks, int size) {
    std::vector<int> median(2, 0);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if ((*marks)[j] > (*marks)[j + 1]) {
                int temp = (*marks)[j];
                (*marks)[j] = (*marks)[j + 1];
                (*marks)[j + 1] = temp;
            }
        }
    }
    /*for (int i = 0; i < size; ++i) {
        std::cout << (*marks)[i] << std::endl;
    }*/
    if (size % 2 == 0) {
        median[0] = (*marks)[size / 2 - 1];
        median[1] = (*marks)[size / 2];
        std::cout << "Median:" << median[0] << " " << median[1] << std::endl;
    }
    else {
        median[0] = (*marks)[size / 2];
        std::cout << "Median:" << median[0] << std::endl;
    }
}

void Mode(std::vector <int>* marks, int size) {
    int k = 0, v = 0, maxk = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if ((*marks)[j] > (*marks)[j + 1]) {
                int temp = (*marks)[j];
                (*marks)[j] = (*marks)[j + 1];
                (*marks)[j + 1] = temp;
            }
        }
    }
    /*for (int i = 0; i < size; ++i) {
        cout << (*marks)[i] << endl;
    }*/
    for (int i = 0; i < size - 1; ++i) {
        if ((*marks)[i] == (*marks)[i + 1]) {
            k++;
        }
        else {
            if (k > maxk) {
                maxk = k;
                v = (*marks)[i];

            }
            k = 0;
        }
    }
    for (int i = 0; i < size; ++i) {
        if ((*marks)[i] == v) {
            
        }
    }
    std::cout << "Mode:" << v << std::endl;
}
/*
* Коктейльная сортировка
    void cocktailSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        // Проход слева направо, как в пузырьковой сортировке
        for (int i = start; i < end; ++i) {
            // Если текущий элемент больше следующего, меняем их местами
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Если внутренний цикл не сделал ни одного обмена, значит массив уже отсортирован
        if (!swapped)
            break;
        swapped = false;

        // Уменьшаем диапазон, так как самый большой элемент уже находится в конце
        --end;

        // Проход от конца массива к началу
        for (int i = end - 1; i >= start; --i) {
            // Если текущий элемент больше следующего, меняем их местами
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Увеличиваем начало, так как самый маленький элемент уже находится в начале
        ++start;
    }
}

Выводы векторов:
//range-based for-loop
void printVector(const std::vector<int>& vec) {
  for (const auto& element : vec) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

//с использованием итератора
void printVector(const std::vector<int>& vec) {
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

// с использованием обычного индексового цикла
void printVector(const std::vector<int>& vec) {
  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}
*/

/*
  // Создаем пары (имя, оценка)
  std::vector<std::pair<std::string, int>> nameGradePairs;
  for (int i = 0; i < names.size(); ++i) {
    nameGradePairs.push_back({names[i], grades[i]});
  }

  // Сортируем пары по возрастанию оценок
  std::sort(nameGradePairs.begin(), nameGradePairs.end(), [](const auto& p1,const auto& p2) {
    return p1.second < p2.second;
  });

  // Обновляем векторы имен и оценок с отсортированными значениями
  for (int i = 0; i < nameGradePairs.size(); ++i) {
    names[i] = nameGradePairs[i].first;
    grades[i] = nameGradePairs[i].second;
  }

  // Выводим отсортированные значения
  for (int i = 0; i < names.size(); ++i) {
    std::cout << names[i] << ": " << grades[i] << std::endl;
  }
  return 0;
}*/