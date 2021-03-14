#include"ffmpeg.h"

namespace ffmpeg {
	const char* ffmpeg_path = "/ffmpeg/bin";

	/*
	*src_img_path为图片文件所在相对地址 图片命名格式为 "img0001.jpg  img0002.jpg"
	 *dst_video_path为最终视频相对地址
	 *img_format为图片格式
	 *video_format为视频格式
	 *fps为视频每秒的帧数
	 */
	void ImgToVideo(const char* src_img_path,
		const char* dst_video_path,
		const char* img_format,
		int fps,
		const char* video_format) 
	{
		char* cmd = (char*)malloc(CMD_MAX_SIZE);
		char* current_path = (char*)malloc(CMD_MAX_SIZE);
		_getcwd(current_path, CMD_MAX_SIZE);
		
		sprintf(cmd,
			"%s/%s/ffmpeg.exe -y -f image2 -i %s/img%%04d.%s -r 25 %s/video.%s",
			current_path,ffmpeg_path,src_img_path,img_format, dst_video_path,video_format);

		system(cmd);
	}

	/*
	*src_video_path: 视频文件地址  视频文件统一命名为"video.xxx"
	*dst_img_path: 图片保存文件地址
	*video_format: 视频格式
	*img_format:  图片格式
	*/
	void VideoToImg(const char* src_video_path,
		const char* dst_img_path,
		const char* video_format,
		const char* img_format)
	{
		char* cmd = (char*)malloc(CMD_MAX_SIZE);
		char* current_path = (char*)malloc(CMD_MAX_SIZE);
		_getcwd(current_path, CMD_MAX_SIZE);
		sprintf(cmd,
			"%s/%s/ffmpeg.exe -i %s/video.%s -r 1 %s/img%%04d.%s",
			current_path, ffmpeg_path, src_video_path, video_format, dst_img_path,img_format);

		system(cmd);
	}

}

