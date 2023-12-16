// Krugi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include "Krug_class.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string filename;
    Krug circle1(1, 2, 2, 34, 45, 56);
    Krug circle2(1, 2, 2, 34, 45, 56);
    Krug circle3(1, 2, 2, 34, 45, 56);

    int R, G, B;
    std::string change, item;
    double x, y, r;
    
    std::cout << "Введите номер круга(1-3), который хотите изменить, если желаете прекратить изменения введите '0'" << std::endl;
    std::cin >> item;
    while (true) {
        if (item != "0") {
            if (item == "1") {
                std::cout << "Введите 1.изменить х \t2.изменить у \t3.изменить r \t4.изменить цвет \t5.изменить цвет на рандомный \t6.изменить все \t7.ничего не менять" << std::endl;
                std::cin >> change;
                while (true) {
                    if (change != "7") {
                        switch (std::stoi(change))
                        {
                        case 1:
                            std::cout << "Введите новое значение х" << std::endl;
                            std::cin >> x;
                            circle1.SetX(x);
                            break;
                        case 2:
                            std::cout << "Введите новое значение y" << std::endl;
                            std::cin >> y;
                            circle1.SetY(y);
                            break;
                        case 3:
                            std::cout << "Введите новое значение r" << std::endl;
                            std::cin >> r;
                            circle1.SetR(r);
                            break;
                        case 4:
                            std::cout << "Введите новое значение RGB" << std::endl;
                            std::cin >> R;
                            std::cin >> G;
                            std::cin >> B;
                            circle1.Set_Color(R, G, B);
                            break;
                        case 5:
                            circle1.Krug_Color();
                            break;
                        case 6:
                        {//только этот кейс взяла в скобки фигурные, так как инчае ошибка C2361 https://learn.microsoft.com/ru-ru/cpp/error-messages/compiler-errors-1/compiler-error-c2361?view=msvc-170&f1url=%3FappId%3DDev16IDEF1%26l%3DRU-RU%26k%3Dk(C2361)%26rd%3Dtrue
                            std::cout << "Введите новое значение х" << std::endl;
                            std::cin >> x;
                            std::cout << "Введите новое значение y" << std::endl;
                            std::cin >> y;
                            std::cout << "Введите новое значение r" << std::endl;
                            std::cin >> r;
                            std::cout << "Введите новое значение RGB" << std::endl;
                            std::cin >> R;
                            std::cin >> G;
                            std::cin >> B;
                            /*circle1.SetX(x);
                            circle1.SetY(y);
                            circle1.SetR(r);
                            circle1.Set_Color(R, G, B);*/
                            Krug circle1(x, y, r, R, G, B);
                            break; }
                        default:
                            break;
                        }
                        std::cout << "Введите 1.изменить х \t2.изменить у \t3.изменить r \t4.изменить цвет \t5.изменить цвет на рандомный \t6.изменить все \t7.больше ничего не менять" << std::endl;
                        std::cin >> change;
                    }
                    else break;
                }
            }
            else if (item == "3") {
                std::cout << "Введите 1.изменить х \t2.изменить у \t3.изменить r \t4.изменить цвет \t5.изменить цвет на рандомный \t6.изменить все \t7.ничего не менять" << std::endl;
                std::cin >> change;
                while (true) {
                    if (change != "7") {
                        switch (std::stoi(change))
                        {
                        case 1:
                            std::cout << "Введите новое значение х" << std::endl;
                            std::cin >> x;
                            circle3.SetX(x);
                            break;
                        case 2:
                            std::cout << "Введите новое значение y" << std::endl;
                            std::cin >> y;
                            circle3.SetY(y);
                            break;
                        case 3:
                            std::cout << "Введите новое значение r" << std::endl;
                            std::cin >> r;
                            circle3.SetR(r);
                            break;
                        case 4:
                            std::cout << "Введите новое значение RGB" << std::endl;
                            std::cin >> R;
                            std::cin >> G;
                            std::cin >> B;
                            circle3.Set_Color(R, G, B);
                            break;
                        case 5:
                            circle3.Krug_Color();
                            break;
                        case 6: 
                        {
                            std::cout << "Введите новое значение х" << std::endl;
                            std::cin >> x;
                            std::cout << "Введите новое значение y" << std::endl;
                            std::cin >> y;
                            std::cout << "Введите новое значение r" << std::endl;
                            std::cin >> r;
                            std::cout << "Введите новое значение RGB" << std::endl;
                            std::cin >> R;
                            std::cin >> G;
                            std::cin >> B;
                            /*circle3.SetX(x);
                            circle3.SetY(y);
                            circle3.SetR(r);
                            circle3.Set_Color(R, G, B);*/
                            Krug circle3(x, y, r, R, G, B);
                            break;
                        }
                        default:
                            break;
                        }
                        std::cout << "Введите 1.изменить х \t2.изменить у \t3.изменить r \t4.изменить цвет \t5.изменить цвет на рандомный \t6.изменить все \t7.больше ничего не менять" << std::endl;
                        std::cin >> change;
                    }
                    else break;
                }

            }
            else if (item == "2") {
                std::cout << "Введите 1.изменить х \t2.изменить у \t3.изменить r \t4.изменить цвет \t5.изменить цвет на рандомный \t6.изменить все \t7.ничего не менять" << std::endl;
                std::cin >> change;
                while (true) {
                    if (change != "7") {
                        switch (std::stoi(change))
                        {
                        case 1:
                            std::cout << "Введите новое значение х" << std::endl;
                            std::cin >> x;
                            circle2.SetX(x);
                            break;
                        case 2:
                            std::cout << "Введите новое значение y" << std::endl;
                            std::cin >> y;
                            circle2.SetY(y);
                            break;
                        case 3:
                            std::cout << "Введите новое значение r" << std::endl;
                            std::cin >> r;
                            circle2.SetR(r);
                            break;
                        case 4:
                            std::cout << "Введите новое значение RGB" << std::endl;
                            std::cin >> R;
                            std::cin >> G;
                            std::cin >> B;
                            circle2.Set_Color(R, G, B);
                            break;
                        case 5:
                            circle2.Krug_Color();
                            break;
                        case 6:
                        {
                            std::cout << "Введите новое значение х" << std::endl;
                            std::cin >> x;
                            std::cout << "Введите новое значение y" << std::endl;
                            std::cin >> y;
                            std::cout << "Введите новое значение r" << std::endl;
                            std::cin >> r;
                            std::cout << "Введите новое значение RGB" << std::endl;
                            std::cin >> R;
                            std::cin >> G;
                            std::cin >> B;
                            /*circle2.SetX(x);
                            circle2.SetY(y);
                            circle2.SetR(r);
                            circle2.Set_Color(R, G, B);*/
                            Krug circle2(x, y, r, R, G, B);
                            break; }
                        default:
                            break;
                        }
                        std::cout << "Введите 1.изменить х \t2.изменить у \t3.изменить r \t4.изменить цвет \t5.изменить цвет на рандомный \t6.изменить все \t7.больше ничего не менять" << std::endl;
                        std::cin >> change;
                    }
                    else break;
                }

            }
            else break;
            std::cout << "Введите номер круга(1-3), который хотите изменить, если желаете прекратить изменения введите '0'" << std::endl;
            std::cin >> item;
        }
        else break;
    }
    circle1.Krug_Square();
    circle1.Krug_Lenght();
    circle2.Krug_Square();
    circle2.Krug_Lenght();
    circle3.Krug_Square();
    circle3.Krug_Lenght();
    filename = "Data1.txt";
    circle1.PrintFile(&filename);
    filename = "Data2.txt";
    circle2.PrintFile(&filename);
    filename = "Data3.txt";
    circle3.PrintFile(&filename);


    /*
    //в один файл
    std::ofstream file("Data.txt");
    file << "x\ty\tr\tcolor(RGB)" << "\tcircle1 circle" << std::endl;
    file << circle1.getX() << "\t" << circle1.getY() << "\t" << circle1.getR() << "\t" << circle1.getColor() << "\t" << std::endl;
    file << "x\ty\tr\tcolor(RGB)" << "\tcircle2 circle" << std::endl;
    file << circle2.getX() << "\t" << circle2.getY() << "\t" << circle2.getR() << "\t" << circle2.getColor() << "\t" << std::endl;
    file << "x\ty\tr\tcolor(RGB)" << "\tcircle3 circle" << std::endl;
    file << circle3.getX() << "\t" << circle3.getY() << "\t" << circle3.getR() << "\t" << circle3.getColor() << "\t" << std::endl;*/

}

