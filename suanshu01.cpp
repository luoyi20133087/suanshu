#include<iostream>
using namespace std;
#include<time.h>
#include<string>

int main()
{
	int count=0 ;
	srand(time(NULL));//用系统当前时间设置rand()随机序列种子，保证每次运行随机序列不一样 
	char ch;
	while(count<30)
	{
		cout<<"选择做整数运算（输入'a'）或真分数运算（输入'b'）"<<endl;
	    //产生整数的运算
		cin>>ch;
		if(ch=='a')
		{cout<<"开始产生四则运算："<<endl;
	    int shu1=0,shu2=0;
	//随机数产生0-100
	//shu1=srand(1000);

	
	shu1=0+rand()%100;
	shu2=0+rand()%100;

	int sum=0;
	int fushu=0;
	string fuhao[4]={"+","-","*","/"};
	fushu=((0+rand()%4)+4)%4;
	//cout<<fushu<<endl;

	//判断shu2是否为0和是否为除法 若为则重新生成
	while(shu2==0&fushu==3)
	{
		shu2=0+rand()%100;
	}
	//随机产生的符号
	switch(fushu)
	{
	case 0:cout<<shu1<<fuhao[fushu]<<shu2<<endl;break;
	case 1:cout<<shu1<<fuhao[fushu]<<shu2<<endl;break;
	case 2:cout<<shu1<<fuhao[fushu]<<shu2<<endl;break;
	case 3:cout<<shu1<<fuhao[fushu]<<shu2<<endl;break;
	}
		}

	//产生真分数的运算
		if(ch=='b')
		{
	int zhenfens1_m=0,zhenfens1_z=0,zhenfens2_m=0,zhenfens2_z=0;
	
	zhenfens1_m=0+rand()%100;
	zhenfens1_z=0+rand()%100;

	//判断产生的真分数正确性
	while(zhenfens1_m<zhenfens1_z)
	{
		zhenfens1_m=0+rand()%100;
		zhenfens1_z=0+rand()%100;
	}

	zhenfens2_m=0+rand()%100;
	zhenfens2_z=0+rand()%100;

	//判断产生的真分数正确性
	while(zhenfens2_m<zhenfens2_z)
	{
		zhenfens2_m=0+rand()%100;
		zhenfens2_z=0+rand()%100;
	}

	string fuhao[4]={"+","-","*","/"};
	int fushu=((0+rand()%4)+4)%4;
	//cout<<fushu<<endl;

	//判断shu2是否为0和是否为除法 若为则重新生成
	//随机产生的符号
	switch(fushu)
	{
	case 0:cout<<"("<<zhenfens1_z<<"/"<<zhenfens1_m<<")"<<fuhao[fushu]<<"("<<zhenfens2_z<<"/"<<zhenfens2_m<<")"<<endl;break;
	case 1:cout<<"("<<zhenfens1_z<<"/"<<zhenfens1_m<<")"<<fuhao[fushu]<<"("<<zhenfens2_z<<"/"<<zhenfens2_m<<")"<<endl;break;
	case 2:cout<<"("<<zhenfens1_z<<"/"<<zhenfens1_m<<")"<<fuhao[fushu]<<"("<<zhenfens2_z<<"/"<<zhenfens2_m<<")"<<endl;break;
	case 3:cout<<"("<<zhenfens1_z<<"/"<<zhenfens1_m<<")"<<fuhao[fushu]<<"("<<zhenfens2_z<<"/"<<zhenfens2_m<<")"<<endl;break;
	}

		}
	count++;
	}
}