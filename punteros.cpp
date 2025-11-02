#include <iostream>
<<<<<<< HEAD
int main(){

int *pNum=NULL;

pNum=new int;

*pNum=25;

std::cout<<"direccion:"<<pNum<<'\n';
std::cout<<"valor:"<<*pNum<<'\n';
std::cout<<"valor:"<<&pNum<<'\n';


return 0;
=======
using namespace std;
int main(int argc,char const *argv[])
{
int *pNum=NULL;
pNum= new int;
*pNum = 25 ;

std::cout<<"Direccion::"<< pNum <<'\n';
std::cout<<"Valor:"<< *pNum <<'\n';

cout<<"tipos de datos:" << endl;
cout<<"Tamaño int:"<<sizeof(int) << endl;
cout<<"Tamaño long:"<<sizeof(long) << endl;
cout<<"Tamaño Float:"<<sizeof(float) << endl;
cout<<"Tamaño double:"<<sizeof(double) << endl;
cout<<"Tamaño char:"<<sizeof(char) << endl;
cout<<"Tamaño bool:"<<sizeof(bool) << endl;
cout<<"Tamaño byte:"<<sizeof(byte) << endl;  









>>>>>>> 145c591d594cbd73f890acd984e008d5c6886aed

}