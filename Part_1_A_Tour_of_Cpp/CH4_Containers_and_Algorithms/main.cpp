#include <iostream>
#include <vector>

struct Entry
{
      std::string name;
      int number;
};

std::ostream& operator<<(std::ostream& os, const Entry& e)
{
   return os << "{\"" << e.name << "\", " << e.number << "}";
}

std::istream& operator>>(std::istream& is, Entry& e)
{
   char ch1, ch2;
   std::string msg;

   if(is >> ch1 && ch1 == '{' && is >> ch2 && ch2 == '"')
   {
      std::string name;
      while(is.get(ch1) && ch1 != '"')
      {
         name += ch1;
      }

      if(is>>ch1 && ch1 == ',')
      {
         int number = 0;
         if(is >> number >> ch1 && ch1 == '}')
         {
            e = {name, number};
            return is;
         }
      }
   }
   // is.setf(std::ios_base::failbit); // Didn't work for me, so I throw an error
   throw "Error";
}

void print_book(const std::vector<Entry>& book)
{
   for (const auto& x : book)
   {
      std::cout << x << '\n';
   }
}

void input_book(std::vector<Entry>& phone_book)
{
   for (Entry e; std::cin>>e;)
      phone_book.push_back(e);
}

template<typename T>
class Vector: std::vector<T>
{
   public:
      using std::vector<T>::vector;
      T& operator[](int i){ std::vector<T>::at(i); }
      const T& operator[](int i) const { std::cout << "const" << std::endl; std::vector<T>::at(i); }
};

int main()
{
   /*** 4.2 Strings ***/
   {
//      std::string name = "Niels Stroustrup";
//      std::string s = name.substr(6,10); // s = "Stroustrup"
//      name.replace(0,5,"nicholas"); // name becomes "nicholas Stroustrup"
//      name[0] = toupper(name[0]); // name becomes "Nicholas Stroustrup
   }

   /*** 4.3 Stream I/O ***/
   {
//      std::string name_1;
//      std::cout << "Enter a name: ";
//      std::cin >> name_1; // terminates with whitespace
//      std::cout << name_1 << "\n";

//      std::cin.ignore(); // ignoer whateve in cin

//      std::cout << "Please enter your name\n";
//      std::string str;
//      std::getline(std::cin,str);
//      std::cout << "Hello, " << str << "!\n";

//      Entry entry;
//      std::cin >> entry;
//      std::cout << entry << std::endl;
   }

   /*** 4.4 Containers ***/
   {
      std::vector<Entry> phone_book = {
         {"David Hume",123456},
         {"Karl Popper",234567},
         {"Bertrand Arthur William Russell",345678}
      };
      //phone_book.clear();
      //input_book(phone_book);
      //print_book(phone_book);
      Vector<Entry> v {
         {"David Hume",123456},
         {"Karl Popper",234567},
         {"Bertrand Arthur William Russell",345678}
      };
      std::cout << "First" << std::endl;
      v[0] = {"Jehad Alghamdi", 255566};
      std::cout << "Second" << std::endl;
      Vector<Entry> vv;
      vv[0] = v[2];
   }
}
