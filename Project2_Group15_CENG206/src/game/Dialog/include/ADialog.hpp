#ifndef _AGAMEDIALOG_H_
#define _AGAMEDIALOG_H_

#include <wx/wx.h>
#include "IDialog.hpp"

class ADialog : public wxDialog, public IDialog
{
public:
	ADialog(wxWindow* parent, wxString& title);
	virtual ~ADialog();

	virtual void Show() = 0;
	virtual void Hide() = 0;
};


#endif

