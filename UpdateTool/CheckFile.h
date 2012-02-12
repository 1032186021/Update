#pragma once

// ����ļ�����,����WPARAM��ʾ����ļ���������,LPARAM�����ļ���.
#define WM_CHECK_PROGRESS		(WM_USER + 2001)

// ����ļ����,����WPARAM��ʾ����ļ�����,LPARAM�Ƿ��ļ�����,����Ϊ0,������Ϊȱʧ�ļ���.
#define WM_CHECK_COMPLETE		(WM_USER + 2002)

// �����ļ�������Ϣ,����WPARAM��ʾ�ļ�����.
#define WM_CHECK_FILE_COUNT		(WM_USER + 2003)


class CCheckFile
{
public:
    CCheckFile(void);
    ~CCheckFile(void);

public:
    // �����ļ��б�.
    void GetFileList(ListXml& mFileList);

    // ͳ���ļ���.
    void CountFileSum(path const& p, path const& l);

    // ����ļ����б�.
    void AddFiles(ListXml& t, path const& p, path const& l);

    // �����ļ�����.
    DWORD GetListCount() { return m_dwFileCount; }

    // �����ļ�·��.
    void SetFindPath(CString& strPath) { m_strPath = strPath; }

    // �����б�.
    void CleanList() { m_lstXmlInfo.clear(); }

    // �ļ��汾�Ŵ�����.
    BOOL GetFileVersion(LPCTSTR szFilename, LONGLONG& lVer);
    BOOL GetFileVersion(LPCTSTR szFilename, CString& strVer);
    BOOL GetFileVersion(CString& strVer, LONGLONG& lVer);
    BOOL GetFileVersion(LONGLONG& lVer, CString& strVer);
    int CompareVersion(LPCTSTR szFile1, LPCTSTR szFile2); // �汾��Ϣ�Ƚ�,file1�汾����file2ʱ���ش���0,����ʱ����0,С��ʱ����С��0,����-1Ϊ�Ƚ�ʧ��.

public:
    // ��ִ�г���.
    HRESULT Execute(DWORD_PTR dwParam, HANDLE hObject);

private:
    CString m_strPath;
    DWORD m_dwFileCount;
    XMLNODEINFO m_xmlTemp;
    ListXml m_lstXmlInfo;						// xml��Ϣ.
    HWND m_hMsgWnd;								// ��Ϣ֪ͨ���ھ��.
};
