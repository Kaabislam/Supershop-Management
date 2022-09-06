#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
template<class t1,class t2,class t3>
class Date
{
      t1 day;
      t2 month;
      t3 year;
      public:
          Date(){}
             Date(t1 d,t2 m,t3 y)
             {
                   day=d;
                   month=m;
                   year=y;
             }
             void display()
             {
                  cout<<"\nDate:"<<day<<"-"<<month<<"-"<<year<<endl;
             }
};

class product
{
    int pno;
    char name[50];
    float price, qty, tax, dis;

    public:
        int retpno()
        {
            return pno;
        }
        float retprice()
        {
            return price;
        }

        char * retname()
        {
            return name;
        }

        int retdis()
        {
            return dis;
        }

        void create_product()
            {
                cout << "\nPlease Enter The Product No. of The Product : ";
                cin >> pno;
                cout << "\nPlease Enter The Name of The Product : ";
                cin >> name;
                cout << "\nPlease Enter The Price of The Product : ";
                cin >> price;
                cout << "\nPlease Enter The Discount (%) : ";
                cin >> dis;
            }
        void show_product()
        {
            cout << "\nThe Product No. of The Product : " << pno;
            cout << "\nThe Name of The Product : ";
            puts(name);
            cout << "\nThe Price of The Product : " << price;
            cout << "\nDiscount : " << dis;
        }
        friend void display_all();

};
product pr;
class admin;
class customer
{
    int cno;
    char name[50];
public:

    void create_customer()
            {
                cout << "\nPlease Enter The Name of The Customer : ";
                cin >> name;
                cout << "\nPlease Enter The Id of The Customer : ";
                cin >> cno;

            }
    void show_customer()
    {
        cout << " Customer Name : ";
        puts(name);
        cout << "Unique ID No : " << cno;
    }
    int retcno()
    {
        return cno;
    }
    friend class product;
    friend void display_all();
    virtual void login()
    {
        cout << "enter as a customer" << endl;
        cout << "Products Are Shown Below " << endl;
        display_all();
    }

