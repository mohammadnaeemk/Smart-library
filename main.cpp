#include <iostream>
#include <string>

using namespace std;
//---------------------------------------------------------------------------------
class Date{
  int year;
  string month;

public:
   Date(int number=0 , string str=""){
      year=number;
      month=str;
  }
~Date(){}
};
//---------------------------------------------------------------------------------
class Book:public Date
{
private:
    string name;
    string authorName;
    string category;
public:
    Date dateOfRelease;
     Book(string N="",string A="",string C="")
     {
         name=N;
         authorName=A;
         category=C;
     }
    void SetName(string Name){
        name=Name;
    }
    void SetAuthorName(string AName){
        authorName=AName;
    }
    void SetCategory(string CY){
        category=CY;
    }

     string GiveName()
     {
         return name;
     }
    string GiveCategory()
    {
        return category;
    }


    ~Book(){}
};
//---------------------------------------------------------------------------------
class Library{
private:
    int size;
    Book *books;

public:
    Library(int a=0){
        size=0;
        books=new Book[size];
    }
    void BookAdder(Book book){
        ++size;
     Book *temp = new Book[size];
        for (int i = 0; i < size-1; ++i) {
            temp[i]=books[i];
        }
        temp[size]=book;

        delete books;
        books=new Book[size];

        for (int i = 0; i < size; ++i) {
            books[i]=temp[i];
        }
    }
    string  CategoryFinder(string bookName){
        bool flag= false;
        for (int i = 0; i < size; ++i) {
            if (books[i].GiveName()==bookName){
                books[i].GiveCategory();
                flag= true;
                break;
            }
        }
        if (flag= false){
            return "not found";
        }
    }
    ~Library(){}
};
//---------------------------------------------------------------------------------
int main() {

    return 0;
}
