#include <iostream>
#include <array>

class Cents{
        private:
                int m_cents{};
        public:
                Cents(int cents){m_cents = cents;}
                friend Cents operator+(const Cents& c1, int value);
                friend Cents operator+(int value, const Cents& c1);

                int getCents() const {return m_cents;}
};
                Cents operator+(const Cents& c1, int value){
                        return c1.m_cents + value;
                }
                Cents operator+(int value, const Cents& c1){
                        return  value + c1.m_cents;
                }
        

main(){
        Cents c1{ Cents{ 4 } + 6 };
	Cents c2{ 6 + Cents{ 4 } };

	std::cout << "I have " << c1.getCents() << " cents.\n";
	std::cout << "I have " << c2.getCents() << " cents.\n";
        return 0;
};