#include <cassert>
#include <iostream>
#include <array>

class Fraction{
        private:
                int m_numerator{};
                int m_denominator{};
        public:
        Fraction(int numerator =0,int denominator =1)
                :m_numerator{numerator},m_denominator{denominator}
                {
                assert (denominator !=0);
                }
        Fraction(const Fraction& fract)
                :m_numerator{fract.m_numerator},m_denominator{fract.m_denominator}
                {
                std::cout<<"Copy constr called "<<'\n';
                }
        friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

        std::ostream& operator<<(std::ostream& out, const Fraction& f1)
        {
                out<<f1.m_numerator<<'/'<<f1.m_denominator;
                return out;
        }

/*class Point3d{
        private:
           double m_x{};
           double m_y{};
           double m_z{};
        public:
           Point3d (double x=0.0,double y=0.0, double z=0.0)
           : m_x{x},m_y{y},m_z{z}
           {}
        friend std::ostream& operator<<(std::ostream& out, const Point3d& point);
};
        std::ostream& operator<<(std::ostream& out, const Point3d& point){
                out<<"Point3d (" << point.m_x<<' '<<point.m_y<<' '<<point.m_z<<" )"<<'\n';
                return out;
        }

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
      void doesStuff operator-(const Cents& c1, int vale){
                        std::cout<<"i did Stuff"<<'\n';
      }*/  

main(){
        Fraction fiveThirds {5,3};
        Fraction fCopy {fiveThirds};
        std::cout<<fCopy<<'\n';

        /*Point3d point1{1.1,2.2,3.3};
        std::cout<<point1<<'\n';
        Cents c1{ Cents{ 4 } + 6 };
	Cents c2{ 6 + Cents{ 4 } };

        
	std::cout << "I have " << c1.getCents() << " cents.\n";
	std::cout << "I have " << c2.getCents() << " cents.\n";*/
        return 0;
};