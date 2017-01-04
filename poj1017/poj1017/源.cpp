#include<iostream>
#include<vector>
using namespace std;

//放入3*3包裹后，剩余的空间可放2*2包裹的数量
int remainder3_3(int n){
	int n1 = 0;//可以放2*2包裹的数量
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
	int n;//最少需要包裹数量
	int input[6];
	vector<int> output;
	//输入
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
		//若全为0则退出
		if (input[0] == 0 && input[1] == 0 && input[2] == 0
			&& input[3] == 0 && input[4] == 0 && input[5] == 0)
			break;
		
		//处理
		n = input[5];//一个包裹最多只能放入1个6*6包裹
		n += input[4];//一个包裹最多只能放入1个5*5包裹
		n51 = input[4] * 11;//装入5*5后包裹空余的大小，全部只能放1*1
		n += input[3];//一个包裹最多只能放入1个4*4包裹
		n42 = input[3] * 5;//装入4*4后包裹空余的大小能装入2*2包裹的个数
		n += input[2] / 4;//一个包裹最多只能放入4个3*3包裹
		if (input[2]%4 != 0){
			n++;
			n32 = remainder3_3(input[2]%4);//装入3*3后包裹空余的大小能装入2*2包裹的个数
			n31 = 36 - input[2] % 4 * 9 - n32 * 4;//假如能放入3*3和2*2的都放至最多后，剩余可放1*1的数量
		}
		if (input[1] > n42 + n32){
			input[1] -= (n42 + n32);//装入空余地方后剩下的2*2包裹个数
			n += input[1] / 9;//一个包裹最多只能放入9个2*2包裹
			if (input[1] % 9 != 0){
				n++;
				n21 = 36 - input[1] % 9 * 4;//装入2*2后包裹空余的大小能装入1*1包裹的个数
			}	
		}
		else{	
			n1 = (n42 + n32 - input[1]) * 4;//将所有2*2包裹填入后，原本可以装入2*2包裹的空间可装1*1包裹的个数
		}

		n1 = n51  + n31 + n21 + n1;//最终剩余空间大小，只剩1*1包裹
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