#include <cassert>
#include <iostream>
#include <array>
#include <numeric>
class Cents{
        private:
                int m_cents{};
        public:
                Cents(int cents){m_cents = cents;}
                
                Cents operator+(int value);

                friend bool operator>(const Cents& c1,const Cents& c2){
                        return c1.m_cents>c2.m_cents;                  }
                friend bool operator==(const Cents& c1,const Cents& c2){
                        return c1.m_cents==c2.m_cents;                  }

                friend Cents operator+(const Cents& c1, const Cents& c2){
                        return {c1.m_cents+c2.m_cents};                 }

                Cents operator-() const
                {
                        return {-m_cents};
                }

                friend std::ostream& operator<<(std::ostream& out, const Cents& c){
                        out<<"O_STREAM  "<<c.m_cents<<'\n';
                        return out;                                               }

                int getCents() const {return m_cents;}
};

class Point3d{
        private:
           double m_x{};
           double m_y{};
           double m_z{};
        public:
           Point3d (double x=0.0,double y=0.0, double z=0.0)
           : m_x{x},m_y{y},m_z{z}
           {}
        Point3d operator+() const{
                return {m_x,m_y,m_z};
        }
        friend std::ostream& operator<<(std::ostream& out, const Point3d& point);
};
        std::ostream& operator<<(std::ostream& out, const Point3d& point){
                out<<"Point3d (" << point.m_x<<' '<<point.m_y<<' '<<point.m_z<<" )"<<'\n';
                return out;
        }

class Fraction{
        private:
                
                
        public:
                int m_numerator{};
                int m_denominator{};
        Fraction(int numerator =0,int denominator =1)                          //FUCKING DUH ITS BEING PASSED IN
                :m_numerator{numerator},m_denominator{denominator}             //THEN UNIFORM DECLARATION
                {
                assert (denominator !=0);
                }
        Fraction(const Fraction& fract)
                :m_numerator{fract.m_numerator},m_denominator{fract.m_denominator}
                {
                                                                                        //std::cout<<fract<<" Copy constr called "<<'\n';
                }
        friend bool operator<(Fraction& f1, Fraction& f2){
                return (f1.m_numerator*f2.m_denominator<f2.m_numerator*f1.m_denominator);
                
                /*Fraction::multiLcm(f1,f2);
                                                                                        //std::cout<<"f1 : "<<'\t'<<f1<<'\n'<<"f2 : "<<'\t'<<f2<<'\n';
                return {f1.m_numerator<f2.m_numerator};*/
        }
        friend bool operator==(Fraction& f1, Fraction& f2){
                {       //Fraction::multiLcm(f1,f2);
                        return ((f1.m_numerator * f2.m_denominator )==(f1.m_denominator * f2.m_numerator)); 
                }
        }
        friend std::ostream& operator<<(std::ostream& out, const Fraction& f1){
                out<<f1.m_numerator<<'/'<<f1.m_denominator;
                return out;
        }
        friend std::istream& operator>>(std::istream& in, Fraction& f1){
                in>>f1.m_numerator;
                in>>f1.m_denominator;
                return in;
        }
        
        static void multiLcm(Fraction& f1,Fraction& f2){
                int lm  = std::lcm(f1.m_denominator, f2.m_denominator);
                
                f1*(lm/f1.m_denominator);
                f1.m_denominator = lm;
                f2*(lm/f2.m_denominator);
                f2.m_denominator = lm;
        }

        friend Fraction operator*(const Fraction& f1, const Fraction& f2)
        {       
                return {f1.m_numerator*f2.m_numerator,f1.m_denominator*f2.m_denominator};
        }
        friend Fraction operator*(Fraction& f1, int value)
        {       f1.m_numerator = f1.m_numerator*value;
                return f1;
        }
        friend Fraction operator/(const Fraction& f1, const Fraction& f2)
        {
               return {f1.m_numerator*f2.m_denominator,f1.m_denominator*f2.m_numerator};
        }
};
          
        template <typename T>
        T average(const T* myArray, int numValues)
        {
                T sum{0};
                for (int i=0;i<numValues;i++){
                        sum += myArray[i];
                }
                sum /= numValues;

                return sum;

        };

main(){
       
        Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << (!(f1 == f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << (!(f1 < f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << (((f1 == f2)||(f1<f2)) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << (((!(f1 < f2))||(f1 == f2)) ? " >= " : " not >= ") << f2 << '\n';
       
       
       /* Fraction f1{11,7};
        Fraction f2{7,5};
        std::cout<<"LCM & match denominator "<<f1<<' '<<f2<<'\n';
        std::cout<<"f1<f2 :"<<'\n'<<std::boolalpha<<(f1<f2)<<'\n'<<'\n';
       
       
       
       
       
       /*Point3d point1{-1.1,-2.2,-3.3};
        std::cout<<+point1<<'\n';
       */
       /* 
        Cents c1{8};
        Cents c2{8};
        bool b1{c1>c2};
        std::cout<<" c1 > c2 : "<<b1<<'\n';
        
        Cents centsArray[]{Cents{23},Cents{5},Cents{10},Cents{11},Cents{21}};
        std::cout<<average(centsArray,5)<<'\n';
        
        int myArray[]{1,5,8,2,16};
        std::cout<<average(myArray,5)<<'\n';
        double dubArray[]{1.1,4.6,3.5,8.8,10};
        std::cout<<"dub avg "<<average(dubArray,5);
        
        Cents nickle{5};
	Cents dime {10};
        Cents bigger = max(dime,nickle);
        std::cout<<" bigger is "<<bigger<<'\n';
        
	std::cout << "I have " << c1.getCents() << " cents.\n";
	std::cout << "I have " << c2.getCents() << " cents.\n";
        std::cout<<c2<<'\n';
        */
       
       /*
       Fraction f5;
       std::cout<<" Enter Numerator, space, Denominator, Enter "<<'\n';
       std::cin>>f5;
       std::cout<<f5;
        int x = std::gcd(f5.m_numerator,f5.m_denominator);
        std::cout<<"GCD "<<x<<'\n';
        
        Fraction f1 {1,2};
        Fraction f2 {1,4};
        Fraction f3 {f1*f2};
        std::cout<<f3<<'\n';
        Fraction f4 {f1/f2};
        std::cout<<f4<<'\n';
        //std::gcd(p, q);
        int x = std::gcd(f4.m_numerator,f4.m_denominator);
        */

        return 0;
};