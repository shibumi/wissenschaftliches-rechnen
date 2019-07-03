//
// Christian Rebischke
// Matrikelnummer: 432108
//
// Sajedeh Majdi
// Matrikelnummer: 493981
//

#include <functional>
#include <numeric>
#include <vector>
#include <cmath>
#include <iostream>

/**
 * Our genericNorm template function, that shares the `accumulate` function from the STL with all other norms.
 *
 * @tparam T The type of our vector
 * @param vec Our vector with type T.
 * @param binop This function provides the binary operator for the accumulate function.
 * @param unop Provides the outer function for post-processing, for example sqrt() for the hilbert norm.
 * @return Result of the unop function with the accumulate function as shared function between all norms,
 * the vector as arguments with 0 as initialization and binop as binary operator for the accumulate function.
 */
template<typename T>
T genericNorm(
        std::vector<T> &vec,
        std::function<T(T, T)> binop,
        std::function<T(T)> unop
) {
    return unop(std::accumulate(vec.begin(), vec.end(), 0, binop));
}

/**
 * This lambda called `id` simply returns the identity.
 * We use lambda or closures here with the following syntax:
 * [ captures ] (parameters) -> returnTypesDeclaration { lambdaStatements; }
 *
 * The identity will be used in cases where we don't need a unop function.
 * So unop aka the identity will just pass the last value further.
 *
 * @tparam T The type of our vector
 */
template<typename T>
auto id = [](T x) {
    return x;
};

/**
 * Here we bind our arguments to the genericNorm<T> via std::bind().
 * We use the placeholder _1 to bind the first argument of the function call with the vector argument
 * in our genericNorm.
 * Furthermore we use lambdas to generate the necessary binary operator for the accumulator function.
 * As unop we use sqrt() for the hilbertNorm and simply the identity for all other norms, an unop function
 * is not needed there.
 * @tparam T
 */
template<typename T>
auto hilbertNorm = std::bind(genericNorm<T>, std::placeholders::_1, [](T x, T y) { return x + y * y; },
                             static_cast<T(*)(T)>(std::sqrt));

template<typename T>
auto sumNorm = std::bind(genericNorm<T>, std::placeholders::_1, [](T x, T y) { return x + std::abs(y); }, id<T>);

template<typename T>
auto maxNorm = std::bind(genericNorm<T>, std::placeholders::_1, [](T x, T y) { return std::max(x, std::abs(y)); },
                         id<T>);


/**
 * Smaller main function for testing
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char const *argv[]) {
    std::vector<double> v{1, 2, 3};
    std::cout << hilbertNorm<double>(v) << std::endl;
    std::cout << sumNorm<double>(v) << std::endl;
    std::cout << maxNorm<double>(v) << std::endl;

    return 0;
}