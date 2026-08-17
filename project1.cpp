#include<iostream>
#include<fstream>
using namespace std;
class student{
    string name;
    int roll;
    float marks;
    public:
    float getmarks(){
        return marks;
    }
    string getname(){
        return name;
    }
    int getroll(){
        return roll;
    }
    bool search(int roll){
        if(this->roll==roll)
        return true;
        return false;
    }
    void input(){
        cout<<"Enter name :";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter roll :";
        cin>>roll;
        cout<<"Enter marks :";
        cin>>marks;
    }
    void display(){
        cout<<"Name :"<<name<<endl;
        cout<<"Roll :"<<roll<<endl;
        cout<<"Marks :"<<marks<<endl;
    }
    void update(){
        cout<<"Enter new marks :";
        cin>>marks;
    }
    void setdata(string name,int roll,float marks){
        this->name=name;
        this->roll=roll;
        this->marks=marks;
    }
};
void swap(student* a,student* b){
    student temp=*a;
    *a=*b;
    *b=temp;
}
void Sort(student s[],int n){
    if(n==0||n==1)
    return;
    for(int i=0;i<n-1;i++){ 
   int max=i;
    for(int j=i+1;j<n;j++){
        if(s[j].getmarks()>s[max].getmarks())
        max=j;
    }
    swap(&s[i],&s[max]);
    }
}
void deletes(student s[],int &n,int pos){
    int i=pos;
    while(i+1<n){
        s[i]=s[i+1];
        i++;
    }
    n--;
}
int findstudent(student s[],int n,int r){
    for(int i=0;i<n;i++){
        if(s[i].search(r))
        return i;
    }
    return -1;
}
void save(student s[],int n){
    ofstream file("student.txt");
    for(int i=0;i<n;i++){
        file<<s[i].getname()<<"\n"<<s[i].getroll()<<"\n"<<s[i].getmarks()<<'\n';
    }
    file.close();
}
void load(student s[],int &n){
    ifstream file("student.txt");
    string name;
    int roll;
    float marks;
    while(getline(file,name)){
        file>>roll;
        file>>marks;
        file.ignore();
        s[n].setdata(name,roll,marks);
        n++;
    }
    file.close();
}
int main(){
    student s[10];
    int n=0;
    load(s,n);
    int choice=1;
    int r,pos;
    while(choice!=0){
        cout<<"1.Add student\n2.Display students\n3.Exit\n4.Search student\n5.Sort students\n6.Delete student\n7.Update marks\n";
        cout<<"Enter choice :";
        cin>>choice;
        switch(choice){
            case 1:
            if(n == 10){
            cout << "Student limit reached\n";
            break;
            }
            s[n].input();
             for(int i=0;i<n;i++){
                if(s[i].search(s[n].getroll())){
                    cout<<"the roll exists please reenter";
                    n--;
                    break;
                }
            }
            n++;
            break;
            case 2:
            for(int i=0;i<n;i++){
                s[i].display();
            }
            break;
            case 3:
            save(s,n);
            choice=0;
            break;
            case 4:
            cout<<"Enter roll :";
            cin>>r;
            pos=findstudent(s,n,r);
            if (pos==-1)
            cout<<"Not found"<<endl;
            else
            s[pos].display();
            break;
            case 5:
            Sort(s,n);
            break;
            case 6:
            cout<<"Enter roll :";
            cin>>r;
            pos=findstudent(s,n,r);
            if (pos==-1)
            cout<<"Not found"<<endl;
            else
            deletes(s,n,pos);
            break;
            case 7:
            cout<<"Enter roll :";
            cin>>r;
            pos=findstudent(s,n,r);
            if (pos==-1)
            cout<<"Not found"<<endl;
            else
            s[pos].update();
            break;
            default :
            cout<<"Invalid choice.Enter again\n";
        }
    }
}