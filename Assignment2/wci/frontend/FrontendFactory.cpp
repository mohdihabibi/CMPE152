/**
 * <h1>FrontendFactory</h1>
 *
 * <p>A factory class that creates parsers for specific source languages.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "FrontendFactory.h"

#include "java/JavaParserTD.h"
#include "java/JavaScanner.h"
#include "Parser.h"
#include "Scanner.h"
#include "Source.h"
#include "pascal/PascalParserTD.h"
#include "pascal/PascalScanner.h"
namespace wci { namespace frontend {

using namespace wci::frontend::pascal;
using namespace wci::frontend::java;

Parser *FrontendFactory::create_parser(string language, string type,
                                       Source *source)
    throw (string)
{
    if ((language == "Pascal") && (type == "top-down"))
    {
        Scanner *scanner = new PascalScanner(source);
        return new PascalParserTD(scanner);
    }
    else if ((language == "Java") && (type == "top-down"))
        {
            Scanner *scanner = new JavaScanner(source);
            return new JavaParserTD(scanner);
        }
//    else if ((language != "Pascal") && (language != "Java")) {
//        throw new string("Parser factory: Invalid language '" +
//                         language + "'");
//    }
    else {
        throw new string("Parser factory: Invalid type '" +
                         type + "'");
    }
}

}} // namespace wci::frontend
