/*Create three database using header linked list
Student (Roll No, Name, Branch ID, CGPA)
University (University ID, University Name, University Location, Year of start)
Branch (Branch ID, University ID, Branch Name)
Implement the following modules/ sub-modules using menu driven approach:*/
#include<iostream>
#include<string>
using namespace std;
class university
{
    public:
        string uni_name, uni_loc, yob;
        int uni_id;
        university* next;
    public:
        university() {next=NULL;}
};
class university_head
{
    public:
        university* head;
    public:
        university_head() {head=NULL;}
        void insert(){
            university* temp= new university, *p =head, *q=NULL;
            cout << "Enter university name: ";
            cin >> temp->uni_name;
            cout << "Enter university ID: ";
            cin >> temp->uni_id;
            cout << "Enter university location: ";
            cin >> temp->uni_loc;
            cout << "Enter year of start: ";
            cin >> temp->yob;
            for (int i=0; temp->uni_name[i]; i++)
                if (temp->uni_name[i]>96)
                    temp->uni_name[i]= temp->uni_name[i]-32;
            if (!p)
                head= temp;
            else{
                university* q= NULL;
                while (p && p->uni_id!= temp->uni_id && p->yob < temp->yob){
                    q= p;
                    p= p->next;
                }
                if (!p)
                    q->next= temp;
                else if (p->uni_id== temp->uni_id){
                    cout << "Error: Duplicate detected\n";
                    delete temp;
                    return;
                }
                else if (!q){
                    temp->next= head;
                    head= temp;
                }
                else{
                    temp->next= q->next;
                    q->next= temp;
                }
            }
        }
        void update(int x){
            university* p=head, *q=NULL, *t=NULL;
            while (p->uni_id!=x){
                q= p;
                p= p->next;
            }
            if (!q){
                head= head->next;
                p->next= NULL;
            }
            else{
                q->next= p->next;
                p->next= NULL;
            }
            cout << "Enter new University name: ";
            cin >> p->uni_name;
            cout << "Enter new University location: ";
            cin >> p->uni_loc;
            cout << "Enter new University year of start: ";
            cin >> p->yob;
            q= head;
            while (q && q->yob < p->yob){
                t= q;
                q= q->next;
            }
            if (!q)
                t->next= p;
            else if (!t){
                p->next= head;
                head= p;
            }
            else{
                p->next= t->next;
                t->next= p;
            }
        }
        void del(int x){
            university* p=head, *q=NULL;
            while (p->uni_id!=x){
                q= p;
                p= p->next;
            }
            if (!q){
                head= head->next;
                free(p);
            }
            else{
                q->next= p->next;
                free(p);
            }
        }
        void display(){
            university* p=head;
            while (p){
                cout << "University name: " << p->uni_name << endl;
                cout << "University ID: "<< p->uni_id << endl;
                cout << "University Location: " << p->uni_loc << endl;
                cout << "University year of start: " << p->yob << endl;
                p= p->next;
            }
        }
        void display_name(char s[]){
            university* p=head;
            for (int i=0; s[i]; i++)
                if (s[i]>96)
                    s[i]= s[i]-32;
            while (p){
                int j, k;
                for (j=0, k=0; s[j] && p->uni_name[k]; k++)
                    if (s[j]==p->uni_name[k])
                        j++;
                if (!s[j]){
                    cout << "University name: " << p->uni_name << endl;
                    cout << "University ID: "<< p->uni_id << endl;
                    cout << "University Location: " << p->uni_loc << endl;
                    cout << "University year of start: " << p->yob << endl;
                }
                p= p->next;
            }
        }
};
class branch
{
    public:
        string branch_name;
        int branch_id, uni_id;
        branch* next;
    public:
        branch() {next=NULL;}
};
class branch_head{
    public:
        branch* head;
    public:
        branch_head() {head=NULL;}
        void insert(){
            branch* temp= new branch, *p =head, *q=NULL;
            cout << "Enter branch name: ";
            cin >> temp->branch_name;
            cout << "Enter branch ID: ";
            cin >> temp->branch_id;
            cout << "Enter University ID: ";
            cin >> temp->uni_id;
            for (int i=0; temp->branch_name[i]; i++)
                if (temp->branch_name[i]>96)
                    temp->branch_name[i]= temp->branch_name[i]-32;
            if (!p)
                head= temp;
            else{
                while (p->next && p->branch_id!= temp->branch_id)
                    p= p->next;
                
                if (p->branch_id== temp->branch_id){
                    cout << "Error: Duplicate detected\n";
                    delete temp;
                    return;
                }
                p->next= temp;
            }
        }
        void update(int x){
            branch* p=head;
            while (p->branch_id!=x)
                p= p->next;
            cout << "Enter new branch name: ";
            cin >> p->branch_name;
            cout << "Enter University ID: ";
            cin >> p->uni_id;
        }
        void del(int x){
            branch* p=head, *q=NULL;
            while (p->branch_id!=x){
                q= p;
                p= p->next;
            }
            if (!q){
                head= head->next;
                free(p);
            }
            else{
                q->next= p->next;
                free(p);
            }
        }
        void display(){
            branch* p=head;
            while (p){
                cout << "Branch name: " << p->branch_name << endl;
                cout << "Branch ID: "<< p->branch_id << endl;
                cout << "University ID: " << p->uni_id << endl;
                p= p->next;
            }
        }
        void display_uni_branches(int x){
            branch* p=head;
            while (p){
                if (p->uni_id==x){
                    cout << "Branch name: " << p->branch_name << endl;
                    cout << "Branch ID: "<< p->branch_id << endl;
                    cout << "University ID: " << p->uni_id << endl;
                }
                p= p->next;
            }
        }
};
class student{
    public:
        string name;
        int roll, cgpa, branch_id;
        student* next;
    public:
    student() {next=NULL;}
};
class student_head{
    public:
        student* head;
        student* backed;
    public:
        student_head() {head=NULL; backed=NULL;}
        void insert(branch_head* b){
            student* temp= new student, *p=head;
            branch* r= b->head;
            cout << "Enter student name: ";
            cin >> temp->name;
            cout << "Enter branch ID: ";
            cin >> temp->branch_id;
            cout << "Enter CGPA: ";
            cin >> temp->cgpa;
            cout << "Enter roll: ";
            cin >> temp->roll;
            while (r && r->branch_id!= temp->branch_id)
                r= r->next;
            if (!r){
                cout << "Error: No such branch in database.\n";
                free(temp);
                return;
            }
            for (int i=0; temp->name[i]; i++)
                if (temp->name[i]>96)
                    temp->name[i]= temp->name[i]-32;
            if (!p)
                head= temp;
            else{
                while (p->next && p->roll!= temp->roll)
                    p= p->next;
                
                if (p->roll== temp->roll){
                    cout << "Error: Duplicate detected\n";
                    delete temp;
                    return;
                }
                if (temp->cgpa >= 6)
                    p->next= temp;
                else{
                    student* z= backed;
                    if (!z)
                        backed=temp;
                    else{
                        while (z->next && z->roll!= temp->roll)
                            z= z->next;
                
                        if (z->roll== temp->roll){
                            cout << "Error: Duplicate detected\n";
                            delete temp;
                            return;
                        }
                        z->next= temp;
                    }
                }
            }
        }
        void display(){
            student* p=head;
            for (int i=0; i<2; i++){
                while (p){
                    cout << "Student name: " << p->name << endl;
                    cout << "Branch ID: "<< p->branch_id << endl;
                    cout << "CGPA: " << p->cgpa << endl;
                    cout << "Enter roll: " << p->roll << endl;
                    p= p->next;
                }
                p= backed;
            }
        }
        void update(int x){
            student* p=head, *q=NULL;
            int flag=1;
            for (int i=0; i<2; i++){
                while (p && p->roll!=x){
                    q= p;
                    p= p->next;
                }
                if (!p){
                    p= backed;
                    q=NULL;
                    flag=0;
                }
            }
            cout << "Enter new name: ";
            cin >> p->name;
            cout << "Enter new branch ID: ";
            cin >> p->branch_id;
            cout << "Enter new CGPA: ";
            cin >> p->cgpa;
            for (int i=0; p->name[i]; i++)
                if (p->name[i]>96)
                    p->name[i]= p->name[i]-32;
            if (p->cgpa <6 && flag==1){
                student* t= backed;
                if (!t){
                    if (!q){
                        head= head->next;
                        p->next= NULL;
                    }
                    else{
                        q->next= p->next;
                        p->next= NULL;
                    }
                    backed= p;
                }
                else{
                    while (t->next)
                        t= t->next;
                    if (!q){
                        head= head->next;
                        p->next= NULL;
                        t->next= p;
                    }
                    else{
                        q->next= p->next;
                        p->next= NULL;
                        t->next= p;
                    }
                }  
            }
            else if (p->cgpa >= 6 && flag==0){
                student* t= head;
                if (!t){
                    if (!q){
                        backed= backed->next;
                        p->next= NULL;
                    }
                    else{
                        q->next= p->next;
                        p->next= NULL;
                    }
                    backed= p;
                }
                else{
                    while (t->next)
                        t= t->next;
                    if (!q){
                        backed= backed->next;
                        p->next= NULL;
                        t->next= p;
                    }
                    else{
                        q->next= p->next;
                        p->next= NULL;
                        t->next= p;
                    }
                }
            }
        }
        void del(int x){
            student* p=head, *q=NULL;
            int flag=1;
            for (int i=0; i<2; i++){
                while (p->roll!=x){
                    q= p;
                    p= p->next;
                }
                if (!p){
                    p=backed;
                    q=NULL;
                    flag=0;
                }
            }
            if (!q && flag==1){
                head= head->next;
                free(p);
            }
            else if (!q && flag==0){
                backed= backed->next;
                free(p);
            }
            else{
                q->next= p->next;
                free(p);
            }
        }
        void display_kiit(int x){
            student* p=head;
            cout << "Students at KIIT CSE branch:\n";
            for (int i=0; i<2; i++){
                while (p){
                    if (p->branch_id==x){
                        cout << "Student name: " << p->name << endl;
                        cout << "Branch ID: "<< p->branch_id << endl;
                        cout << "CGPA: " << p->cgpa << endl;
                        cout << "Enter roll: " << p->roll << endl;
                    }
                    p= p->next;
                }
                p= backed;
            }
        }
        void display_name(string s){
            student* p=head;
            for (int i=0; s[i]; i++)
                if (s[i]>96)
                    s[i]= s[i]-32;
            for (int i=0; i<2; i++){
                while (p){
                    int j, k;
                    for (j=0, k=0; s[j] && p->name[k]; k++)
                        if (s[j]==p->name[k])
                            j++;
                    if (!s[j]){
                        cout << "Student name: " << p->name << endl;
                        cout << "Branch ID: "<< p->branch_id << endl;
                        cout << "CGPA: " << p->cgpa << endl;
                        cout << "Enter roll: " << p->roll << endl;
                    }
                    p= p->next;
                }
                p= backed;
            }
        }
};
int main(){
    branch_head b;
    student_head s;
    university_head u;
    int c=1, i=1;
    while (c){
        cout << "\n0: Exit\n1. Student db\n2. University db\n3. Branch db\n>";
        cin >> c;
        if (c==1){
            while (i){
                int a, x;
                cout <<"\n1. Insert\n2. Edit\n3. Delete\n4. Display\n5. Display KIIT CSE student\n6. Display student with specified name\n>";
                cin >> a;
                switch (a){
                    case 1:
                        s.insert(&b);
                        break;
                    case 2:
                        cout <<"Enter roll of student you want to update details for: ";
                        cin >> x;
                        s.update(x);
                        break;
                    case 3:
                        cout <<"Enter roll of student you want to remove: ";
                        cin >> x;
                        s.del(x);
                        break;
                    case 4:
                        s.display();
                        break;
                    case 5:
                        cout << "Enter branch ID of kiit cse: ";
                        cin >> x;
                        s.display_kiit(x);
                        break;
                    case 6:
                        char f[20];
                        cout << "Enter string to search for: ";
                        cin >> f;
                        s.display_name(f);
                        break;
                    default:
                        cout <<"Invalid Input\n";
                        break;
                }
                cout <<"0: Go back\n1: Continue\n>";
                cin >> i;
            }
        }
        else if (c==2){
            while (i){
                int a, x;
                cout <<"\n1. Insert\n2. Edit\n3. Delete\n4. Display\n5. Display university with specified name\n>";
                cin >> a;
                switch (a){
                    case 1:
                        u.insert();
                        break;
                    case 2:
                        cout <<"Enter university id you want to update details for: ";
                        cin >> x;
                        u.update(x);
                        break;
                    case 3:
                        cout <<"Enter university you want to remove: ";
                        cin >> x;
                        u.del(x);
                        break;
                    case 4:
                        u.display();
                        break;
                    case 5:
                        char f[20];
                        cout << "Enter string to search for: ";
                        cin >> f;
                        u.display_name(f);
                        break;
                    default:
                        cout <<"Invalid Input\n";
                        break;
                }
                cout <<"0: Go back\n1: Continue\n>";
                cin >> i;
            }
        }
        else if (c==3){
            while (i){
                int a, x;
                cout <<"\n1. Insert\n2. Edit\n3. Delete\n4. Display\n5. Display university branches\n>";
                cin >> a;
                switch (a){
                    case 1:
                        b.insert();
                        break;
                    case 2:
                        cout <<"Enter branch id you want to update details for: ";
                        cin >> x;
                        b.update(x);
                        break;
                    case 3:
                        cout <<"Enter branch id you want to remove: ";
                        cin >> x;
                        b.del(x);
                        break;
                    case 4:
                        b.display();
                        break;
                    case 5:
                        cout << "Enter university id to display: ";
                        cin >> x;
                        b.display_uni_branches(x);
                        break;
                    default:
                        cout <<"Invalid Input\n";
                        break;
                }
                cout <<"0: Go back\n1: Continue\n>";
                cin >> i;
            }
        }
        else if (c!=0)
            cout <<"Invalid Input\n";
        i=1;
    }
}