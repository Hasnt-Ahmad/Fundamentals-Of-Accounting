#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class Accounting{
    public:
    string Current_Assests[50];
    string Non_Current_Assests[50];
    string Current_liabilities[50];
    string Non_Current_liabilities[50];
    string Expense[50];
    string Revenue[50];

    string Account_Name;
    int Current_Assests_Amount[50];
    int Non_Current_Assests_Amount[50];  
    int Current_Liabilities_Amount[50];
    int Non_Current_Liabilities_Amount[50];
    int Expense_Amount[50];
    int Equity_Amount=0;
    int Revenue_Amount[50];
    int Curr_Assests=0;
    int Non_Curr_Assests=0;
    int Curr_liabilities=0;
    int Non_Curr_liabilities=0;
    int Expe=0;
    int Revenue_Count=0;
    int Debit;
    int Credit;

    int Total_Current_Assets=0;             // balance sheet
    int Total_Assets=0;
    int Total_Current_Liabilities=0;
    int Total_Liabilities=0;                
    int Total_Revenue=0;
    int Total_Expense=0;
    int Total_Liabilities_Equity=0;

    int credit_check=0;
    int debit_check=0;
    void Entries(string acc){
        string space="";
        string acc_type;
        int choice;
        if(acc=="Assets"){
            cout<<"1.Current Asset , 2,Non Current Assest : "<<endl;
            cin>>choice;
            cin.ignore();
            cout<<"Account Name : "<<endl;
            getline(cin,Account_Name);
            cout<<"Debit Or Credit : ";
            cin>>acc_type;
            if(acc_type=="Debit"){
                int length=48;
                length=length-Account_Name.size();
                for(int i=0;i<length;i++){
                    space+=" ";
                }
                cout<<"Enter Amount : "<<endl;
                cin>>Debit;
                cout<<"Debit : "<<Debit<<endl;
                fstream myfile;
                myfile.open("General_Journal.txt",ios::app);
                if(myfile.is_open()){
                myfile<<"\n";
                myfile<<"----------------------------------------------------------------------------------------------------------------------------"<<"\n";
                myfile<<Account_Name<<space<<Debit<<"\n";
                }
                if(choice==1){
                    for(int i=0;i<=Curr_Assests;i++){
                        if(Current_Assests[i]==Account_Name){
                            Current_Assests_Amount[i]+=Debit;
                            return;
                        }
                    }
                    Current_Assests[ Curr_Assests]=Account_Name;
                    Current_Assests_Amount[Curr_Assests]=Debit;
                    Curr_Assests++;
                }
                else if(choice==2){
                    for(int i=0;i<=Non_Curr_Assests;i++){
                        if(Non_Current_Assests[i]==Account_Name){
                            Non_Current_Assests_Amount[i]+=Debit;
                            return;
                        }
                    }
                    Non_Current_Assests[Non_Curr_Assests]=Account_Name;
                    Non_Current_Assests_Amount[Non_Curr_Assests]=Debit;
                    Non_Curr_Assests++; 
                }
                debit_check++;
            }
            else if(acc_type=="Credit"){
                int length=70;
                length=length-Account_Name.size();
                for(int i=0;i<length;i++){
                    space+=" ";
                }
                cout<<"Enter Amount : "<<endl;
                cin>>Credit;
                fstream myfile;
                myfile.open("General_Journal.txt",ios::app);
                if(myfile.is_open()){
                myfile<<Account_Name<<space<<Credit<<"\n";
                myfile<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<"\n";
                myfile<<"\n";
                }
                if(choice==1){
                    for(int i=0;i<=Curr_Assests;i++){
                        if(Current_Assests[i]==Account_Name){
                            Current_Assests_Amount[i]-=Credit;
                            return;
                        }
                    }
                    Current_Assests[ Curr_Assests]=Account_Name;
                    Current_Assests_Amount[Curr_Assests]=Credit;
                    Curr_Assests++;
                }
                else if(choice==2){
                    for(int i=0;i<=Non_Curr_Assests;i++){
                        if(Non_Current_Assests[i]==Account_Name){
                            Non_Current_Assests_Amount[i]-=Credit;
                            return;
                        }
                    }
                    Non_Current_Assests[Non_Curr_Assests]=Account_Name;
                    Non_Current_Assests_Amount[Non_Curr_Assests]=Credit;
                    Non_Curr_Assests++;
                }
                credit_check++;
            }
            }
         if(acc=="Liabilities"){
            cout<<"1.Current Liabilities , 2,Non Current Libilities : "<<endl;
            cin>>choice;
             cin.ignore();
            cout<<"Account Name : ";
            getline (cin, Account_Name);
            cout<<"Debit Or Credit : ";
            cin>>acc_type;
            if(acc_type=="Debit"){
                int length=48;
                length=length-Account_Name.size();
                for(int i=0;i<length;i++){
                    space+=" ";
                }
                cout<<"Enter Amount : "<<endl;
                cin>>Debit;
                cout<<"Debit : "<<Debit<<endl;
                fstream myfile;
                myfile.open("General_Journal.txt",ios::app);
                if(myfile.is_open()){
                myfile<<"\n";
                myfile<<"----------------------------------------------------------------------------------------------------------------------------"<<"\n";
                myfile<<Account_Name<<space<<Debit<<"\n";
                }
                if(choice==1){
                    for(int i=0;i<=Curr_liabilities;i++){
                        if(Current_liabilities[i]==Account_Name){
                            Current_Liabilities_Amount[i]-=Debit;
                            return;
                        }
                    }
                    Current_liabilities[ Curr_liabilities]=Account_Name;
                    Current_Liabilities_Amount[Curr_liabilities]=Debit;
                    Curr_liabilities++;
                }
                else if(choice==2){
                    for(int i=0;i<=Non_Curr_liabilities;i++){
                        if(Non_Current_liabilities[i]==Account_Name){
                           Non_Current_Liabilities_Amount[i]-=Debit;
                            return;
                        }
                    }
                    Non_Current_liabilities[Non_Curr_liabilities]=Account_Name;
                    Non_Current_Liabilities_Amount[Non_Curr_liabilities]=Debit;
                    Non_Curr_liabilities++; 
                }
                debit_check++;
            }
            else if(acc_type=="Credit"){
                int length=70;
                length=length-Account_Name.size();
                for(int i=0;i<length;i++){
                    space+=" ";
                }
                cout<<"Enter Amount : "<<endl;
                cin>>Credit;
                fstream myfile;
                myfile.open("General_Journal.txt",ios::app);
                if(myfile.is_open()){
                myfile<<Account_Name<<space<<Credit<<"\n";
                myfile<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<"\n";
                myfile<<"\n";
                }
                if(choice==1){
                    for(int i=0;i<=Curr_liabilities;i++){
                        if(Current_liabilities[i]==Account_Name){
                            Current_Liabilities_Amount[i]+=Credit;
                            return;
                        }
                    }
                    Current_liabilities[ Curr_liabilities]=Account_Name;
                    Current_Liabilities_Amount[Curr_liabilities]=Credit;
                    Curr_liabilities++;
                }
                else if(choice==2){
                    for(int i=0;i<=Non_Curr_liabilities;i++){
                        if(Non_Current_liabilities[i]==Account_Name){
                           Non_Current_Liabilities_Amount[i]+=Credit;
                            return;
                        }
                    }
                    Non_Current_liabilities[Non_Curr_liabilities]=Account_Name;
                    Non_Current_Liabilities_Amount[Non_Curr_liabilities]=Credit;
                    Non_Curr_liabilities++; 
                }
                credit_check++;
            }  
            }
            if(acc=="Expense"){
                cin.ignore();
                cout<<"Account Name : ";
                getline (cin, Account_Name);
                cout<<"Debit Or Credit : ";
                cin>>acc_type;
                 if(acc_type=="Debit"){
                    int length=48;
                    length=length-Account_Name.size();
                    for(int i=0;i<length;i++){
                    space+=" ";
                    }
                    cout<<"Enter Amount : "<<endl;
                    cin>>Debit;
                    fstream myfile;
                    myfile.open("General_Journal.txt",ios::app);
                    if(myfile.is_open()){
                        myfile<<"\n";
                        myfile<<"----------------------------------------------------------------------------------------------------------------------------"<<"\n";
                        myfile<<Account_Name<<space<<Debit<<"\n";
                        }
                    for(int i=0;i<=Expe;i++){
                        if(Expense[i]==Account_Name){
                            Expense_Amount[i]+=Debit;
                            return;
                        }
                    }
                    Expense[Expe]=Account_Name;
                    Expense_Amount[Expe]=Debit;
                    Expe++;
                    debit_check++;
                    }
                if(acc_type=="Credit"){
                    int length=70;
                    length=length-Account_Name.size();
                    for(int i=0;i<length;i++){
                    space+=" ";
                    }
                    cout<<"Enter Amount : "<<endl;
                    cin>>Credit;
                    fstream myfile;
                    myfile.open("General_Journal.txt",ios::app);
                    if(myfile.is_open()){
                       myfile<<Account_Name<<space<<Credit<<"\n";
                       myfile<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<"\n";
                       myfile<<"\n";
                    }
                    for(int i=0;i<=Expe;i++){
                        if(Expense[i]==Account_Name){
                            Expense_Amount[i]-=Credit;
                            return;
                        }
                    }
                    Expense[Expe]=Account_Name;
                    Expense_Amount[Expe]=Credit;
                    Expe++;
                    credit_check++;
                }
            }
            if(acc=="Equity"){
                cin.ignore();
                cout<<"Account Name : ";
                getline (cin, Account_Name);
                cout<<"Debit Or Credit : ";
                cin>>acc_type;
                 if(acc_type=="Debit"){
                    int length=48;
                    length=length-Account_Name.size();
                    for(int i=0;i<length;i++){
                    space+=" ";
                    }
                    cout<<"Enter Amount : "<<endl;
                    cin>>Debit;
                    fstream myfile;
                    myfile.open("General_Journal.txt",ios::app);
                    if(myfile.is_open()){
                        myfile<<"\n";
                        myfile<<"----------------------------------------------------------------------------------------------------------------------------"<<"\n";
                        myfile<<Account_Name<<space<<Debit<<"\n";
                    }
                        Equity_Amount-=Debit;
                    debit_check++;
                }
                if(acc_type=="Credit"){
                    int length=70;
                    length=length-Account_Name.size();
                    for(int i=0;i<length;i++){
                        space+=" ";
                    }
                    cout<<"Enter Amount : "<<endl;
                    cin>>Credit;
                    fstream myfile;
                    myfile.open("General_Journal.txt",ios::app);
                    if(myfile.is_open()){
                       myfile<<Account_Name<<"\t"<<" \t "<<" \t "<<" \t "<<" \t "<<" \t "<<" \t "<<" \t "<<" \t "<<" \t "<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<Credit<<"\n";
                       myfile<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<"\n";
                       myfile<<"\n";
                    }
                        Equity_Amount+=Credit;
                        credit_check++;
                    }
            }
             if(acc=="Revenue"){
                cin.ignore();
                cout<<"Account Name : ";
                getline (cin, Account_Name);
                cout<<"Debit Or Credit : ";
                cin>>acc_type;
                 if(acc_type=="Debit"){
                    int length=48;
                    length=length-Account_Name.size();
                    for(int i=0;i<length;i++){
                    space+=" ";
                    }
                    cout<<"Enter Amount : "<<endl;
                    cin>>Debit;
                    fstream myfile;
                    myfile.open("General_Journal.txt",ios::app);
                    if(myfile.is_open()){
                        myfile<<"\n";
                        myfile<<"----------------------------------------------------------------------------------------------------------------------------"<<"\n";
                        myfile<<Account_Name<<space<<Debit<<"\n";
                    }
                       for(int i=0;i<=Revenue_Count;i++){
                        if(Revenue[i]==Account_Name){
                            Revenue_Amount[i]-=Debit;
                            return;
                        }
                    }
                    Revenue[Revenue_Count]=Account_Name;
                    Revenue_Amount[Revenue_Count]=Debit;
                    Revenue_Count++;
                    debit_check++;
                }
                if(acc_type=="Credit"){
                    int length=70;
                    length=length-Account_Name.size();
                    for(int i=0;i<length;i++){
                    space+=" ";
                    }
                    cout<<"Enter Amount : "<<endl;
                    cin>>Credit;
                    fstream myfile;
                    myfile.open("General_Journal.txt",ios::app);
                    if(myfile.is_open()){
                       myfile<<Account_Name<<space<<Credit<<"\n";
                       myfile<<"-------------------------------------------------------------------------------------------------------------------------------------------"<<"\n";
                       myfile<<"\n";
                    }
                        for(int i=0;i<=Revenue_Count;i++){
                        if(Revenue[i]==Account_Name){
                            Revenue_Amount[i]+=Credit;
                            return;
                        }
                    }
                    Revenue[Revenue_Count]=Account_Name;
                    Revenue_Amount[Revenue_Count]=Credit;
                    Revenue_Count++;
                    credit_check++;
                    }
            }
        }
        void Balance_Sheet(){
            fstream myfile;
            myfile.open("Balance_Sheet.txt",ios::app);
                    if(myfile.is_open()){
                        myfile<<"\n";
                        myfile<<"Assets"<<"\n";
                        int i=0;
                        while(Current_Assests[i]!="\0"){
                            myfile<<Current_Assests[i]<<"\t"<<Current_Assests_Amount[i]<<"\n";
                            Total_Current_Assets+=Current_Assests_Amount[i];
                            i++;
                        }
                        myfile<<"Total Current Assets "<<Total_Current_Assets<<"\n";
                        Total_Assets=Total_Current_Assets;
                         i=0;
                        while(Non_Current_Assests[i]!="\0"){
                            myfile<<Non_Current_Assests[i]<<"\t"<<Non_Current_Assests_Amount[i]<<"\n";
                            Total_Assets+=Non_Current_Assests_Amount[i];
                            i++;
                        }
                        myfile<<"Total Assets "<<Total_Assets<<"\n"<<"\n";
                        myfile<<"Liabilities"<<"\n";
                         i=0;
                        while(Current_liabilities[i]!="\0"){
                            myfile<<Current_liabilities[i]<<"\t"<<Current_Liabilities_Amount[i]<<"\n";
                            Total_Current_Liabilities+=Current_Liabilities_Amount[i];
                            i++;
                        }
                        myfile<<"Total Current Liabilities "<<Total_Current_Liabilities<<"\n";
                        Total_Liabilities=Total_Current_Liabilities;
                         i=0;
                        while(Non_Current_liabilities[i]!="\0"){
                            myfile<<Non_Current_liabilities[i]<<"\t"<<Non_Current_Liabilities_Amount[i]<<"\n";
                            Total_Liabilities+=Non_Current_Liabilities_Amount[i];
                            i++;
                        }
                         myfile<<"Total Liabilities "<<Total_Liabilities<<"\n";
                         Total_Liabilities_Equity+=Equity_Amount;
                         i=0;
                         while(Revenue[i]!="\0"){
                           Total_Liabilities_Equity+=Revenue_Amount[i];
                            i++;
                        }
                        i=0;
                        while(Expense[i]!="\0"){
                            Total_Liabilities_Equity-=Expense_Amount[i];
                            i++;
                        }
                        myfile<<" Share Holders Equity "<<Equity_Amount<<"\n";
                        myfile<<"Total Liabilities + Equity "<<Total_Liabilities+Total_Liabilities_Equity;
                    }
        }
        void Income_Statement(){
            fstream myfile;
            myfile.open("Income_Statement.txt",ios::app);
                    if(myfile.is_open()){
                        myfile<<"\n";
                        myfile<<"Revenue "<<"\n";
                        int i=0;
                        while(Revenue[i]!="\0"){
                            myfile<<Revenue[i]<<"\t"<<Revenue_Amount[i]<<"\n";
                            Total_Revenue+=Revenue_Amount[i];
                            i++;
                        }
                        myfile<<"Total Revenue "<<Total_Revenue<<"\n";
                        myfile<<"\n";
                        i=0;
                        myfile<<"Expenses "<<"\n";
                        while(Expense[i]!="\0"){
                            myfile<<Expense[i]<<"\t"<<Expense_Amount[i]<<"\n";
                            Total_Expense+=Expense_Amount[i];
                            i++;
                        }
                        myfile<<"Total Expenses "<< Total_Expense<<"\n";
                        myfile<<"\n";
                        myfile<<"Net Income  "<< Total_Revenue-Total_Expense<<"\n";
                    }

        }
        void Trial_Balance(){
            string space="";
            int length=47;
            fstream myfile;
            myfile.open("Trial_Balance.txt",ios::app);
                    if(myfile.is_open()){
                        myfile<<"\n";
                        int i=0;
                        while(Current_Assests[i]!="\0"){
                            length=length-Current_Assests[i].size();
                            
                            for(int j=0;j<length;j++){
                                space+=" ";
                            }
                            myfile<<Current_Assests[i]<<space<<"|"<<Current_Assests_Amount[i]<<endl;
                            space="";
                            length=47;
                            i++;
                        }
                        i=0;
                        length=47;
                        space="";
                        while(Non_Current_Assests[i]!="\0"){
                            length=length-Non_Current_Assests[i].size();
                            cout<<length;
                            for(int j=0;j<length;j++){
                                space+=" ";
                            }
                            myfile<<Non_Current_Assests[i]<<space<<"|"<<Non_Current_Assests_Amount[i]<<endl;
                            space="";
                            length=47;
                            i++;
                        }
                        i=0;
                        length=70;
                        space="";
                        while(Current_liabilities[i]!="\0"){
                            length=length-Current_liabilities[i].size();
                            cout<<length;
                            for(int j=0;j<length;j++){
                                space+=" ";
                            }
                            myfile<<Current_liabilities[i]<<space<<"|"<<Current_Liabilities_Amount[i]<<endl;
                            length=70;
                            space="";
                            i++;
                        }
                         i=0;
                        length=70;
                        space="";
                        while(Non_Current_liabilities[i]!="\0"){
                            length=length-Non_Current_liabilities[i].size();
                            cout<<length;
                            for(int j=0;j<length;j++){
                                space+=" ";
                            }
                            myfile<<Non_Current_liabilities[i]<<space<<"|"<<Non_Current_Liabilities_Amount[i]<<"\n";
                            length=70;
                            space="";
                            i++;
                        }
                        length=64;
                        space="";
                        for(int i=0;i<length;i++){
                            space+=" ";
                        }
                        myfile<<"Equity"<<space<<"|"<<Equity_Amount<<"\n";
                        length=70;
                        space="";
                        i=0;
                         while(Revenue[i]!="\0"){
                             length-=Revenue[i].size();
                             for(int i=0;i<length;i++){
                                 space+=" ";
                             }
                            myfile<<Revenue[i]<<space<<"|"<<Revenue_Amount[i]<<"\n";
                            i++;
                            length=70;
                            space="";
                        }
                        length=47;
                        space="";
                        i=0;
                        while(Expense[i]!="\0"){
                            length-=Expense[i].size();
                            for(int i=0;i<length;i++){
                                space+=" ";
                            }
                            myfile<<Expense[i]<<space<<"|"<<Expense_Amount[i]<<"\n";
                            i++;
                            length=47;
                            space="";
                        }
                    }
        }
};
int main(){
    Accounting A1;
    int choice;
    char B;
    bool Exit=true;
        cout<<" -------- Accounting System --------- "<<endl;
    while(Exit==true){
        if(A1.credit_check!=A1.debit_check){
            cout<<"Record 2nd Transaction : "<<endl;
        }
        cout<<"Choose An Account : "<<endl;
        cout<<"1. Assets "<<endl;
        cout<<"2. Liabilities "<<endl;
        cout<<"3. Equity "<<endl;
        cout<<"4. Revenue "<<endl;
        cout<<"5. Expense "<<endl;
        cout<<"6.Exit "<<endl;
        cin>>choice;
        if(choice==1){
            A1.Entries("Assets");
        }
        else if(choice==2){
            A1.Entries("Liabilities");
        }
        else if(choice==3){
            A1.Entries("Equity");
        }
        else if(choice==4){
            A1.Entries("Revenue");
        }
        else if(choice==5){
            A1.Entries("Expense");
        }
        else if(choice==6){
            Exit=false;
        }
    }
    cout<<"Do You Want To Generate Balance Sheet >|? Y/N "<<endl;
    cin>>B;
    if(B=='Y'){
        A1.Balance_Sheet();
    }
    cout<<"Do You Want To Generate Income Statement ? Y/N "<<endl;
    cin>>B;
    if(B=='Y'){
        A1.Income_Statement();
    }
    cout<<"Do You Want To Generate Trial Balance ? Y/N "<<endl;
    cin>>B;
    if(B=='Y'){
        A1.Trial_Balance();
    }
}