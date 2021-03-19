//
// Created by Pochita on 2021/3/19.
//

//No.1603
class ParkingSystem {
private:
    int b, m, s;
public:
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }

    bool addCar(int carType) {
        switch (carType) {
            case 1:
                b--;
                return b >= 0;
            case 2:
                m--;
                return m >= 0;
            case 3:
                s--;
                return s >= 0;
        }
    }
};