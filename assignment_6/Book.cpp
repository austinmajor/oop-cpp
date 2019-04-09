/*
* Program: (Textbook Cha9 Q9) Create a Library class.
* Author: Austin Major
* Class: CS311
* Date: 4/9/19
*/

#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <stdexcept>
#include "Book.h"

// default constructor /////////////////////////////////////////////////////////
Book::Book()
    : isbn13("###"), title("***"), author_fname("***"), author_lname("***"),
      genre(unknown), is_checkedin(false)
{
  std::cout << "DEBUG: Book::Book()\n";
}

// member function definitions /////////////////////////////////////////////////

// non-modifying operations ////////////////////////////////////////////////////
/**
 * Display state of book
 */
void Book::print()
{
  cout << "DEBUG: Book::print()\n";
  cout << "Title:\t\t" << get_title() << endl
       << "Author:\t\t" << get_author() << endl
       << "Genre:\t\t" << genre_tostring() << endl
       << "ISBN:\t\t" << get_isbn() << endl
       << "Checked in:\t" << (is_bookin() ? "Yes" : "No") << endl;
  return;
}

// modifying operations ///////////////////////////////////////////////////////

// use to initialise all class parameters
// return true if set parameters correctly
void Book::Init(std::string isbn, std::string title,
                std::string fn, std::string ln,
                Genre g, Book_status s)
{
  cout << "DEBUG: Book::Init()\n";
  set_isbn(isbn);
  set_title(title);
  set_author(fn, ln);
  set_genre(g);
  if (s == in)
    checkin();
  else
    checkout();
}

/**
 * read input data and set isbn number for book
 */
void Book::read_isbn()
{
  cout << "DEBUG: Book::read_isbn()\n";
  bool is_isbn = false; // true when isbn is valid
  std::string str_in;		// input from user

  while (is_isbn == false)
  {
    cout << "Enter ISBN for book: ";
    getline(cin, str_in);
    if (set_isbn(str_in))
    {
      ;
      is_isbn = true;
    }
    else
      cout << "Please try again.\n";
  }
}

// set isbn number, checking that n is 13 characters long
bool Book::set_isbn(std::string n)
{
  cout << "DEBUG: Book::set_isbn()\n";
  if (n.size() == isbn13_length)
  {
    isbn13 = n;
    return true;
  }
  else
    cout << "ERROR: isbn must be " << isbn13_length << " digits.\n";

  return false;
}

/**
 * read input data and set title for book
 */
void Book::read_title()
{
  cout << "DEBUG: Book::read_title()\n";
  std::string str_in; // input from user

  cout << "Enter book's title: ";
  getline(cin, str_in);
  title = str_in;
}

/**
 * read input data and set author for book
 */
void Book::read_author()
{
  cout << "DEBUG: Book::read_author()\n";
  std::string str_in, first, last; // input from user

  cout << "Enter author's first and last names: ";
  // using getline is good: it doesn't leave unused keystrokes
  // in a buffer to mess up the next input function
  getline(cin, str_in);
  set_author(first, last);
}

// set author name
void Book::set_author(std::string fname, std::string lname)
{
  cout << "DEBUG: Book::set_author()\n";
  author_fname = fname;
  author_lname = lname;
}

/**
 * read input data and set genre for book
 */
void Book::read_genre()
{
  cout << "DEBUG: Book::read_genre()\n";
  std::string str_in;		 // input from user
  bool is_genre = false; // true if user enters a valid genre
  while (is_genre == false)
  {
    cout << "0.\tFiction\n"
         << "1.\tNonfiction\n"
         << "2.\tPeriodical\n"
         << "3.\tBiography\n"
         << "4.\tChildren\n"
         << "5.\tUnkown\n";
    cout << "Select number coresponding to genre:\n";
    getline(cin, str_in);
    switch (atoi(str_in.c_str()))
    {
    case fiction:
      set_genre(fiction);
      is_genre = true;
      break;
    case nonfiction:
      set_genre(nonfiction);
      is_genre = true;
      break;
    case periodical:
      set_genre(periodical);
      is_genre = true;
      break;
    case biography:
      set_genre(biography);
      is_genre = true;
      break;
    case children:
      set_genre(children);
      is_genre = true;
      break;
    case unknown:
      set_genre(unknown);
      is_genre = true;
      break;
    default:
      cout << "Error: Not a valid genre.\n";
    }
  }
  return;
}

/**
 * return the genre of the book as a string
 */
std::string Book::genre_tostring() const
{
  //cout << "DEBUG: Book::genre_tostring()\n";
  std::string genre_str;

  switch (get_genre())
  {
  case fiction:
    genre_str = "Fiction";
    break;
  case nonfiction:
    genre_str = "Nonfiction";
    break;
  case periodical:
    genre_str = "Periodical";
    break;
  case biography:
    genre_str = "Biography";
    break;
  case children:
    genre_str = "Children";
    break;
  case unknown:
    genre_str = "Unknown";
    break;
  default:
    cout << "Error: Not a valid genre\n";
    genre_str = "invalid genre";
  }
  return genre_str;
}

// logic operators
bool operator==(const Book &a, const Book &b)
{
  return a.get_isbn() == b.get_isbn();
}

bool operator!=(const Book &a, const Book &b)
{
  return !(a == b);
}

// insertion operator prints out Book details on separate lines
std::ostream &operator<<(std::ostream &os, const Book &book)
{
  cout << "Book Information --\n"
       << "Title:\t\t" << book.get_title() << endl
       << "Author:\t\t" << book.get_author() << endl
       << "Genre:\t\t" << book.genre_tostring() << endl
       << "ISBN:\t\t" << book.get_isbn() << endl
       << "Checked in:\t" << (book.is_bookin() ? "Yes" : "No") << endl;
  return os;
}

// check book out of a collection
void Book::checkout()
{
  cout << "DEBUG: Book::checkout()\n";
  is_checkedin = false;
}

// check book into a collection
void Book::checkin()
{
  cout << "DEBUG: Book::checkin()\n";
  is_checkedin = true;
}
