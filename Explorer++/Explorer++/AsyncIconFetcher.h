// Copyright (C) Explorer++ Project
// SPDX-License-Identifier: GPL-3.0-only
// See LICENSE in the top level directory

#pragma once

#include <boost/core/noncopyable.hpp>
#include <concurrencpp/concurrencpp.h>
#include <shtypes.h>
#include <memory>
#include <stop_token>

class CachedIcons;
class Runtime;

class AsyncIconFetcher : private boost::noncopyable
{
public:
	AsyncIconFetcher(const Runtime *runtime, std::shared_ptr<CachedIcons> cachedIcons);

	[[nodiscard]] concurrencpp::lazy_result<std::optional<int>> GetIconIndexAsync(
		PCIDLIST_ABSOLUTE pidl, std::stop_token stopToken);
	int GetCachedIconIndexOrDefault(PCIDLIST_ABSOLUTE pidl) const;

private:
	std::optional<int> MaybeGetCachedIconIndex(PCIDLIST_ABSOLUTE pidl) const;
	int GetDefaultIconIndex(PCIDLIST_ABSOLUTE pidl) const;

	const Runtime *const m_runtime;
	const std::shared_ptr<CachedIcons> m_cachedIcons;
	int m_defaultFileIconIndex;
	int m_defaultFolderIconIndex;
};
