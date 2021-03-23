#pragma once
#include <iostream>
#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;
namespace GetPos
{
	vector<cv::Point> GetPosition(string path);//返回的四个坐标从左上角开始顺时针顺序
	//两个测试函数
	void Display(string path);
	void Output_Position(vector<cv::Point> position);
}
