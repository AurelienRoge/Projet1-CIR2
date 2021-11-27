class coordinatesXY{
private:
    float X,Y;
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