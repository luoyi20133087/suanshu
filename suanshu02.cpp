//author:ly 2016.3.12
/*function:arithmetic operation that avoid duplication
 can order question number
 can select division and multiplication
 can choose brackets
 Specified range of operation
*/
#include<iostream>
#include<time.h>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;

string Judge[30][30];   //�ж��Ƿ��ظ�������
string para[30];       //��������
char op_arrays[4]={'+','-','*','/'};   //���������
int row=0;   //������
int ran=0;   //������
int k=0;
int parameters[30];           //�����������
void Random_build1(int,int,int);    //��������ʽ�ĺ���
void Random_build2(int,int,int);    
void Random_build3(int,int,int);  
void Random_build4(int,int,int);  
void Decu(int,int,int);      //�ݹ麯��

int main()
{
	//���ڲ������ŵ��������ɻ������� ϣ����ʦ�����ܸ����ڲ�����ָ��һ����������

	int count_t=0;     //������Ŀ����
	char print_way;    //�жϴ�ӡ��ʽ
	char Jude_has_mul_dev;    //�ж��Ƿ��г˳���
	char  Jude_has_brackets;   //�ж��Ƿ�������

	int parameters_num=0;     //��������
	int rangeof_count=0;    //ָ�������ķ�Χ
	int brackets_l=0;     //�ж������ŵ�����
	int brackets_r=0;     //�ж������ŵ�����

	cout<<"��������Ҫ��������Ԫ���������"<<endl;
	cin>>count_t;

	while(1)
	{
	//�ж����޳˳��� 
	cout<<"�Ƿ���Ҫ���˳�  �ǣ�����y�� ������n��"<<endl;
	cin>>Jude_has_mul_dev;
	cout<<"�ж��Ƿ���Ҫ���� �ǣ�����y�� ������n��"<<endl;
	cin>> Jude_has_brackets;
	cout<<"�ж�����Ҫ���ļ���ķ�Χ(С��1000)��"<<endl;
	cin>>rangeof_count;

	 srand(time(NULL));//��ϵͳ��ǰʱ������rand()����������ӣ���֤ÿ������������в�һ�� 
	 memset(Judge,0,sizeof(Judge));
	 memset(parameters,0,sizeof(parameters));
	while(row<count_t)
	{
	   parameters_num=2+rand()%9;   //����2-10�������
	   ran=0;
	   memset(para,0,sizeof(para));

	if(Jude_has_mul_dev=='n')
	{
		//�����˳���
		if(Jude_has_brackets=='n')
		{
			//��������
			//���ò�������ʽ�ĺ���
			int i=1;

			while(i<=parameters_num)
			{
				Random_build2(parameters_num, rangeof_count, i);
				i++;
			}
			parameters[row]=ran;    //��¼ÿ�β��������ĸ���

	   }
		else
		{
			//��������(���õݹ鷽ʽ��������)
			//�Ȳ�������ʽ ���������¼
			int i=1,s,l;
			int flag=1; //�жϵݹ麯�����Ƿ���������
			while(i<=parameters_num)
			{
				Random_build3(parameters_num, rangeof_count, i);
				i++;
			}

			s=k,l=0;

			Decu(l,k,flag);

			parameters[row]=ran;    //��¼ÿ�β��������ĸ���

	  }
	}
	else
	{
		//���˳���
		if(Jude_has_brackets=='n')
		{
			//��������
			int i=1;
			while(i<=parameters_num)
			{
				Random_build1(parameters_num, rangeof_count, i);
				i++;
			}
				parameters[row]=ran;    //��¼ÿ�β��������ĸ���
		}
		else
		{
			//������
			//��������(���õݹ鷽ʽ��������)
			//�Ȳ�������ʽ ���������¼
			int i=1,s,l;
			int flag=1; //�жϵݹ麯�����Ƿ���������
			while(i<=parameters_num)
			{
				Random_build4(parameters_num, rangeof_count, i);
				i++;
			}
			s=k,l=0;
			
			Decu(l,k,flag);
			parameters[row]=ran;    //��¼ÿ�β��������ĸ���
		}
	}
	      row++;    //����ʽ������
	}

	cout<<"����������Ҫ�Ĵ�ӡ��ʽ��(����a �ڿ���̨��ӡ��� ����b ���ļ������)"<<endl;
	cin>>print_way;

	if(print_way=='a')
	{
	//��ӡ������������ʽ
	cout<<"������������ʽΪ��"<<endl;
	for(int i=0;i<count_t;i++)
	{
		cout<<i+1<<". ";
		for(int j=0;j<=parameters[i];j++)
			cout<<Judge[i][j];
		cout<<endl;
	}
	}
	else
	{
		//������������������ʽ�����D:\1.txt��
		ofstream out("D:\1.txt");
		for(int i=0;i<count_t;i++)
	{
		out<<i+1<<". ";
		for(int j=0;j<=parameters[i];j++)
			out<<Judge[i][j];
		out<<endl;
	}
	}
 }
	return 0;
}