    void display_all()
    {

    fstream fp;
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    fp.open("Shop.txt", ios:: in );
    while (fp.read((char * ) & pr, sizeof(product)))
    {
        pr.show_product();
        cout << "\n\n====================================\n";

    }
    fp.close();

}

};
customer cr;
class admin:public product,public customer
{
        string u,uname = "kuet";
        int p,pass = 123,rin,i=0;
public:

void admin_input()
{

        cout << "enter username : ";
        cin >> u;
        cout << "enter password : ";
        cin >> p;
}
void login()
    {
        admin_input();
        if(u == uname && p == pass)
        {
                cout << "Login Successful!" << endl;
                main_menu();

        }
        else
        {
            i += 1;
            if(i==3)
            {
                cout << "you failed 3 times in a row!" << endl;

            }
            else
            {
                cout << "1 - Retry for login " << endl;
                cout << "2-Quit!" << endl;

                cin >> rin;
                if(rin==1)
                {

                    login();
                }
            }
        }

    }
void main_menu()
{
                cout << "\n\n====================================\n";
                int dec,a,x,n;
                cout << "What You wants To Do ?" << endl;
                cout << "1.For product " << endl;
                cout << "2.For Customer " << endl;
                cout << "3.For Bill Prepare"<<endl;
                cin >> a;
                if(a==1)
                {
                    cout << "1 : Write product " << endl;
                    cout << "2 : Delete product " << endl;
                    cout << "3 : Search and show product description " << endl;
                    cout << "4 : Show All product " << endl;
                    cin >> dec;
                    if(dec == 1)
                    {
                        write_product();
                        cout << endl << "Press 1 For Back To Main Menu"<< endl;
                        cin >> n;
                        if(n==1)
                        {
                            main_menu();
                        }

                    }
                    if(dec == 2)
                    {
                        delete_product();
                        cout << endl << "Press 1 For Back To Main Menu"<< endl;
                        cin >> n;
                        if(n==1)
                        {
                            main_menu();
                        }
                    }
                    if(dec == 3)
                    {

                        display_sp();
                        cout << endl << "Press 1 For Back To Main Menu"<< endl;
                        cin >> n;
                        if(n==1)
                        {
                            main_menu();
                        }
                    }
                    else if(dec == 4)
                    {
                        display_all();
                        cout << endl << "Press 1 For Back To Main Menu"<< endl;
                        cin >> n;
                        if(n==1)
                        {
                            main_menu();
                        }
                    }

                }
                else if(a==2)
                {
                    cout << "1.For Add New Customer"<<endl;
                    cout << "2.Delete a Customer "<< endl;
                    cout << "3.Display All customer" << endl;

                    cin >> x;
                    if(x==1)
                    {
                        write_customer();
                        cout << endl << "Press 1 For Back To Main Menu"<< endl;
                        cin >> n;
                        if(n==1)
                        {
                            main_menu();
                        }
                    }
                    else if(x == 2)
                    {
                        delete_customer();
                        cout << "New List of Customers !" << endl;
                        display_clist();
                        cout << endl << "Press 1 For Back To Main Menu"<< endl;
                        cin >> n;
                        if(n==1)
                        {
                            main_menu();
                        }
                    }
                    else if(x==3)
                    {
                        display_clist();
                        cout << endl << "Press 1 For Back To Main Menu"<< endl;
                        cin >> n;
                        if(n==1)
                        {
                            main_menu();
                        }
                    }

                }
                 else if(a==3)
                    {
                        place_order();
                    }
}


fstream fp;
void write_product()
{
    fp.open("Shop.txt", ios::out | ios::app);
    pr.create_product();
    fp.write((char * ) & pr, sizeof(product));
    fp.close();
    cout << "\n\nThe Product Has Been Created ";
    getch();
}
void write_customer()
{
    fp.open("customer.txt", ios::out | ios::app);
    cr.create_customer();
    fp.write((char * ) & cr, sizeof(customer));
    fp.close();
    cout << "\n\nThe Customer Has Been Listed ";
    getch();
}
void delete_customer()
{
    int no;
    system("cls");
    cout << "\n\n\n\tDelete Record";
    cout << "\n\nPlease Enter The id no. of The customer You Want To Delete";
    cin >> no;
    fp.open("customer.txt", ios:: in | ios::out);
    fstream fp2;
    fp2.open("Tempcustomer.txt", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char * ) & cr, sizeof(customer)))
    {
        if (cr.retcno() != no)
        {
            fp2.write((char * ) & cr, sizeof(product));
        }
    }
    fp2.close();
    fp.close();
    remove("customer.txt");
    rename("Tempcustomer.txt", "customer.txt");
    cout << "\n\n\tRecord Deleted ..";
    getch();
}


void display_clist()
    {

    cout << "\n\n\n\t\tDISPLAY ALL Customer RECORD  !!!\n\n";
    fp.open("customer.txt", ios:: in );
    while (fp.read((char * ) & cr, sizeof(customer)))
    {
        cr.show_customer();
        cout << "\n\n====================================\n";

    }
     fp.close();

}

void display_sp()
{

    int n,flag = 0;
    cout << "enter product no : ";
    cin >> n;
    fp.open("Shop.txt", ios:: in );
    while (fp.read((char * ) & pr, sizeof(product)))
    {
        if (pr.retpno() == n)
        {
            system("cls");
            pr.show_product();
            flag = 1;
        }
    }
    fp.close();
    if (flag == 0)
        cout << "\n\nrecord not exist";
    getch();
}
void delete_product()
{
    int no;
    system("cls");
    cout << "\n\n\n\tDelete Record";
    cout << "\n\nPlease Enter The product no. of The Product You Want To Delete";
    cin >> no;
    fp.open("Shop.txt", ios:: in | ios::out);
    fstream fp2;
    fp2.open("Temp.txt", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char * ) & pr, sizeof(product)))
    {
        if (pr.retpno() != no)
        {
            fp2.write((char * ) & pr, sizeof(product));
        }
    }
    fp2.close();
    fp.close();
    remove("Shop.txt");
    rename("Temp.txt", "Shop.txt");
    cout << "\n\n\tRecord Deleted ..";
    getch();
}
void menu()
{

    fp.open("Shop.txt", ios:: in );
    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File ";
        cout << "\n\n\n Program is closing ....";
        getch();
        exit(0);
    }

    cout << "\n\n\t\tProduct MENU\n\n";
    cout << "====================================================\n";
    cout << "P.NO.\t\tNAME\t\tPRICE\n";
    cout << "====================================================\n";

    while (fp.read((char * ) & pr, sizeof(product)))
    {
        cout << pr.retpno() << "\t\t" << pr.retname() << "\t\t" << pr.retprice() << endl;
    }
    fp.close();
}

