# Grammar Value

A Value in the CL language a is either a [number](Number.md) or an [identifier](Identifier.md).

As you can see in the [language grammar](../../usage/Grammar.md),
a type looks like:
```
value: number | identifier
```

## Code

You can find the prototype of the function in the [Value.hpp](../../../src/CPT/Grammar/Value.hpp) file and the implementation in the [Value.cpp](Value.cpp) file.

Class prototype:
```hpp
namespace CPT::Grammar
{
    class Value : public Packrat::IExpr {
    public:
        Value();
        enum cpt_type type();
        struct result *parse(Packrat::Parser &p);
    };
} // namespace CPT::Grammar
```

The class inherit from the [Packrat::IExpr](../Packrat/IExpr.md) class that obligate the class to implement the `parse` and `type` methods. The parsed value is not stored in the class, it's returned in the [result](../Packrat/Result.md) structure.

## Parsing strategy

- Save the current position
- Make an [ordered choice](../Packrat/OrderedChoice.md) between:
  - [Number](Number.md)
  - [Identifier](Identifier.md)
    - If the parsing failed, return a failure
    - If the parsing succeed, continue
- Commit the changes and return the result
