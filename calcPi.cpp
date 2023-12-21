#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/math/special_functions/factorials.hpp>

using boost::multiprecision::cpp_dec_float_50;

int main() 
{
    cpp_dec_float_50 sum = 0;

    for (int k = 0; k < 100; ++k) 
    {
        cpp_dec_float_50 numerator = boost::math::factorial<cpp_dec_float_50>(4 * k) * (1103 + 26390 * k);
        cpp_dec_float_50 denominator = pow(boost::math::factorial<cpp_dec_float_50>(k), 4) * pow(396, 4 * k);
        sum += numerator / denominator;
    }

    cpp_dec_float_50 result = 1 / ((2 * sqrt(2) / 9801) * sum);
    cpp_dec_float_50 pi_boost = boost::math::constants::pi<cpp_dec_float_50>();

    std::cout << "Ramanujan : " << result << std::endl;
    std::cout << "Pi boost: " << pi_boost << std::endl;

    return 0;
}


