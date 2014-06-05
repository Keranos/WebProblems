// #191 Intersections
#include <iostream>

int main(){
  double lx1, lx2, ly1, ly2;
  double x1, x2, y1, y2;
  double m, b;
  int n;
  int count=0; 

  std::cin >> n;
  while(n != count){
    std::cin >> lx1 >> ly1 >> lx2 >> ly2 >> x1 >> y2 >> x2 >> y1;
    if((ly1 < y1 && ly2 < y1) || (ly1 > y2 && ly2 > y2) || 
       (lx1 < x1 && lx2 < x1) || (lx1 > x2 && lx2 > x2))
      std::cout << "F" << std::endl;
    else if(lx1 > x1 && lx1 < x2 && lx2 > x2 && lx2 < x2 && 
            ly2 > y1 && ly2 < y2 && ly2 > y2 && ly2 < y2)
      std::cout << "F" << std::endl;
    else{
      if(
    }
    count++;
  }
}