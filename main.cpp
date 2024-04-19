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
class Book
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
    void SetDate(Date D){
        dateOfRelease=D;
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
    Book *books;
    int index;
    int z=0;
public:

    Library(int a){
        index=a;
        books =new Book[index];
    }

    void BookAdder(Book &book){
        books[z]=book;
        ++z;
    }
    string  CategoryFinder(string bookName){
        for (int i = 0; i < index; ++i) {
            if (books[i].GiveName()==bookName){
                return books[i].GiveCategory();
            }
        }
        return "not found";
    }
    ~Library(){}
};

//---------------------------------------------------------------------------------
int main() {
    int order;
    cin>>order;
    Library lib(order) ;
    Book B ;
    for (int i = 0; i < order; ++i) {
        string str;
        int num;

        getline(cin>>ws,str) ;
        str.erase(str.find_last_not_of(" \n\r\t")+1);
        B.SetName(str);

        getline(cin>>ws,str) ;
        str.erase(str.find_last_not_of(" \n\r\t")+1);
        B.SetAuthorName(str);

        cin>>num;
        cin>>str;
        Date *tempDate=new Date(num,str);
        B.SetDate(*tempDate);

        getline(cin>>ws,str);
        str.erase(str.find_last_not_of(" \n\r\t")+1);
        B.SetCategory(str);
        lib.BookAdder(B);
    }
    cin>>order;
    string arr[order];
    for (int i = 0; i < order; ++i) {
        string str;
        getline(cin>>ws,str);
        str.erase(str.find_last_not_of(" \n\r\t")+1);
        arr[i]=lib.CategoryFinder(str);
    }
    for (int i = 0; i < order; ++i) {
       cout<<arr[i]<<endl;
    }


    return 0;
}