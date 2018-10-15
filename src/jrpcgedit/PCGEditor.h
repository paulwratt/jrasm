//=============================================================================
// PCGEditor.h
//=============================================================================
#ifndef __JRPCGEDIT_PCGEDITOR_H__
#define __JRPCGEDIT_PCGEDITOR_H__

#include "PCGInfo.h"

//-----------------------------------------------------------------------------
// PCGEditor
//-----------------------------------------------------------------------------
class PCGEditor : public wxPanel {
public:
	class Listener {
	public:
		virtual void NotifyPCGModified() = 0;
	};
	class ListenerList : public std::vector<Listener *> {
	public:
		void NotifyPCGModified();
	};
private:
	enum {
		_mgnLeft = 8,
		_mgnRight = 8,
		_mgnTop = 8,
		_mgnBottom = 8,
	};
private:
	wxRect _rcMatrix;
	AutoPtr<PCGInfo> _pPCGInfo;
	std::unique_ptr<wxBitmap> _pBmpMatrix;
	wxPen _penBorder;
	wxPen _penGrid;
	wxPen _penGridHL;
	wxBrush _brushBg;
	wxBrush _brushMatrix;
	ListenerList _listenerList;
public:
	PCGEditor(wxWindow *pParent, PCGInfo *pPCGInfo);
	inline void AddListener(Listener *pListener) { _listenerList.push_back(pListener); }
	inline int DotPosXToMatrixCoord(int dotPosX) const { return _mgnLeft + dotPosX * GetDotSize(); }
	inline int DotPosYToMatrixCoord(int dotPosY) const { return _mgnTop + dotPosY * GetDotSize(); }
	inline int GetDotSize() const { return _pPCGInfo->GetDotSizeEditor(); }
	void SetDotSize(int dotSize);
	void SetPCGInfo(PCGInfo *pPCGInfo);
	void PrepareMatrix(bool refreshFlag);
	void UpdateMatrix(bool refreshFlag);
	void PutDot(int dotPosX, int dotPosY, bool flag);
	wxRect DotPosToCursorRect(int dotPosX, int dotPosY);
	void PointToDotPos(const wxPoint &pt, int *pDotPosX, int *pDotPosY) const;
private:
    wxDECLARE_EVENT_TABLE();
	void OnEraseBackground(wxEraseEvent &event);
	void OnSize(wxSizeEvent &event);
	void OnPaint(wxPaintEvent &event);
	void OnSetFocus(wxFocusEvent &event);
	void OnKillFocus(wxFocusEvent &event);
	void OnMotion(wxMouseEvent &event);
	void OnLeftDown(wxMouseEvent &event);
	void OnLeftUp(wxMouseEvent &event);
	void OnLeftDClick(wxMouseEvent &event);
	void OnRightDown(wxMouseEvent &event);
	void OnRightUp(wxMouseEvent &event);
	void OnLeaveWindow(wxMouseEvent &event);
	void OnKeyDown(wxKeyEvent &event);
	void OnKeyUp(wxKeyEvent &event);
};

#endif