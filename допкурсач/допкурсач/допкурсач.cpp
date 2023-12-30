﻿#include <iostream>
#include "Stack.h"

int main() {
    Stack stack;

    int option;
    int value;

    do {
        std::cout << "Выберите опцию:\n";
        std::cout << "1. Добавить элемент в стек\n";
        std::cout << "2. Удалить элемент из стека\n";
        std::cout << "3. Вывести содержимое стека\n";
        std::cout << "4. Вывести длину стека\n";
        std::cout << "5. Инвертировать стек\n";
        std::cout << "6. Выйти из программы\n";
        std::cout << "Опция: ";
        std::cin >> option;

        switch (option) {
        case 1:
            std::cout << "Введите значение элемента: ";
            std::cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.print();
            break;
        case 4:
            std::cout << "Длина стека: " << stack.length() << std::endl;
            break;
        case 5:
            stack.reverse();
        case 6:
            std::cout << "Выход из программы\n";
            break;
        default:
            std::cout << "Недопустимая опция. Попробуйте снова.\n";
            break;
        }

        std::cout << std::endl;
    } while (option != 6);

    stack.remove();

    return 0;
}

//теория
/*
* стек: первым зашел- последним вышел, данные складываются в "коробку" друг на друга, верхний предмет мешает достать нижние,
  соответсвенно в такой структуре данных что-то делать(добавлять, удалять) можно только с вершиной стека 
  схематически (цифра- порядок входа): 
  3 ↓
  2 ↓
  1 ↓

* очередь: первый пришел-первый вышел. по принципу реальной очереди: первый удаляется - тот, что стоит у кассы, то есть тот, кто первый пришел,
  последний добавляется- тот, кто только встал в очередь
  голова      хвост
  1   2   3   4   5
  <- очередь продвинулась и подошел новый покупатель (#6)
  2   3   4   5  6

* дерево: как семейное дерево- иерархическая структура, узлы и вершины, соединенные ребрами.самый верхний узел без родителя- корневой узел, 
  все нижние- дочерние верхний узел для дочерних- родительский. вершина без дочерних узлов- лист
            A
          / | \
        B   C   D
       / \     / \
      E   F   G   H

*/