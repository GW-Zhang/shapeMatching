//#include "LocationRotation.h"
//#include <time.h>
//
//
//void showImgM(char *windowName, const Mat &img)
//{
//	namedWindow(windowName, WINDOW_NORMAL);
//	imshow(windowName, img);
//}
//
//void rotateImgM(const Mat &src, Mat &dst, double angle)
//{
//	Point center = Point(src.cols / 2, src.rows / 2);
//	Mat rotMat = getRotationMatrix2D(center, angle, 1.);
//	warpAffine(src, dst, rotMat, src.size());
//}
//
//
//void testTrain()
//{
//	char templePath[100] = {"D:\\files\\c++文件夹\\c++ files\\shapeMatching\\shapeMatching\\Template.jpg"};
//#ifdef TRAIN_IMG_ONE
//	sprintf(templePath, "%s", TRAIN_PATH);
//#else		TRAIN_IMG_TWO
//	sprintf(templePath, "%s%d%s", TRAIN_PATH, 1, ".bmp");
//#endif // TRAIN_IMG_ONE
//
//	Mat img = imread("Template.jpg", IMREAD_GRAYSCALE);
//	if (0 == img.data)
//	{
//		cout << "image path is wrong.\n";
//		//		return;
//	}
//
//	if (TRAIN)
//	{
//		Train t(img, FEATURE_NUM);
//		t.doTrain(0, 360, 1.);
//
//		t >> XML_PATH;
//		return;
//	}
//
//	int angle_id = -1;
//	float maxScore = -1;
//	int best_r = -1, best_c = -1;
//
//	char TEST_FULL_PATH[100] = "D:\\files\\c++文件夹\\c++ files\\shapeMatching\\shapeMatching\\Search1.jpg";
//	LocationRotation test;
//
//
//	test.loadXML(XML_PATH);
//	for (size_t n = 1; n <= NUM; ++n)
//	{
//		Point p;
//		sprintf(TEST_FULL_PATH, "%s%d%s", TEST_PATH, n, ".bmp");
//		Mat testImg = imread("Search1.jpg", IMREAD_GRAYSCALE);
//		if (0 == testImg.data)
//		{
//			cout << "test image path is wrong.\n";
//			return;
//		}
//
//		clock_t start = clock();
//
//		test.loadImg(testImg);
//
//		test.doRun();
//		clock_t time = clock() - start;
//		cout << "time:" << time << "ms" << "\n";
//		putText(test.showMat, "Time: " + to_string(time) + "ms", Point(200, 500), 20, 3, Scalar(0, 0, 255), 2);
//
//#ifdef DEBUG
//
//		destroyAllWindows();
//		char winName[20] = {"结果："};
//		sprintf(winName, "%d", n);
//		namedWindow(winName, WINDOW_NORMAL);
//		imshow(winName, test.showMat);
//		//	waitKey(0);
//		waitKey(1);
//		char path[50]="result.jpg";
//		sprintf(path, "%s%d%s", SAVE_THREAD_PATH, n, ".bmp");
//		imwrite(path, test.showMat);
//		cout << n << " end" << endl << "==============================================\n\n";
//
//#endif
//
//	}
//	waitKey(0);
//}
//
//int main(int argc, char **argv)
//{
//	testTrain();
//
//	return 0;
//}