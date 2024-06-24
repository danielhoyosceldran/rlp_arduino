#include <Math.h>

double largo1 = 14;
double largo2 = 22;
double angulo1,angulo2;
double Pi = 3.14159;

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
  return radianes * 180.0 / Pi;
}

void inverseKinematics(double x, double y, double& a1, double& a2) {
  double dist = distance(x, y);  
  double D1 = atan2(y, x);
  double D2 = lleyDelCos(dist, largo1, largo2);
  double a1Radianes = D1 + D2;
  double a2Radianes = abs(Pi/2 - lleyDelCos(largo1, largo2, dist));
 
  a1 = radiansToDegrees(a1Radianes);
  a2 = radiansToDegrees(a2Radianes);
}
