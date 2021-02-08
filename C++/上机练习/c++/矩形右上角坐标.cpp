#include <iostream>
using namespace std;
class point{
	public:
		void set_number();
	private:
		double x,y;
};
class rectangle:public point{
	public:
		void get_data();
	private:
		double length,wide;
};