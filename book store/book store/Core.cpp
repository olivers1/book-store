#include "Core.h"
#include <iostream>

using namespace std;

void Core::Initialize()
{
	Page* dummyPage = new Page("dummyPage", nullptr);	// dummy page to avoid error when parent pointer is pointing to 'nullptr'
	Page* mainMenu = new Page("Main Menu", dummyPage);

	dummyPage->SetChild(*mainMenu);

	m_page = mainMenu;		// set mainMenu as default page

	Page* addBook = new Page("Add Book", mainMenu);
	Page* setTitle = new Page("Add Book", addBook);
	Page* setAuthor = new Page("Set Author", setTitle);
	Page* setYear = new Page("Set Year", setAuthor);
	Page* setPrice = new Page("Set Price", setYear);
	Page* setStock = new Page("Set Stock", setPrice);

	mainMenu->SetChild(*addBook);
	addBook->SetChild(*setTitle);
	setTitle->SetChild(*setYear);
	setYear->SetChild(*setPrice);
	setPrice->SetChild(*setStock);
	setStock->SetChild(*mainMenu);

	//// add book
	//Page* addBook = new Page(mainMenu, "Add Book");		// creating page object on the heap and assigning parent pointer to its member variable

	//Page* setTitle = new Page(addBook, "Set Title");		// create page without assigning a parent to it

	//Page* setAuthor = new Page(setTitle, "Set Author");

	//Page* setYear = new Page(setAuthor, "Set Year");

	//Page* setPrice = new Page(setYear, "Set Price");

	//Page* setStock = new Page(setPrice, "Set Stock");

	//// find book
	//Page* findBook = new Page(mainMenu, "Search Book");

	//Page* titleFind = new Page(findBook, "Search by Title");
	//
	//Page* authorFind = new Page(titleFind, "Search by Author");

	//Page* yearFind = new Page(authorFind, "Search by Publication Year");

	//Page* priceFind = new Page(yearFind, "Search by Price");

	//Page* stockFind = new Page(priceFind, "Search by no. Items in Stock");

	//addBook->SetChild(*setTitle);
	//setTitle->SetChild(*setAuthor);
	//setAuthor->SetChild(*setYear);

	//findBook->SetChild(*titleFind);
	//findBook->SetChild(*authorFind);
	//findBook->SetChild(*yearFind);
	//findBook->SetChild(*priceFind);
	//findBook->SetChild(*stockFind);

	//// sell book
	//Page* sellBook = new Page(mainMenu, "Sell Book");
	//sellBook->SetChild(*mainMenu);

	//// edit book
	//Page* editBook = new Page(mainMenu, "Edit Book");

	//// mainMenu
	//mainMenu->SetChild(*addBook);		// adding children pages to each page (vector member variable of each page/object)
	//mainMenu->SetChild(*findBook);
	//mainMenu->SetChild(*sellBook);
	//mainMenu->SetChild(*editBook);
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
	cout << "\nParents: ";
	for (Page parent : m_page->GetParentVec())
	{
		cout << parent.GetPageName() << ", ";
	}
	cout << "\nPage: " << m_page->GetPageName();
	cout << "\nChildren: ";
	for (Page child : m_page->GetChildVec())
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
	m_page = &(m_page->GetChild(m_input));	// update page child pointer to point at selected child menu
}

