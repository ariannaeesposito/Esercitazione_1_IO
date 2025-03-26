#include <iostream>
#include <fstream>
#include <iomanip>

double funz(double x){
    int a=1, b=5, c=-1, d=2 ;
    return (c+(x-a)*(d-c)/(b-a));
}

int main() {
    std::ifstream file("data.txt");
    if(file.fail())
    {
        std::cerr<<"errore nell'apertura"<<std::endl;
        return 1;
    }

    std::ofstream file2("result.txt");
    if(file2.fail())
    {
        std::cerr<<"errore nell'apertura"<<std::endl;
        return 1;
    }
std::string linea;
double numero;
double media = 0;
double somma = 0;
int cont = 0;
file2 << "# N Mean"<<std::endl;

while (std::getline(file,linea))  { //secondo dev'essere una stringa
    
    std::stringstream ss(linea);
    ss>>numero;
    double new_value = funz(numero);
    cont ++ ; //itero di uno partendo da zero ogni giro
    somma += new_value;
    media = somma/cont;

    file2 << cont <<" ";
    file2 << std::setprecision(20) << std::scientific << media << std::endl;

}

file.close();
file2.close();


    return 0;
}
