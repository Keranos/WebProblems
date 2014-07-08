#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include "math.h"

int main(){
  std::string s, sh, sm, ss = ":";
  size_t found;
  double h, m, h_angle, m_angle, angle;

  while(std::cin >> s && s != "0:00"){
    found = s.find(ss);
    sh = s.substr(0,found);
    sm = s.substr(found+1, s.size()-found);

    std::istringstream hStream(sh);
    hStream >> h;
    std::istringstream mStream(sm);
    mStream >> m;

    h_angle = 30.0*h + m*0.5;
    m_angle = 6.0*m;
    
    angle = fabs(h_angle - m_angle);
    if(angle > 180.0) angle = 360.0 - angle;

    std::cout << std::fixed << std::showpoint << std::setprecision(3) << angle << std::endl;    
  }
}