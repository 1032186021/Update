Update
======

һ�����ڸ��µĽ������.

UpdateTool	��Ŀ���������ɸ��µĹ���. �������ļ� main.exe, main.ini, main.dll, ��������main.exe.zip, main.ini.zip, main.dll.zip, filelist.xml, Ȼ����Խ���Щ�ļ����Ƶ�һ��http������.


libupdate	���³�����и���ʱ, ����������filelist.xml, Ȼ�����xml�����ݽ��и���. xml�е�����ÿ���еĺ���ֱ�����:
			name 		:	Դ�ļ���.
			compress 	:	ѹ����ʽ, Ŀǰ֧��2��ѹ����ʽ, �ֱ�Ϊzip��gz.
			filehash	:	ѹ���ļ���md5.
			md5			:	Դ�ļ���md5, ������λ�õ��ļ�md5��xml�е�md5��ͬ, ������ļ����������滻, ����check�ر��ʶ�����.
			version		:	�ļ��汾��.
			size		:	Դ�ļ���С.
			url			:	�ļ�����urlλ��, libupdate����ʱ, ���ǴӴ��������ض�Ӧ���ļ���.
			check		:	��ʾֻҪ��鵽�ļ�����, ���滻�ļ�, �ļ�������ʱ, �Żᱻ���ظ���.
			command		:	���ڶԴ��ļ���ִ������, Ŀǰֻ֧��regsvr����. regsvr��ʾ�Դ��ļ����ظ��º�, ��������: regsvr32.exe /s filename, ������ע��COM.

			libupdate���Կ����ʽʵ��, ʹ�������ʱ, ֻ��Ҫ����updater.hpp�Լ��Լ�libupdate����������(���絥������ʱ��ֻ�ṩupdater.hpp��libupdate.lib����).


Update		��һ����libupdateʵ�ֵĿͻ��˸��²���, ��������ʹ��http://codedoom.net/update/filelist.xml, ���Ը���λ��C:\setup_test.



ʹ�÷�����������:
	1. ׼������, ��Ҫһ̨http������, UpdateTool���߳���, ����ʹ��libupdate��д�ĸ��¿ͻ��˳���, �Լ���Ҫ���µĳ���.
		����: http://127.0.0.1, �����Http������Ŀ¼�д���һ��ר���ڸ��µ�Ŀ¼update.
		�������ڸ��µ��ļ���: main.exe, main.ini, main.dll.
	2. ʹ��UpdateTool����xml��ѹ���ļ�.
		��UpdateTool, �ڵ�һ���༭��(Ӧ�ó���װ����Ŀ¼)˫��, ѡ��"main.exe, main.ini, main.dll"�ļ����ڵ��ļ���.
		��main.ini����Ҫ���ͻ��༭��, ��ô����Ҫ��UpdateTool��'������'��һ��˫��ѡ��'��', �������³������ʱ, ��ʹmain.ini�ļ�md5��http�ϵĲ�һ��, Ҳ���ᱻ����.
		����һ�����ڴ��UpdateTool��������ļ����ļ���, ����c:\out_dir, Ȼ����UpdateTool�ڶ����༭��(�����ļ����·��)��˫��, ��ѡ������ļ���.
		�ڵ������༭��(URLλ��)�������http��������·��, ��������http://127.0.0.1/update.
		OK, ����Ϊֹ, ������ȷ���˴�����Ϣ, ����ֻ��Ҫ���"��ʼ����"��ť, UpdateTool����ѹ������ѡ����ļ�������һ��xml��ָ��������ļ���.
	3. ����c:\out_dir����ļ����������ļ�, ��http://127.0.0.1��update���Ŀ¼��, ���·�������þ������.

	���¿ͻ��˵ı�д����ʹ��libupdate����Update��Ŀ��ʵ��.


