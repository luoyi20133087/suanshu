#include<iostream>
using namespace std;
#include<time.h>
#include<string>

int main()
{
	int count=0 ;
	srand(time(NULL));//��ϵͳ��ǰʱ������rand()����������ӣ���֤ÿ������������в�һ�� 
	char ch;
	while(count<30)
	{
		cout<<"ѡ�����������㣨����'a'������������㣨����'b'��"<<endl;
	    //��������������
		cin>>ch;
		if(ch=='a')
		{cout<<"��ʼ�����������㣺"<<endl;
	    int shu1=0,shu2=0;
	//���������0-100
	//shu1=srand(1000);

	
	shu1=0+rand()%100;
	shu2=0+rand()%100;

	int sum=0;
	int fushu=0;
	string fuhao[4]={"+","-","*","/"};
	fushu=((0+rand()%4)+4)%4;
	//cout<<fushu<<endl;

	//�ж�shu2�Ƿ�Ϊ0���Ƿ�Ϊ���� ��Ϊ����������
	while(shu2==0&fushu==3)
	{
		shu2=0+rand()%100;
	}
	//��������ķ���
	switch(fushu)
	{
	case 0:cout<<shu1<<fuhao[fushu]<<shu2<<endl;break;
	case 1:cout<<shu1<<fuhao[fushu]<<shu2<<endl;break;
	case 2:cout<<shu1<<fuhao[fushu]<<shu2<<endl;break;
	case 3:cout<<shu1<<fuhao[fushu]<<shu2<<endl;break;
	}
		}

	//���������������
		if(ch=='b')
		{
	int zhenfens1_m=0,zhenfens1_z=0,zhenfens2_m=0,zhenfens2_z=0;
	
	zhenfens1_m=0+rand()%100;
	zhenfens1_z=0+rand()%100;

	//�жϲ������������ȷ��
	while(zhenfens1_m<zhenfens1_z)
	{
		zhenfens1_m=0+rand()%100;
		zhenfens1_z=0+rand()%100;
	}

	zhenfens2_m=0+rand()%100;
	zhenfens2_z=0+rand()%100;

	//�жϲ������������ȷ��
	while(zhenfens2_m<zhenfens2_z)
	{
		zhenfens2_m=0+rand()%100;
		zhenfens2_z=0+rand()%100;
	}

	string fuhao[4]={"+","-","*","/"};
	int fushu=((0+rand()%4)+4)%4;
	//cout<<fushu<<endl;

	//�ж�shu2�Ƿ�Ϊ0���Ƿ�Ϊ���� ��Ϊ����������
	//��������ķ���
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