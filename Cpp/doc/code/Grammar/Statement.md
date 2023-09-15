# Grammar Statement

Statement is a class that represent a function line, it's pure action, not condition, not function declaration or other, everything that end with a semicolon is a statement

As you can see in the [language grammar](../../usage/Grammar.md),
a type looks like:

```
statement:
    variable_decl
    ';'
```
We can see that's ending with a semicolon

## Code

Here is the prototype of the SpecialChar
```hpp
namespace CPT::Grammar
{
    class Statement : public Packrat::IExpr
    {
    public:
        Statement() {};
        Statement(Packrat::IExpr *expr): expr(expr) {}
        struct result *parse(Packrat::Parser &p);
        enum cpt_type type() { return CPT_UNKNOWN; };

    private:
        Packrat::IExpr *expr = nullptr;
    };
} // namespace CPT::Grammar
```

The class inherit from the [Packrat::IExpr](../Packrat/IExpr.md) class that obligate the class to implement the `parse` and `type` methods. The parsed value is stored in the `c` attribute.

## Parsing strategy

- Save the current position
- Make an [ordered choice](../Packrat/OrderedChoice.md) between
    - [VariableDecl](VariableDecl.md)
        - if it fails, it's rolling back and return a failure
        - if it succeed, continue
- Commit the changes and return the result
