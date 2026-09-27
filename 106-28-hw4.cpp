#include<iostream>
using namespace std;
/*
   106 28 葉恩齊
   程式功能:計算num個同學的總成績、平均成績、不及格人數
   111/11/15 
*/ 
int main()
{   
	int num , failure = 0; 
	float sum = 0 , average = 0;
	cout << "請輸入班上有幾位同學" << endl <<"-->";
	cin >> num; 		//輸入學生人數 
	int score[num];     
	cout << "請輸入" << num <<"位同學的成績:" << endl;
	for (int i = 1 ; i <= num ; i++){
		cin >> score[i];               //輸入全部同學的成績 
		sum = sum + score[i]; 		   //計算總分 
		if (score[i] < 60)             //計算不及格人數 
		  failure++;   	
	}
	average = (sum/num);               //計算平均成績 
	cout <<"--------------------------------"<< endl; 
	cout << "本班的" << endl;			     //輸出總成績、平均成績、不及格人數 
	cout << "總成績 " << sum << endl;
	cout << "平均成績 " << average << endl;
	cout << "不及格人數 " << failure;  
} 
	
	
