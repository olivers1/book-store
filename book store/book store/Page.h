#pragma once

#include <vector>
#include <iostream>

using namespace std;

class Page
{
private:
	vector<Page> m_vecParents;		// pointer to parent page
	vector<Page> m_vecChildren;		// vector containing all children of current page

	string m_pageName;		// name of the page
public:
	Page(string pageName) : m_pageName(pageName) {}

	Page(string pageName, Page* parent)
	{
		m_pageName = pageName;
		SetParent(*parent);
	}

	Page(string& pageName, Page* parent, Page& child)
	{
		m_pageName = pageName;
		SetParent(*parent);
		SetChild(child);
	}

	void SetChild(Page&);

	vector<Page>& GetChildVec();

	Page& GetChild(int&);

	void SetParent(Page&);

	vector<Page>& GetParentVec();

	const string& GetPageName();

};

