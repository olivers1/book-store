#include "Core.h"
#include <iostream>

using namespace std;

void Core::Initialize()
{
	Page* mainMenu = new Page(nullptr, "Main Menu");
	m_state = mainMenu;		// set mainMenu as default page
	m_children = &(m_state->GetChildVec());	// set pointer to point at mainMenu's child vector containing all its children pages

	Page* add = new Page(mainMenu, "Add Book");		// creating page object on the heap and assigning parent pointer to its member variable
	Page* addTitle = new Page(add, "Author");
	Page* addAuthor = new Page(addTitle, "Title");
	Page* addYear = new Page(addAuthor, "Year");
	Page* addStock = new Page(addYear, "Stock");
	Page* showBook = new Page(addStock, "Created");

	Page* sell = new Page(mainMenu, "Sell Book");

	Page* find = new Page(mainMenu, "Search Book");
	Page* findTitle = new Page(find, "Title");
	Page* findAuthor = new Page(findTitle, "Author");
	Page* findYear = new Page(findAuthor, "Year");
	Page* findStock = new Page(findYear, "Stock");

	Page* edit = new Page(mainMenu, "Edit Book");

	// DON'T KNOW HOW TO DO WITH searchResult that has findTitle, findAuthor, findYear, findStock as parents
	Page* searchResult = new Page(findTitle, "Search Result");


	// mainMenu
	mainMenu->AddChild(*add);		// adding children pages to each page (vector member variable of each page/object)
	mainMenu->AddChild(*find);
	mainMenu->AddChild(*sell);
	mainMenu->AddChild(*edit);

	// add
	add->AddChild(*addTitle);
	addTitle->AddChild(*addAuthor);
	addAuthor->AddChild(*addYear);
	addYear->AddChild(*addStock);
	addStock->AddChild(*showBook);
	showBook->AddChild(*mainMenu);

	// sell
	sell->AddChild(*find);

	// find
	find->AddChild(*findTitle);
	find->AddChild(*findAuthor);
	find->AddChild(*findYear);
	find->AddChild(*findStock);

	// edit
	edit->AddChild(*find);
}

void Core::Execute()
{
	while (m_input != -1)
	{
		ShowMenu();
		ReadInput();
		UpdateState();
	}
}

void Core::ShowMenu()
{
	cout << "\nPage name: " << m_state->GetPageName();
	cout << "\nChildren: ";
	for (Page child : *m_children)
	{
		cout << child.GetPageName() << ", ";
	}
}

void Core::ReadInput()
{
	cout << "\nEnter selection: ";
	cin >> m_input;
	cin.ignore();
}

void Core::UpdateState()
{
	m_state = &(m_state->GetChild(m_input));	// update page child pointer to point at selected child menu
	m_children = &(m_state->GetChildVec());	// update child vector pointer to point at children pages of new parent
}

