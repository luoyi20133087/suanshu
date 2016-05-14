#include<stack>
#include<iostream>
#include<deque>
#include<string>
#include<sstream>
#include<time.h>
using namespace std;

int  Num[100];    //将数字存入数组a
string op_arrays[100];    //将运算符存入数组b
string  All[100];    //合成总数组e
string fu[100];      //辅助数组
int true_num = 0;     //统计做对的题目数
int false_num = 0;    //统计做错的题目数

bool isPra(char);    //判断是否为括号
int getPri(char);    //获得符号优先性
void check(char c, stack<char>& coll2, deque<char>& coll3);//判断符号优先性
void allocate(deque<char>& coll1, stack<char>& coll2, deque<char>& coll3);  //将中缀表达式分解为符号和运算数
void calculate(deque<char>& coll3, stack<double>& coll4);  //计算后缀表达式

int main()
{
	srand((int)time(NULL));//设置随机种子，使得程序每次运行的结果都不同
	int subject_number;    //出题数量
	int random_number = 0;    //运算数字字数
	int operation_character = 0;
	int fuhao = 0;    //判定运算符

	int Jude_has_brackets;       //定义左、右括号的是否存在的随机变量
	string left;    //左括号变量
	string right;    //左括号变量
	string sign = "a";   //定义符号变量
	char Jude_has_mul_dev;   //定义是否需要乘除法的变量

	deque<char> coll0;  //消除中缀表达式的空格
	deque<char> coll1;  //盛放中缀表达式
	stack<char> coll2;  //盛放操作符
	deque<char> coll3;	//盛放后缀表达式
	stack<double>coll4;	//计算后缀表达式的辅助容器

	int min, Max;    //定义输入的值得范围的最值(仅能输入整数<=30)
	string w = " ";

	//写一个简易菜单
	cout << "欢       ／￣＼＿／￣＼ "<<endl;
	cout << "迎     　▏     ▔▔▔▔＼    " << endl;
	cout << "使     ／＼　／　　　　　　﹨" << endl;
	cout << "用   ∕　　　　　　　／　　　）" << endl;
	cout << "小   ▏　　　　　　　　●　　▏"<<endl;
	cout << "天   ▏　　　　　　　　　　　▔█ " << endl;
	cout << "才 ◢██◣　　　　　　／＼＿＿／" << endl;
	cout << "四  █████◣　　　　　　　／" << endl;
	cout << "则  █████████████◣ " << endl;
	cout << "运◢██████████████▆▄" << endl;
	cout << "算 █◤◢██◣◥█████████◤＼" << endl;
	cout << "自◥◢████　████████◤　　 ＼" << endl;
	cout << "助  █████　██████◤　　　　　 ﹨" << endl;
	cout << "系 │　　　│█████◤　　　　　　　　▏" << endl;
	cout << "统 │　　　│　　　　　　　　　　　　　　▏" << endl;
	cout << "   ∕　　　∕　　　　／▔▔▔＼　　　　 ∕" << endl;
	cout << "  ∕＿＿_／﹨　　　∕　　　　　 ＼　　／＼" << endl;
	cout << "             ＼ 　　 ＼_　　　　　﹨／　　﹨" << endl;
	cout << "               ＼＿＿＿＼　　　　 ﹨／▔＼﹨／▔＼" << endl;
	cout << "	 	                  ＼　　 ∕" << endl;
	    cout << "1.请输入产生数字的范围（最小和最大）：";
	    cin >> min >> Max;
	    cout << "提示：若您需要做乘除法 请不要做超过30以外的乘除法" << endl;
	    cout << endl;
	    cout << "2.是否需要乘除法[y为需要乘除法 n为不需要乘除法] ";
	    cin >> Jude_has_mul_dev;
		while (min<0)
		{
		cout << "请做正数运算：" << endl;
		cout << "输入最小值" << endl;
		cin >> min;
	     }
	while (Max>30 && Jude_has_mul_dev == 'y')
	{
		cout << "请重新输入最大值:" << endl;
		cin >> Max;
	}
	cout << "请输入出题数量：";
	cin >> subject_number;

	int i = 0, j, k;
	if ('y' == Jude_has_mul_dev)
	{
		random_number = rand() % 9 + 2;    //随机生成2~10个数
		for (j = 0; j < subject_number; j++)    //设置题目数量
		{
			//清除数组元素
			memset(Num, 0, sizeof(Num));    
			memset(op_arrays, 0, sizeof(op_arrays));    
			memset(fu, 0, sizeof(fu));    

			random_number = rand() % 9 + 2;    //随机生成2~10个数
			for (i = 0; i < random_number; i++)
			{
				stringstream ss;
				operation_character = rand() % (Max - min + 1) + min;
				Num[i] = operation_character;
				fuhao = rand() % 4 + 1;
				switch (fuhao)
				{
				case 1:sign = "+"; break;
				case 2:sign = "-"; break;
				case 3:sign = "*"; break;
				case 4:sign = "/"; break;
				}
				//若为除法则除数不为零
				while (Num[i] == 0 && i >= 1)
				{
					if (op_arrays[i - 1] == "/")
					{
						operation_character = rand() % (Max - min + 1) + min;
						Num[i] = operation_character;
					}
				}
				op_arrays[i] = sign;

				fu[4 * i] = w;
				ss << Num[i];
				ss >> fu[4 * i + 1];
				fu[4 * i + 2] = w;
				if (i != (random_number - 1))   //最后一次不产生符号
					fu[4 * i + 3] = op_arrays[i];
				else fu[4 * i + 3] = w;
			}
			Jude_has_brackets = rand() % 2 + 1;  //随机确定有无括号
			switch (Jude_has_brackets)
			{
			case 1:
				left = "(";
				right = ")";
				break;
			case 2:
				left = w;
				right = w;
				break;
			}

			for (i = 0; i < random_number; i++)
			{
				for (k = 0; k < (random_number - 1) / 2; k++)
				{
					fu[4 * k] = left;
					if (left == "(")
					{
						fu[4 * k + 10] = right;
					}
				}
				if ((fu[4 * i] == left) && (fu[4 * i + 2] == right))
				{
					fu[4 * i] = w;
					fu[4 * i + 2] = w;
				}

				All[j] += fu[4 * i] + fu[4 * i + 1] + fu[4 * i + 2] + fu[4 * i + 3];
			}
			cout << j + 1 << "题. " << All[j] << "= " ;
			for (int i = 0; i != All[j].size(); ++i)
			{
				//逐一加入每个字符，这里使用deque因为deque在两端删除添加的速度最快
				coll0.push_back(All[j][i]);      //在尾部加入一个元素
			}

			//将coll0转换为后缀表达式coll1
			for (int i = 0; i != All[j].size(); ++i)
			{
				char k = coll0.front();
				coll0.pop_front();
				if (k != ' ')        //消除空格
					coll1.push_back(k);
			}
			//从coll中取出元素，分配元素到coll2和coll3中
			allocate(coll1, coll2, coll3);

			//计算后缀表达式
			calculate(coll3, coll4);

			double result = 0;
			cin >> result;
			if (result == coll4.top())
			{
				cout << "正确！" << endl;
				true_num++;
				cout << "计算结果为:" << coll4.top() << endl;
			}
			else
			{
				cout << "错误！" << endl;
				false_num++;
				cout << "计算结果为:" << coll4.top() << endl;
			}
			//将栈清空
			coll4.pop();
		}
		if (true_num >= false_num)
			cout << "恭喜你！您共做对" << true_num << "道题！" << "做错" << false_num << "道题！" << endl;
		else
			cout << "还需加油！您共做对" << true_num << "道题！" << "做错" << false_num << "道题！" << endl;
	}
	else
	{
		random_number = rand() % 9 + 2;    //随机生成2~10个数
		for (j = 0; j < subject_number; j++)    //设置题目数量
		{
			//清除数组元素
			memset(Num, 0, sizeof(Num));
			memset(op_arrays, 0, sizeof(op_arrays));
			memset(fu, 0, sizeof(fu));

			random_number = rand() % 9 + 2;    //随机生成2~10个数
			for (i = 0; i < random_number; i++)
			{
				stringstream ss;
				operation_character = rand() % (Max - min + 1) + min;
				Num[i] = operation_character;
				fuhao = rand() % 2 + 1;
				switch (fuhao)
				{
				case 1:sign = "+"; break;
				case 2:sign = "-"; break;
				}
				op_arrays[i] = sign;

				fu[4 * i] = w;
				ss << Num[i];
				ss >> fu[4 * i + 1];
				fu[4 * i + 2] = w;
				if (i != (random_number - 1))   //最后一次不产生符号
					fu[4 * i + 3] = op_arrays[i];
				else fu[4 * i + 3] = w;
			}
			Jude_has_brackets = rand() % 2 + 1;  //随机确定有无括号
			switch (Jude_has_brackets)
			{
			case 1:
				left = "(";
				right = ")";
				break;
			case 2:
				left = w;
				right = w;
				break;
			}

			for (i = 0; i < random_number; i++)
			{
				for (k = 0; k < (random_number - 1) / 2; k++)
				{
					fu[4 * k] = left;
					if (left == "(")
					{
						fu[4 * k + 10] = right;
					}
				}
				if ((fu[4 * i] == left) && (fu[4 * i + 2] == right))
				{
					fu[4 * i] = w;
					fu[4 * i + 2] = w;
				}

				All[j] += fu[4 * i] + fu[4 * i + 1] + fu[4 * i + 2] + fu[4 * i + 3];
			}
			cout << j + 1 << "题. " << All[j] << "= " << endl;
			for (int i = 0; i != All[j].size(); ++i)
			{
				//逐一加入每个字符，这里使用deque因为deque在两端删除添加的速度最快
				coll0.push_back(All[j][i]);      //在尾部加入一个元素
			}

			//将coll0转换为后缀表达式coll1
			for (int i = 0; i != All[j].size(); ++i)
			{
				char k = coll0.front();
				coll0.pop_front();
				if (k != ' ')        //消除空格
					coll1.push_back(k);
			}
			//从coll中取出元素，分配元素到coll2和coll3中
			allocate(coll1, coll2, coll3);

			//计算后缀表达式
			calculate(coll3, coll4);

			double result = 0;
			cin >> result;
			if (result == coll4.top())
			{
				cout << "正确！" << endl;
				true_num++;
				cout << "计算结果为:" << coll4.top() << endl;
			}
			else
			{
				cout << "错误！" << endl;
				false_num++;
				cout << "计算结果为:" << coll4.top() << endl;
			}
			//将栈清空
			coll4.pop();
		}
		if (true_num >= false_num)
			cout << "恭喜你！您共做对" << true_num << "道题！" << "做错" << false_num << "道题！" << endl;
		else
			cout << "还需加油！您共做对" << true_num << "道题！" << "做错" << false_num << "道题！" << endl;
	}
	return 0;
}


