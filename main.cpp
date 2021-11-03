#include <iostream>

#include <fstream>
#include "rir_generator_core.h"
//#include "pad.h"
using namespace std;
int main()
{
    std::cout << "Hello World!\n";
    printf("end !!!");
   /* double input[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
    double kernel[4] = { 1, 2, 0, 3 };
    double output[11];
    conv_(kernel, 4, input, 8, output);
    for (int i = 0; i < 11; i++)
        printf("%lf ", output[i]);*/
    int samples = 4000;
    int sf = 16000;
    double c = 343.0;
    int nMicrophones = 1;
    int order = -1;
    int hp_filter = 1;
    double* imp = new double[samples];
   
    double rr[3] = {1,2,3};
    double beta[6] = { 0.6, 0.6, 0.6, 0.6, 0.6, 0.6 };
    double LL[3] = { 4,5,6 };
    double ss[3] = { 3,4,5 };
    double microphone_angle[2] = { 0, 0 };
    memset(imp, 0, samples * sizeof(double));
    computeRIR(imp, c, sf, rr, nMicrophones, samples, ss,  LL, beta, 'o', order, microphone_angle, hp_filter);
    printf("end !!!");
    for (int i = 0; i < 4000; i++) 
    {
        printf("%lf ",imp[i]);
    }
    ofstream outfile("out.txt", ios::trunc);
    for (int i = 0; i < samples; i++)
    {
        outfile << imp[i] << ' ' ;
    }
    outfile.close();
    
}