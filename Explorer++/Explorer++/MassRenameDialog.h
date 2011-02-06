#ifndef MASSRENAMEDIALOG_INCLUDED
#define MASSRENAMEDIALOG_INCLUDED

#include "../Helper/BaseDialog.h"
#include "../Helper/ResizableDialog.h"
#include "../Helper/DialogSettings.h"

class CMassRenameDialog;

class CMassRenameDialogPersistentSettings : public CDialogSettings
{
public:

	~CMassRenameDialogPersistentSettings();

	static CMassRenameDialogPersistentSettings &GetInstance();

private:

	friend CMassRenameDialog;

	static const TCHAR SETTINGS_KEY[];

	CMassRenameDialogPersistentSettings();

	CMassRenameDialogPersistentSettings(const CMassRenameDialogPersistentSettings &);
	CMassRenameDialogPersistentSettings & operator=(const CMassRenameDialogPersistentSettings &);
};

class CMassRenameDialog : public CBaseDialog
{
public:

	CMassRenameDialog(HINSTANCE hInstance,int iResource,HWND hParent,std::list<std::wstring> FullFilenameList);
	~CMassRenameDialog();

protected:

	BOOL	OnInitDialog();
	BOOL	OnCommand(WPARAM wParam,LPARAM lParam);
	BOOL	OnClose();
	BOOL	OnDestroy();

	void	GetResizableControlInformation(CBaseDialog::DialogSizeConstraint &dsc,std::list<CResizableDialog::Control_t> &ControlList);

private:

	void	OnOk();
	void	OnCancel();

	void	SaveState();

	void	ProcessFileName(const std::wstring strTarget,const std::wstring strFilename,int iFileIndex,std::wstring &strOutput);

	std::list<std::wstring>	m_FullFilenameList;
	HICON	m_hDialogIcon;
	HICON	m_hMoreIcon;

	CMassRenameDialogPersistentSettings	*m_pmrdps;
};

#endif