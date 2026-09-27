#include<iostream>
using namespace std;
/*
   106 28 葉恩齊
   程式功能:排序
   111/12/14 
*/ 
int main()
{  
	int n = 0 , i = 0 , j = 0 , min = 0 , temp = 0; 
	cout << "請問輸入幾筆資料-->"; 
	cin >> n ;
	float grade[n];
	cout << "請輸入資料" << endl;
	for (i = 0 ; i < n ; i++){
		cin >> grade[i];                        //輸入全部資料 
	}	
	
	cout << "排序前的資料:" << endl; 
	for (i = 0 ; i < n ; i++)
		cout << grade[i] << "   ";              //輸出全部資料 
			  
	for (i = 0 ; i < n ; i++){
		min = i; 
		for (j = min + 1 ; j < n ; j++){
			if (grade[min] < grade[j])
				min = j; 
		}
		if( min != j ){
				temp = grade[i];
				grade[i] = grade[min];
				grade[min] = temp;               //用選擇排序法排序資料  
		}
	}
	
	cout << endl << "排序後的資料:" << endl;
	for (i = 0 ; i < n ; i++)
		cout << grade[i] << "   ";               //輸出已排序資料
} 
	
	
