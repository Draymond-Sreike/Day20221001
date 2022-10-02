#include<opencv2/opencv.hpp>
#include<iostream>
#include"quickopencv.h"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat src = imread("D:/OpenCV_Learning/考核任务/1.完成《任务文档》内的任务一/1.图片读取与显示，调节图像大小/微信图片_20211103234539.jpg");
	//imread读取到8位（256位），三个通道分别是RGB，各个通道的取值都是0-255（256位）
	//若再加上一个透明通道就是4个256位，四个通道总共就是2^32，即总共2^32种颜色
	if (src.empty())
	{
		cout << "error:没有读取到相应图片！" << endl;
		return -1;
	}

	QuickDemo qd;
	qd.mat_creation_demo(src);
	
	waitKey(0);
	destroyAllWindows();
	return 0;
}