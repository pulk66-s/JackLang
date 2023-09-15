# Grammar Special Char

SpecialChar is a class that handle the char detection in the parsing.

## Code

Here is the prototype of the SpecialChar
```hpp
namespace CPT::Grammar
{
    class SpecialChar : public Packrat::IExpr
    {
    public:
        SpecialChar(char c);
        struct result *parse(Packrat::Parser &p);
        enum cpt_type type();
        char get();
    private:
        char c;
    };
} // namespace CPT
```

The class inherit from the [Packrat::IExpr](../Packrat/IExpr.md) class that obligate the class to implement the `parse` and `type` methods. The parsed value is stored in the `c` attribute.

The class constructor takes a char parameter that specify which char you want to parse, e.g.
```
SpecialChar('=').parse(p); // Want to parse an equal sign
SpecialChar('.').parse(p); // Want to parse a dot
```

## Parsing strategy

- Save the current position
- Get the next char
    - If the char is different from the wanted one, rollback and return a failure
    - If the char is the same as the wanted one, continue
- Commit the changes and return the result
