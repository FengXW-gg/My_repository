#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <iomanip>

using namespace std;

void Menu(); //菜单

class Student//学生类
{
public:
	~Student();//析构函数
	void initialStudent(void);//初始学习信息
    void InputStudent(void);//增加学生信息
    void OutputStudent(void);//浏览学生信息
    void DeleteStudent(void);//删除学生信息
    void ChangeStudent(void);//修改学生信息
    void sortStudent(void);//对学生排序
    void seek_Name(void);//按学生的姓名查找
    void seek_Total(void);//按学生的总分查找
    void seek_s_rank(void);//按学生的排名查找

private:
    Student *St;     //学生类指针
    int Size;       //学生的人数
    int fuzhu ;    //辅助数
    int Grade;      //班级
    string Name;    //姓名
    int Number;      //学号
    float Score[2];//两科的成绩
    float Total;  //两科总分
    int s_rank;      //排名
};

Student::~Student()
{
	delete(St);
}

//菜单
void Menu()
{
	printf("—————————————————————————————————————————————————\n");
	printf("*\t欢迎使用学生成绩管理系统V1.0\t\t*\n");
	printf("*\t\t请选择功能\t\t\t*\n");
	printf("—————————————————————————————————————————————————\n");
	printf("*\t\t1.添加学生信息\t\t\t*\n");
	printf("*\t\t2.浏览学生信息\t\t\t*\n");
	printf("*\t\t3.删除学生信息\t\t\t*\n");
	printf("*\t\t4.修改学生信息\t\t\t*\n");
	printf("*\t\t5.按学生的姓名查找\t\t*\n");
	printf("*\t\t6.按学生的总分查找\t\t*\n");
	printf("*\t\t7.按学生的排名查找\t\t*\n");
	printf("*\t\t0.退出系统\t\t\t*\n");
	printf("—————————————————————————————————————————————————\n");
}

void Student::initialStudent()//初始输入学生信息
{
    int len;//学生的人数
    cout<<"请输入学生的人数:   ";
    cin>>len;


    Size  = len;
    fuzhu = len + 10000;//为以后增加预留

    St = new Student[fuzhu];

    for(int i=0; i<len; i++)
    {
        cout<<"请输入第"<<i+1<<"个学生的姓名:";
        cin>>St[i].Name;

        cout<<"请输入第"<<i+1<<"个学生的学号:";
        cin>>St[i].Number;

        cout<<"请输入第"<<i+1<<"个学生的班级:";
        cin>>St[i].Grade;

        cout<<"请输入第"<<i+1<<"个学生的高数成绩:";
        cin>>St[i].Score[0];

        cout<<"请输入第"<<i+1<<"个学生的英语成绩:";
        cin>>St[i].Score[1];

        St[i].Total = St[i].Score[0] + St[i].Score[1] ;

        St[i].s_rank=0;
        cout<<endl;

    }

}

void Student::InputStudent()//添加学生信息
{
    Size=Size+1;
    int i=Size;

    cout<<"请输入第"<<i<<"个学生的姓名:";
    cin>>St[i-1].Name;
    //system("cls");

    cout<<"请输入第"<<i<<"个学生的学号:";
    cin>>St[i-1].Number;
    //system("cls");

    cout<<"请输入第"<<i<<"个学生的班级:";
    cin>>St[i-1].Grade;
    //system("cls");

    cout<<"请输入第"<<i<<"个学生的高数成绩:";
    cin>>St[i-1].Score[0];
    // system("cls");

    cout<<"请输入第"<<i<<"个学生的英语成绩:";
    cin>>St[i-1].Score[1];
    //system("cls");

    St[i-1].Total = St[i-1].Score[0] + St[i-1].Score[1] ;

    St[i-1].s_rank=0;

    Student Temp=St[i-1];

    //增加后排序
    if(St[0].Total < St[i-1].Total)     // 插入总分最高的
    {
        for(int j = Size-1; j>0; j--)
        {
            St[j] = St[j-1];    //移位
        }

        St[0] = Temp;  //排在第一

        for(int j = 0; j < Size; j++)
        {
            St[j].s_rank+=1;    //排名加一
        }

    }

    bool s=true;

    if (St[0].Total > St[i-1].Total)
    {
        for(int j=0; j<Size-1; j++)
        {
            if(St[j].Total > St[i-1].Total && St[j+1].Total < St[i-1].Total)
            {

                for(int p = Size-1; p > j+1; p--)
                {
                    St[p] = St[p-1];
                }

                St[j+1] = Temp;
                St[j+1].s_rank = j+2;

                for(int p = j+2; p <Size; p++)
                {
                    St[p].s_rank +=1 ;
                }
                s=false;
            }
            if(!s)
                break;
        }
        if(s)
           St[i-1].s_rank=i;

    }
    cout<<"添加后："<<endl;
    OutputStudent();
    system("cls");

}

