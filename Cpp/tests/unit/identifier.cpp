#include <CppTester/Assert.hpp>
#include <CppTester/Tests.hpp>
#include "parse.hpp"
#include "CPT.hpp"

static void assert_identifier(struct CPT::result *res, std::string identifier)
{
    if (identifier == "") {
        expect(res).to.be.null();
    } else {
        expect(res->exprs.size()).to.be.equal(1);
        expect(res->exprs[0]->type()).to.be.equal(CPT::CPT_PROGRAM);

        CPT::Grammar::Program *program = (CPT::Grammar::Program *)res->exprs[0];
        expect(program->get().size()).to.be.equal(1);
        expect(program->get()[0]->type()).to.be.equal(CPT::CPT_IDENTIFIER);

        CPT::Grammar::Identifier *id = (CPT::Grammar::Identifier *)program->get()[0];
        expect(id->get()).to.be.equal(identifier);
    }
}

Test(Identifier, alpha) {
    struct CPT::result *res = parse_file("tests/files/identifiers/alpha.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "identifier");
}

Test(Identifier, alphaLowerCase) {
    struct CPT::result *res = parse_file("tests/files/identifiers/alphaLowerCase.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "identifierlowercase");
}

Test(Identifier, alphaMixedCase) {
    struct CPT::result *res = parse_file("tests/files/identifiers/alphaMixedCase.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "iDeNtIfIeRmIxEdCaSe");
}

Test(Identifier, alphaUpperCase) {
    struct CPT::result *res = parse_file("tests/files/identifiers/alphaUpperCase.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "IDENTIFIERUPPERCASE");
}

Test(Identifier, camelcase) {
    struct CPT::result *res = parse_file("tests/files/identifiers/camelcase.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "thisIsAnIdentifier");
}

Test(Identifier, dot) {
    struct CPT::result *res = parse_file("tests/files/identifiers/dot.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "");
}

Test(Identifier, empty) {
    struct CPT::result *res = parse_file("tests/files/identifiers/empty.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "");
}

Test(Identifier, firstUnderscore) {
    struct CPT::result *res = parse_file("tests/files/identifiers/firstUnderscore.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "_identifier");
}

Test(Identifier, letter) {
    struct CPT::result *res = parse_file("tests/files/identifiers/letter.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "f");
}

Test(Identifier, mixed) {
    struct CPT::result *res = parse_file("tests/files/identifiers/mixed.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "id3ntifier_");
}

Test(Identifier, number) {
    struct CPT::result *res = parse_file("tests/files/identifiers/number.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "");
}

Test(Identifier, pascalCase) {
    struct CPT::result *res = parse_file("tests/files/identifiers/pascalCase.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "ThisIsAnIdentifier");
}

Test(Identifier, snakeCase) {
    struct CPT::result *res = parse_file("tests/files/identifiers/snakeCase.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "this_is_an_identifier");
}

Test(Identifier, startDigit) {
    struct CPT::result *res = parse_file("tests/files/identifiers/startDigit.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "");
}

Test(Identifier, underscore) {
    struct CPT::result *res = parse_file("tests/files/identifiers/underscore.cl", [&](CPT::Packrat::Parser &parser) {
        return CPT::Grammar::Identifier().parse(parser);
    });

    assert_identifier(res, "_____");
}
