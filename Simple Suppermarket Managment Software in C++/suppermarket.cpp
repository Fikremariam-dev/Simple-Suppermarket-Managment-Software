#include<iostream>
using namespace std;
#include<cstdlib>
#include<string>
#include<fstream>
#include<iomanip>
int gt[1000];
void additem()
{
    system("cls");
    fstream x;
    string tt;
    x.open("item file.txt",ios::out | ios::app);
    cout<<"Enter the name of the item\n";
    cin>>tt;
    x<<tt<<"\n";
    cout<<"Enter the ID of the item\n";
    cin>>tt;
    x<<tt<<"\n";
    cout<<"Enter location of the item\n";
    cin>>tt;
    x<<tt<<"\n";
    cout<<"Enter the unit price\n";
    cin>>tt;
    x<<tt<<"\n";
    cout<<"enter the available quantity\n";
    cin>>tt;
    x<<tt<<"\n";
    cout<<"enter discount percentage\n";
    cin>>tt;
   x<<tt<<"\n";
    x.close();
    system("cls");
}
void displayitem()
{
    system("cls");
    int c=1,d=0;
    ifstream x("item file.txt");
    string line;
    if(x.is_open())
    {
        while ( getline (x,line) )
        {
            for(int d=0;gt[d]!=0;d++){
            if(c==gt[d])
                cout<<"Name               : "<<line<<"\n";
            if(c==gt[d]+1)
                cout<<"Item ID            : "<<line<<"\n";
            if(c==gt[d]+2)
                cout<<"Item location      : "<<line<<"\n";
            if(c==gt[d]+3)
                cout<<"unit price         : "<<line<<"\n";
            if(c==gt[d]+4)
                cout<<"Available quantity : "<<line<<"\n";
            if(c==gt[d]+5)
                cout<<"Discount           : "<<line<<"\n\n\n";
            }
            c++;
        }
        x.close();

    }
    cout<<"\n\n\n\n";
    system("pause");
}
void searchitem()
{
    system("cls");
    int q,z=1,qq,i=0;
    ifstream x("item file.txt");
    string line,a;
    do
    {
        cout<<"1. By Name\n";
        cout<<"2. By Item ID\n";
        cout<<"3. By Location\n";
        cin>>q;
        if(q<1||q>3)
        {
            system("cls");
            cout<<"     choose from 1 to 3 only!"<<endl;
        }
    }while(q<1||q>3);
    system("cls");
    if (q==1)
        cout<<"Enter the name of the item\n";
    else if(q==2)
        cout<<"Enter the Item Id\n";
    else
        cout<<"Enter the location of the item\n";
    cin>>a;
    qq=q;
    gt[0]='n';
    if(x.is_open())
    {
       while ( getline (x,line) )
    {
        if(qq==z)
        {
            if(line==a)
            {
                gt[i]=z;
                i++;
                gt[i]=0;
            }
            qq=qq+6;
        }
            z++;
    }
        x.close();
    }
    else
        cout<<" No items have been added yet"<<endl;
    q--;
    int d=0;
    while(gt[d]!=0)
    {
        gt[d]=gt[d]-q;
        d++;
    }
    if (gt[0]==0)
    {
        cout<<"\n\n The data you entered dose not exist!"<<endl;
        system("pause");
        return;
    }
    else
        displayitem();
}

