#include <iostream>
#include<fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // srand(time(NULL));
    // int random_number = rand()%4; // rand() return a number between ​0​ and RAND_MAX
    // std::cout << random_number<<endl;;
    ifstream input;
    ifstream dll;
    input.open("peta.txt");
	int n;
	int m;
	string temp;
	input>>n;
	input>>m;
	char **peta;
	peta = new char*[n];
	for(int i=0;i<n;i++){
		peta[i] = new char[m];
	}
	for(int i=0;i<n;i++){
		input>>temp;
		for(int j=0;j<m;j++){
			peta[i][j] = temp[j];
		}
	}
	for(int i =0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<peta[i][j]<<" ";
		}
		cout<<endl;
	}
	char c;
	int x,y;
	dll.open("dll.txt");
	while(!dll.eof()){
		dll>>c;
		dll>>x;
		dll>>y;
		cout<<c<<" "<<x<<" "<<y<<endl;
	}
    return 0;
}