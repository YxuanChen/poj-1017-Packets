#include<iostream>
#include<vector>
using namespace std;

//����3*3������ʣ��Ŀռ�ɷ�2*2����������
int remainder3_3(int n){
	int n1 = 0;//���Է�2*2����������
	if (n == 3){
		n1 = 1;
	}
	else if (n == 2){
		n1 = 3;
	}
	else if (n == 1){
		n1 = 5;
	}
	return n1;
}

int main(){
	int n;//������Ҫ��������
	int input[6];
	vector<int> output;
	//����
	while (true)
	{
		int n51 = 0;
		int n42 = 0;
		int n32 = 0;
		int n31 = 0;
		int n21 = 0;
		int n1 = 0;//
		for (int i = 0; i < 6; i++)
		{
			cin >> input[i];
		}
		//��ȫΪ0���˳�
		if (input[0] == 0 && input[1] == 0 && input[2] == 0
			&& input[3] == 0 && input[4] == 0 && input[5] == 0)
			break;
		
		//����
		n = input[5];//һ���������ֻ�ܷ���1��6*6����
		n += input[4];//һ���������ֻ�ܷ���1��5*5����
		n51 = input[4] * 11;//װ��5*5���������Ĵ�С��ȫ��ֻ�ܷ�1*1
		n += input[3];//һ���������ֻ�ܷ���1��4*4����
		n42 = input[3] * 5;//װ��4*4���������Ĵ�С��װ��2*2�����ĸ���
		n += input[2] / 4;//һ���������ֻ�ܷ���4��3*3����
		if (input[2]%4 != 0){
			n++;
			n32 = remainder3_3(input[2]%4);//װ��3*3���������Ĵ�С��װ��2*2�����ĸ���
			n31 = 36 - input[2] % 4 * 9 - n32 * 4;//�����ܷ���3*3��2*2�Ķ���������ʣ��ɷ�1*1������
		}
		if (input[1] > n42 + n32){
			input[1] -= (n42 + n32);//װ�����ط���ʣ�µ�2*2��������
			n += input[1] / 9;//һ���������ֻ�ܷ���9��2*2����
			if (input[1] % 9 != 0){
				n++;
				n21 = 36 - input[1] % 9 * 4;//װ��2*2���������Ĵ�С��װ��1*1�����ĸ���
			}	
		}
		else{	
			n1 = (n42 + n32 - input[1]) * 4;//������2*2���������ԭ������װ��2*2�����Ŀռ��װ1*1�����ĸ���
		}

		n1 = n51  + n31 + n21 + n1;//����ʣ��ռ��С��ֻʣ1*1����
		if (input[0] > n1){
			input[0] -= n1;
			n += input[0] / 36;
			if (input[0] % 36 != 0){
				n++;
			}
		}
		output.push_back(n);
	}

	for (int i = 0; i < output.size(); i++){
		cout << output[i] << endl;
	}

	output.clear();
	
	return 0;
}