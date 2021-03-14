#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS 1
#endif

#include<cstringt.h>
#include<malloc.h>
#include<direct.h>

namespace ffmpeg{

#define CMD_MAX_SIZE 256	
	
	void ImgToVideo(const char* src_img_path,
		const char* dst_video_path,
		const char* img_format,
		int fps=10,
		const char* video_format="mpg");
	void VideoToImg(const char* src_video_path,
		const char* dst_img_path,
		const char* video_format,
		const char* img_format);
}
