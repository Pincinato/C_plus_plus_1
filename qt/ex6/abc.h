#ifndef ABC_H
#define ABC_H

class a
{
public:
    a(){
        cout <<"Constructor A"<<endl;
    }
    ~a(){
        cout <<" Destructor A"<<endl;
   }
};

class b
{
public:
    b(){
      cout <<"Constructor B"<<endl;
    }
    ~b(){
        cout <<" Destructor B"<<endl;
   }
};


class c
{
public:
    c(){
      cout <<"Constructor C"<<endl;
    }
    ~c(){
        cout <<" Destructor C"<<endl;
   }
};

class abc: public a,public c, public b
{
public:
    abc(){
      cout <<"Constructor ABC"<<endl;
    }
    ~abc(){
        cout <<" Destructor ABC"<<endl;
   }
};
#endif // ABC_H
