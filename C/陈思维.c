#include <stdio.h>

int main(void)
{
	//����һ���ַ��������Сд��ĸ����Сд��ĸ��2��
	//����Ǵ�д��ĸ������д��ĸ��3��
	//���ڲ�����Χ����ĸ����ѭ����
	//�����ַ�y��y+2������Сд��ĸ�ķ�Χ����ô��y���a�� 
	//��Ӧ��z��Ϊb����д��ĸͬ��
	char ch;
	while(1)
	{
		scanf("%c", &ch);
		if(ch < 'A' || ch > 'z')
			break;
		else if(ch > 'Z' && ch < 'a')
			break;
		else
		{
			if(ch + 2 > 'z')
				ch = ch - 'z' + 'a' - 1;
			else if(ch <= 'Z' && ch + 2 > 'Z')
				ch = ch - 'Z' + 'A' - 1;
			else
				ch += 2;
		}
		printf("%c\n", ch);
	}
	return 0;
}