//判断是否为括号
bool isPra(char c)
{
	if (c == '(' || c == ')')
		return true;
	else
		return false;
}

//获得符号的优先性
int getPri(char c)
{
	switch (c)
	{
	case '+':
	case '-':
		return 0;	//如果是加减，返回0
		break;
	case '*':
	case '/':
		return 1;	//如果是乘除，返回1
		break;
	case '(':
	case ')':
		return -1;  //注意，这里将括号设为最低优先级，因此括号不会被弹出，除非遇到右括号
		break;
	}
	return 2;
}

//判断符号的优先性
void check(char c, stack<char>& coll2, deque<char>& coll3)
{
	if (coll2.empty())
	{
		coll2.push(c);
		return;
	}

	if (isPra(c))
	{
		if (c == '(')
			coll2.push(c);
		else
		{
			//弹出所有元素直到遇到左括号
			while (coll2.top() != '(')
			{
				char ch = coll2.top();
				coll3.push_back(ch);
				coll2.pop();
			}

			//当遇到左括号时，弹出但不加入coll3(后缀表达式中）--(“（”“）”都不放入后缀表达式中)
			coll2.pop();  //弹出左括号
		}
	}
	else	//如果不是括号
	{
		//取出栈顶元素，与当前符号进行优先性比较
		char sym = coll2.top();

		//比较两符号的优先性
		if (getPri(c) <= getPri(sym))
		{
			//如果c的优先性比栈顶符号小或等于，弹出栈顶元素
			coll2.pop();
			//并将其压入coll3（后缀表达式）中
			coll3.push_back(sym);
			//递归调用check,比较当前符号c与下一个栈顶符号的优先性
			check(c, coll2, coll3);
		}
		else
		{
			//如果c比栈顶符号优先级大，那将c压入coll2(操作符栈）中
			coll2.push(c);
		}
	}
}

