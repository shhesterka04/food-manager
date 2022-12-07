#include <iostream>
#include <string>
#include <vector>

int get_cal(double height, double weight, int age, std::string gender) {
    double msj_eq = 0;
    double rhb_eq = 0;
    if (gender == "M") {
        msj_eq = 10 * weight + 6.25 * height - 5 * age + 5;
        rhb_eq = 13.397 * weight + 4.799 * height - 5.677 * age + 88.362;
    }
    if (gender == "F") {
        msj_eq = 10 * weight + 6.25 * height - 5 * age - 161;
        rhb_eq = 9.247 * weight + 3.098 * height - 4.330 * age + 447.593;
    }
    double cal_passive = (msj_eq + rhb_eq) / 2;
    return cal_passive;
}

// int get_multi(std::string goal, std::string activity) {
//     return 0;
// }

// std::vector<double> make_plan(double height, double weight, int age, std::string gender, std::string goal, std::string activity) {
//     std::vector<double> your_rec(4,0);
//     double your_cal = your_cal = int(get_multi(goal, activity) * get_cal(height, weight, age, gender));
//     double proteins = int(weight * 2.2);
//     double fats = int(your_cal / 27);
//     double carbohydrates = int((your_cal - (proteins * 4 + fats * 9)) / 4);
//     your_rec[0] = your_cal;
//     your_rec[1] = proteins;
//     your_rec[2] = fats;
//     your_rec[3] = carbohydrates;
//     return your_rec;
// }

int main() {
    std::cout << get_cal(173, 66.6, 19, "M");
	return 0;
}