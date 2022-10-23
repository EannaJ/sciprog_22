#include <stdio.h>
#include <math.h>

//converting from degrees to radians                                                                
                                                                                                         
float deg_to_rad(float theta)
{
    return M_PI * theta /180.;
}

//trapazoidal rule function
float trap_rule(float a, float b, int N, float function_array[N + 1]) 
{
    float sum = function_array[0] + function_array[N];
    int i = 0;
    for (i = 0; i < N; i++)
    {
     sum += 2 * function_array[i]; // += adding to itself (sum)
    }
      return (b - a) * (sum) /(2 * N);
}

int main(void)
{   // trapazoidal rule parameters
    float start = 0;
    float end = 60;
    int N = 12;
    float step_size = (end - start) / N;
    float tan_array[N + 1]; //array that holds tan() values

    // for loop calculates tan values
    int i =0;
    for (i = 0; i <= N; i++)
    {
        tan_array[i] = tan(deg_to_rad(step_size * i));
    }
      float ans = trap_rule(deg_to_rad(start), deg_to_rad(end), N, tan_array);
      printf("The answer is %f\n", ans);
      return 0;
}
