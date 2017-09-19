/*
 * JavaToken.h
 *
 *  Created on: Sep 13, 2017
 *      Author: Mohdi
 */

#ifndef WCI_FRONTEND_JAVA_JAVATOKEN_H_
#define WCI_FRONTEND_JAVA_JAVATOKEN_H_


#include <string>
#include <map>
#include "../Token.h"
#include "../Source.h"

namespace wci { namespace frontend { namespace java {

using namespace std;
using namespace wci::frontend;

/**
 * Pascal token types.
 */
enum class JavaTokenType
{

	// Reserved words.
	CASE, CONST, DO, ELSE, FOR, GOTO, IF, WHILE,
	ABSTRACT, DOUBLE, BREAK, ENUM, CHAR, EXTENDS,
	CLASS, FLOAT, CONTINUE, INT, NATIVE,
	RETURN, SHORT, PACKAGE, PROTECTED, STATIC,
	LONG, SWITCH, SUPER, THIS, THROW, VOID, VOLATILE,


	// Special symbols.
	TILDA, EXCLAIM, AT, MODULUS, POWER, AND, STAR, MINUS,
	PLUS, EQUAL, OR , F_SLASH, COLON, SEMI_COLON, Q_MARK,
	LESS_THAN, GREATER_THAN, DOT, D_QUOTE, S_QUOTE, L_PAR,
	R_PAR, L_BRACKET, R_BRACKET, L_BRACE, R_BRACE, PLUS_PLUS,
	MINUS_MINUS, SHIFT_L, COMMA, SHIFT_R, L_EQUAL, G_EQUAL, PLUS_EQUAL,
	C_COMMENT, MINUS_EQUAL, STAR_EQAUL, DIVIDE_EQAUL, EQAUL_EQAUL,
	OR_EQAUL, MODULUS_EQAUL, AND_EQAUL, POWER_EQAUL, NOT_EQUAL, SL_EQAUL,
	SR_EQAUL, OR_LOGICAL, AND_AND, FORWARD_SLASH_SLASH, O_COMMENT,