void Random_build1(int parameters_num,int rangeof_count,int i)
{
	int parameters;
	int fuhao=0;
	stringstream ss;
	//������� ��������
	parameters=0+rand()%rangeof_count;
	//�ж���һ�β������Ƿ����
	if(fuhao==3)
	{
	   while(parameters==0)     //����Ϊ0����������
		{
			parameters=0+rand()%rangeof_count;
		}
	}
	//������� �����(���һ�β����������)
	if(i<parameters_num)
	{
		fuhao=((0+rand()%4)+4)%4;
	}
	if(i<parameters_num)
	{
		//���������������ж��ظ���������
		ss<<parameters;
		ss>>Judge[row][ran];
		ran++;    //������
		Judge[row][ran]=op_arrays[fuhao];
		ran++;    //������
	}
	else 
	{
		ss<<parameters;
		ss>>Judge[row][ran];
	}
}

void Random_build2(int parameters_num,int rangeof_count,int i)
{
	int parameters;
	int fuhao;
	stringstream ss;
	//������� ��������
	parameters=0+rand()%rangeof_count;

	//������� �����(���һ�β����������)
	if(i<parameters_num)
	{
		 fuhao=((0+rand()%2)+2)%2;
	}
	if(i<parameters_num)
	{
		//���������������ж��ظ���������
		ss<<parameters;
		ss>>Judge[row][ran];
		ran++;    //������
		Judge[row][ran]=op_arrays[fuhao];
		ran++;    //������
	}
	else 
	{
		ss<<parameters;
		ss>>Judge[row][ran];
	}
}

void Random_build3(int parameters_num,int rangeof_count,int i)
{
	int parameters;
	int fuhao;
	stringstream ss;
	//������� ��������
	parameters=0+rand()%rangeof_count;

	//������� �����(���һ�β����������)
	if(i<parameters_num)
	{
		 fuhao=((0+rand()%2)+2)%2;
	}
	if(i<parameters_num)
	{
		//�������������ַ������ж��ظ���������
		ss<<parameters;
		ss>>para[k];
		k++;    //������

		para[k]=op_arrays[fuhao];
		k++;    //������
	}
	else 
	{
		ss<<parameters;
		ss>>para[k];
	}
}

void Random_build4(int parameters_num,int rangeof_count,int i)
{
	int parameters;
	int fuhao=0;
	stringstream ss;
	//������� ��������
	parameters=0+rand()%rangeof_count;
	if(fuhao==3)
	{
	   while(parameters==0)     //����Ϊ0����������
		{
			parameters=0+rand()%rangeof_count;
		}
	}
	//������� �����(���һ�β����������)
	if(i<parameters_num)
	{
		 fuhao=((0+rand()%4)+4)%4;
	}
	if(i<parameters_num)
	{
		//�������������ַ������ж��ظ���������
		ss<<parameters;
		ss>>para[k];
		k++;    //������

		para[k]=op_arrays[fuhao];
		k++;    //������
	}
	else 
	{
		ss<<parameters;
		ss>>para[k];
	}
}

void Decu(int l,int s,int flag)
{
	srand(time(NULL));//��ϵͳ��ǰʱ������rand()����������ӣ���֤ÿ������������в�һ��

	if((s-l)<2) return ;

	if((s-l)==2)
	{
		if(flag==1)
		{
			//��������
		  Judge[row][ran]="(";
		  ran++;
		  Judge[row][ran]=para[l];
		  ran++;
		  Judge[row][ran]=para[l+1];
		  ran++;
		  Judge[row][ran]=para[s];
		  ran++;
		  Judge[row][ran]=")";
		  ran++;
		}
		if(flag==0)
		{
		  Judge[row][ran]=para[l];
		  ran++;
		  Judge[row][ran]=para[l+1];
		  ran++;
		  Judge[row][ran]=para[s];
		  ran++;
		}
		return ;
	}
	if((s-l)==4)
	{
		//�������������Ϊ���������
		flag=0+rand()%2;
		if(flag==1)
		{
		 Judge[row][ran]="(";
		 ran++;
		 Judge[row][ran]=para[l];
		 ran++;
		 Judge[row][ran]=para[l+1];
		 ran++;
		 flag=0+rand()%2;
		 Decu(l+2,s,flag);
		 Judge[row][ran]=")";
		  ran++;
		}
		if(flag==0)
		{
			 Judge[row][ran]=para[l];
		 ran++;
		 Judge[row][ran]=para[l+1];
		 ran++;
		 flag=0+rand()%2;
		 Decu(l+2,s,flag);
		}
		  return ;
	}

	if((s-l)>4)
	{
			flag=0+rand()%2;
		if(flag==1)
		{
		 Judge[row][ran]="(";
		 ran++;
		 	flag=0+rand()%2;
		 Decu(l,s-4,flag);
		 Judge[row][ran]=para[s-3];
		 ran++;
		 l=s-2;
		 flag=0+rand()%2;
		 Decu(l,s,flag);
		 Judge[row][ran]=")";
		  ran++;
		}
		if(flag==0)
		{
			flag=0+rand()%2;
		 Decu(l,s-4,flag);
		 Judge[row][ran]=para[s-3];
		 ran++;
		 l=s-2;
		 flag=0+rand()%2;
		 Decu(l,s,flag);
		}
		  return ;
	}
}