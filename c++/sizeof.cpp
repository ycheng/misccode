#include <iostream>

using namespace std;

int
main() {
	cout << "sizeof( " << "short    " << " ) is " << sizeof(short) << endl;
	cout << "sizeof( " << "int      " << " ) is " << sizeof(int) << endl;
	cout << "sizeof( " << "long     " << " ) is " << sizeof(long) << endl;
	cout << "sizeof( " << "long long" << " ) is " << sizeof(long long) << endl;
	cout << "sizeof( " << "int8_t   " << " ) is " << sizeof(int8_t) << endl;
	cout << "sizeof( " << "int16_t  " << " ) is " << sizeof(int16_t) << endl;
	cout << "sizeof( " << "int32_t  " << " ) is " << sizeof(int32_t) << endl;
	cout << "sizeof( " << "int64_t  " << " ) is " << sizeof(int64_t) << endl;

	return 0;
}
