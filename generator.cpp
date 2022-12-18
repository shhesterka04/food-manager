#include <iostream>
#include <vector>
#include <algorithm>

bool comp(std::vector<int> a, std::vector<int> b) {
    if (a[4] == b[4]) {
        if (a[0] == b[0]) {
            if (a[1] == b[1]) {
                if (a[2] == b[2]) {
                    return (a[3] > b[3]);
                }
                else {
                    return (a[2] > b[2]);
                }
            }
            else {
                return (a[0] > b[0]);
            }
        }
        else {
            return (a[0] > b[0]);
    }
    }
    else {
        return (a[4] < b[4]);
    }
}

//int kkal, int p, int f, int c, int counter или на вход экземпляр пользователя?
void make_diet() {
}

int main() {
    std::vector<std::vector<int>> data = {
        {164, 4,23,20,2},
        {489,23,76,88,0},
        {564,56,99,98,3},
        {395,23,27,35,0},
        {418,32,54,52,0},
        {412,11,63,12,0},
        {368,16,32,23,0},
        {410,9,81,73, 0},
        {266,29,51,12,0},
        {520,52,42,83,0},
        {260,32,22,13,0},
        {257,22,19,11,0},
        {357,41,52,46,0},
        {189,12,7,11, 0},
        {221,9,13,23, 0},
        {458,23,24,75,0},
        {364,32,32,32,0},
        {178,16,13,11,0},
        {542,15,43,84,0},
        {211,12,23,22,0}
        //{kkal, p, f, c, counter}
    };
    double my_kkal = 2656;
    double my_p = 107;
    double my_c = 377;
    double my_f = 89;
    int meals = 3;
    for (int meal = 0; meal < meals; ++meal) {
        std::sort(data.begin(),data.end(), comp);
        for (int i = 0; i < data.size(); ++i) {
            if (data[i][0] < my_kkal*1.1 && data[i][1] < my_p*1.1 && data[i][2] < my_c*1.1 && data[i][3] < my_f*1.1) {
                std::cout << "Блюдо №" << meal+1 << std::endl << 
                "Калорий: " << data[i][0] << std::endl <<
                "Белков: " << data[i][1] << std::endl <<
                "Жиров: " << data[i][2] << std::endl <<
                "Углеводов: " << data[i][3] << std::endl <<
                std::endl;
                my_kkal -= data[i][0];
                my_p -= data[i][1];
                my_c -= data[i][2];
                my_f -= data[i][3];
                data[i][4]++;
            }
        }  
    }
    
    // for (int day = 0; day < 7; ++day) {
    //     for (int meal = 0; meal < meals; ++meal) {
            
    //         //взять вставить первый элемент, увеличить счетчик (при условии, что нужных калорий > в блюде (см. цель!))
    //         //опять отсортировать?
    //     }
    // }
    return 0;
}
