#include "shape_match.h"
#include<math.h>

int main(int argc, char **argv) {

	

	shapematch::ShapeMatching Kcg("D:\\files\\c++�ļ���\\c++ files\\shapeMatching\\shapeMatching", "temp");
	// ��ȡģ��ͼ��
	Mat model = imread("Template.jpg");
	// ת�Ҷ�
	
	//cvtColor(model, model, COLOR_BGR2GRAY);
	// ָ��Ҫ������ģ��Ƕȣ��߶ȷ�Χ
	shapematch::AngleRange ar(0.f, 360.f, 2.0f);
	shapematch::ScaleRange sr(1.0f, 1.0f, 0.05f);
	// ��ʼ����ģ��,����Ҫ��ģ�壬������ѵ��ģ��
	Kcg.MakingTemplates(model, ar, sr, 0, 60.f, 150.f);

	// ����ģ��
	cout << "Loading model ......" << endl;
	Kcg.LoadModel();
	cout << "Load succeed." << endl;

	// ��ȡ����ͼ��
	Mat source = imread("Search4.jpg");
	Mat draw_source;
	source.copyTo(draw_source);
	cvtColor(source, source, COLOR_BGR2GRAY);

	//����Ӧ��ֵ��
 // ����Ӧ��ֵ��ֵ��
	Mat srcBinary;
	cv::adaptiveThreshold(source, source, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, 10);

	////���л���ͼ����
	//cv::Mat sum;
	//cv::integral(source, sum,  CV_32S);
	//cv::normalize(sum, sum, 0, 255, NORM_MINMAX, CV_8UC1, Mat());
	
	//Timer timer;
	// ��ʼƥ��
	double start = (double)getTickCount();
	auto matches =
		Kcg.Matching(source, 0.70f, 0.6f, 60.f, 0.9f,
			shapematch::PyramidLevel_2,4,4);
	//double t = timer.out("=== Match time ===");
	double time = (((double)getTickCount() - start)) / getTickFrequency() * 1000;
	printf("edge template matching time : %.2f ms\n", time);
	cout << "Final match size: " << matches.size() << endl << endl;

	// ����ƥ����
	Kcg.DrawMatches(draw_source, matches, Scalar( 0, 0, 255));

	// ����ƥ��ʱ��
	rectangle(draw_source, Rect(Point(0, 0), Point(136, 20)), Scalar(255, 255, 255), -1);
	cv::putText(draw_source,
		"time: " + to_string(time) + "ms",
		Point(0, 16), FONT_HERSHEY_PLAIN, 1.f, Scalar(0, 0, 0), 1);

	// ��ʾ���ͼ��
	namedWindow("draw_source", 0);
	imshow("draw_source", draw_source);
	waitKey(0);
	system("pause");
}

//int getMinExp(int length);
//
////��������
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
////ɸѡ������
//void filtrateFeatures(cv::Mat &image)
//{
//	int newLength = drawGrid(image);
//
//}
//
//int main()
//{
//	// ��ȡģ��ͼ��
//	cv::Mat model = imread("Template.jpg");
//	int newLength = drawGrid(model);
//	system("pause");
//	return 0;
//}