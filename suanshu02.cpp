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

string Judge[30][30];   //判断是否重复的数组
string para[30];       //备用数组
char op_arrays[4]={'+','-','*','/'};   //运算符数组
int row=0;   //定义行
int ran=0;   //定义列
int k=0;
int parameters[30];           //定义参数数组
void Random_build1(int,int,int);    //产生算术式的函数
void Random_build2(int,int,int);    
void Random_build3(int,int,int);  
void Random_build4(int,int,int);  
void Decu(int,int,int);      //递归函数

int main()
{
	//对于产生括号的运算生成还有问题 希望老师看了能给我在博客中指点一下问题所在

	int count_t=0;     //产生题目数量
	char print_way;    //判断打印方式
	char Jude_has_mul_dev;    //判断是否有乘除法
	char  Jude_has_brackets;   //判断是否有括号

	int parameters_num=0;     //参数个数
	int rangeof_count=0;    //指定计数的范围
	int brackets_l=0;     //判断左括号的序数
	int brackets_r=0;     //判断右括号的序数

	cout<<"请输入需要产生四则元算的题数："<<endl;
	cin>>count_t;

	while(1)
	{
	//判断有无乘除法 
	cout<<"是否需要做乘除  是（输入y） 否（输入n）"<<endl;
	cin>>Jude_has_mul_dev;
	cout<<"判断是否需要括号 是（输入y） 否（输入n）"<<endl;
	cin>> Jude_has_brackets;
	cout<<"判断你需要做的计算的范围(小于1000)："<<endl;
	cin>>rangeof_count;

	 srand(time(NULL));//用系统当前时间设置rand()随机序列种子，保证每次运行随机序列不一样 
	 memset(Judge,0,sizeof(Judge));
	 memset(parameters,0,sizeof(parameters));
	while(row<count_t)
	{
	   parameters_num=2+rand()%9;   //产生2-10个随机数
	   ran=0;
	   memset(para,0,sizeof(para));

	if(Jude_has_mul_dev=='n')
	{
		//不含乘除法
		if(Jude_has_brackets=='n')
		{
			//不含括号
			//调用产生算术式的函数
			int i=1;

			while(i<=parameters_num)
			{
				Random_build2(parameters_num, rangeof_count, i);
				i++;
			}
			parameters[row]=ran;    //记录每次产生参数的个数

	   }
		else
		{
			//产生括号(采用递归方式产生括号)
			//先产生算术式 并用数组记录
			int i=1,s,l;
			int flag=1; //判断递归函数中是否生成括号
			while(i<=parameters_num)
			{
				Random_build3(parameters_num, rangeof_count, i);
				i++;
			}

			s=k,l=0;

			Decu(l,k,flag);

			parameters[row]=ran;    //记录每次产生参数的个数

	  }
	}
	else
	{
		//含乘除法
		if(Jude_has_brackets=='n')
		{
			//不含括号
			int i=1;
			while(i<=parameters_num)
			{
				Random_build1(parameters_num, rangeof_count, i);
				i++;
			}
				parameters[row]=ran;    //记录每次产生参数的个数
		}
		else
		{
			//含括号
			//产生括号(采用递归方式产生括号)
			//先产生算术式 并用数组记录
			int i=1,s,l;
			int flag=1; //判断递归函数中是否生成括号
			while(i<=parameters_num)
			{
				Random_build4(parameters_num, rangeof_count, i);
				i++;
			}
			s=k,l=0;
			
			Decu(l,k,flag);
			parameters[row]=ran;    //记录每次产生参数的个数
		}
	}
	      row++;    //运算式的行数
	}

	cout<<"请输入你需要的打印方式：(输入a 在控制台打印输出 输入b 在文件中输出)"<<endl;
	cin>>print_way;

	if(print_way=='a')
	{
	//打印产生的运算表达式
	cout<<"产生的运算表达式为："<<endl;
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
		//将产生的四则运算表达式输出到D:\1.txt中
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
	//随机产生 运算表达数
	parameters=0+rand()%rangeof_count;
	//判断上一次产生的是否除法
	if(fuhao==3)
	{
	   while(parameters==0)     //除数为0就重新生成
		{
			parameters=0+rand()%rangeof_count;
		}
	}
	//随机产生 运算符(最后一次不产生运算符)
	if(i<parameters_num)
	{
		fuhao=((0+rand()%4)+4)%4;
	}
	if(i<parameters_num)
	{
		//将产生的数放入判断重复的数组中
		ss<<parameters;
		ss>>Judge[row][ran];
		ran++;    //列增加
		Judge[row][ran]=op_arrays[fuhao];
		ran++;    //列增加
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
	//随机产生 运算表达数
	parameters=0+rand()%rangeof_count;

	//随机产生 运算符(最后一次不产生运算符)
	if(i<parameters_num)
	{
		 fuhao=((0+rand()%2)+2)%2;
	}
	if(i<parameters_num)
	{
		//将产生的数放入判断重复的数组中
		ss<<parameters;
		ss>>Judge[row][ran];
		ran++;    //列增加
		Judge[row][ran]=op_arrays[fuhao];
		ran++;    //列增加
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
	//随机产生 运算表达数
	parameters=0+rand()%rangeof_count;

	//随机产生 运算符(最后一次不产生运算符)
	if(i<parameters_num)
	{
		 fuhao=((0+rand()%2)+2)%2;
	}
	if(i<parameters_num)
	{
		//将产生的数以字符放入判断重复的数组中
		ss<<parameters;
		ss>>para[k];
		k++;    //列增加

		para[k]=op_arrays[fuhao];
		k++;    //列增加
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
	//随机产生 运算表达数
	parameters=0+rand()%rangeof_count;
	if(fuhao==3)
	{
	   while(parameters==0)     //除数为0就重新生成
		{
			parameters=0+rand()%rangeof_count;
		}
	}
	//随机产生 运算符(最后一次不产生运算符)
	if(i<parameters_num)
	{
		 fuhao=((0+rand()%4)+4)%4;
	}
	if(i<parameters_num)
	{
		//将产生的数以字符放入判断重复的数组中
		ss<<parameters;
		ss>>para[k];
		k++;    //列增加

		para[k]=op_arrays[fuhao];
		k++;    //列增加
	}
	else 
	{
		ss<<parameters;
		ss>>para[k];
	}
}

void Decu(int l,int s,int flag)
{
	srand(time(NULL));//用系统当前时间设置rand()随机序列种子，保证每次运行随机序列不一样

	if((s-l)<2) return ;

	if((s-l)==2)
	{
		if(flag==1)
		{
			//产生括号
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
		//存在随机数个数为奇数的情况
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