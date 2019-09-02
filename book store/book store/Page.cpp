#include "Page.h"
#include <vector>

using namespace std;

void Page::SetChild(Page& pageObj)
{
	m_vecChildren.push_back(pageObj);
}

vector<Page>& Page::GetChildVec()
{
	return m_vecChildren;
}

Page& Page::GetChild(int& i)
{
	return m_vecChildren[i];
}

void Page::SetParent(Page& pageObj)
{
	m_vecParents.push_back(pageObj);
}

vector<Page>& Page::GetParentVec()
{
	return m_vecParents;
}

const string& Page::GetPageName()
{
	return m_pageName;
}
