#include <iostream>

using namespace std;

class RaceCar{
    protected:
        double price;
        int speed;
        int distance;
    public:

        virtual RaceCar buy(){
            RaceCar new_race_car;
            new_race_car.setPrice(200000.00);
            new_race_car.setSpeed(300);
            new_race_car.setDistance(0);
            return new_race_car;
        }

        void setPrice(double price){
            this->price = price;
        }

        void setSpeed(int speed){
            this->speed = speed;
        }

        void setDistance(int distance){
            this->distance = distance;
        }

        double getPrice(){
            return price;
        }

        int getSpeed(){
            return speed;
        }

        int getDistance(){
            return distance;
        }

        void drive(){
            distance += speed;
        }
        //Compare two cars with speed
        bool operator|(RaceCar car) const {
            return this->speed > car.getSpeed();
        }
        //Compare two cars with distance
        bool operator>(RaceCar car) const {
            return this->distance > car.getDistance();
        }
        //Compare two cars with distance
        bool operator<(RaceCar car) const {
            return this->distance < car.getDistance();
        }
        friend ostream& operator<<(ostream& output, RaceCar car){
            output << "Price : " << car.getPrice();
            output << "Speed : " << car.getSpeed();
            output << "Distance : " << car.getDistance();
            return output;
        }
};

int main(){
    RaceCar car;
    RaceCar car1;
    car.buy();
    car1.buy();
    car.drive();
    car1.drive();

    return 0;
}