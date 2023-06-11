#include "shape_match.h"
#include<math.h>

int main(int argc, char **argv) {

	

	shapematch::ShapeMatching Kcg("D:\\files\\c++文件夹\\c++ files\\shapeMatching\\shapeMatching", "temp");
	// 读取模板图像
	Mat model = imread("Template.jpg");
	// 转灰度
	
	//cvtColor(model, model, COLOR_BGR2GRAY);
	// 指定要制作的模板角度，尺度范围
	shapematch::AngleRange ar(0.f, 360.f, 2.0f);
	shapematch::ScaleRange sr(1.0f, 1.0f, 0.05f);
	// 开始制作模板,若需要新模板，则重新训练模板
	Kcg.MakingTemplates(model, ar, sr, 0, 60.f, 150.f);

	// 加载模板
	cout << "Loading model ......" << endl;
	Kcg.LoadModel();
	cout << "Load succeed." << endl;

	// 读取搜索图像
	Mat source = imread("Search4.jpg");
	Mat draw_source;
	source.copyTo(draw_source);
	cvtColor(source, source, COLOR_BGR2GRAY);

	//自适应二值化
 // 自适应阈值二值化
	Mat srcBinary;
	cv::adaptiveThreshold(source, source, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, 10);

	////进行积分图计算
	//cv::Mat sum;
	//cv::integral(source, sum,  CV_32S);
	//cv::normalize(sum, sum, 0, 255, NORM_MINMAX, CV_8UC1, Mat());
	
	//Timer timer;
	// 开始匹配
	double start = (double)getTickCount();
	auto matches =
		Kcg.Matching(source, 0.70f, 0.6f, 60.f, 0.9f,
			shapematch::PyramidLevel_2,4,4);
	//double t = timer.out("=== Match time ===");
	double time = (((double)getTickCount() - start)) / getTickFrequency() * 1000;
	printf("edge template matching time : %.2f ms\n", time);
	cout << "Final match size: " << matches.size() << endl << endl;

	// 画出匹配结果
	Kcg.DrawMatches(draw_source, matches, Scalar( 0, 0, 255));

	// 画出匹配时间
	rectangle(draw_source, Rect(Point(0, 0), Point(136, 20)), Scalar(255, 255, 255), -1);
	cv::putText(draw_source,
		"time: " + to_string(time) + "ms",
		Point(0, 16), FONT_HERSHEY_PLAIN, 1.f, Scalar(0, 0, 0), 1);

	// 显示结果图像
	namedWindow("draw_source", 0);
	imshow("draw_source", draw_source);
	waitKey(0);
	system("pause");
}

//int getMinExp(int length);
//
////画出网格
//int drawGrid(cv::Mat &image)
//{
//	int r = image.rows;
//	int c = image.cols;
//	int exp1 = getMinExp(r);
//	int exp2 = getMinExp(c);
//	int newRow = pow(2, exp1);
//	int newCol = pow(2, exp2);
//	int length = std::min(newRow, newCol);
//	int newLength = length;
//	while (newLength > length / 8)
//	{
//		newLength /= 2;
//	}
//	return newLength;
//}
//
//int getMinExp(int length)
//{
//	int i = 0;
//	int k = 0;
//	while (1)
//	{
//		if (length > pow(2, i) && length > pow(2, i + 1))
//		{
//			i++;
//		}
//		else {
//			if (length == pow(2, i))
//			{
//				k = i;
//			}
//			else
//			{
//				k = i + 1;
//			}
//			break;
//		}
//	}
//	return k;
//}
//
////筛选特征点
//void filtrateFeatures(cv::Mat &image)
//{
//	int newLength = drawGrid(image);
//
//}
//
//int main()
//{
//	// 读取模板图像
//	cv::Mat model = imread("Template.jpg");
//	int newLength = drawGrid(model);
//	system("pause");
//	return 0;
//}