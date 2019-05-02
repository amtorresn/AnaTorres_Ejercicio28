#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
using std::cout;
using std::endl;

void solve(string filename);

int main(){
    
    solve("datos.dat");
    return 0;
}

void solve(string filename){
    
    ofstream outfile;
    outfile.open(filename);
    
    float dt = 0.5;
    float dx = 0.01;
    float n = dt*200/(dx*dx*900*2700);
    
    int Xmax = 200;
    int Tmax = 101;
    float T_old[Xmax];
    float T_new[Xmax] = {0};
    //Inicializa
    for (int i = 0; i < Xmax; i++){
        if(i>=80 && i <= 120){
            T_old[i] = 500;
        }
        else{
            T_old[i] = 300;
        }
    }
    
    // New
    float t = 0;
    
    while(t < Tmax){
        for (int i = 1; i < Xmax-1; i++){
            T_new[i] = T_old[i] + n*(T_old[i+1] + T_old[i-1] - 2*T_old[i]);
        }
        for (int i = 0; i < Xmax; i++){
            T_old[i] = T_new[i];
            outfile << T_old[i] << " ";
            
        }
        t = t + 0.5;
        outfile << endl;
    }
  
    outfile.close();
    
}