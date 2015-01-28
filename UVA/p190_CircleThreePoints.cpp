#include <iostream>
#include <cmath>
#include <iomanip>

struct P{
  double x;
  double y;
};

P circumcenter(const P& A, const P& B, const P& C){
  P p;
  double D = 2.0 * (A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y));
  double As = A.x*A.x + A.y*A.y;
  double Bs = B.x*B.x + B.y*B.y;
  double Cs = C.x*C.x + C.y*C.y;
  
  p.x = (As*(B.y - C.y) + Bs*(C.y - A.y) + Cs*(A.y - B.y)) / D;
  p.y = (As*(C.x - B.x) + Bs*(A.x - C.x) + Cs*(B.x - A.x)) / D;

  return p;
}

double distance(const P& p1, const P& p2){
  return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

void posneg(const double& d){
  if(d == -0.0)
    std::cout << "+ " << std::abs(d);
  if(d < 0.0)
    std::cout << "- " << std::abs(d);
  else
    std::cout << "+ " << d;
}

void print(const P& p, const double& r){
  std::cout << "(x ";
  posneg(-1.0*p.x);
  std::cout << ")^2 + (y ";
  posneg(-1.0*p.y); 
  std::cout << ")^2";
  std::cout << " = " << r << "^2";

  std::cout << std::endl;

  double t = p.x*p.x + p.y*p.y - r*r;

  std::cout << "x^2 + y^2 ";
  posneg(-2.0*p.x);
  std::cout << "x ";
  posneg(-2.0*p.y);
  std::cout << "y ";
  posneg(t);
  std::cout << " = 0" << std::endl << std::endl;
}

int main(){
  std::cout << std::fixed;
  std::cout << std::setprecision(3); 

  P a, b, c;
  double ax, ay, bx, by, cx, cy;
  while(std::cin >> ax >> ay >> bx >> by >> cx >> cy){
    a.x = ax; a.y = ay;
    b.x = bx; b.y = by;
    c.x = cx; c.y = cy;
    
    P u = circumcenter(a, b, c);
     
    print(u, distance(u, c));
  }

  return 0;
}
