#include <iostream>
using namespace std;
/*
   106 28 葉恩齊
   程式功能:基本運算與邏輯	
   111/10/07 
*/
int main()
{
	int  a=30 ,b;
	float c=3.2 ;
	
	cout << "輸入一個整數 b=" ;
	cin >> b;
	
	
	// 算術運算子
	cout << endl << "算術運算子" << endl;
	cout << "a=" << a <<"  b=" << b << "  c=" << c << endl; 
	cout << "a+b=" << (a+b) << endl; 
	cout << "a-b=" << (a-b) << endl; 
	cout << "a*b=" << (a*b) << endl;   // aHb
	cout << "a/b=" << (a/b) << endl;   // aHb (Lp) 
	cout << "a/c=" << (a/c) << endl;   // aHc
	cout << "a%b=" << (a%b) << endl;   // aHbl 
	
	// 複合算術運算子
	a++;  // a = a+1 
	cout << "a++ =" << a << endl;
	--b;  // b = b-1
	cout << "--b =" << b << endl << endl; 
	
	--a;  // aBb
	b++;
    
	//比較運算子
	cout << endl << "比較運算子" << endl;
	cout << "a=" << a <<"  b=" << b << endl;
    cout << "a>=bGO" << (a>=b) << endl;         // a j b
    cout << "a!=bGO" << (a!=b) << endl;         // a b
    cout << "a==bGO" << (a==b) << endl << endl; // a b
    
    //邏輯運算子
    bool left = true , right = false ; 
    cout << endl << "邏輯運算子" << endl;
    cout << "left=" << left <<" ; right=" << right << endl;
    cout << "!right =" << (!right) << endl;                   // right(NOT)
    cout << "left&&right =" << (left&&right) << endl;     // left&&right(AND)
    cout << "left||right =" << (left||right) << endl;       // left||right(OR)
    
    cout << "106 28 葉恩齊" << endl; 
}
	
	
