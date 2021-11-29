#include "coordinatesXY.hpp"

class trajectory{
private:
    float coeffX;
    float coeffY;
public:
    void calculateTrajectory(coordinatesXY origin, coordinatesXY destination);
    void printTrajectory();
    float getCoeffX();
    float getCoeffY();
};

void trajectory::calculateTrajectory(coordinatesXY origin, coordinatesXY destination) {
    float totalX = destination.getX() - origin.getX();
    float totalY = destination.getY() - origin.getY();
    float total = totalX + totalY;
    coeffX = totalX/total;
    coeffY = 1 - coeffX;
}

void trajectory::printTrajectory() {
    std::cout << "X :" << coeffX << " Y :" << coeffY << std::endl;
}

float trajectory::getCoeffX() {
    return coeffX;
}
float trajectory::getCoeffY() {
    return coeffY;
}

