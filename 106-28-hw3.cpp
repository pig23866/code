#include<iostream>
using namespace std;
/*
   106 28 葉恩齊
   程式功能:條件選擇 銷費金額與折扣 
   111/10/27  
*/ 
int main()
{
	int price;
	cout << "請輸入銷費金額 -->"; 
	cin >> price;
    if (price >=10000)                                       //如果金額大於或等於10000 輸出金額打8折 
		cout << "金額打8折，需付"  << (price*0.8) << "元";
	else if (price >= 8000)                                  //如果金額大於或等於8000  輸出金額打9折
		cout << "金額打9折，需付"  << (price*0.9) << "元";	
	else if (price >= 5000)                                  //如果金額大於或等於5000  輸出金額打5折
		cout << "金額打95折，需付" << (price*0.95) << "元";	
	else                                                     //如果金額小於5000   輸出金額不打折 
		cout << "不打折，照原價" << price << "元" ;
}
	
	
