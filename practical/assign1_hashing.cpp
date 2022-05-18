#include <iostream>
#include<string>

using namespace std;

class node {
    string name;
    long int tel;
    int id;

public:
    node()
    {
        tel = 0;
        id = 0;
    }
    friend class hashing;
};


class hashing
{
    node data[100];
    string n;
    long int t;
    int i, index;

public:
    hashing()
    {
        i = 0;
        t = 0;
    }

     void create_record(int size)
    {

        cout<<"\nenter id";
        cin>>i;

        cout<<"\nenter name";
        cin>>n;

         cout<<"\nenter telephone number";
        cin>>t;


        index = i % size;


        for (int j = 0; j < size; j++)
        {
            if (data[index].id == 0)
            {
                data[index].id = i;
                data[index].name = n;
                data[index].tel = t;
                break;
            }
            else
                index = (index + 1) % size;
        }
    }

    void display_record(int size)
    {
        cout << "\n\tID \tNAME";
        cout << " \t\tTELEPHONE ";

        for (int a = 0; a < size; a++)
        {
            if (data[a].id != 0)
            {
                cout << "\n\t"<< data[a].id<< " \t"<< data[a].name << " \t"<< data[a].tel;
            }

        }
    }


     void search_record(int size)
    {
        int index1, key, flag = 0;

        cout << "\nEnter record id to search : ";
         cin>>key;

        index1 = key % size;


        for (int a = 0; a < size; a++)
        {
            if (data[index1].id == key)
            {
                flag = 1;
                cout << "\nRecord found:";
                cout << "\n\tID " << "\tNAME "<<"\t\tTELEPHONE ";
                cout << "\n\t"<< data[index1].id<< " \t"<< data[index1].name<< " \t"<< data[index1].tel;
                break;
            }
            else
                index1= (index1 + 1) % size;
        }
        if (flag == 0)
            cout << "\nRecord not found";
    }

void delete_record(int size)
    {
        int index1, key, flag = 0;

        cout << "\nEnter record id to delete : ";
            cin>>key;
        index1 = key % size;

        for (int a = 0; a < size; a++)
        {
            if (data[index1].id== key)
            {
                flag = 1;
                data[index1].id = 0;
                data[index1].name = " ";
                data[index1].tel = 0;
                cout << "\nRecord deleted successfully";
                   break;
            }
            else
                index1= (index1 + 1) % size;
        }
        if (flag == 0)
            cout << "\nRecord not found";
    }




};



int main()
{

    int size,ch;
    hashing s;
    size = 20;
  do{
  cout<<"\n1.create\n\n2.display\n3.search \n4.delete\n5.exit ";
  cout<<"\nenter your choice";
  cin>>ch;
  switch( ch)
  {

    case 1:
        cout << "\n1.CREATE record ";
        s.create_record(size);
        break;

    case 2:
        cout << "\n\n\n\n2.DISPLAY record";
        cout << " record ";
        s.display_record(size);
    break;



    case 3:
        cout<<"\nSearch record";
        s.search_record(size);
        break;



    case 4:
        cout<<"\ndelete record";
        s.delete_record(size);
        break;


    case 5:
        exit(0);
  }
  }while(ch!=5);


    return 0;
}