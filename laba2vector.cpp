#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "functions.h"


void vector_output(std::vector<std::string>* names, std::vector<int>* marks, int size);
template <typename T>
std::vector<T> file_to_vector(std::string filename, int length_of_sample);
void Mean(std::vector <int>* marks, int size);
void Median(std::vector <int>* marks, int size);
void Mode(std::vector <int>* marks, int size);

int main()
{
    std::locale::global(std::locale(".utf8"));
    std::vector<std::string> names;
    std::vector<int> marks;
    int length_of_sample = 0;
    int item=0;
    std::cout << "Hello! select an item:\n1.demostration \n2.Random data Analysis  \n3.User data analysis\n";
    std::cin >> item;
    if (item == 1) {
        names = { "Olivia", "XiaoWang", "David", "Masha", "Eric", "Cassie", "Sharlotte", "Mark", "Katy", "Chloe" };
        marks = { 31,87, 98, 100, 45, 23, 65, 78, 53, 100 };
        length_of_sample = 10;
   
    }
    else if (item == 2) {
        std::cout<< "Enter lenght of sample" << std::endl;
        std::cin >> length_of_sample;
        names = file_to_vector<std::string>("names.txt", length_of_sample);
        marks = file_to_vector<int>("marks.txt", length_of_sample);
        
    }
    else if (item == 3) {
        int inputi;
        std::string inputs;
        std:: cout << "Enter lenght of sample" << std::endl;
        std::cin >> length_of_sample;
        for (int i = 0; i < length_of_sample; i++) {
            std::cout << "Name: ";
            std::cin >> inputs;
            names.push_back(inputs);
            std::cout << "Mark" << ":  ";
            std::cin >> inputi;
            marks.push_back(inputi);
        }

        
    }
    vector_output(&names, &marks, length_of_sample);
    std::cout << "Analysis:" << std::endl;
    Mean(&marks, length_of_sample);
    Median(&marks, length_of_sample);
    Mode(&marks, length_of_sample);


    int add_delete = 0;
    std::cout << "Enter the item, if u wanna:\n0 - cancel, 1 - add, 2 - delete" << std::endl;
    std::cin >> add_delete;
    if (add_delete == 1) {
        int inputi, len_of_samp=0;
        std::string inputs;
        std::cout << "Enter how mach u wanna add" << std::endl;
        std::cin >> len_of_samp;
        length_of_sample += len_of_samp;
        for (int i = 0; i < len_of_samp; i++) {
            std::cout << "Name: ";
            std::cin >> inputs;
            names.push_back(inputs);
            std::cout << "Mark" << ":  ";
            std::cin >> inputi;
            marks.push_back(inputi);
        }
        
    }
    else {
        if (add_delete == 2) {
            std::string delname;
            std::cout << "Wich one do u want to delete(enter name)" << std::endl;
            std::cin >> delname;
            for (int i = 0; i < length_of_sample; i++) {
                if ((names)[i] == delname) {
                    names.erase(names.begin() + i);
                    marks.erase(marks.begin() + i);
                    break;

                }
            }
            length_of_sample -= 1;
        }
    }
    
  /*  std::cout << "data with edited lines:" << std::endl;
    vector_output(&names, &marks, length_of_sample);*/
    std::cout << "Analysis with changes data:" << std::endl;
    Mean(&marks, length_of_sample);
    Median(&marks, length_of_sample);
    Mode(&marks, length_of_sample);
    
    return 0;
}