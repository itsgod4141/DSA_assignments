#include <iostream>
#include<stdlib.h>
using namespace std;
int count;
class BTNODE
{
public:
string word;
string mean;
BTNODE *left;
BTNODE *right;
BTNODE()
{
 left=right=NULL;
 word=mean=-1;
}
};
class DICTIONARY
{
public:
BTNODE *root;
DICTIONARY()
 {
 root=NULL;
}
void create();
BTNODE *search(string);
void Insert(string,string);
 void InOrder(BTNODE *);
BTNODE *getBTNODE(string,string);
 BTNODE *findparent(BTNODE *);
 void delet1(BTNODE *);
};
BTNODE *DICTIONARY::search(string key)
{
BTNODE *T=root;
while(T!=NULL)
{
if(T->word==key )
{
count++;
return T;
}
else if(T->word>key)
{
count++;
 T=T->left;
}
else
{
count++;
T=T->right;
}
}
return T;
}
BTNODE *DICTIONARY::getBTNODE(string key,string min)
{
BTNODE *p;
p=new BTNODE;
if(!p)
{
cout<<"memory is not sufficient"<<endl;
}
else
{
p->word=key;
p->mean=min;
}
return p;
}

void DICTIONARY::Insert(string key,string min)
{
 BTNODE *p=getBTNODE(key,min);
 if(root==NULL)
 {
root=p;
 }
 else
 {
 BTNODE *T=root;
 while(1)
 {
 if(key<T->word)
 {
 if(T->left==NULL)
 {
 T->left=p;
 break;
 }
 else
 {
 T=T->left;
 }
 }
 else
 {
if(T->right==NULL)
{
T->right=p;
break;
}
else
{
T=T->right;
}
 }
 }
 }
}

void DICTIONARY::create()
{
 string key,min;
char ch;
do
{
cout<<"enter the word ="<<endl;
cin>>key;
cout<<"enter the meaning ="<<endl;
cin>>min;
if(search(key)==NULL)
{
Insert(key,min);
}
else
{
cout<<" word is already present....."<<endl;
}
cout<<"do you want to add more word="<<endl;
cin>>ch;
}while(ch=='y'||ch=='Y');
}

void DICTIONARY::InOrder(BTNODE *T)
{
if(T!=NULL)
{
InOrder(T->left);
cout<<endl<<T->word<<"-:"<<T->mean;
InOrder(T->right);
}
}
BTNODE *DICTIONARY::findparent(BTNODE *K)
{
BTNODE *q=root;
if(K==root)
{
return NULL;
}
else
{
while(1)
{
if((q->left==K)||(q->right==K))
{
return q;
}
else
{
if(K->word<q->word)
{
q=q->left;
}
else
{
q=q->right;
}
}
}
}
return NULL;
}

void DICTIONARY::delet1(BTNODE *q)
{
BTNODE *p;
if((q->left==NULL)&&(q->right==NULL))
{
if(q==root)
{
root=NULL;
delete q;
return;
}
 else
 {
p=findparent(q);
if(p->left==q)
{
p->left=NULL;
delete q;
return;
}
else
{
p->right=NULL;
delete q;
return;
}
 }
 }

if((q->left==NULL && q->right!=NULL) || (q->left!=NULL && 
q->right==NULL))
{
if(q==root)
{
if(q->left!=NULL)
{
root=q->left;
delete q;
return;
}
else
{
root=q->right;
delete q;
return;
}
}
else
{
p=findparent(q);
if(p->left==q)
{
 if(q->left!=NULL)
 {
p->left=q->left;
delete q;
return;
 }
 else
{
p->left=q->right;
delete q;
return;
}
}
else
{
if(q->left!=NULL)
{
p->right=q->left;
delete q;
return;
}
else
{
p->right=q->right;
delete q;
return;
}
}
}
} 
BTNODE *S=q->right;
while(S->left!=NULL)
{
S=S->left;
}
q->word=S->word;
delet1(S);

}
int main() {
 string key;
 DICTIONARY b;
int ch;
while(ch!=6)
{
cout<<" 1 create dictonary"<<endl;
cout<<" 2 display dictonary using inorder sequence"<<endl;
cout<<" 3 serach word meaning in the dictonary"<<endl;
cout<<" 4 insert word in the dictonary"<<endl;
cout<<" 5 delete the word"<<endl;
cout<<" 6 exit."<<endl;
cout<<" enter choice.....="<<endl;
cin>>ch;
switch(ch)
{
case 1:b.create();
 break;
case 2:cout<<"DICTIONARY is ="<<endl;
 b.InOrder(b.root);
 break;
case 3:cout<<" enter word whose meaning to find ="<<endl;
 cin>>key;
 count=0;
 if(b.search(key)==NULL)
 {
 cout<<" word is not found...."<<endl;
 }
 else
 {
 cout<<"\n "<<b.search(key)->word<<"-:"<<b.search(key)->mean<<" required comparisons="<<count<<endl;
 }
 break;
 case 4:b.create();
 cout<<" after insertion DICTIONARY is ="<<endl;
 b.InOrder(b.root);
 break;
 case 5:cout<<" enter word which you want to delete ="<<endl;
 cin>>key;
 BTNODE *p=b.search(key);
 b.delet1(p);
 cout<<" after deletion DICTIONARY becomes"<<endl;
 b.InOrder(b.root);
 break;
}
}
return 0;
}
