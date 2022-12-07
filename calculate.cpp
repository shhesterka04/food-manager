#include <iostream>
#include <string>
#include <vector>

int get_cal(double height, double weight, int age, std::string sex) {
    double msj_eq = 0;
    double rhb_eq = 0;
    if (sex == "M") {
        msj_eq = 10 * weight + 6.25 * height - 5 * age + 5;
        rhb_eq = 13.397 * weight + 4.799 * height - 5.677 * age + 88.362;
    }
    if (sex == "F") {
        msj_eq = 10 * weight + 6.25 * height - 5 * age - 161;
        rhb_eq = 9.247 * weight + 3.098 * height - 4.330 * age + 447.593;
    }
    double cal_passive = (msj_eq + rhb_eq) / 2;
    return cal_passive;
}

int get_multi(int goal, int activity) {
    double multi = 1;
    if (activity == 1){
        multi *= 1.2;
    }
    else if (activity == 2) {
        multi *= 1.375;
    }
    else if (activity == 3) {
        multi *= 1.550;
    }
    else if (activity == 4) {
        multi *= 1.725;
    }
    else if (activity == 5) {
        multi *= 1.9;
    }

    if (goal == 1) {
        multi *= 1.15;
    }
    else if (goal == 2) {
        multi *= 0.85;
    }
    return multi;
}


void get_bmr(int& proteins, int& fats, int& carbohydrates, double& weight, int& your_cal) {
    proteins = weight * 2.2;
    fats = your_cal / 27;
    carbohydrates = (your_cal - (proteins * 4 + fats * 9)) / 4;
}

class User
{
private:
    double height = 0;
    double weight = 0;
    int age = 0;
    std::string sex = "";
    int goal = -1;
    int activity = -1;
    std::string level = "visitor"; //Добавить
    std::string username = "";
    
    int cal = 0;
    int proteins = 0;
    int fats = 0;
    int carbohydrates = 0;

public:
    void register_user() {
        std::cout << "Enter your username: " ;
        std::cin >> username;
        std::cout << "Enter your height in cm: ";
        std::cin >> height;
        std::cout << "Enter your weight in kg: ";
        std::cin >> weight;
        std::cout << "Enter your full age: ";
        std::cin >> age;
        std::cout << "Enter your sex: 'M' if you man or 'W' if you woman: " << std::endl;
        std::cin >> sex;
        std::cout << "Chose your goal: " << std::endl;
        std::cout << "1) Lose weight" << std::endl;
        std::cout << "2) Save weight" << std::endl;
        std::cout << "3) Gain weight" << std::endl;
        std::cin >> goal;
        std::cout << "Enter your activity level: " << std::endl;
        std::cout << "1) Sedentary: little or no exercise, less than 10,000 steps per day stable" << std::endl;
        std::cout << "2) Low activity: 1-2 workouts or equivalent activity, averaging 10,000 steps per day consistently" << std::endl;
        std::cout << "3) Moderate activity: moderate physical work or 3-5 workouts per week" << std::endl;
        std::cout << "4) High activity: physical work daily or 6-7 workouts per week" << std::endl;
        std::cout << "5) Very high activity: exhausting workouts every day" << std::endl;
        std::cin >> activity;
        cal = get_cal(height, weight, age, sex) * get_multi(goal,activity);
        get_bmr(proteins, fats, carbohydrates, weight, cal);


    }
    void improve_user(){}
    void edit_data() {}
    void add_favorite() {}
    void get_info() {
        std::cout << username << std::endl << cal << std::endl << proteins << std::endl << fats << std::endl << carbohydrates;
    };
};

int main() {
    User new_user = User();
    new_user.register_user();
    new_user.get_info();
	return 0;
}
//TODO: сделать енам для целей и активности
//Сделать тестовый набор рецептов (а мб и не тестовый)
//Написать алгос на дин.проге...