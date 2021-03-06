﻿#ifndef _STDAFX_H_
#define _STDAFX_H_

//---------------- enum ------------------------

enum DL_state { DL_WAIT, DL_RUN, DL_FAIL, DL_SUCCESS };//下载的状态
enum DL_protocol { http, https, magnet, thunder, ED2K, ftp, Err };//下载协议
//错误枚举
enum DL_remark
{
	RE_Run,//下载创建
	RE_OK,//下载成功
		  //需要再次尝试
		  RE_xunlei_error,//迅雷错误
		  RE_Parse_error,//解析错误
		  RE_Link_error,//链接不能下载
							  //不再尝试
							  RE_Link_timeout,//链接超时
							  RE_Download_timeout,//下载超时
							  RE_xunlei_save_error,//迅雷存储错误
							  RE_URL_error,//链接不符合要求
							  RE_Download_repeat//重复下载
};

//---------------- struct ----------------------

//信息传递
struct url_info
{
	int DJID;//下载ID
	int JID;//下载链接ID
	char url[1024];//url
	int RETRY_COUNT;//下载次数
	char filename[4092];//下载完成文件的名称
	int filesize;//下载完成文件大小
	char filepath[1024];//下载存放的路径
	int progress;//下载进度
	DL_protocol protocol;//下载使用的协议
	DL_state state;//下载状态
	DL_remark remark;//下载失败说明
	char start_time[64] = "";//下载开始时间
	char end_time[64] = "";//下载完成时间
	char update_time[64] = "";//更新时间
	char tool[256] = { "thunder" };//使用的下载工具
};

//配置参数
struct Config
{
	char xunlei[256] = "";
	char urlPath[256] = "";
	char savePath[256] = "";//window存储路径=save_Path+relativePath
	char save_Path[256] = "";//存储根目录
	char relativePath[256] = "";//存储相对路径
	char user[256] = "";
	char passwd[256] = "";
	char dbhost[256] = "";
	char dbName[256] = "";
	char tableName[256] = "";
	int timeout_time = 6000;//判断下载文件超时时间，单位秒
	char http_mold[256] = "";
	char https_mold[256] = "";
	char magnet_mold[256] = "";
	char ED2K_mold[256] = "";
	char ftp_mold[256] = "";
	char thunder_mold[256] = "";
	char tool[256] = "";
	int MaxTask = 20;//最大的任务量
	int MaxPetryCount = 5;
	int WaitTime = 20;
	char file_rule[1024] = "";
	int machine_id = 0;//分布式ID号
};

//---------- global ---------
extern Config g_config;

//----------------- functions ------------------
bool is_url_valid(url_info & info);//判断URL是否正确
bool is_file_valid(char ex[]);//判断文件扩展名

#endif // !_STDAFX_H_

