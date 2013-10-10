#include <iostream>

using namespace std;

struct polynode
{
    double coef;
    int exp;
    polynode *link;
};
typedef polynode *polypointer;

char compare(int a,int b)
{
    if(a>b)
        return '>';
    else if(a<b)
        return '<';
    else
        return '=';
}

polypointer Attach(int c,int e,polypointer d)
{

    polypointer x;
    x=new polynode;
    x->coef=c;
    x->exp=e;
    d->link=x;
    return x;
}

polypointer PolyAdd(polypointer a,polypointer b)
{
    polypointer p,q,d,c;
    int x;
    p=a;
    q=b;
    c=new polynode;
    d=c;
    while((p!=NULL)&&(q!=NULL))
        switch(compare(p->exp,q->exp))
        {
        case'=':
            x=p->coef+q->coef;
            if(x!=0)
                d=Attach(x,p->exp,d);
            p=p->link;
            q=q->link;
            break;
        case'>':
            d=Attach(p->coef,p->exp,d);
            p=p->link;
            break;
        case'<':
            d=Attach(p->coef,p->exp,d);
            q=q->link;
            break;
        }
    while (p!=NULL)
    {
        d=Attach(p->coef,p->exp,d);
        p=p->link;
    }
    while(q!=NULL)
    {
        d=Attach(q->coef,q->exp,d);
        q=q->link;
    }
    d->link=NULL;
    p=c;
    c=c->link;
    delete p;
    return c;
}

int main()
{
    polypointer a,b,c,d,e;
    a=new polynode;
    b=new polynode;
    c=new polynode;
    int coef,exp, i = 1;
    d = a;
    e = b;
    while(i)
    {
        cout<<"分别输入系数，指数：";
       cin>>coef;
       cout<<endl;
       cin>>exp;
       cout<<endl;
       if(coef==0&&exp==0)
        break;
       d=Attach(coef,exp,d);
    }

        cout<<"第二个:";

    while(1)
    {
        cout<<"分别输入系数，指数：";
       cin>>coef;
       cout<<endl;
       cin>>exp;
       cout<<endl;
       if(coef==0&&exp==0)
        break;
       e=Attach(coef,exp,e);
    }
    c=PolyAdd(a->link,b->link);
    cout<<"所得结果为:";
    cout<<c->coef<<"x^"<<c->exp;
    c=c->link;
    while(c!=NULL)
    {
        cout<<"+"<<c->coef<<"x^"<<c->exp;
        c=c->link;
    }
    cout<<endl;
    return 0;
}