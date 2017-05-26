/* === Before Getting Started === */
/* Lambda's Notation
 * [capture] (list-of-arguments) {function-body};
 * auto keyword
 */

/* === Getting Started === */
/*
 * Write an **Identity** function
 * identity(3) // 3
 */
auto identity = [](auto x)
{
    return x;
};

/*
 * Write a **Sum** function
 * add(3,4) // 7
 */
auto add = [](auto x, auto y)
{
    return x + y;
};

/*
 * Write a **Difference** function
 * sub(4,3) // 1
 */
auto sub = [](auto x, auto y)
{
    return x - y;
};

/*
 * Write a **product** function
 * mul(4,5) // 20
 */
auto mul = [](auto x, auto y)
{
    return x *y;
};

/* === Functions as First-class Citizens === */
/*
 *  Write a function, **identityf**, that takes
 *  an argument and returns a function
 *  that returns that argument.
 *  identityf(5)() // 5
 */
auto identityf = [](auto x)
{
    return [=]()
    {
        return x;
    };
};

/*
 *  Write a function,**addf**
 *  that adds from two invocations.
 *  addf(5)(4) // 9
 */
auto addf = [](auto x)
{
    return [=](auto y)
    {
        return add(x,y);
    };
};

/*
 *  Write a function,**swap** that swaps
 *  the arguments of a binary function.
 *  swap(sub)(3, 2) // -1
 */
auto swap = [](auto binary)
{
    return [=](auto x, auto y)
    {
        return binary(y,x);
    };
};

/*
 *  Write a function,**twice** that takes a binary function
 *  and returns a unary function that its
 *  argument to the binary function twice.
 *  twice(add)(11) // 22
 */
auto twice = [](auto binary)
{
    return [=](auto x)
    {
        return binary(x,x);
    };
};

/*
 *  Write a function, **applyf** that takes a
 *  binary function
 *  and makes it callable with two invocations.
 *  applyf(mul)(3)(4) // 12
 */
auto applyf = [](auto binary)
{
    return [=](auto x)
    {
      return [=](auto y)
      {
          return binary(x,y);
      };
    };
};

/*
 *  Write a function, **curry** that takes a binary
 *  function and an argument and  returns a function
 *  that takes the second argument and applies the function.
 *  curry(mul, 3)(4) // 12
 */
auto curry = [](auto binary, auto x)
{
    return [=](auto y)
    {
        return binary(x,y);
    };
};


/*
 *  Write a function, **increment** that takes
 *  one parameter.
 *  Try to use previous functions
 *  increment(19) // 20
 */
auto increment = curry(add,1);

/*
 *  Write a function, **binaryCallback** that
 *  takes a binary function
 *  and returns a function that takes two
 *  arguments and a callback.
 *  binaryCallback(mul)(5, 6, inc)
 */
auto binaryCallback = [](auto binary)
{
    return [=](auto x, auto y, auto cb)
    {
        return cb(binary(x,y));
    };
};

/*
 * Compose N Functions
 */
template<class F>
auto compose(F function)
{
    return [=](auto x)
    {
        return function(x);
    };
}

template<class F, class ...Args>
auto compose(F function, Args... args)
{
    return [=](auto x)
    {
        return function(compose(args...)(x));
    };
};