#define _CRT_SECURE_NO_DEPRECATE    
/*����˼·
	�������һ�����������Χ:1-100
	������:���ǲµ����ȴ�ҪС������ʾ��С��;��֮����ʾ�´���;���ǲ¶��ˣ�����ʾ��ϲ��Ҳ¶�ඣ����ּ�һ��
*/
// ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>			//rand����ͷ�ļ���
#include <time.h>			//ʱ�亯��ͷ�ļ�


void Menu() {				//�˵�����,���÷�������
	printf("------------------------------\n");
	printf("-----------��ӭʹ��-----------\n");
	printf("---------[1] ������Ϸ---------\n");
	printf("---------[2] ��Ϸ����---------\n");
	printf("---------[3] ���ֲ�ѯ---------\n");
	printf("---------[0] �˳���Ϸ---------\n");
	printf("-----------��������-----------\n");
	printf("-----------������-----------\n");
	printf("-----------��ϵ����-----------\n");
	printf("-----------@: liang-----------\n");
	printf("------------------------------\n");
}
int Game()					//��Ϸ����,������int����Ϊ���ﶨ����һ�����ֱ�����Ҫ�����ֽ��з���
{
	int ret = rand()%100 +1;						//���������,�������ΧΪ1-100
	int Score = 0;									//���ֱ���
	int guess_number = 0;							//�洢�����������
	while (1) {										//��ѭ������֤����һֱ������Ϸ
		printf("��������µ�����:>");
		scanf("%d", &guess_number);					//������ֵ
		if (guess_number < ret) {					//���һ��С��
			printf("��µ����ֱȴ�С�����ٴ�����\n");
		}
		else if (guess_number > ret) {				//�����,����
			printf("��µ����ֱȴ𰸴����ٴ�����\n");
		}
		else {										//�����������
			printf("��ϲ�㣬�¶��ˣ�\n");
			Score++;
			break;									//�¶Ժ�Ҫ��break����ѭ��
		}
	}
	return Score;									//���ػ���
}
int main()
{
	//ʱ�������һ�ξ���
	srand((unsigned int)time(NULL));		//�õ�ʱ�����ǿ������ת��Ϊunsigned int,time��������ָ��
	int input_option = 0;					//ѡ��
	int Result = 0;							//����
	do {									//������do��while��ԭ��������Ҫ��ӡһ��˵�
		Menu();
		scanf("%d", &input_option);
		switch (input_option) {
		case 1:
			Result = Game();
			
			break;
		case 2:
			printf("����Ϊ��Ϸ�Ľ���\n");
			break;
		case 3:
			printf("��Ļ���Ϊ:%d\n", Result);
			break;
		case 0:
			printf("�˳���Ϸ�ɹ�\n");
			break;
		default:
			printf("��������д�������������\n");
			break;
		}
	} while (input_option);
	return 0;
}