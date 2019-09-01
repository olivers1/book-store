#include "Core.h"
#include <iostream>

using namespace std;

void Core::Initialize()
{
	Page* dummyPage = new Page(nullptr, "dummyPage");	// dummy page to avoid error when parent pointer is pointing to 'nullptr'
	Page* mainMenu = new Page(dummyPage, "Main Menu");
	dummyPage->SetChild(*mainMenu);

	m_page = mainMenu;		// set mainMenu as default page
	m_parent = &(mainMenu->GetParent());	// set pointer to point at mainMenu's parent
	m_children = &(m_page->GetChildVec());	// set pointer to point at mainMenu's child vector containing all its children pages

	// add book
	Page* addBook = new Page(mainMenu, "Add Book");		// creating page object on the heap and assigning parent pointer to its member variable

	Page* setTitle = new Page(addBook, "Set Title");		// create page without assigning a parent to it

	Page* setAuthor = new Page(setTitle, "Set Author");

	Page* setYear = new Page(setAuthor, "Set Year");

	Page* setPrice = new Page(setYear, "Set Price");

	Page* setStock = new Page(setPrice, "Set Stock");

	// find book
	Page* findBook = new Page(mainMenu, "Search Book");

	Page* titleFind = new Page(findBook, "Search by Title");
	
	Page* authorFind = new Page(titleFind, "Search by Author");

	Page* yearFind = new Page(authorFind, "Search by Publication Year");

	Page* priceFind = new Page(yearFind, "Search by Price");

	Page* stockFind = new Page(priceFind, "Search by no. Items in Stock");

	addBook->SetChild(*setTitle);
	setTitle->SetChild(*setAuthor);
	setAuthor->SetChild(*setYear);

	findBook->SetChild(*titleFind);
	findBook->SetChild(*authorFind);
	findBook->SetChild(*yearFind);
	findBook->SetChild(*priceFind);
	findBook->SetChild(*stockFind);

	// sell book
	Page* sellBook = new Page(mainMenu, "Sell Book");
	sellBook->SetChild(*mainMenu);

	// edit book
	Page* editBook = new Page(mainMenu, "Edit Book");

	// mainMenu
	mainMenu->SetChild(*addBook);		// adding children pages to each page (vector member variable of each page/object)
	mainMenu->SetChild(*findBook);
	mainMenu->SetChild(*sellBook);
	mainMenu->SetChild(*editBook);
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
	cout << "\nParent: " << m_parent->GetPageName();	//--Hamid: m_page -> GetParent() -> GetPageName()
	cout << "\nPage: " << m_page->GetPageName();
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
	//	Hamid: You just need to update the m_page, then you can update its parent and child from m_page's methods

	m_page = &(m_page->GetChild(m_input));	// update page child pointer to point at selected child menu
	m_parent = &(m_page->GetParent());	// update parent pointer to point at the parent of current page
	m_children = &(m_page->GetChildVec());	// update child vector pointer to point at children pages of new parent
}

