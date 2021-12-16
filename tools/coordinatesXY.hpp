class coordinatesXY{
private:
    float X = 0,Y = 0;
public:
    float getX() const{
        return X;
    }
    float getY() const{
        return Y;
    }
    void setX(float newX){
        this->X = newX;
    }
    void setY(float newY){
        this->Y = newY;
    }
    float distanceFrom(coordinatesXY point) const;
    coordinatesXY();
    coordinatesXY(float X, float Y);
};

coordinatesXY::coordinatesXY() {
    X = 0;
    Y = 0;
}

coordinatesXY::coordinatesXY(float X, float Y) {
    this->X = X;
    this->Y = Y;
}

float coordinatesXY::distanceFrom(coordinatesXY point) const{
    return std::abs(abs(point.getX() - this->X) + abs(point.getY() - this->Y));
}