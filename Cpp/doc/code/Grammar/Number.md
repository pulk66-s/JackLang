# Grammar Number

A number in the CL language is a sequence of digits that can be preceded by a minus sign. As you can see in the [language grammar](../../usage/Grammar.md), a number looks like:
```
number: sign? digit+

sign: '+' | '-'

digit: [0-9]
```

## Code

You can find the prototype of the function in the [Number.hpp](../../../src/CPT/Grammar//Number.hpp) file and the implementation in the [Number.cpp](Number.cpp) file.

Class prototype:
```hpp
namespace CPT::Grammar
{
    class Number : public Packrat::IExpr
    {
    public:
        Number(): value(0) {};
        Number(int value): value(value) {};
        struct result *parse(Packrat::Parser &p);
        int get();
        enum cpt_type type() { return CPT_NUMBER; }

    private:
        int value;
    };
};     // namespace CPT
```

The class inherit from the [Packrat::IExpr](../Packrat/IExpr.md) class that obligate the class to implement the `parse` and `type` methods. The parsed value is stored in the `value` attribute.

## Parsing strategy

- Save the current position
- Try to parse a sign ('-' or '+')
    - If it fails, go back to the saved position and continue
    - If it succeeds, save the sign in a variable (1 for '+', -1 for '-')
- Get a Packrat Number (see file: TODO)
    - If it fails, go back to the saved position and return a failure
    - If it succeeds, continue
- Multiply the number by the sign
- Commit the changes and return the result
