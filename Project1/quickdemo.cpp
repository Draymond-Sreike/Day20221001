#include"quickopencv.h"

void QuickDemo::colorSpace_Demo(Mat& image)
{
	Mat hsv, gray;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	//��ͨ��HSV��ȡֵ��Χ:H(0-180),S��V(0-255),H��S��ʾ��ɫ��S�������Ͷȣ�V����ͼ������
	//RGB���Ե���ͼ�����ȣ�����Ҫ����ͼ����������Խ�ͼ��ת��HSVɫ�ʿռ���д���
		//ͨ��V���ں��ٷ���RGBɫ�ʿռ�
	cvtColor(image, gray, COLOR_BGR2GRAY);
	namedWindow("HSV", WINDOW_FREERATIO);
	namedWindow("GRAY", WINDOW_FREERATIO);
	namedWindow("BGR", WINDOW_FREERATIO);
	imshow("HSV", hsv);
	imshow("GRAY", gray);
	imshow("BGR", image);
	//Tips:imshow()��֧��256λ������������ʾ
		//��imread()��ȡʱ���Զ�ת��Ϊ8λ�����������ʹ��
	imwrite("D:/OpenCV_Learning/Day20221001/hsv.png", hsv);
	imwrite("D:/OpenCV_Learning/Day20221001/gray.png", gray);
}

void QuickDemo::mat_creation_demo(Mat& image)
{
	Mat m1, m2;
	m1 = image.clone();//��¡
	image.copyTo(m2);//����
	//��¡�͸��ƶ��Ǵ���һ��ȫ�µĶ������ڴ���ʵʵ���ڵؿ���һ����ԭ����֮��Ŀռ�
	//���������m1��m2������������Ӱ��ԭimage

	Mat m3 = Mat::zeros(Size(8, 8), CV_8UC3);
	//������һ��8*8���ش�С�ľ���zeros():�����ÿ��Ԫ�ض�Ϊ0��ֻ��ÿ�����ص�ĵ�һ��ͨ����ֵ0��
	//CV_8UC1��8��ʾ8λ��unsigned char���ͣ�ÿ��ͨ��ȡֵ��256�֣�2��8�η���
	//CV_8UC1��1��ʾ��ͨ����CV_8UC3���ʾ��ͨ������ÿ�����ص��ͨ����
	//Mat m3 = Mat::ones(Size(8, 8), CV_8UC1);
	//������һ��8*8��С�ľ���ones():�����ÿ��Ԫ�ض�Ϊ1��ֻ��ÿ�����ص�ĵ�һ��ͨ����ֵ1������ͨ����Ϊ0��
	
	//m3 = 127;//��m3ÿ�����ص�ĵ�һͨ����ֵΪ127������ͨ��Ĭ��Ϊ0
	//m3 = Scalar(127, 127, 127);//��m3ÿ�����ص��ÿ��ͨ������ֵΪ127
	m3 = Scalar(0, 255, 0);//BGR������һ�Ŵ���ͼ��
	m3.cols;//��ȡm3������������������ص������������ڿ��*ͨ������
	m3.rows;///��ȡm3������������������ص�����
	m3.channels();//��ȡm3��ͨ����
	//std::cout << m3 << std::endl;//��ʾm3�ľ�������
	imshow("output1", m3);

	Mat m4 = m3;
	//ʵ����m3��m4���ڴ���ָ��ͬһ���ڴ�
	//��ʱ��û��Ϊm4�ٿ���һ���µĿռ�,�����������m4�����ڲ���m3
	m4 = Scalar(0, 255, 255);
	imshow("output2", m3);
}