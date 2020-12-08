#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <iomanip>

using namespace std;

void Menu(); //�˵�

class Student//ѧ����
{
public:
	~Student();//��������
	void initialStudent(void);//��ʼѧϰ��Ϣ
    void InputStudent(void);//����ѧ����Ϣ
    void OutputStudent(void);//���ѧ����Ϣ
    void DeleteStudent(void);//ɾ��ѧ����Ϣ
    void ChangeStudent(void);//�޸�ѧ����Ϣ
    void sortStudent(void);//��ѧ������
    void seek_Name(void);//��ѧ������������
    void seek_Total(void);//��ѧ�����ֲܷ���
    void seek_s_rank(void);//��ѧ������������

private:
    Student *St;     //ѧ����ָ��
    int Size;       //ѧ��������
    int fuzhu ;    //������
    int Grade;      //�༶
    string Name;    //����
    int Number;      //ѧ��
    float Score[2];//���Ƶĳɼ�
    float Total;  //�����ܷ�
    int s_rank;      //����
};

Student::~Student()
{
	delete(St);
}

//�˵�
void Menu()
{
	printf("��������������������������������������������������������������������������������������������������\n");
	printf("*\t��ӭʹ��ѧ���ɼ�����ϵͳV1.0\t\t*\n");
	printf("*\t\t��ѡ����\t\t\t*\n");
	printf("��������������������������������������������������������������������������������������������������\n");
	printf("*\t\t1.���ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t2.���ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t3.ɾ��ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t4.�޸�ѧ����Ϣ\t\t\t*\n");
	printf("*\t\t5.��ѧ������������\t\t*\n");
	printf("*\t\t6.��ѧ�����ֲܷ���\t\t*\n");
	printf("*\t\t7.��ѧ������������\t\t*\n");
	printf("*\t\t0.�˳�ϵͳ\t\t\t*\n");
	printf("��������������������������������������������������������������������������������������������������\n");
}

void Student::initialStudent()//��ʼ����ѧ����Ϣ
{
    int len;//ѧ��������
    cout<<"������ѧ��������:   ";
    cin>>len;


    Size  = len;
    fuzhu = len + 10000;//Ϊ�Ժ�����Ԥ��

    St = new Student[fuzhu];

    for(int i=0; i<len; i++)
    {
        cout<<"�������"<<i+1<<"��ѧ��������:";
        cin>>St[i].Name;

        cout<<"�������"<<i+1<<"��ѧ����ѧ��:";
        cin>>St[i].Number;

        cout<<"�������"<<i+1<<"��ѧ���İ༶:";
        cin>>St[i].Grade;

        cout<<"�������"<<i+1<<"��ѧ���ĸ����ɼ�:";
        cin>>St[i].Score[0];

        cout<<"�������"<<i+1<<"��ѧ����Ӣ��ɼ�:";
        cin>>St[i].Score[1];

        St[i].Total = St[i].Score[0] + St[i].Score[1] ;

        St[i].s_rank=0;
        cout<<endl;

    }

}

