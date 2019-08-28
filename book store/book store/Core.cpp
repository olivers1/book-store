#include "Core.h"
#include <iostream>

using namespace std;

void Core::Initialize()
{
	Page* mainMenu = new Page(nullptr, "Main Menu");
	m_page = mainMenu;		// set mainMenu as default page
	//m_parent = &(m_page->GetParent());	// update parent variable with parent of current page	MAYBE DOES NOT WORK BECAUSE OF NULLPTR
	m_children = &(m_parent->GetChildVec());	// set pointer to point at mainMenu's child vector containing all its children pages

	// add book
	Page* addBook = new Page(mainMenu, "Add Book");		// creating page object on the heap and assigning parent pointer to its member variable
	
	Page* setTitle = new Page("Set Title");		// create page without assigning a parent to it
	setTitle->SetParent(*addBook);	// set parent of the page

	Page* setAuthor = new Page("Set Author");
	setAuthor->SetParent(*setTitle);

	Page* setYear = new Page("Set Year");
	setYear->SetParent(*setAuthor);

	Page* setPrice = new Page("Set Price");
	setPrice->SetParent(*setYear);

	Page* setStock = new Page("Set Stock");
	setStock->SetParent(*setPrice);

	Page* displayBook = new Page("Display Book");
	displayBook->SetParent(*setStock);
	
	addBook->SetChild(*setTitle);	// add child to the page's child vector
	setTitle->SetChild(*setAuthor);
	setAuthor->SetChild(*setYear);
	setYear->SetChild(*setPrice);
	setPrice->SetChild(*displayBook);
	displayBook->SetChild(*mainMenu);

	// find book
	Page* findBook = new Page(mainMenu, "Search Book");
	Page* titleFind = new Page(findBook, "Search by Title");

	Page* authorFind = new Page(findBook, "Search by Author");

	Page* yearFind = new Page(findBook, "Search by Publication Year");

	Page* priceFind = new Page(findBook, "Search by Price");

	Page* stockFind = new Page(findBook, "Search by no. Items in Stock");

	findBook->SetChild(*titleFind);
	findBook->SetChild(*authorFind);
	findBook->SetChild(*yearFind);
	findBook->SetChild(*priceFind);
	findBook->SetChild(*stockFind);

	// sell book
	Page* sellBook = new Page(mainMenu, "Sell Book");

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
	cout << "\nPage: " << m_page->GetPageName();
	//cout << "\n (Parent: " << m_parent->GetPageName() << ")";
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
	m_page = &(m_page->GetChild(m_input));	// update page child pointer to point at selected child menu
	
	//m_parent = &(m_page->GetParent());		// update parent variable with parent of current page
	
	m_children = &(m_page->GetChildVec());	// update child vector pointer to point at children pages of new parent
}

