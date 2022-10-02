#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat original_Image = imread("D:/OpenCV_Learning/考核任务/1.完成《任务文档》内的任务一/1.图片读取与显示，调节图像大小/微信图片_20211103234539.jpg");
	//创建一个Mat矩阵original_Image，接收imread()对原图(original_Image)读取的返回值
	//默认读取图片以彩图进行读取，即默认:IMREAD_COLOR
//	Mat original_Image = imread("D:/OpenCV_Learning/考核任务/1.完成《任务文档》内的任务一/1.图片读取与显示，调节图像大小/微信图片_20211103234539.jpg", IMREAD_GRAYSCALE);
	//以灰度图形式进行图片读取

	if (original_Image.empty())
	{//提高代码健壮性，保证src是读取到图片之后才让程序继续运行，没有读到图片的时候结束程序
		printf("error:没有读取到相应图片！\n");
		return -1;
	}

	//namedWindow("Original_Image", WINDOW_FREERATIO);
	//创建一个名为"Original_Image"窗口
		//注意这里"Original_Image"要与后续imshow()中传入的显示窗口名字相同需要同为"Original_Image"或其他
	//函数第2个参数的设置让后续调用imshow()函数显示出来的图片窗口大小自由可调
	imshow("Original_Image", original_Image);
	//用一个窗口来显示src的图片,窗口名为"Original_Image"
	//imshow()创建的窗口默认是原始尺寸显示，其更改大小的方式是上面的namedWindow()函数
	//只有在namedWindow和imshow两个函数的窗口显示名字相同时，imshow显示的图片才会在同一个窗口
	//如若imshow与namedwindow两个函数创建的窗口名称不同则会显示两个窗口
		//且namedwindow窗口为无内容窗口，imshow将是一个有图片显示但无法调节大小的,与原图等大的原始窗口
	
	Mat change_Image;
	//创建一个Mat矩阵change_Image，后续用于存储大小经过转换后的图像
	int changeLength = 1280;
	int changeWide = 720;
	//根据题目要求，设定图像转换后的大小
	resize(original_Image, change_Image, Size(changeLength, changeWide));
	//调用resize函数转换图像大小，并将转换后的图像存入change_Image对象
	imshow("Change_Image", change_Image);
	//显示大小经过转换后的图像
	imwrite("D:/OpenCV_Learning/考核任务/1.完成《任务文档》内的任务一/1.图片读取与显示，调节图像大小/效果图/Change_Image.png"
				, change_Image);
	//调用imwrite函数将转换后的图像change_Image存储在对应路径下，并存储为Change_Image.png
	
	waitKey(0);
	//生成一个阻塞，让窗口显示的图片一直出现
	//若改成waitKey(n)，则是让窗口停留n毫秒

	destroyAllWindows();
	//关闭前面创建的所有显示窗口

	return 0;
}
