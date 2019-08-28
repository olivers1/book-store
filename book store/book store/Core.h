#pragma once

#include "Page.h"

class Core
{
private:
	Page* m_state;
	vector<Page>* m_children;
	int m_input;
public:
	void Initialize();

	void Execute();

	void ShowMenu();

	void ReadInput();

	void UpdateState();
};