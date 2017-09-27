/**
 * <h1>IfExecutor</h1>
 *
 * <p>Execute an IF statement.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <vector>
#include "WhenExecutor.h"
#include "StatementExecutor.h"
#include "ExpressionExecutor.h"
#include "../../../DataValue.h"
#include "../../../intermediate/ICodeNode.h"
#include "../../../intermediate/icodeimpl/ICodeNodeImpl.h"

namespace wci { namespace backend { namespace interpreter { namespace executors {

using namespace std;
using namespace wci;
using namespace wci::backend::interpreter;
using namespace wci::intermediate;
using namespace wci::intermediate::icodeimpl;

WhenExecutor::WhenExecutor(Executor *parent)
    : StatementExecutor(parent)
{
}

DataValue *WhenExecutor::execute(ICodeNode *node)
{
    // Get the IF node's children.
    vector<ICodeNode *> children = node->get_children();
    vector<ICodeNode *> left_stmt;
    vector<ICodeNode *> right_stmt;
    vector<ICodeNode *> otherwise_stmt;
    for(int i = 0; i < children.size()-2; )
    {
        if(children[i]->get_type() == (ICodeNodeType)NT_OTHERWISE){
            otherwise_stmt.push_back(children[i]);
            i = i + 1;
        } else if(children[i]->get_type() == (ICodeNodeType)NT_WHEN_BRANCH)
        {
            left_stmt.push_back(children[i]);
            right_stmt.push_back(children[i+1]);
            i = i + 2;
        } 

    }

    ExpressionExecutor expression_executor(this);
    StatementExecutor statement_executor(this);

    // Evaluate the expression to determine which statement to execute.
    for( int i = 0; i < left_stmt.size()+otherwise_stmt.size(); i = i++)
    {
        DataValue *data_value = expression_executor.execute(left_stmt[i]);
        if (data_value->b)
        {
            statement_executor.execute(right_stmt[i]);
        }
        else if (otherwise_stmt[i] != nullptr)
        {
            statement_executor.execute(otherwise_stmt[i]);
        }

        ++execution_count;  // count the WHEN_BRANCH(technically) statement itself
    }
    return nullptr;
}

}}}}  // namespace wci::backend::interpreter::executors
