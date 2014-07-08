#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <map>
#include <math.h>

double det(double x1, double y1, double x2, double y2, double x3, double y3){
  return fabs(x1*y2 - x1*y3 - y1*x2 + y1*x3 + x2*y3 - x3*y2);
}

class Point{
public:
  double x, y;
};

class Rectangle{
public:
  Rectangle(double nx1, double ny1, double nx2, double ny2);
  bool contained(Point p);
private: 
  double x1, y1, x2, y2;
};

class Circle{
public : 
  Circle(double nx, double ny, double nr);
  bool contained(Point p);
private:
  double x, y, r;
};

class Triangle{
public : 
  Triangle(double nx1, double ny1, double nx2, double ny2, double nx3, double ny3);
  bool contained(Point p);
private: 
  double x1, y1, x2, y2, x3, y3;
};

Rectangle::Rectangle(double nx1, double ny1, double nx2, double ny2){
  this->x1 = nx1; this->y1 = ny1; this->x2 = nx2; this->y2 = ny2;
}

bool Rectangle::contained(Point p){
  if(p.x > this->x1 && p.x < this->x2 && p.y < this->y1 && p.y > this->y2)
    return true;
  return false;
}

Circle::Circle(double nx, double ny, double nr){
  this->x = nx; this->y = ny; this->r = nr;
}

bool Circle::contained(Point p){
  if((this->x-p.x)*(this->x-p.x) + (this->y-p.y)*(this->y-p.y) < this->r*this->r)
    return true;
  return false;
}

Triangle::Triangle(double nx1, double ny1, double nx2, double ny2, double nx3, double ny3){
  this->x1 = nx1; this->y1 = ny1; this->x2 = nx2; this->y2 = ny2; this->x3 = nx3; this->y3 = ny3;
} 

bool Triangle::contained(Point p){
  if((det(this->x1, this->y1, this->x2, this->y2, p.x, p.y) +
     det(this->x1, this->y1, this->x3, this->y3, p.x, p.y) +
     det(this->x2, this->y2, this->x3, this->y3, p.x, p.y) - 
     det(this->x1, this->y1, this->x2, this->y2, this->x3, this->y3)) < 0.0001)
    return true;
  return false;
}

int main(){
  std::vector<Rectangle> vr;
  std::vector<Circle> vc;
  std::vector<Triangle> vt;
  std::vector<std::string> vs;
  std::string c;

  double d1, d2, d3, d4, d5, d6;
  while(std::cin >> c && c != "*"){
    vs.push_back(c);
    if(c == "r"){
      std::cin >> d1 >> d2 >> d3 >> d4;
      Rectangle r(d1, d2, d3, d4);
      vr.push_back(r);
    }
    else if(c == "c"){
      std::cin >> d1 >> d2 >> d3;
      Circle c(d1, d2, d3);
      vc.push_back(c);
    }
    else if(c == "t"){
      std::cin >> d1 >> d2 >> d3 >> d4 >> d5 >> d6;
      Triangle t(d1, d2, d3, d4, d5, d6);
      vt.push_back(t);
    }
  }

  Point p;
  std::vector<std::string>::iterator siter;
  int p_count = 0;

  while(std::cin >> p.x >> p.y && (p.x != 9999.9 && p.y != 9999.9)){
    std::vector<Rectangle>::iterator riter = vr.begin();
    std::vector<Circle>::iterator citer = vc.begin();
    std::vector<Triangle>::iterator titer = vt.begin();
    p_count++;
    bool contains, ever = false;
    int f_count = 0;
    for(siter = vs.begin(); siter != vs.end(); ++siter){
      f_count++;
      if(*siter == "r"){
        contains = (*riter).contained(p);
        riter++;
      }
      if(*siter == "c"){
        contains = (*citer).contained(p);
        citer++;
      }
      if(*siter == "t"){
        contains = (*titer).contained(p);
        titer++;
      }
      if(contains){
        std::cout << "Point " << p_count << " is contained in figure " << f_count << std::endl;
        ever = true;
      }
    }
    if(!ever)
      std::cout << "Point " << p_count << " is not contained in any figure" << std::endl;
  }  
 
}