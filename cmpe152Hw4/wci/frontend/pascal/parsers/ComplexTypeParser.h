/**
 * <h1>ComplexTypeParser</h1>
 *
 * <p>Parse a Pascal complex type specification.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef COMPLEXTYPEPARSER_H_
#define COMPLEXTYPEPARSER_H_                            // NEW USED RECORD AND CHANGED TO COMPLEX

#include <set>
#include "TypeSpecificationParser.h"

namespace wci { namespace frontend { namespace pascal { namespace parsers {

using namespace std;
using namespace wci::frontend::pascal;

class ComplexTypeParser : public TypeSpecificationParser
{
public:
    /**
     * Constructor.
     * @param parent the parent parser.
     */
    ComplexTypeParser(PascalParserTD *parent);

    /**
     * Parse a simple Pascal type specification.
     * @param token the current token.
     * @return the simple type specification.
     * @throw a string message if an error occurred.
     */
    TypeSpec *parse_declaration(Token *token) throw (string);

private:
    // Synchronization set for the END.
    static set<PascalTokenType> END_SET;

    static bool INITIALIZED;

    /**
     * Initialize the synchronization set.
     */
    static void initialize();
};

}}}}  // namespace wci::frontend::pascal::parsers

#endif /* COMPLEXTYPEPARSER_H_ */
