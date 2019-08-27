#pragma once

#include <vector>
#include <iostream>

using namespace std;

class Page
{
private:
	Page* m_parent;		// pointer to parent page
	vector<Page>* m_child;	// pointer to vector that contains the children pages of current page
	vector<Page> m_vecChildren;		// vector containing all children of current page

	string m_pageName;		// name of the page
public:
	Page(Page* parent, string pageName) : m_parent(parent), m_pageName(pageName), m_child(&m_vecChildren) {}

	void AddChild(Page&);

	const string& GetPageName();

	const string& GetChildName();

	Page& GetChild(int&);

	vector<Page>& GetChildVec();

	const int& GetChildSize();
};

