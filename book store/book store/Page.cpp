#include "Page.h"
#include <vector>

using namespace std;

void Page::AddChild(Page& pageObj)
{
	m_vecChildren.push_back(pageObj);
}

const string& Page::GetPageName()
{
	return m_pageName;
}

const string& Page::GetChildName()
{
	for (Page child : m_vecChildren)
	{
		cout << "\n" << child.GetPageName();
	}
}

Page& Page::GetChild(int& i)
{
	return m_vecChildren[i];
}

vector<Page>& Page::GetChildVec()
{
	return m_vecChildren;
}

const int& Page::GetChildSize()
{
	return m_vecChildren.size();
}