void edititem()
{
    fstream x;
    cout<<"enter the name of the item you would like to edit"<<endl;

}
void item()
{
    system("cls");
    int x;
    do
    {
        do
        {
            cout<<"1. Add New Item\n";
            cout<<"2. Search\n";
            cout<<"3. Edit\n";
            cout<<"4. Back To Main Switch Board\n";
            cout<<"5. Exit\n";
            cin>>x;
            if(x<1||x>5)
            cout<<"     choose from 1 to 5 only!"<<endl;
        }   while(x<1||x>5);
        if (x==1)
        {
            additem();
            system("cls");
        }
        else if (x==2)
        {
            searchitem();
            system("cls");
        }
        else if (x==3)
        {
            edititem();
            system("cls");
        }
        else if (x==4)
        {
            return ;
        }
        else
            exit(0);
    }while(x!=5);
}
void addpurchase()
{
    system("cls");
    fstream y;
    string uu;
    y.open("purchase(in).txt",ios::out | ios::app);
    cout<<"Enter the purchaseID\n";
    cin>>uu;
    y<<uu<<"\n";
    cout<<"Enter the InvoiceNo\n";
    cin>>uu;
    y<<uu<<"\n";
    cout<<"Enter the Item ID\n";
    cin>>uu;
    y<<uu<<"\n";
    cout<<"Enter the purchase date\n";
    cin>>uu;
    y<<uu<<"\n";
    cout<<"Enter quantity\n";
    cin>>uu;
    y<<uu<<"\n";
    cout<<"Enter unit price\n";
    cin>>uu;
    y<<uu<<"\n";
    y.close();
}
void displaypurchase()
{
    system("cls");
    int c=1,d=0;
    ifstream x("purchase(in).txt");
    string line;
    if(x.is_open())
    {
        while ( getline (x,line) )
        {
            for(int d=0;gt[d]!=0;d++){
            if(c==gt[d])
                cout<<"purchase Id          : "<<line<<"\n";
            if(c==gt[d]+1)
                cout<<"InvoiceNo            : "<<line<<"\n";
            if(c==gt[d]+2)
                cout<<"Item ID              : "<<line<<"\n";
            if(c==gt[d]+3)
                cout<<"Date                 : "<<line<<"\n";
            if(c==gt[d]+4)
                cout<<"quantity             : "<<line<<"\n";
            if(c==gt[d]+5)
                cout<<"Unit price           : "<<line<<"\n";
            }
            c++;
        }
        x.close();

    }
    cout<<"\n\n\n\n";
    system("pause");
}
void searchpurchase(string id="null",string date="null")
{
    int q,i=0,z=1,qq;
    ifstream w("purchase(in).txt",ios::in);
    string line,a;
    if(id=="null"&&date=="null"){
    do
    {
        cout<<"1. By purchase ID\n";
        cout<<"2. By InvoiceNo\n";
        cout<<"3. By Item Id\n";
        cout<<"4. By date\n";
        cin>>q;
        if(q<1||q>4)
        {
            system("cls");
            cout<<"     choose from 1 to 4 only!"<<endl;
        }
    }while(q<1||q>4);
    system("cls");
    if (q==1)
        cout<<"Enter the purchase ID\n";
    else if(q==2)
        cout<<"Enter the InvoiceNo\n";
    else if(q==3)
        cout<<"Enter the Item Id\n";
    else
        cout<<"Enter the sale date\n";
    cin>>a;
    }
    if(id!="null"&&date=="null")
    {
        a=id;
        q=3;
    }
    if(id=="null"&&date!="null")
    {
        a=date;
        q=4;
    }
    qq=q;
    gt[0]=0;
    if(w.is_open())
    {
       while ( getline (w,line) )
    {
        if(qq==z)
        {
            if(line==a)
            {
                gt[i]=z;
                i++;
                gt[i]=0;
            }
            qq=qq+6;
        }
            z++;
    }
    }
    q--;
    int d=0;
    while(gt[d]!=0)
    {
        gt[d]=gt[d]-q;
        d++;
    }
    if(gt[0]==0)
    {
        cout<<"\n\n The data you entered dose not exist!"<<endl;
        system("pause");
        return;
    }
    else
        displaypurchase();
cout<<"\n\n\n\n";
    system("pause");
}
void editpurchase()
{
    ;
}
void purchase()
{
    system("cls");
    int x;
    do
    {
        do
        {
            cout<<"1. New purchase\n";
            cout<<"2. Search\n";
            cout<<"3. Edit\n";
            cout<<"4. Back To Main Switch Board\n";
            cout<<"5. Exit\n";
            cin>>x;
            if(x<1||x>5)
            cout<<"     choose from 1 to 5 only!"<<endl;
        }   while(x<1||x>5);
        if (x==1)
        {
            addpurchase();
            system("cls");
        }
        else if (x==2)
        {
            searchpurchase();
            system("cls");
        }
        else if (x==3)
        {
            editpurchase();
            system("cls");
        }
        else if (x==4)
        {
            return ;
        }
        else
            exit(0);
    }while(x!=5);
}
void addsale()
{
    system("cls");
    fstream w;
    string v;
    w.open("sale(out).txt",ios::out | ios::app);
    cout<<"Enter Sale ID\n";
    cin>>v;
    w<<v<<"\n";
    cout<<"Enter InvoiceNo\n";
    cin>>v;
    w<<v<<"\n";
    cout<<"Enter Item ID\n";
    cin>>v;
    w<<v<<"\n";
    cout<<"Enter the date\n";
    cin>>v;
    w<<v<<"\n";
    cout<<"Enter the quantity\n";
    cin>>v;
    w<<v<<"\n";
    cout<<"Enter the unit price\n";
    cin>>v;
    w<<v<<"\n";
    cout<<"Enter the discount percentage\n";
    cin>>v;
    w<<v<<"\n";
    w.close();
    system("cls");
}
void displaysale()
{
    system("cls");
    int c=1,d=0;
    ifstream x("sale(out).txt");
    string line;
    if(x.is_open())
    {
        while ( getline (x,line) )
        {
            for(int d=0;gt[d]!=0;d++){
            if(c==gt[d])
                cout<<"sale Id              : "<<line<<"\n";
            if(c==gt[d]+1)
                cout<<"InvoiceNo            : "<<line<<"\n";
            if(c==gt[d]+2)
                cout<<"Item ID              : "<<line<<"\n";
            if(c==gt[d]+3)
                cout<<"Date                 : "<<line<<"\n";
            if(c==gt[d]+4)
                cout<<"quantity             : "<<line<<"\n";
            if(c==gt[d]+5)
                cout<<"Unit price           : "<<line<<"\n";
            if(c==gt[d]+6)
                cout<<"Discount percentage  : "<<line<<"\n\n\n";
            }
            c++;
        }
        x.close();

    }
    cout<<"\n\n\n\n";
    system("pause");
}
void searchsale(string id="null",string date="null")
{
    int q,i=0,z=1,qq;
    ifstream w("sale(out).txt",ios::in);
    string line,a;
    if(id=="null"&&date=="null"){
    do
    {
        cout<<"1. By sale ID\n";
        cout<<"2. By InvoiceNo\n";
        cout<<"3. By Item Id\n";
        cout<<"4. By date\n";
        cin>>q;
        if(q<1||q>4)
        {
            system("cls");
            cout<<"     choose from 1 to 4 only!"<<endl;
        }
    }while(q<1||q>4);
    system("cls");
    if (q==1)
        cout<<"Enter the sale ID\n";
    else if(q==2)
        cout<<"Enter the InvoiceNo\n";
    else if(q==3)
        cout<<"Enter the Item Id\n";
    else
        cout<<"Enter the sale date\n";
    cin>>a;
    }
    if(id!="null"&&date=="null")
    {
        a=id;
        q=3;
    }
    if(id=="null"&&date!="null")
    {
        a=date;
        q=4;
    }
    qq=q;
    gt[0]=0;
    if(w.is_open())
    {
       while ( getline (w,line) )
    {
        if(qq==z)
        {
            if(line==a)
            {
                gt[i]=z;
                i++;
                gt[i]=0;
            }
            qq=qq+7;
        }
            z++;
    }
    q--;
    int d=0;
    while(gt[d]!=0)
    {
        gt[d]=gt[d]-q;
        d++;
    }
    if(gt[0]==0)
    {
        cout<<"\n\n The data you entered dose not exist!"<<endl;
        system("pause");
        return;
    }
    else
        displaysale();
cout<<"\n\n\n\n";
    system("pause");
}
}
void editsale()
{
    ;
}
void sale()
{
    system("cls");
    int x;
    do
    {
        do
        {
            cout<<"1. New sale\n";
            cout<<"2. Search\n";
            cout<<"3. Edit\n";
            cout<<"4. Back To Main Switch Board\n";
            cout<<"5. Exit\n";
            cin>>x;
            if(x<1||x>5)
            cout<<"     choose from 1 to 5 only!"<<endl;
        }   while(x<1||x>5);
        if (x==1)
        {
            addsale();
            system("cls");
        }
        else if (x==2)
        {
            searchsale();
            system("cls");
        }
        else if (x==3)
        {
            editsale();
            system("cls");
        }
        else if (x==4)
        {
            return ;
        }
        else
            exit(0);
    }while(x!=5);
}
void iteminventory()
{
    ifstream x("item file.txt");
    string line;
    int z=1;
    if(x.is_open())
    {
        while(getline(x,line))
        {
            if(z==1){
                cout<<"Name               : "<<line<<"\n";
                z=2;
                }
            else if(z==2){
                cout<<"Item ID            : "<<line<<"\n";
                z=3;
                }
            else if(z==3){
                cout<<"Item location      : "<<line<<"\n";
                z=4;
                }
            else if(z==4){
                cout<<"unit price         : "<<line<<"\n";
                z=5;
                }
            else if(z==5){
                cout<<"Available quantity : "<<line<<"\n";
                z=6;
                }
            else{
                cout<<"Discount           : "<<line<<"\n\n\n";
                z=1;
                }
        }
        x.close();
    }
    else
        cout<<"no item in the inventory\n\n\n\n";
    system("pause");
}
void Rsearch(string id,string date,int c)
{
    system("cls");
    int z=1,x=0,i=0;
    ifstream s("sale(out).txt");
    ifstream p("purchase(in).txt");
    string line;
    gt[0]=0;
    if(c==0)
    {
        if(s.is_open())
        {
            while( getline(s,line) )
            {
                if (line==id)
                    x=z;
                if (line==date&&1==z-x)
                {
                gt[i]=x-2;
                i++;
                gt[i]=0;
                }
                z++;
            }
        }
        else
            cout<<"No sales have been made\n";
            displaysale();
    }
    if(c==1)
    {
        if(p.is_open())
        {
            while( getline(p,line) )
            {
                if (line==id)
                    x=z;
                if (line==date&&1==z-x)
                {
                gt[i]=x-2;
                i++;
                gt[i]=0;
                }
                z++;
            }
        }
        else
            cout<<"No purchases have been made\n";
            displaypurchase();
    }
}
void Rsale()
{
    ifstream q("sale(out).txt");
    string line;
    system("cls");
    int c,m=1;
    do{
    cout<<"1. Total sale of the day by item"<<endl;
    cout<<"2. Total sale of the day by a particular item"<<endl;
    cout<<"3. Total sale by item"<<endl;
    cout<<"4. Total sale"<<endl;
    cin>>c;
    system("cls");
    }while(c<0||c>4);
    if (c==4)
    {
        if(q.is_open())
        {
            while ( getline (q,line) )
            {
                if(m==1){
                    cout<<"sale ID    : "<<line<<'\n';
                    m=2;}
                else if(m==2){
                    cout<<"InvoiceNo  : "<<line<<'\n';
                    m=3;}
                else if(m==3){
                    cout<<"Item ID    : "<<line<<'\n';
                    m=4;}
                else if(m==4){
                    cout<<"sale date  : "<<line<<'\n';
                    m=5;}
                else if(m==5){
                    cout<<"Quantity   : "<<line<<'\n';
                    m=6;}
                else if (m==6){
                    cout<<"Unit price : "<<line<<'\n';
                    m=7;}
                else {
                    cout<<"Discount   : "<<line<<"\n\n\n\n";
                    m=1;}
            }
            system("pause");
            q.close();
        }
        else{
            cout<<"error!"<<endl;
            system("pause");}

    }
    else if(c==3)
    {
        cout<<"Enter the ID of the item"<<endl;
        string id;
        cin>>id;
        searchsale(id);
    }
    else if(c==1)
    {
        cout<<"Enter the date \n";
        string date;
        cin>>date;
        searchsale("null",date);
    }
    else
    {
        cout<<"Enter the date\n";
        string date;
        cin>>date;
        cout<<"Enter the item id\n";
        string id;
        cin>>id;
        Rsearch(id,date,0);
    }
}
void profit()
{
    system("cls");
    ifstream s("sale(out).txt");
    ifstream p("purchase(in).txt");
    int c,pp=5,pppp=7,z=1,i=0,j=0,k=0;
    string uni[100],qun[100],suni[100],squn[100],sdis[100];
    string line,su,ssu,sssu;
    float stot=0,ptot=0,u,d,q,tot,totalprofit;
    qun[0]="null";uni[0]="null";
    do{
    cout<<"1. Total profit by item\n";
    cin>>c;
    system("cls");
    }while(c<1||c>1);
    if(c==1)
        {
           if(p.is_open()){
            while(getline(p,line))
            {
                if(z==pp){
                    qun[i]=line;
                    i++;
                    qun[i]="null";
                    pp=pp+6;
                }
                if(z==pp-5)
                {
                    uni[j]=line;
                    j++;
                    uni[j]="null";
                }
                z++;
            }
            p.close();
        }
    else{
        cout<<"there is no transaction yet\n\n";
        system("pause");
        }
        z=1;pp=5;i=0;j=0;
        sdis[0]="null";squn[0]="null";suni[0]="null";
    if(s.is_open())
    {
        while(getline(s,line))
            {
                if(z==pp){
                    squn[i]=line;
                    i++;
                    squn[i]="null";
                    pp=pp+7;
                }
                if(z==pp-6)
                {
                    suni[j]=line;
                    j++;
                    suni[j]="null";
                }
                if(z==pppp)
                {
                    sdis[k]=line;
                    k++;
                    sdis[k]="null";
                    pppp=pppp+7;
                }
                z++;
            }
            s.close();
        }
        else
            cout<<"no transactions have been made yet"<<endl;
        int m=0;
        while(uni[m]!="null")
        {
            u=::atof(uni[m].c_str());
            q=::atof(qun[m].c_str());
            tot=u*q;
            ptot=ptot+tot;
            m++;
        }
        m=0;
        while(suni[m]!="null")
        {
            d=::atof(sdis[m].c_str());
            d=d/100;
            u=::atof(suni[m].c_str());
            d=d*u;
            u=u-d;
            q=::atof(squn[m].c_str());
            tot=u*q;
            stot=stot+tot;
        }
        totalprofit=stot-ptot;
        cout<<"Total profit:   "<<totalprofit<<endl;
        system("pause");
        }

}
void Rpurchase()
{
    ifstream q("purchase(in).txt");
    string line;
    system("cls");
    int c,m=1;
    do{
    cout<<"1. Total purchase of the day by item"<<endl;
    cout<<"2. Total purchase of the day by a particular item"<<endl;
    cout<<"3. Total purchase by item"<<endl;
    cout<<"4. Total purchase"<<endl;
    cin>>c;
    system("cls");
    }while(c<0||c>4);
    if (c==4)
    {
        if(q.is_open())
        {
            while ( getline (q,line) )
            {
                if(m==1){
                    cout<<"purchase ID    : "<<line<<'\n';
                    m=2;}
                else if(m==2){
                    cout<<"InvoiceNo      : "<<line<<'\n';
                    m=3;}
                else if(m==3){
                    cout<<"Item ID        : "<<line<<'\n';
                    m=4;}
                else if(m==4){
                    cout<<"purchase date  : "<<line<<'\n';
                    m=5;}
                else if(m==5){
                    cout<<"Quantity       : "<<line<<'\n';
                    m=6;}
                else {
                    cout<<"Unit price     : "<<line<<"\n\n\n";
                    m=1;}
            }
            system("pause");
            q.close();
        }

    }
    else if(c==3)
    {
        cout<<"Enter the ID of the item"<<endl;
        string id;
        cin>>id;
        searchpurchase(id,"null");
    }
    else if(c==1)
    {
        cout<<"Enter the date \n";
        string date;
        cin>>date;
        searchpurchase("null",date);
    }
    else
    {
        cout<<"Enter the date\n";
        string date;
        cin>>date;
        cout<<"Enter the item id\n";
        string id;
        cin>>id;
        Rsearch(id,date,1);
    }
}
void report()
{
    system("cls");
    int c;
    do{
    cout<<"1. Item Inventory\n";
    cout<<"2. Sale\n";
    cout<<"3. purchase\n";
    cout<<"4. Profit\n";
    cout<<"5. Back to main switch board\n";
    cout<<"6. Exit\n";
    cin>>c;
    system("cls");}while(c<0||c>6);
    if(c==1)
    {
        iteminventory();
        system("cls");
    }
    else if(c==2)
    {
        Rsale();
        system("cls");
    }
    else if (c==3)
    {
        Rpurchase();
        system("cls");
    }
    else if (c==4)
    {
        profit();
        system("cls");
    }
    else if(c==5)
        return ;
    else
        exit(0);
}
int main()
{
    int n;
    do {
            do
            {
                cout<<"Enter the number of the operation you would like to perform.\n";
                cout<<"1. Item\n";
                cout<<"2. Sale\n";
                cout<<"3. Purchase\n";
                cout<<"4. Report\n";
                cout<<"5. Exit\n";
                cin>>n;
                if ( n<1 || n>5)
            {
            system("cls");
            cout<<"     choose from 1 to 5 only!"<<endl;
        }
    }while(n<1 || n>5);
			if ( n==1 ){
				item ();
				system ("cls");
			}
			else if (n==2) {
				sale ();
				system ("cls");
			}
			else if (n==3) {
				purchase ();
				system ("cls");
            }
			else if (n==4) {
				report ();
				system ("cls");
			}
			else
                exit(0);
	} while (n != 5);
}
