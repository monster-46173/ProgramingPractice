//#include<iostream>
//using namespace std;
//static int monthDays[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};   //12����ÿ���µ�����
//static char* weekDays[] = {"������", "����һ", "���ڶ�", "������", "������", "������", "������"};
//inline int getDayOfYear(int year)   //���ĳһ�������
//{
//    return ( year%4==0 && year%100!=0 ) || (year%400==0) ? 366 : 365;
//}
//int main()
//{
//    int year, month, day;
//    cout << "please enter year month day: ";
//    cin >> year >> month >> day;
//    while(year != 0 && month != 0 && day != 0)  //����һ������Ϊ0��ֹͣ����ִ��
//    {
//        if(year < 1 || month < 1 || month > 12 || day < 1)  //�����ղ��Ϸ�
//            cout << "input error!" << endl;
//        else
//        {
//            int dayOfWeek = 1, total = 0;
//            monthDays[1] = getDayOfYear(year) == 365 ? 28 : 29; //������һ����µ�����
//            if(day > monthDays[month - 1])  //���ڲ��Ϸ�
//                cout << "input error!" << endl;
//            else
//            {
//                for(int i = 1; i < year; i++)
//                    total += getDayOfYear(i);   //����1��1��1�յ���һ��1��1�վ���������
//                for(int i = 0; i < month - 1; i++)
//                    total += monthDays[i];      //������һ��1��1�յ���һ��1�վ���������
//                total += day;   //��������µ�����
//                cout << year << "��" << month << "��" << day << "����" << weekDays[total % 7] << endl;
//            }
//        }
//        cout << "please enter year month day: ";
//        cin >> year >> month >> day;
//    }
//    return 0;
//}