void Student::InputStudent()//���ѧ����Ϣ
{
    Size=Size+1;
    int i=Size;

    cout<<"�������"<<i<<"��ѧ��������:";
    cin>>St[i-1].Name;
    //system("cls");

    cout<<"�������"<<i<<"��ѧ����ѧ��:";
    cin>>St[i-1].Number;
    //system("cls");

    cout<<"�������"<<i<<"��ѧ���İ༶:";
    cin>>St[i-1].Grade;
    //system("cls");

    cout<<"�������"<<i<<"��ѧ���ĸ����ɼ�:";
    cin>>St[i-1].Score[0];
    // system("cls");

    cout<<"�������"<<i<<"��ѧ����Ӣ��ɼ�:";
    cin>>St[i-1].Score[1];
    //system("cls");

    St[i-1].Total = St[i-1].Score[0] + St[i-1].Score[1] ;

    St[i-1].s_rank=0;

    Student Temp=St[i-1];

    //���Ӻ�����
    if(St[0].Total < St[i-1].Total)     // �����ܷ���ߵ�
    {
        for(int j = Size-1; j>0; j--)
        {
            St[j] = St[j-1];    //��λ
        }

        St[0] = Temp;  //���ڵ�һ

        for(int j = 0; j < Size; j++)
        {
            St[j].s_rank+=1;    //������һ
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
    cout<<"��Ӻ�"<<endl;
    OutputStudent();
    system("cls");

}

void Student::OutputStudent()//���ѧ����Ϣ
{

    cout<<"    ����    �༶    ѧ��    ����    Ӣ��    �ܷ�    ����"<<endl;

    for(int i=0; i<Size ; i++)
    {
        cout<<setw(8)<<St[i].Name<<setw(8)<<St[i].Grade<<setw(8)<<St[i].Number<<setw(8)<<St[i].Score[0]<<
            setw(8)<<St[i].Score[1]<<setw(8)<<St[i].Total<<setw(8)<<St[i].s_rank<<endl;
    }

    system("pause");

}

void Student::DeleteStudent()//ɾ��ѧ����Ϣ
{
    string str;
    cout<<"����������Ҫɾ����ѧ��������:";
    cin>>str;

    int num;//����������ʱ���±�

    //Ѱ���������ʱ���±�
    for(int i=0; i<Size; i++)
    {
        //���������ʱ
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

    Size -= 1;//ѧ����������һ��
    cout<<"ɾ����"<<endl;
    OutputStudent();

    system("cls");

}

void Student::ChangeStudent()//�޸�ѧ����Ϣ
{
    string name;
    cin>>name;

    int i,a;
    bool t=true;
    for(i=0; i<Size; i++)
    {
        if(name == St[i].Name)
        {   t=false;
            cout<<"�޸�ǰѧ������Ϣ:"<<endl;

            cout<<"    ����    �༶    ѧ��    ����    Ӣ��    �ܷ�    ����"<<endl;

            cout<<setw(8)<<St[i].Name<<setw(8)<<St[i].Grade<<setw(8)<<St[i].Number<<setw(8)<<St[i].Score[0]<<
                    setw(8)<<St[i].Score[1]<<setw(8)<<St[i].Total<<setw(8)<<St[i].s_rank<<endl;
            break;
        }
    }

    cout<<"�޸ĺ������"<<endl;
    cout<<"������ѧ��������:";
    cin>>St[i].Name;

    cout<<"������ѧ����ѧ��:";
    cin>>St[i].Number;

    cout<<"������ѧ���İ༶:";
    cin>>St[i].Grade;

    cout<<"������ѧ���ĸ����ɼ�:";
    cin>>St[i].Score[0];

    cout<<"������ѧ����Ӣ��ɼ�:";
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

void Student::sortStudent()//��ѧ����ʼ����
{
    for(int i=1; i<Size; i++)
    {
        int j = i-1;

        //���������е�����
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

void Student::seek_Name()//��ѧ������������
{
    string name;
    cout<<"��¼���ѧ���У�"<<endl;
    for(int j=0; j<Size; j++)
    {
        cout<<St[j].Name<<setw(10);
    }
    cout<<endl;

    cout<<"����������Ҫ���ҵ�ѧ��������:";
    cin>>name;

    int i;
    bool t=false;

    for(i=0; i<Size; i++)
    {
        if(name == St[i].Name)
        {
            cout<<"    ����    �༶    ѧ��    ����    Ӣ��    �ܷ�    ����"<<endl;

            cout<<setw(8)<<St[i].Name<<setw(8)<<St[i].Grade<<setw(8)<<St[i].Number<<setw(8)<<St[i].Score[0]<<
            setw(8)<<St[i].Score[1]<<setw(8)<<St[i].Total<<setw(8)<<St[i].s_rank<<endl;
            t = true;
        }
    }

    if( t == false)
        cout<<"�� �� �� ��"<<endl;

    system("pause");

}

void Student::seek_Total()//��ѧ�����ֲܷ���
{
    int left ,right;
    cout<<"����������Ҫ���ҵ�ѧ�����ܷ�����:";
    cin>>left >> right ;

    int i;
    bool t = false;

    cout<<"    ����    �༶    ѧ��    ����    Ӣ��    �ܷ�    ����"<<endl;
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
        cout<<"�� �� �� ��"<<endl;

    system("pause");

}

void Student::seek_s_rank()//��ѧ������������
{
    int q_rank;
    cout<<"����������Ҫ���ҵ�ѧ��������:";
    cin>>q_rank;

    int i;
    bool t = false;

    for(i=0; i<Size; i++)
    {
        if(q_rank == St[i].s_rank)
        {
            cout<<"    ����    �༶    ѧ��    ����    Ӣ��    �ܷ�    ����"<<endl;

            cout<<setw(8)<<St[i].Name<<setw(8)<<St[i].Grade<<setw(8)<<St[i].Number<<setw(8)<<St[i].Score[0]<<
            setw(8)<<St[i].Score[1]<<setw(8)<<St[i].Total<<setw(8)<<St[i].s_rank<<endl;
            t = true;
        }
    }

    if(t == false)
        cout<<"�� �� �� ��"<<endl;

    system("pause");
}

int main()
{
    Student stu;
    stu.initialStudent();

    stu.sortStudent();  //���ܷ�����

    system("cls");

    bool t = true;

	while (t)
	{

		//��ӡ�˵�
        Menu();
		cout<<"�������������: ";

        int ch;
		cin>>ch;

		switch (ch)
		{
		case 1://1.���ѧ����Ϣ
			stu.InputStudent();
			break;

		case 2://2.���ѧ����Ϣ
			stu.OutputStudent();
			break;

		case 3://3.ɾ��ѧ����Ϣ
		    stu.OutputStudent();
			stu.DeleteStudent();
			break;

		case 4://4.�޸�ѧ����Ϣ
		    stu.OutputStudent();
		    cout<<"����������Ҫ�޸ĵ�ѧ��������:";
			stu.ChangeStudent();
			break;

		case 5://5.��ѧ������������
			stu.seek_Name();
			break;

		case 6://6.��ѧ�����ֲܷ���
            stu.seek_Total();
			break;

        case 7://7.��ѧ������������
			stu.seek_s_rank();
			break;

		case 0://0.�˳�ϵͳ
			t = false;
			break;

		default:
			printf("��������û�иù���\n\n");
			system("pause");  //��ͣ
			system("cls");    //����
			break;
		}

        system("cls");
	}

    system("cls");
	return 0;
}


