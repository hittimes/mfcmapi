#pragma once
#include <UI/Dialogs/ContentsTable/ContentsTableDlg.h>

class CContentsTableListCtrl;
class CSingleMAPIPropListCtrl;
class CParentWnd;

namespace cache
{
	class CMapiObjects;
}

namespace dialog
{
	class CMsgServiceTableDlg : public CContentsTableDlg
	{
	public:
		CMsgServiceTableDlg(
			_In_ ui::CParentWnd* pParentWnd,
			_In_ cache::CMapiObjects* lpMapiObjects,
			_In_ const std::string& szProfileName);
		virtual ~CMsgServiceTableDlg();

	private:
		// Overrides from base class
		void HandleAddInMenuSingle(
			_In_ LPADDINMENUPARAMS lpParams,
			_In_ LPMAPIPROP lpMAPIProp,
			_In_ LPMAPICONTAINER lpContainer) override;
		void OnDeleteSelectedItem() override;
		void OnDisplayItem() override;
		void OnRefreshView() override;
		_Check_return_ LPMAPIPROP OpenItemProp(int iSelectedItem, __mfcmapiModifyEnum bModify) override;
		void OnInitMenu(_In_ CMenu* pMenu) override;

		// Menu items
		void OnConfigureMsgService();
		void OnOpenProfileSection();

		LPSERVICEADMIN m_lpServiceAdmin;
		std::string m_szProfileName;

		DECLARE_MESSAGE_MAP()
	};
} // namespace dialog