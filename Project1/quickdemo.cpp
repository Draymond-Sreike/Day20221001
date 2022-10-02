#include"quickopencv.h"

void QuickDemo::colorSpace_Demo(Mat& image)
{
	Mat hsv, gray;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	//三通道HSV，取值范围:H(0-180),S、V(0-255),H和S表示颜色，S决定饱和度，V决定图像亮度
	//RGB难以调整图像亮度，若需要调节图像亮度则可以将图像转至HSV色彩空间进行处理
		//通过V调节后再返回RGB色彩空间
	cvtColor(image, gray, COLOR_BGR2GRAY);
	namedWindow("HSV", WINDOW_FREERATIO);
	namedWindow("GRAY", WINDOW_FREERATIO);
	namedWindow("BGR", WINDOW_FREERATIO);
	imshow("HSV", hsv);
	imshow("GRAY", gray);
	imshow("BGR", image);
	//Tips:imshow()仅支持256位、浮点数据显示
		//而imread()读取时会自动转化为8位，二者需搭配使用
	imwrite("D:/OpenCV_Learning/Day20221001/hsv.png", hsv);
	imwrite("D:/OpenCV_Learning/Day20221001/gray.png", gray);
}

void QuickDemo::mat_creation_demo(Mat& image)
{
	Mat m1, m2;
	m1 = image.clone();//克隆
	image.copyTo(m2);//复制
	//克隆和复制都是创建一个全新的对象，在内存中实实在在地开辟一块在原对象之外的空间
	//后续如果对m1，m2操作，并不会影响原image

	Mat m3 = Mat::zeros(Size(8, 8), CV_8UC3);
	//创建了一个8*8像素大小的矩阵，zeros():矩阵的每个元素都为0（只对每个像素点的第一个通道赋值0）
	//CV_8UC1中8表示8位的unsigned char类型，每个通道取值有256种（2的8次方）
	//CV_8UC1中1表示单通道，CV_8UC3则表示三通道，即每个像素点的通道数
	//Mat m3 = Mat::ones(Size(8, 8), CV_8UC1);
	//创建了一个8*8大小的矩阵，ones():矩阵的每个元素都为1（只对每个像素点的第一个通道赋值1，其他通道仍为0）
	
	//m3 = 127;//将m3每个像素点的第一通道赋值为127，其他通道默认为0
	//m3 = Scalar(127, 127, 127);//将m3每个像素点的每个通道都赋值为127
	m3 = Scalar(0, 255, 0);//BGR，创建一张纯绿图像
	m3.cols;//获取m3矩阵的列数，即横像素点总数（不等于宽度*通道数）
	m3.rows;///获取m3矩阵的行数，即竖像素点总数
	m3.channels();//获取m3的通道数
	//std::cout << m3 << std::endl;//显示m3的矩阵数组
	imshow("output1", m3);

	Mat m4 = m3;
	//实际上m3、m4在内存中指向同一块内存
	//此时并没有为m4再开辟一块新的空间,后续如果操作m4就是在操作m3
	m4 = Scalar(0, 255, 255);
	imshow("output2", m3);
}