void place_order()
{
    int order_arr[50], quan[50], c = 0;
    float amt, damt, total = 0;
    char ch = 'Y';
    menu();
    cout << "\n============================";
    cout << "\n PLACE YOUR ORDER";
    cout << "\n============================\n";
    do
    {
        cout << "\n\nEnter The Product No. Of The Product : ";
        cin >> order_arr[c];
        cout << "\nQuantity in number : ";
        cin >> quan[c];
        c++;
        cout << "\nDo You Want To Order Another Product ? (y/n)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\nThank You For Placing The Order";
    getch();
    //clrscr();
    cout << "\n\n******************************** INVOICE ************************\n";
    cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\ n ";
    for (int x = 0; x <= c; x++)
    {
        fp.open("Shop.txt", ios:: in );
        fp.read((char * ) & pr, sizeof(product));
        while (!fp.eof())
        {
            if (pr.retpno() == order_arr[x])
            {
                amt = pr.retprice() * quan[x];
                damt = amt - (amt * pr.retdis() / 100);
                cout << "\n" << order_arr[x] << "\t" << pr.retname() <<
                    "\t" << quan[x] << "\t\t" << pr.retprice() << "\t" << amt << "\t\t" << damt;
                total += damt;
            }
            fp.read((char * ) & pr, sizeof(product));
        }

        fp.close();
    }
    cout << "\n\n\t\t\t\t\tTOTAL = " << total;
    getch();
}

void call()
{
    int order_arr[50], quan[50], c = 0;
    float amt, damt, total;
    char ch = 'Y';
    do
    {
        cout << "\n\nEnter The Product No. Of The Product : ";
        cin >> order_arr[c];
        cout << "\nQuantity in number : ";
        cin >> quan[c];
        c++;
        cout << "\nDo You Want To Order Another Product ? (y/n)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\nThank You For Placing The Order";
    getch();

    cout << "\n\n******************************** INVOICE ************************\n";
    cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\ n ";
    for (int x = 0; x <= c; x++)
    {
        fp.open("Shop.dat", ios:: in );
        fp.read((char * ) & pr, sizeof(product));
        while (!fp.eof())
        {
            if (pr.retpno() == order_arr[x])
            {
                amt = pr.retprice() * quan[x];
                damt = amt - (amt * pr.retdis() / 100);
                cout << "\n" << order_arr[x] << "\t" << pr.retname() <<
                    "\t" << quan[x] << "\t\t" << pr.retprice() << "\t" << amt << "\t\t" << damt;
                total += damt;
            }
            fp.read((char * ) & pr, sizeof(product));
        }

        fp.close();
    }
}
};



int main()
{
    int dd,yy;
    string mm;
    cout<<"Enter Date,Month,Year sequentially:";
    cin>>dd;
    cin>>mm;
    cin>>yy;
    Date<int,string,int>d1(dd,mm,yy);
    d1.display();


    cout << "\n\nHow you wants to enter ? " << endl;
    cout << "1.As a customer " << endl;
    cout << "2.As Admin"<< endl;
    int x;
    cin >> x;
    admin ar,*aptr;
    aptr = &ar;
    customer *cptr;
    cptr = &cr;


    if(x==1)
    {
        cptr -> login();
    }
    else if(x == 2)
    {
        cptr = &ar;
        cptr->login();
    }

}







