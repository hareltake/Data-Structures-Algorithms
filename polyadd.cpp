#include <iostream>

using namespace std;

struct polynode
{
    double coef;
    int exe;
    polynode * next;
};
void tailinsert(polynode *head,double a,int b);
void frontinsert(polynode *position1,double a,int b);
void polyadd(polynode *position1,polynode *position2);
int main()
{
    polynode *head1=new polynode;
    polynode *head2=new polynode;
    head1->next=NULL;
    head2->next=NULL;
    cout<<"请按如下格式输入多项式一：系数 指数（指数从高到低，以0 0结束）"<<endl;
    double a;
    int b;
    cin>>a>>b;
    while(a!=0||b!=0)
    {
        tailinsert(head1,a,b);
        cin>>a>>b;
    }
    cout<<"请按上述格式输入多项式二："<<endl;
    cin>>a>>b;
    while(a!=0||b!=0)
    {
        tailinsert(head2,a,b);
        cin>>a>>b;
    }
    polynode *p1=head1;
    polynode *p2=head2;
    while(p2->next!=NULL)
    {
        if(p1->next==NULL)
        {
            while(p2->next!=NULL)
            {
                tailinsert(head1,p2->next->coef,p2->next->exe);
                p2=p2->next;
            }
            break;
        }
        if(p1->next->exe<p2->next->exe)
        {
            frontinsert(p1,p2->next->coef,p2->next->exe);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->next->exe==p2->next->exe)
        {
            polyadd(p1,p2);
            p1=p1->next;
            p2=p2->next;
        }
        else
        {
            p1=p1->next;
        }
    }
    cout<<"两多项式相加如下："<<endl;
    p1=head1;
    while(p1->next!=NULL)
    {
        cout<<p1->next->coef<<"X^"<<p1->next->exe<<"+";
        p1=p1->next;
    }
}
void tailinsert(polynode *head,double a,int b)
{
    polynode *p=head;
    while(p->next!=NULL)
        p=p->next;
    p->next=new polynode;
    p->next->coef=a;
    p->next->exe=b;
    p->next->next=NULL;
}
void frontinsert(polynode *position1,double a,int b)
{
    polynode *temp=position1->next;
    position1->next=new polynode;
    position1->next->coef=a;
    position1->next->exe=b;
    position1->next->next=temp;
}
void polyadd(polynode *position1,polynode *position2)
{
    position1->next->coef+=position2->next->coef;
}
