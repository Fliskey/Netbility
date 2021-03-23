#include"GetPosition.h";
namespace GetPos
{
	vector<cv::Point> GetPosition(string path)//返回的四个坐标从左上角开始顺时针顺序
	{
		cv::Mat img = imread(path);
		cv::QRCodeDetector QRdetecter;
		vector<cv::Point> list;
		cv::Mat  res;
		QRdetecter.detectAndDecode(img, list, res);//调用构造函数，保存四个点（如果有二维码），否则为空。

		return list;
	}

	void Display(string path)
	{
		cv::Mat img = imread(path);
		vector<cv::Point> list;
		list = GetPosition(path);
		for (int i = 0; i < list.size(); i++)
		{

			if (i == 3)
				line(img, list[i], list[0], Scalar(0, 255, 0), 2);
			else
				line(img, list[i], list[i + 1], Scalar(0, 255, 0), 2);

		}
		imshow("二维码定位", img);
		waitKey(0);
	}

	void Output_Position(vector<cv::Point> position)
	{
		if (position.size() == 0)
		{
			cout << "识别不出二维码!" << endl;
			return;
		}cout << "四个点坐标为:\n";
		for (int i = 0; i < 4; i++)
			cout << "(" << position[i].x << "," << position[i].y << ")" << endl;
	}
}
