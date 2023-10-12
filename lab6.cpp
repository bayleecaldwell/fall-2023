#include <iostream>

class Point {
private:
  double x;
  double y;
  double z;

public:
  
  Point() : x(0.0), y(0.0), z(0.0) {}
  Point(double newX, double newY, double newZ) : x(newX), y(newY), z(newZ) {}

  
  void setCoordinates(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  void move(double offsetX, double offsetY, double offsetZ) {
    x += offsetX;
    y += offsetY;
    z += offsetZ;
  }

  void move(Point* offset) {
    x += offset->getX();
    y += offset->getY();
    z += offset->getZ();
  }

  double getX() const {
    return x;
  }

  double getY() const {
    return y;
  }

  double getZ() const {
    return z;
  }
};

int main() {
  Point point1; 
  Point point2(3.0, 3.0, 3.0); 

  
  std::cout << "Point 1: " << point1.getX() << " " << point1.getY() << " " << point1.getZ() << std::endl;
  std::cout << "Point 2: " << point2.getX() << " " << point2.getY() << " " << point2.getZ() << std::endl;

  
  point1.setCoordinates(2.0, 1.0, 2.0);
  point1.move(&point2);

 
  std::cout << "Updated Point 1: " << point1.getX() << " " << point1.getY() << " " << point1.getZ() << std::endl;

  
  point2.move(3.0, 3.0, 3.0);

  
  std::cout << "Updated Point 2: " << point2.getX() << " " << point2.getY() << " " << point2.getZ() << std::endl;

  return 0;
}
