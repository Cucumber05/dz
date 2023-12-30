#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void vector_output(vector<string>* names, vector<int>* marks, int size);
template <typename T>
vector<T> file_to_vector(string filename, int length_of_sample);
void Mean(vector <int>* marks, int size);
void Median(vector <int>* marks, int size);
void Mode(vector <int>* marks, int size);

int main()
{
    ::locale::global(std::locale(".utf8"));
    vector<string> names;
    vector<int> marks;
    int length_of_sample = 0;
    int item=0;
    std::cout << "Hello! select an item:\n1.demostration \n2.Random data Analysis  \n3.User data analysis\n";
    cin >> item;
    if (item == 1) {
        names = { "Olivia", "XiaoWang", "David", "Masha", "Eric", "Cassie", "Sharlotte", "Mark", "Katy", "Chloe" };
        marks = { 31,87, 98, 100, 45, 23, 65, 78, 53, 100 };
        length_of_sample = 10;
   
    }
    else if (item == 2) {
        cout<< "Enter lenght of sample" << endl;
        cin >> length_of_sample;
        names = file_to_vector<string>("names.txt", length_of_sample);
        marks = file_to_vector<int>("marks.txt", length_of_sample);
        
    }
    else if (item == 3) {
        int inputi;
        string inputs;
        cout << "Enter lenght of sample" << endl;
        cin >> length_of_sample;
        for (int i = 0; i < length_of_sample; i++) {
            cout << "Name: ";
            cin >> inputs;
            names.push_back(inputs);
            cout << "Mark" << ":  ";
            cin >> inputi;
            marks.push_back(inputi);
        }

        
    }
    vector_output(&names, &marks, length_of_sample);
    cout << "Analysis:" << endl;
    Mean(&marks, length_of_sample);
    Median(&marks, length_of_sample);
    Mode(&marks, length_of_sample);
    int ade = 0;
    cout << "Enter the item, if u wanna:\n0 - cancel, 1 - add, 2 - delete" << endl;
    cin >> ade;
    if (ade==1) {
        int inputi, len_of_samp;
        string inputs;
        cout << "Enter how mach u wanna add" << endl;
        cin >> len_of_samp;
        for (int i = 0; i < len_of_samp; i++) {
            cout << "Name: ";
            cin >> inputs;
            names.push_back(inputs);
            cout << "Mark" << ":  ";
            cin >> inputi;
            marks.push_back(inputi);
        }
    cout << "data with add lines:" << endl;
    vector_output(&names, &marks, length_of_sample);
    cout << "Analysis with changes data:" << endl;
    Mean(&marks, length_of_sample);
    Median(&marks, length_of_sample);
    Mode(&marks, length_of_sample);
    }


    return 0;
}

void vector_output(vector<string>* names, vector<int>* marks, int size) {
    if ((names != nullptr) && (marks != nullptr)){
        for (int i = 0; i < size; ++i) {
            cout << (*names)[i] << "-" << (*marks)[i] << endl;
        }
    }
    
}

template <typename T>
vector<T> file_to_vector(string filename, int length_of_sample) {
    vector<T> vec;
    T line;
    int i = 0;
    ::locale::global(std::locale(".utf8"));
    ifstream vec_list(filename);
    if (!vec_list.is_open()) {
        cout << "The file could not be opened" << endl;
    }
    else {
        while ((vec_list >> line)&& i< length_of_sample) {
            vec.push_back(line);
            i++;
            }  
    }
    vec_list.close();
    return vec;
}


void Mean(vector <int>* marks, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += (*marks)[i];
    }
    cout << "Mean:" << sum/size << endl;
}

void Median(vector <int>* marks, int size) {
    vector<int> median(2, 0);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if ((*marks)[j] > (*marks)[j + 1]) {
                int temp = (*marks)[j]; 
                (*marks)[j] = (*marks)[j + 1]; 
                (*marks)[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        cout << (*marks)[i] << endl;
    }
    if (size % 2 == 0) {
        median[0] = (*marks)[size / 2 - 1];
        median[1] = (*marks)[size / 2];
        cout << "Median:" << median[0] << " " << median[1] << endl;
    }
    else {
        median[0] = (*marks)[size / 2];
        cout << "Median:" << median[0] << endl;
    }
}

void Mode(vector <int>* marks, int size) {
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
    for (int i = 0; i < size-1; ++i) {
        if ((*marks)[i] == (*marks)[i + 1]) {
            k++;
        }
        else {
            if (k > maxk){
                maxk = k;
                v = (*marks)[i];

            }
            k = 0;
        }
    }
    cout << "Mode:" << v << endl;
}
/*void shaker() {
    bool sort_or_not = true; //показывает менялось ли знач ячейка за 2 цикла

    do {
        sort_or_not = true;
        for (int i = 0; i < n; i++) { // n - размер сортируемого массива
            if (chisla[i] > chisla[i + 1]) {
                swap(chisla[i], chisla[i + 1]);
                sort_or_not = false;
            }
        }
        for (int i = 4; i >= 1; i--) {
            if (chisla[i] < chisla[i - 1]) {
                swap(chisla[i], chisla[i - 1]);
                sort_or_not = false;
            }
        }
    } while (sort_or_not == false);
}*/