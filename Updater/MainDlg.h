#include "updater.hpp"

#pragma once


// ���Ը��µĶԻ���.

#define WM_CHECK_PROGRESS		(WM_USER + 2001)  // ����ļ�״̬.
#define WM_WORK_PROGRESS		(WM_USER + 2002)  // ���ع���״̬.
#define WM_UPDATE_PROGRESS		(WM_USER + 2003)  // ִ�и���״̬.

typedef struct 
{
   CString text;
   int single_pos;
   int main_pos;
} msg_info;

class CMainDlg : public CDialogImpl<CMainDlg>
{
public:
	enum { IDD = IDD_MAINDLG };

	BEGIN_MSG_MAP(CMainDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		COMMAND_ID_HANDLER(IDOK, OnOK)
		COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
      MESSAGE_HANDLER(WM_CHECK_PROGRESS, OnCheckProgress)
      MESSAGE_HANDLER(WM_WORK_PROGRESS, OnWorkProgress)
      MESSAGE_HANDLER(WM_UPDATE_PROGRESS, OnUpdateProgress)
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

   LRESULT OnCheckProgress(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
   LRESULT OnWorkProgress(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
   LRESULT OnUpdateProgress(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);

private:
   void check_files_callback(std::string file, int count, int index);
   void update_files_process(std::string file, int count, int index);
   void down_load_callback(std::string file, int count, int index, 
      int total_size, int total_read_bytes, int file_size, int read_bytes);

private:
   CProgressBarCtrl m_single_progress;	// single������.
   CProgressBarCtrl m_main_progress;	// main������.
   CWindow m_single_text;  // single��ʾ�ı�.
   CWindow m_main_text;    // main��ʾ�ı�.
   updater m_updater;      // �������, for test.
   int m_status;           // ��ǰ����״̬.
   CString m_single_str;
   CString m_main_str;
   CString m_last_string;
};
