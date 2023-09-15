# Grammar Maybe Value

A MaybeValue in the class implementation of the [Packrat zero_or_one](../Packrat/ZeroOrOne.md) function but for the [value](Value.md), it's for using in other packrat function

## Code

You can find the prototype of the function in the [Number.hpp](../../../src/CPT/Grammar//Number.hpp) file and the implementation in the [Number.cpp](Number.cpp) file.

Class prototype:
```hpp
namespace CPT::Grammar
{
    class MaybeValue : public Packrat::IExpr {
    public:
        enum cpt_type type() { return CPT_UNKNOWN; };
        struct result *parse(Packrat::Parser &p);
    };
} // namespace CPT::Grammar
```

The class inherit from the [Packrat::IExpr](../Packrat/IExpr.md) class that obligate the class to implement the `parse` and `type` methods. The parsed value is not stored but returned in the `parse` method

## Parsing strategy

- Save the current position
- Try to get [zero or one](../Packrat/ZeroOrOne.md) [Value](Value.md)
    - If it success it commit and return the parsed class
    - If it fails it commit and return an instance of `MaybeValue` class
