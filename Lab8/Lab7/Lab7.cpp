// Lab7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <locale> 
#include <iomanip>
#include <iostream>
#include "IP.h"


using namespace std;

bool corrects (char* ip)//проверка на корректность
{
	int s=0;         // количество точек
	while (ip[s] != '\0'){
		s++;
	}

	for(int i=0; i<s; i++) //Проверка символа на вхождение в диапазон цифр
	{
		if((ip[i]<='9'&&ip[i]>='0')||ip[i]=='.');  
		else{
			return false;
		}
	}

	for (int i = 0; i < s - 1; i++){ //Проверка на две точки вподряд
		if (ip[i] == '.'&&ip[i + 1] == '.'){
			return false;
		}
	}

	int nd=0;
	for (int i = 0; i < s - 1; i++){  // Проверяет количество точек (не больше и не меньше трех)
		 if(ip[i]=='.') nd++;
	}
	if (nd != 3){
		return false;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale (LC_ALL, "Russian");
	char *str;
	int ip[4], 
		mask[4], 
		subNet[4], 
		Host[4];
	int t=1;
	str = new char[16];
	while(t!=0)
	{
		t=0;
		cout<<"Введите IP:	";
		cin>>str;
		if (corrects(str)==true)
		{
			Split(str, ip);
			int w=0;
			for (int i = 0; i < 4; i++){
				if(ip[i]==0) w++;
			}
			if (w == 4){
				t++;
			}

			for (int i = 0; i < 4; i++){
				if (ip[i] < 0 || ip[i]>255){
					t++;
				}
			}
			if (t != 0)   {
				cout<<"Ошибка IP: "<<endl;
			}
		}
		else
		{
			cout<<"Ошибка IP "<<endl;
			t++;
		}
	}
	t=1;
	while (t!=0)
	{
		t=0;
		cout<<"Maska:	";
		cin>>str;
		if (corrects(str)==false) t++;//если не корректно
		Split(str, mask);
		int ma=0;
		int mi=0;
		for(int i=0; i<4; i++)//255.255.255.255
		{
			if(mask[i]==255) ma++;
			if(mask[i]==0) mi++;
		}
		if(ma==4||mi==4) t++;
		for(int i=0; i<4; i++)//252.0.255.255.
		{
			if(mask[i]!=255)
			{
				if (i<=2&&mask[i+1]!=0)
				{
					//Прерывание маски
					t++;
				}
			}
			if (mask[i]==0||mask[i]==128||mask[i]==192||mask[i]==224||mask[i]==240||mask[i]==248||mask[i]==252||mask[i]==254||mask[i]==255);
			else
			{
				t++;
			}
			if(mask[i]<0||mask[i]>255)
			{	
				t++;
			}
		}
		if(t!=0)	
			std::cout<<"erorr mask "<<std::endl;
	}

	IDN(ip, mask, subNet);//подсеть
	IDH(ip, subNet, Host);//хост
	int* Broad = new int[4];
	BroadcastRass(ip, mask, Broad);
	
	std::cout<<":ID подсети:	"<< subNet[0]<<"."<<subNet[1]<<"."<<subNet[2]<<"."<<subNet[3]<<"\n";
	std::cout<<"ID хоста	"<<Host[0]<<"."<<Host[1]<<"."<<Host[2]<<"."<<Host[3]<<"\n";
	std::cout << "Broadcast ip:" <<  Broad[0] << "." << Broad[1] << "." <<  Broad[2] << "." << Broad[3] << "\n";


	system("pause");
	return 0;
}