void Student::OutputStudent()//浏览学生信息
{

    cout<<"    姓名    班级    学号    高数    英语    总分    排名"<<endl;

    for(int i=0; i<Size ; i++)
    {
        cout<<setw(8)<<St[i].Name<<setw(8)<<St[i].Grade<<setw(8)<<St[i].Number<<setw(8)<<St[i].Score[0]<<
            setw(8)<<St[i].Score[1]<<setw(8)<<St[i].Total<<setw(8)<<St[i].s_rank<<endl;
    }

    system("pause");

}

void Student::DeleteStudent()//删除学生信息
{
    string str;
    cout<<"请输入你需要删除的学生的姓名:";
    cin>>str;

    int num;//标记姓名相等时的下标

    //寻找姓名相等时的下标
    for(int i=0; i<Size; i++)
    {
        //当姓名相等时
        if(str == St[i].Name)
        {
            num = i;
        }
    }


    for(int j=num+1; j<Size ; j++)
    {
        St[j-1] = St[j];
        St[j-1].s_rank-=1;
    }

    Size -= 1;//学生人数减少一个
    cout<<"删除后："<<endl;
    OutputStudent();

    system("cls");

}

void Student::ChangeStudent()//修改学生信息
{
    string name;
    cin>>name;

    int i,a;
    bool t=true;
    for(i=0; i<Size; i++)
    {
        if(name == St[i].Name)
        {   t=false;
            cout<<"修改前学生的信息:"<<endl;

            cout<<"    姓名    班级    学号    高数    英语    总分    排名"<<endl;

            cout<<setw(8)<<St[i].Name<<setw(8)<<St[i].Grade<<setw(8)<<St[i].Number<<setw(8)<<St[i].Score[0]<<
                    setw(8)<<St[i].Score[1]<<setw(8)<<St[i].Total<<setw(8)<<St[i].s_rank<<endl;
            break;
        }
    }

    cout<<"修改后的数据"<<endl;
    cout<<"请输入学生的姓名:";
    cin>>St[i].Name;

    cout<<"请输入学生的学号:";
    cin>>St[i].Number;

    cout<<"请输入学生的班级:";
    cin>>St[i].Grade;

    cout<<"请输入学生的高数成绩:";
    cin>>St[i].Score[0];

    cout<<"请输入学生的英语成绩:";
    cin>>St[i].Score[1];

    St[i].Total = St[i].Score[0] + St[i].Score[1] ;

    Student temp=St[i];

    if(temp.Total > St[0].Total)
    {
        for(int j = i; j >0 ; j--)
        {
            St[j]=St[j-1];
            St[j].s_rank+=1;
        }
        St[0]=temp;
        St[0].s_rank=1;
    }

    else if(temp.Total < St[Size-1].Total)
    {
        for(int j = i; j<Size-1; j++)
        {
            St[j]=St[j+1];
            St[j].s_rank-=1;
        }
        St[Size-1]=temp;
        St[Size-1].s_rank=Size;
    }

    else if(temp.Total<St[0].Total && temp.Total>St[i-1].Total)
    {
        int j=0;
        for( j=0; j < i; j++)
        {
            if( temp.Total>= St[j].Total )
            break;
        }
        for(int p = i; p > j ; p--)
        {
            St[p]=St[p-1];
            St[p].s_rank+=1;
        }
        St[j]=temp;
        St[j].s_rank=j+1;
    }

    else if(temp.Total > St[Size-1].Total && temp.Total < St[i+1].Total)
    {
        int j=0;
        for( j=Size-1; j > i; j--)
        {
            if( temp.Total <= St[j].Total )
            break;
        }
        for(int p = i; p < j; p++)
        {
            St[p]=St[p+1];
            St[p].s_rank-=1;
        }
        St[j]=temp;
        St[j].s_rank=j+1;
    }

    OutputStudent();
    system("pause");
}

