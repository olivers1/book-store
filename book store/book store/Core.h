#pragma once

#include "Page.h"

class Core
{
private:
	Page* m_page;
	Page* m_parent;	//--Hamid: You don't need this
	vector<Page>* m_children;	//--Hamid: You don't need this
	int m_input;
public:
	void Initialize();

	void Execute();

	void ShowMenu();

	void ReadInput();

	void UpdateState();
};