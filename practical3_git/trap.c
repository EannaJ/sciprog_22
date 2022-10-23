#include<stdio.h>
#include<math.h>

int main(void){

  int N=12, i;
  float a = 0.0, b_deg = 60.0;
  float b_rad, area, mult_rad;

  //Converting b_deg to radians (b_rad)                                                              
  b_rad = (M_PI * b_deg) / 180.0;
  printf("pi/3 in radians = %f\n", b_rad) ;

  //Finding first sum (tan(a) + tan(b))                                                              
  area = tan(a) + tan(b_rad);
  //Calculating the area at incrementing points i.e 1, 2 , ... ,11                                   
  for(i = 5; i<60; i = i+5) {
    area = area + 2*tan((M_PI*i)/180.0);
  }

  //Multiply partial area by (pi/3) / (2*N)                                                          
  //Convert to radians                                                                               
  mult_rad = (M_PI * ((b_deg) / (2*N)) / 180);
  area = mult_rad*area;

  printf(" Approximate Area=%f, Exact Area = %f\n", area, log(2.0));


  return 0;
}
