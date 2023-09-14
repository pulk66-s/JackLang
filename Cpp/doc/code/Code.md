# Code

## Introduction

This is the code documentation of the project. This compiler is written in C++. It's using a recursive descent parser. The code is divided into 3 parts:

- CPT: Concrete Parse Tree, it's the grammar of the language.
- AST: Abstract Syntax Tree, it's the representation of the program. Once the CPT is done it will be converted into an AST that will make the code generation easier and faster.
- Codegen: Code generation, it's the part that will generate the binary from the AST. For now it's only generating LLVM IR.

## CPT

the CPT is the grammar of the language. It's a tree that contains the parser behavior. The CPT is splitted in two parts, the Packrat and the Grammar, the Packrat is the part that will parse the input and the Grammar is the part that will define the language.

- [Packrat](Packrat.md)
- [Grammar](Grammar.md)
