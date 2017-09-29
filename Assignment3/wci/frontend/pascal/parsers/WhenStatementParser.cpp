/**
 * <h1>WhenStatementParser</h1>
 *
 * <p>Parse a Pascal IF statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <set>
#include "WhenStatementParser.h"
#include "StatementParser.h"
#include "AssignmentStatementParser.h"
#include "ExpressionParser.h"
#include "../PascalParserTD.h"
#include "../PascalToken.h"
#include "../PascalError.h"
#include "../../Token.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/ICodeFactory.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

bool WhenStatementParser::INITIALIZED = false;

set<PascalTokenType> WhenStatementParser::RIGHT_ARROW_SET;

void WhenStatementParser::initialize()
{
    if (INITIALIZED) return;

    RIGHT_ARROW_SET = StatementParser::STMT_START_SET;
    RIGHT_ARROW_SET.insert(PascalTokenType::RIGHT_ARROW);

    set<PascalTokenType>::iterator it;
    for (it  = StatementParser::STMT_FOLLOW_SET.begin();
         it != StatementParser::STMT_FOLLOW_SET.end();
         it++)
    {
        RIGHT_ARROW_SET.insert(*it);
    }

    INITIALIZED = true;
}

WhenStatementParser::WhenStatementParser(PascalParserTD *parent)
    : StatementParser(parent)
{
    initialize();
}

ICodeNode *WhenStatementParser::parse_statement(Token *token) throw (string)
{
    token = next_token(token);  // consume the when

    // Create an WHEN_BRANCH node.
    ICodeNode *when_node =
            ICodeFactory::create_icode_node((ICodeNodeType) NT_WHEN);



    ExpressionParser expression_parser(this);
    StatementParser statement_parser(this);
    //when_node->add_child(expression_parser.parse_statement(token));

    
    while ((token != nullptr) &&
           (token->get_type() != (TokenType) PT_OTHERWISE))
    {
        when_node->add_child(expression_parser.parse_statement(token));

        token = current_token();
    if (token->get_type() == (TokenType) PT_RIGHT_ARROW)
    {
        token = next_token(token);  // consume the :
    }
    else
    {
        error_handler.flag(token, MISSING_RIGHT_ARROW, this);
    }

    when_node->add_child(statement_parser.parse_statement(token));

    token = current_token();

    // Look for the semicolon between CASE branches.
    if (token->get_type() == (TokenType) PT_SEMICOLON)
    {
        token = next_token(token);  // consume the ;
    }

    // If at the start of the next constant, then missing a semicolon.
    else 
    {
        error_handler.flag(token, MISSING_SEMICOLON, this);
    }        
        
    }

    if (token->get_type() == (TokenType) PT_OTHERWISE)
    {
            token = next_token(token);  // consume Otherwise
        if (token->get_type() == (TokenType) PT_RIGHT_ARROW)
        {
            token = next_token(token);  // consume the =>
        }
        else
        {
            error_handler.flag(token, MISSING_RIGHT_ARROW, this);
        }

        when_node->add_child(statement_parser.parse_statement(token));
    }
      

    if (token->get_type() == (TokenType) PT_END)
    {
        token = next_token(token);  // consume Otherwise
        if (token->get_type() == (TokenType) PT_SEMICOLON)
        {
            token = next_token(token);  // consume the ;
        }

        // If at the start of the next constant, then missing a semicolon.
        else 
        {
            error_handler.flag(token, MISSING_SEMICOLON, this);
        }   
    }
     else 
    {
        error_handler.flag(token, MISSING_END, this);
    }


    return when_node;


    // // Synchronize at the RIGHT_ARROW.
    // token = synchronize(RIGHT_ARROW_SET);
    // if (token->get_type() == (TokenType) PT_RIGHT_ARROW)
    // {
    //     token = next_token(token);  // consume the =>
    // }
    // else {
    //     error_handler.flag(token, MISSING_RIGHT_ARROW, this);
    // }

    // // Parse the RIGHT statement.
    // // The WHEN node adopts the statement subtree as its second child.
    // StatementParser statement_parser(this);
    // when_node->add_child(statement_parser.parse_statement(token));
    // token = current_token();

    // // Look for an SEMICOLON
    // if (token->get_type() == (TokenType) PT_SEMICOLON)
    // {
    //     token = next_token(token);  // consume the SC

    //     // Parse the ELSE statement.
    //     // The IF node adopts the statement subtree as its third child.
    //     when_node->add_child(statement_parser.parse_statement((Token*)PT_WHEN));
    // }
    // else{
    //     if(token->get_type() == (TokenType) PT_END){
    //         token = next_token(token);                          // consume END
    //         if(token->get_type() == (TokenType) PT_SEMICOLON){}
    //         else{error_handler.flag(token, MISSING_SEMICOLON, this);}
    //     }
    //     else{error_handler.flag(token, MISSING_END, this);}
    //     token = next_token(token);                              // consume Semicolon or bad token
    // }

    // return when_node;
}

}}}}