void Student::sortStudent()//对学生初始排序
{
    for(int i=1; i<Size; i++)
    {
        int j = i-1;

        //插入数组中的数据
        Student temp = St[i];

        while(temp.Total  > St[j].Total && j>=0)
        {
            St[j+1]  = St[j];

			j--;
        }

        St[++j] = temp;
    }

    for (int i = 0; i < Size; i++ )
    {
        St[i].s_rank=i+1;
    }

    system("pause");
}

void Student::seek_Name()//按学生的姓名查找
{
    string name;
    cout<<"已录入的学生有："<<endl;
    for(int j=0; j<Size; j++)
    {
        cout<<St[j].Name<<setw(10);
    }
    cout<<endl;

    cout<<"请输入你需要查找的学生的姓名:";
    cin>>name;

    int i;
    bool t=false;

    for(i=0; i<Size; i++)
    {
        if(name == St[i].Name)
        {
            cout<<"    姓名    班级    学号    高数    英语    总分    排名"<<endl;

            cout<<setw(8)<<St[i].Name<<setw(8)<<St[i].Grade<<setw(8)<<St[i].Number<<setw(8)<<St[i].Score[0]<<
            setw(8)<<St[i].Score[1]<<setw(8)<<St[i].Total<<setw(8)<<St[i].s_rank<<endl;
            t = true;
        }
    }

    if( t == false)
        cout<<"查 无 此 人"<<endl;

    system("pause");

}

void Student::seek_Total()//按学生的总分查找
{
    int left ,right;
    cout<<"请输入你需要查找的学生的总分区间:";
    cin>>left >> right ;

    int i;
    bool t = false;

    cout<<"    姓名    班级    学号    高数    英语    总分    排名"<<endl;
    for(i=0; i<Size; i++)
    {
        if(left <= St[i].Total && St[i].Total <= right)
        {
            cout<<setw(8)<<St[i].Name<<setw(8)<<St[i].Grade<<setw(8)<<St[i].Number<<setw(8)<<St[i].Score[0]<<
            setw(8)<<St[i].Score[1]<<setw(8)<<St[i].Total<<setw(8)<<St[i].s_rank<<endl;
            t = true;
        }
    }

    if(t == false)
        cout<<"查 无 此 人"<<endl;

    system("pause");

}

void Student::seek_s_rank()//按学生的排名查找
{
    int q_rank;
    cout<<"请输入你需要查找的学生的排名:";
    cin>>q_rank;

    int i;
    bool t = false;

    for(i=0; i<Size; i++)
    {
        if(q_rank == St[i].s_rank)
        {
            cout<<"    姓名    班级    学号    高数    英语    总分    排名"<<endl;

            cout<<setw(8)<<St[i].Name<<setw(8)<<St[i].Grade<<setw(8)<<St[i].Number<<setw(8)<<St[i].Score[0]<<
            setw(8)<<St[i].Score[1]<<setw(8)<<St[i].Total<<setw(8)<<St[i].s_rank<<endl;
            t = true;
        }
    }

    if(t == false)
        cout<<"查 无 此 人"<<endl;

    system("pause");
}

int main()
{
    Student stu;
    stu.initialStudent();

    stu.sortStudent();  //按总分排序

    system("cls");

    bool t = true;

	while (t)
	{

		//打印菜单
        Menu();
		cout<<"请输入操作命令: ";

        int ch;
		cin>>ch;

		switch (ch)
		{
		case 1://1.添加学生信息
			stu.InputStudent();
			break;

		case 2://2.浏览学生信息
			stu.OutputStudent();
			break;

		case 3://3.删除学生信息
		    stu.OutputStudent();
			stu.DeleteStudent();
			break;

		case 4://4.修改学生信息
		    stu.OutputStudent();
		    cout<<"请输入你需要修改的学生的姓名:";
			stu.ChangeStudent();
			break;

		case 5://5.按学生的姓名查找
			stu.seek_Name();
			break;

		case 6://6.按学生的总分查找
            stu.seek_Total();
			break;

        case 7://7.按学生的排名查找
			stu.seek_s_rank();
			break;

		case 0://0.退出系统
			t = false;
			break;

		default:
			printf("输入有误，没有该功能\n\n");
			system("pause");  //暂停
			system("cls");    //清屏
			break;
		}

        system("cls");
	}

    system("cls");
	return 0;
}


