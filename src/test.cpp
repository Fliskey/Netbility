/*
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include "ffmpeg.h"
using namespace std;

int main() {

	const char* test_para1[4] = { "input" ,"output" ,"jpg","mpg" };
	ffmpeg::ImgToVideo(test_para1[0], test_para1[1],test_para1[2]);

	const char* test_para2[4] = { "output","frame","mpg","jpg" };
	ffmpeg::VideoToImg(test_para2[0], test_para2[1], test_para2[2], test_para2[3]);
	return 0;
}
*/