#include<opencv2/opencv.hpp>
#include<iostream>
#include"quickopencv.h"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat src = imread("D:/OpenCV_Learning/��������/1.��ɡ������ĵ����ڵ�����һ/1.ͼƬ��ȡ����ʾ������ͼ���С/΢��ͼƬ_20211103234539.jpg");
	//imread��ȡ��8λ��256λ��������ͨ���ֱ���RGB������ͨ����ȡֵ����0-255��256λ��
	//���ټ���һ��͸��ͨ������4��256λ���ĸ�ͨ���ܹ�����2^32�����ܹ�2^32����ɫ
	if (src.empty())
	{
		cout << "error:û�ж�ȡ����ӦͼƬ��" << endl;
		return -1;
	}

	QuickDemo qd;
	qd.mat_creation_demo(src);
	
	waitKey(0);
	destroyAllWindows();
	return 0;
}