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
#include "CompoundStatementParser.h"
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
    RIGHT_ARROW_SET.insert(PascalTokenType::END);
    RIGHT_ARROW_SET.insert(PascalTokenType::OTHERWISE);

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
    ICodeNode *when_node = ICodeFactory::create_icode_node((ICodeNodeType) NT_WHEN);
    ICodeNode *when_branch_node = ICodeFactory::create_icode_node((ICodeNodeType) NT_WHEN_BRANCH);
    ICodeNode *otherwise_node = ICodeFactory::create_icode_node((ICodeNodeType) NT_OTHERWISE);
    //cout << "------->" << token->get_text() << endl;

    when_node->add_child(when_branch_node);
    when_branch_node->add_child(otherwise_node);

    ExpressionParser expression_parser(this);
    StatementParser statement_parser(this);
    AssignmentStatementParser assignment_parser(this);
    CompoundStatementParser compound_parser(this);
    //when_node->add_child(expression_parser.parse_statement(token));

    
    while ((token != nullptr) &&
           (token->get_type() != (TokenType) PT_OTHERWISE))
    {
            when_branch_node->add_child(expression_parser.parse_statement(token));

            token = current_token();
            token = synchronize(RIGHT_ARROW_SET);
        if (token->get_type() == (TokenType) PT_RIGHT_ARROW)
        {
            token = next_token(token);  // consume the :
        }
        else
        {
            error_handler.flag(token, MISSING_RIGHT_ARROW, this);
        }

        token = synchronize(RIGHT_ARROW_SET);
        if(token->get_type() == ((TokenType) PT_BEGIN))
        {
            when_branch_node->add_child(compound_parser.parse_statement(token));
        } else
        {
            when_branch_node->add_child(assignment_parser.parse_statement(token));
        }

        token = current_token();

        // Look for the semicolon between CASE branches.
        token = synchronize(RIGHT_ARROW_SET);
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

    token = synchronize(RIGHT_ARROW_SET);
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
        //cout << token->get_text() << endl;
        otherwise_node->add_child(statement_parser.parse_statement(token));
        //cout << token->get_text() << endl;
        //token = next_token(token);
    }
      
    token = synchronize(RIGHT_ARROW_SET);
    if (token->get_type() == (TokenType) PT_END)
    {
        token = next_token(token);  // consume semicolon
        //cout << token->get_text() << endl;
        if (token->get_type() == (TokenType) PT_SEMICOLON)
        {
            //token = next_token(token);  // consume the ;
            //cout << token->get_text() << endl;
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
    //cout << token->get_text() << endl;

    return when_node;

}

}}}}