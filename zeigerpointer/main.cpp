#include <iostream>

using namespace std;

class B { public:
    virtual char* fv(){ return "B:fv"; }; char* fn(){ return "B:fn"; };
    int pubB; protected:
    int protB; private:
    int privB;
};
class A : public B { public:
    virtual char* fv(){ return "A:fv"; }; char* fn(){ return "A:fn"; };
    int pubA;
    void testA(){ /* 5 */ }; protected:
    int protA; private:
    int privA;
};
class C : private B {
public:
    int pubC;
    void testB(){ /* 6 */ }; protected:
    int protC; private:
    int privC;
};
int main() {
    // a)
    A a;
    A *pA=&a;
    B *pB=&a;
    
    cout<<pA->fn()<<endl; /* 1 */
    cout<<pB->fn()<<endl; /* 2 */
    cout<<pA->fv()<<endl; /* 3 */
    cout<<pB->fv()<<endl; /* 4 */
    
    cout<<"-----------"<<endl;
    // b)
    B b;
    
    
    cout<<a.fn()<<endl;
    cout<<a.fv()<<endl;
    cout<<b.fn()<<endl;
    cout<<b.fv()<<endl;
    
    
    
    C c; /* 7 */
}