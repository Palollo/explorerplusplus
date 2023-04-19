// Copyright (C) Explorer++ Project
// SPDX-License-Identifier: GPL-3.0-only
// See LICENSE in the top level directory

#pragma once

#include "Bookmarks/BookmarkHelper.h"
#include "Bookmarks/BookmarkItem.h"
#include "Bookmarks/UI/BookmarkContextMenuController.h"

class BookmarkTree;
class CoreInterface;
class Navigator;

class BookmarkContextMenu
{
public:
	BookmarkContextMenu(BookmarkTree *bookmarkTree, HINSTANCE resourceInstance,
		CoreInterface *coreInterface, Navigator *navigator);

	BOOL ShowMenu(HWND parentWindow, BookmarkItem *parentFolder,
		const RawBookmarkItems &bookmarkItems, const POINT &ptScreen, bool recursive = false);
	bool IsShowingMenu() const;

private:
	void SetUpMenu(HMENU menu, const RawBookmarkItems &bookmarkItems);
	void SetMenuItemStates(HMENU menu);

	HINSTANCE m_resourceInstance;
	BookmarkContextMenuController m_controller;
	bool m_showingMenu;
};
