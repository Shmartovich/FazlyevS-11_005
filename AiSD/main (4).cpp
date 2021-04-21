#include<iostream>
using namespace std;

int main() {
    //Необходимо найти индекс первого вхождения Х в массив и последнего.
    //Прямым перебором решать нельзя - используйте бинарный поиск.

    const int length = 12;
    int mas[length] = {0, 0, 1, 1, 1, 1, 1, 1, 2, 3, 4};

    int result1;
    int result2;

    int x = 0;
    cin >> x;

    bool is_there = false;


    for (int i = 0; i < 12; i++) {
        if (mas[i] == x) {
            cout << "there is such number" << "\n";
            is_there = true;
            break;
        }
    }

    if (is_there) {
        int index_l_boarder = 0;
        int index_r_boarder = length - 1;

        int index_centre = length / 2;
        if (mas[index_centre] < x) {
            index_l_boarder = index_centre;
            index_centre = (length - 1 - index_centre) / 2;
        } else if (mas[index_centre] > x) {
            index_r_boarder = index_centre;
            index_centre = index_centre / 2;
        } else {
            int index_temp = index_centre;

            while (index_l_boarder + 1 != index_r_boarder) {
                if (mas[index_temp] == x) {
                    index_r_boarder = index_temp;
                    index_temp = (index_r_boarder - index_l_boarder) / 2;
                } else {
                    index_l_boarder = index_temp;
                    index_temp = (index_r_boarder - index_l_boarder) / 2;
                }
            }
            result1 = index_l_boarder;

            while (index_l_boarder + 1 != index_r_boarder) {
                index_temp = index_centre;

                index_l_boarder = index_centre;
                index_r_boarder = length - 1;
                if (mas[index_temp] == x) {
                    index_l_boarder = index_temp;
                    index_temp = (index_r_boarder - index_l_boarder) / 2;
                } else {
                    index_r_boarder = index_temp;
                    index_temp = (index_r_boarder - index_l_boarder) / 2;
                }
            }
            result2 = index_r_boarder;
        }
    }
    cout << result1 << " " << result2;
}