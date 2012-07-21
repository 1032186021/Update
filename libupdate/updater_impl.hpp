//
// updater_impl.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2011 Jack (jack.wgm@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// path LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// * $Id: updater_impl.hpp 49 2011-07-15 03:00:34Z jack $
//

#ifndef __UPDATER_IMPL_H__
#define __UPDATER_IMPL_H__

#include "url.hpp"
#include "md5.hpp"
#include "tinyxml.h"
#include "updater.hpp"

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <boost/asio.hpp>
using boost::asio::ip::tcp;

#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/function.hpp>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#include <boost/algorithm/string.hpp>


#pragma once

class updater_impl
{
public:
	typedef boost::function<void (std::string file, 
		int count, int index)> fun_check_files_callback;
	typedef boost::function<void (std::string file, 
		int count, int index)> fun_update_files_process;
	typedef boost::function<void (std::string file, int count, int index, 
		int total_size, int total_read_bytes, int file_size, int read_bytes)> fun_down_load_callback;

	typedef struct
	{
		std::string name;             // �ļ���.
		std::string md5;              // �ļ���MD5ֵ.
		std::string filehash;         // ѹ���ļ���HASH.
		std::string url;              // ���ص�url, Ĭ��Ϊ��.
		std::string command;          // ����.
		std::string compress;         // ѹ��ѡ��.
		bool check;							// �ļ����ѡ��, ���Ϊture, ���ʾ���Ƚ�MD5, ֻ���ļ�������ʱ�Ÿ���.
		boost::uint32_t size;         // ��С.
	} xml_node_info;

public:
	updater_impl(void);
	virtual ~updater_impl(void);

public:
	bool start(const std::string& url, fun_check_files_callback fc, fun_down_load_callback dl,
		fun_check_files_callback cf, fun_update_files_process uf, std::string setup_path);
	void stop();
	void pause();
	void resume();
	updater::result_type result();

protected:
	// ����.
	void update_files();
	bool parser_xml_file(const std::string& file);

	// �ļ�����.
	bool file_down_load(const url& url, const std::string& file,
		xml_node_info& info, const std::string& extera_header = "");
	void down_load_callback(std::string file, int count, int index, 
		int total_size, int total_read_bytes, int file_size, int read_bytes);

	std::string make_http_last_modified(const std::string& file);
	bool parser_http_last_modified(const std::string& str, struct tm* time);

private:
	fun_check_files_callback m_setup_file_check;
	fun_down_load_callback m_down_load_fun;
	fun_check_files_callback m_fun_check_files;
	fun_update_files_process m_update_files_fun;
	bool m_is_downloading;
	std::string m_url;
	std::string m_setup_path;
	boost::thread m_update_thrd;
	std::map<std::string, xml_node_info> m_update_file_list;
	std::map<std::string, xml_node_info> m_need_update_list;
	boost::uint64_t m_upfile_total_size;
	int m_current_index;
	int m_total_read_bytes;
	boost::asio::io_service m_io_service;
	boost::weak_ptr<tcp::socket> m_sock;
	// boost::shared_ptr<boost::asio::io_service> m_io_service;
	bool m_abort;
	bool m_paused;
	updater::result_type m_result;
};

#endif // __UPDATER_IMPL_H__
