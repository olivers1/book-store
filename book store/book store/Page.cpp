#include "Page.h"
#include <vector>

using namespace std;

Page& Page::GetParent()
{
	return *m_parent;
}

void Page::SetParent(Page& parent)
{
	m_parent = &parent;
}

const string& Page::GetPageName()
{
	return m_pageName;
}

void Page::SetChild(Page& pageObj)
{
	m_vecChildren.push_back(pageObj);
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