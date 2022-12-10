// oop5 part 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
public:
    Animal() {
        cout << "Animal is here\n";
    }
    virtual bool isA(const string &who) {
        return (who == "Animal");
    }

    virtual void sound() {
        cout << "Sound of some animal\n";
    }
    //part of tests
    void TestMetod1() {
        TestMetod2();
    }
    void TestMetod2() {
        cout << "test metod2 of parent is here\n ";
    }

    void TestMetodOfVirtual1() {
        TestMetodOfVirtual2();
    }

    virtual void TestMetodOfVirtual2() {
        cout << "virtual metod of parent";
    }

    /*~Animal() {
        cout << "Animal deleted\n";
    }*/
    virtual ~Animal() {
        cout << "Animal virtual deleted\n";
    };

};

class Cat:public Animal {
public:
    Cat() {
        cout << "Cat is here\n";
    };
    void sound() override{
        cout << "mew-mew\n";
        
    }
    
    void soundOfNature() {
        cout << "Sound of Nuture";
        Animal::sound();
    }
    
    void GoEatSomething() {
        cout << "so testy,mew\n";
    }
    bool isA(const string& who)override {
        return (who == "Cat")|| (who == "Animal");
    }
        
    //part of tests
    void TestMetod2() {
        cout << "test metod2 ovvireded in child\n";
    }

    void  TestMetodOfVirtual2() override {
        cout << "Overrided metod of virtual";
    }
    
    ~Cat() {
        cout << "cat deleted\n";
    };
};
class Dog:public Animal {
public:
    Dog() {
        cout << "dog is here\n";
    };
    void sound() override {
        cout << "wow-wow\n";
    }
    void GnawingBone() {
        cout << "hrhrhrhrhr,so testy,wow\n";
    }
    bool isA(const string& who) {
        return (who == "Animal")|| (who=="Dog");
    }
    ~Dog() {
        cout << "Dog deleted\n";
    };
};

int main()
{
    srand(time(NULL));


    Cat * c = new Cat();
    Animal *a = new Cat();
    c->sound();
    
    a->sound();
    cout << endl;
    c->soundOfNature();
    cout << endl;
    delete c;
    delete a;
    cout << endl;

    const int SizeOfZoo = 10;
    Animal* Zoo[SizeOfZoo];
    for (int i = 0; i < SizeOfZoo; i++) {
        if (rand() %2==0)
            Zoo[i] = new Cat();
        else
            Zoo[i] = new Dog();

    }
    for (int i = 0; i < SizeOfZoo; i++)
    {
        Dog* a = dynamic_cast<Dog*>(Zoo[i]);
        if (a != nullptr)
            a->GnawingBone();
    }

    cout << endl << "Static" << endl;
    for(int i = 0; i < SizeOfZoo; i++)
        if(Zoo[i]->isA("Dog"))
        static_cast <Dog*>(Zoo[i])-> GnawingBone();


    for (int i = 0; i < SizeOfZoo; i++) {
        delete Zoo[i];
    }


    cout << endl;
    //part of tests
    Cat* k = new Cat();
    k->TestMetod1();
    k->TestMetodOfVirtual1();
    delete k;
    
}

