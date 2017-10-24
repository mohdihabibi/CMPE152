/**
 * <h1>ComlexTypeParser</h1>
 *
 * <p>Parse a Pascal complex type specification.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */                                                              // NEW USED RECORD AND CHANGED TO COMPLEX
#include <set>
#include "ComplexTypeParser.h"
#include "DeclarationsParser.h"
#include "TypeSpecificationParser.h"
#include "VariableDeclarationsParser.h"
#include "../../../frontend/Token.h"
#include "../../../frontend/pascal/PascalToken.h"
#include "../../../frontend/pascal/PascalError.h"
#include "../../../intermediate/TypeFactory.h"
#include "../../../intermediate/symtabimpl/SymTabEntryImpl.h"
#include "../../../intermediate/typeimpl/TypeSpecImpl.h"
#include "../../../intermediate/SymTabEntry.h"
#include "../../../intermediate/symtabimpl/Predefined.h"        // NEW
#include "../../../intermediate/ICodeNode.h"                    // NEW



namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::symtabimpl;
using namespace wci::intermediate::typeimpl;

bool ComplexTypeParser::INITIALIZED = false;

set<PascalTokenType> ComplexTypeParser::END_SET;

void ComplexTypeParser::initialize()
{
    if (INITIALIZED) return;

    DeclarationsParser::initialize();
    END_SET = DeclarationsParser::VAR_START_SET;
    END_SET.insert(PascalTokenType::COMPLEX);                  // NEW
//    END_SET.insert(PascalTokenType::END);
//    END_SET.insert(PascalTokenType::SEMICOLON);

    INITIALIZED = true;
}

ComplexTypeParser::ComplexTypeParser(PascalParserTD *parent)
    : TypeSpecificationParser(parent)
{
    initialize();
}

TypeSpec *ComplexTypeParser::parse_declaration(Token *token) throw (string)
{
    TypeSpec *complex_typespec =
        TypeFactory::create_type((TypeForm) TypeFormImpl::COMPLEX);

    complex_typespec->set_identifier(Predefined::complex_id);
    // Push a symbol table for the COMPLEX type specification.
    complex_typespec->set_attribute((TypeKey) COMPLEX_SYMTAB,
                                   new TypeValue(symtab_stack->push()));
 //?   TypeSpec *typespec = Predefined::complex_type;

    // Parse the field declarations.
    // VariableDeclarationsParser variable_declarations_parser(this);
    // variable_declarations_parser.set_definition((Definition) DF_FIELD);
    // variable_declarations_parser.parse_declaration(token, nullptr);

    vector<SymTabEntry *> sublist;
    
  //  String name = "test";

//    SymTabEntry *id = nullptr; 
//    id = symtab_stack->enter_local("re");

 //   id->set_definition(ICodeNodeType::NT_VARIABLE);

    SymTabEntry *id = symtab_stack->enter_local("re");
    id->append_line_number(token->get_line_number());
    sublist.push_back(id);

    id = symtab_stack->enter_local("im");
    id->append_line_number(token->get_line_number());
    sublist.push_back(id);




//    id = symtab_stack->enter_local("im");
    id->set_definition((Definition) DF_TYPE);
//    id->append_line_number(token->get_line_number());
//    sublist.push_back(id);

    TypeSpec *typespec = Predefined::real_type;
//    TypeSpec *typespec = (TokenType)PT_REAL;
    for (SymTabEntry *variable_id : sublist)
    {
        variable_id->set_typespec(typespec);
    }



    token = next_token(token);  // consume COMPLEX

    // Pop off the complex's symbol table.
    symtab_stack->pop();

    // Synchronize at the END.
/*    token = synchronize(END_SET);

    // Look for the END.
    if (token->get_type() == (TokenType) PT_SEMICOLON)
    {
        token = next_token(token);  // consume END (;)
    }
    else
    {
        error_handler.flag(token, MISSING_SEMICOLON, this);
    }

*/    return complex_typespec;
}

}}}}  // namespace wci::frontend::pascal::parsers
