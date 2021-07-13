#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;

class Solution
{
    public:
    //Function to find the nth catalan number.
   
    cpp_int findCatalan(int n) 
    {
    cpp_int cat_ = 1;

	for (cpp_int i = 1; i <= n; i++)
	    {
		cat_ *= (4 * i - 2);
		cat_ /= (i + 1);
		if(i==n)
		return cat_;
	    }
	
        
    }
};