//从coll中取出元素，分配元素到coll2和coll3中
void allocate(deque<char>& coll1, stack<char>& coll2, deque<char>& coll3)
{
	while (!coll1.empty())
	{
		char c = coll1.front();
		coll1.pop_front();

		if (c >= '0'&&c <= '9')
		{
			coll3.push_back(c);
			//判断是否为两位数
			if (!coll1.empty())
			{
				c = coll1.front();
				if (c >= '0'&&c <= '9')
					coll3.push_back('@');
			}
		}
		else
		{
			//调用check函数，针对不同情况作出不同操作
			check(c, coll2, coll3);
		}

	}

	//如果输入结束，将coll2的元素全部弹出，加入后缀表达式中
	while (!coll2.empty())
	{
		char c = coll2.top();
		coll3.push_back(c);
		coll2.pop();
	}
}


//计算后缀表达式(修改)
void calculate(deque<char>& coll3, stack<double>& coll4)
{
	while (!coll3.empty())
	{
		char c = coll3.front();   //取出第一个元素
		double op = 0;
		coll3.pop_front();   //并弹出此元素
							 //coll3.erase(coll3.begin());
							 //如果是操作数，压入栈中

							 //若是两位数在压入辅助数组后需要进行判断
		if (c >= '0'&&c <= '9')
		{
			op = (c - '0');
			coll4.push(op);
			//cout<<"op="<<op<<endl;
		}
		else if (c == '@')    		//如果是两位数则再读一位(若超过两位需要while扩展)
		{
			char d = coll3.front();
			op = coll4.top();
			coll4.pop();
			op = op * 10 + (d - '0');
			coll4.push(op);
			coll3.pop_front();
		}
		else	 //如果是操作符，从栈中弹出元素进行计算
		{
			double op1 = coll4.top();
			coll4.pop();
			double op2 = coll4.top();
			coll4.pop();
			switch (c)
			{
			case '+':
				coll4.push(op2 + op1);
				break;
			case '-':
				coll4.push(op2 - op1);
				break;
			case '*':
				coll4.push(op2*op1);
				break;
			case '/':
				coll4.push(op2 / op1);  //注意是op2(op)op1而不是op1(op)op2
				break;
			}
		}
	}
}