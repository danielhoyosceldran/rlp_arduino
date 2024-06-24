// INVERSE KINEMATIKS explication in root path (as a png)

#include <Math.h>

#define PI 3.1415926535897932384626433832795

double upperLimb = 14;
double forearm = 23;

double lleyDelCos(double A, double B, double C) {
  double div = (A*A + B*B - C*C) / (2*A*B);
  if (div < -1.0)
    div = -1.0;
  if(div > 1.0)
    div = 1.0;
  return acos(div);
}

double distance(double x, double y) {
  return sqrt(x*x + y*y);
}

double radiansToDegrees(double radianes) {
  return radianes * 180.0 / PI;
}

void inverseKinematics(double x, double y, double& a1, double& a2) {
  double dist = distance(x, y);  
  double D1 = atan2(y, x);
  double D2 = lleyDelCos(dist, upperLimb, forearm);
  double a1Radianes = D1 + D2;
  double a2Radianes = abs(PI/2 - lleyDelCos(upperLimb, forearm, dist));
 
  a1 = radiansToDegrees(a1Radianes);
  a2 = radiansToDegrees(a2Radianes);
}
