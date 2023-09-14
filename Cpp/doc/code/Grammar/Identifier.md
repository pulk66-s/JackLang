# Grammar Identifier

An Identifier in CL is a word that starts with a letter and can be followed by any letter, number or underscore. As you can see in the [language grammar](../../usage/Grammar.md), an identifier looks like:

```
identifier:
    ('a-z' | 'A-Z' | '_')
    ('a-z' | 'A-Z' | '0-9' | '_')*
```

## Code

You can find the prototype of the function in the [Identifier.hpp](../../../src/CPT/Grammar/Identifier.hpp) file and the implementation in the [Identifier.cpp](Identifier.cpp) file.

Class prototype:
```hpp
namespace CPT::Grammar
{
    class Identifier : public Packrat::IExpr
    {
    public:
        Identifier(): identifier("") {};
        Identifier(std::string identifier): identifier(identifier) {};
        struct result *parse(Packrat::Parser &p);
        enum cpt_type type() { return CPT_IDENTIFIER; };
        std::string get() { return identifier; };
    private:
        std::string identifier;
    };
} // namespace CPT
```

The class inherit from the [Packrat::IExpr](../Packrat/IExpr.md) class that obligate the class to implement the `parse` and `type` methods. The parsed value is stored in the `identifier` attribute.

## Parsing strategy

- Save the current position
- Get a [Packrat Identifier](TODO) that's an alpha letter followed by any alpha, number or underscore
    - If it fails, go back to the saved position and return a failure
    - If it succeeds, continue
- Commit the changes and return the result
