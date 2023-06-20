#include <iostream>

template<typename T1, typename T2>
class base {
protected:
    T1 value1;
    T2 value2;
public:
    base(T1 val1 = 1, T2 val2 = 2) : 
        value1{val1},
        value2{val2}
    {
        std::cout << "val1 " << value1 << std::endl;
        std::cout << "val2 " << value2 << std::endl;
    }
    ~base(){
    }
};

template<typename T1, typename T2,typename T3, typename T4>
class child : public base<T1, T2> {
protected:
    T3 value3;
    T4 value4;
public: 
    child(T3 val3 =10, T4 val4 =20):
        value3{val3},
        value4{val4}
    {
        std::cout << "val3 " << value3 + base<T1,T2>::value1 << std::endl;
        std::cout << "val4 " << value4 + base<T1, T2>::value2 << std::endl;
    }
    ~child() {
        
    }
};

template<typename T1, typename T2,typename T3, typename T4,typename T5, typename T6>
class child2 : public child<T1,T2,T3, T4> {
    T5 value5;
    T6 value6;
public:
    child2(T5 val5, T6 val6) :
        value5{ val5 },
        value6{ val6 }
    {
        std::cout << "val5 " << value5 + child<T1,T2,T3,T4>::value3 << std::endl;
        std::cout << "val6 " << value6 + child<T1,T2,T3,T4>::value4 << std::endl;
    }
    ~child2() {
        
    }
};

int main()
{
    base<int,int> a(10,20);
    child<int, int,int,int> b(30, 40);
    child2<int, int,int,int,int,int> c(40, 50);

}

