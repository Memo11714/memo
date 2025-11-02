#include <iostream>
int main(){

int *pNum=NULL;

pNum=new int;

*pNum=25;

std::cout<<"direccion:"<<pNum<<'\n';
std::cout<<"valor:"<<*pNum<<'\n';
std::cout<<"valor:"<<&pNum<<'\n';


return 0;

}