	IDENTIFIER, INTEGER, REAL, STRING,
	ERROR, END_OF_FILE,
};

// Reserved added by us
constexpr JavaTokenType PT_ABSTRACT = JavaTokenType::ABSTRACT;
constexpr JavaTokenType PT_DOUBLE = JavaTokenType::DOUBLE;
constexpr JavaTokenType PT_BREAK = JavaTokenType::BREAK;
constexpr JavaTokenType PT_ENUM = JavaTokenType::ENUM;
constexpr JavaTokenType PT_CHAR = JavaTokenType::CHAR;
constexpr JavaTokenType PT_EXTENDS = JavaTokenType::EXTENDS;
constexpr JavaTokenType PT_CLASS = JavaTokenType::CLASS;
constexpr JavaTokenType PT_FLOAT = JavaTokenType::FLOAT;
constexpr JavaTokenType PT_CONTINUE = JavaTokenType::CONTINUE;
constexpr JavaTokenType PT_INT = JavaTokenType::INT;
constexpr JavaTokenType PT_NATIVE = JavaTokenType::NATIVE;
constexpr JavaTokenType PT_RETURN = JavaTokenType::RETURN;
constexpr JavaTokenType PT_SHORT = JavaTokenType::SHORT;
constexpr JavaTokenType PT_PACKAGE = JavaTokenType::PACKAGE;
constexpr JavaTokenType PT_PROTECTED = JavaTokenType::PROTECTED;
constexpr JavaTokenType PT_STATIC = JavaTokenType::STATIC;
constexpr JavaTokenType PT_LONG = JavaTokenType::LONG;
constexpr JavaTokenType PT_SWITCH = JavaTokenType::SWITCH;
constexpr JavaTokenType PT_SUPER = JavaTokenType::SUPER;
constexpr JavaTokenType PT_THIS = JavaTokenType::THIS;
constexpr JavaTokenType PT_THROW = JavaTokenType::THROW;
constexpr JavaTokenType PT_VOID = JavaTokenType::VOID;
constexpr JavaTokenType PT_VOLATILE = JavaTokenType::VOLATILE;

// Special symbols by us
constexpr JavaTokenType PT_SL_EQAUL = JavaTokenType::SL_EQAUL;
constexpr JavaTokenType PT_SR_EQAUL = JavaTokenType::SR_EQAUL;
constexpr JavaTokenType PT_AND_AND = JavaTokenType::AND_AND;
constexpr JavaTokenType PT_FORWARD_SLASH_SLASH = JavaTokenType::FORWARD_SLASH_SLASH;
constexpr JavaTokenType PT_O_COMMENT = JavaTokenType::O_COMMENT;
constexpr JavaTokenType PT_DIVIDE_EQAUL = JavaTokenType::DIVIDE_EQAUL;
constexpr JavaTokenType PT_EQAUL_EQAUL = JavaTokenType::EQAUL_EQAUL;
constexpr JavaTokenType PT_OR_EQAUL = JavaTokenType::OR_EQAUL;
constexpr JavaTokenType PT_MODULUS_EQAUL = JavaTokenType::MODULUS_EQAUL;
constexpr JavaTokenType PT_AND_EQAUL = JavaTokenType::AND_EQAUL;
constexpr JavaTokenType PT_POWER_EQAUL = JavaTokenType::POWER_EQAUL;
constexpr JavaTokenType PT_TILDA = JavaTokenType::TILDA;
constexpr JavaTokenType PT_EXCLAIM = JavaTokenType::EXCLAIM;
constexpr JavaTokenType PT_AT = JavaTokenType::AT;
constexpr JavaTokenType PT_MODULUS = JavaTokenType::MODULUS;
constexpr JavaTokenType PT_Q_MARK = JavaTokenType::Q_MARK;
constexpr JavaTokenType PT_PLUS_PLUS = JavaTokenType::PLUS_PLUS;
constexpr JavaTokenType PT_MINUS_MINUS = JavaTokenType::MINUS_MINUS;
constexpr JavaTokenType PT_SHIFT_L = JavaTokenType::SHIFT_L;
constexpr JavaTokenType PT_SHIFT_R = JavaTokenType::SHIFT_R;
constexpr JavaTokenType PT_PLUS_EQUAL = JavaTokenType::PLUS_EQUAL;
constexpr JavaTokenType PT_C_COMMENT = JavaTokenType::C_COMMENT;
constexpr JavaTokenType PT_MINUS_EQUAL = JavaTokenType::MINUS_EQUAL;
constexpr JavaTokenType PT_STAR_EQAUL = JavaTokenType::STAR_EQAUL;

constexpr JavaTokenType PT_AND = JavaTokenType::AND;
constexpr JavaTokenType PT_CASE = JavaTokenType::CASE;
constexpr JavaTokenType PT_CONST = JavaTokenType::CONST;
constexpr JavaTokenType PT_DO = JavaTokenType::DO;

constexpr JavaTokenType PT_ELSE = JavaTokenType::ELSE;
constexpr JavaTokenType PT_FOR = JavaTokenType::FOR;
constexpr JavaTokenType PT_GOTO = JavaTokenType::GOTO;
constexpr JavaTokenType PT_IF = JavaTokenType::IF;

constexpr JavaTokenType PT_NOT = JavaTokenType::EXCLAIM;
constexpr JavaTokenType PT_OR = JavaTokenType::OR;

constexpr JavaTokenType PT_WHILE = JavaTokenType::WHILE;

constexpr JavaTokenType PT_PLUS = JavaTokenType::PLUS;
constexpr JavaTokenType PT_MINUS = JavaTokenType::MINUS;
constexpr JavaTokenType PT_STAR = JavaTokenType::STAR;
constexpr JavaTokenType PT_SLASH = JavaTokenType::F_SLASH;
constexpr JavaTokenType PT_DOT = JavaTokenType::DOT;
constexpr JavaTokenType PT_COMMA = JavaTokenType::COMMA;
constexpr JavaTokenType PT_SEMICOLON = JavaTokenType::SEMI_COLON;
constexpr JavaTokenType PT_COLON = JavaTokenType::COLON;
constexpr JavaTokenType PT_DQUOTE = JavaTokenType::D_QUOTE;
constexpr JavaTokenType PT_QUOTE = JavaTokenType::S_QUOTE;

constexpr JavaTokenType PT_EQUALS = JavaTokenType::EQUAL;
constexpr JavaTokenType PT_NOT_EQUALS = JavaTokenType::NOT_EQUAL;

constexpr JavaTokenType PT_LESS_THAN = JavaTokenType::LESS_THAN;
constexpr JavaTokenType PT_LESS_EQUALS = JavaTokenType::L_EQUAL;
constexpr JavaTokenType PT_GREATER_EQUALS = JavaTokenType::G_EQUAL;
constexpr JavaTokenType PT_GREATER_THAN = JavaTokenType::GREATER_THAN;
constexpr JavaTokenType PT_LEFT_PAREN = JavaTokenType::L_PAR;
constexpr JavaTokenType PT_RIGHT_PAREN = JavaTokenType::R_PAR;
constexpr JavaTokenType PT_LEFT_BRACKET = JavaTokenType::L_BRACKET;
constexpr JavaTokenType PT_RIGHT_BRACKET = JavaTokenType::R_BRACKET;
constexpr JavaTokenType PT_LEFT_BRACE = JavaTokenType::L_BRACE;
constexpr JavaTokenType PT_RIGHT_BRACE = JavaTokenType::R_BRACE;
constexpr JavaTokenType PT_UP_ARROW = JavaTokenType::POWER;

constexpr JavaTokenType PT_IDENTIFIER = JavaTokenType::IDENTIFIER;
constexpr JavaTokenType PT_INTEGER = JavaTokenType::INTEGER;
constexpr JavaTokenType PT_REAL = JavaTokenType::REAL;
constexpr JavaTokenType PT_STRING = JavaTokenType::STRING;
constexpr JavaTokenType PT_ERROR = JavaTokenType::ERROR;
constexpr JavaTokenType PT_END_OF_FILE = JavaTokenType::END_OF_FILE;

class JavaToken : public Token
{
public:
	static map<string, JavaTokenType> RESERVED_WORDS;
	static map<string, JavaTokenType> SPECIAL_SYMBOLS;
	static map<JavaTokenType, string> SPECIAL_SYMBOL_NAMES;

protected:
	/**
	 * Constructor.
	 * @param source the source from where to fetch the token's characters.
	 * @throw a string message if an error occurred.
	 */
	JavaToken(Source *source) throw (string);

private:
	static bool INITIALIZED;

	/**
	 * Initialize the static maps.
	 */
	static void initialize();
};

}}}  // namespace wci::frontend::pascal



#endif /* WCI_FRONTEND_JAVA_JAVATOKEN_H_ */
