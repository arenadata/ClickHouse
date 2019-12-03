#include "OnlyParseHandler.h"

#include <Interpreters/Context.h>
#include <Storages/StorageReplicatedMergeTree.h>
#include <Common/HTMLForm.h>
#include <Common/typeid_cast.h>
#include <Databases/IDatabase.h>
#include <IO/HTTPCommon.h>

#include <Parsers/ParserQuery.h>
#include <Parsers/ASTSetQuery.h>
#include <Parsers/ASTUseQuery.h>
#include <Parsers/ASTInsertQuery.h>
#include <Parsers/ASTSelectWithUnionQuery.h>
#include <Parsers/ASTQueryWithOutput.h>
#include <Parsers/ASTLiteral.h>
#include <Parsers/ASTIdentifier.h>
#include <Parsers/formatAST.h>
#include <Parsers/parseQuery.h>

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>


namespace DB
{


OnlyParseHandler::OnlyParseHandler(Context & context_)
    : context(context_)
{
}


void OnlyParseHandler::handleRequest(Poco::Net::HTTPServerRequest & request, Poco::Net::HTTPServerResponse & response)
{
    try
    {
        HTMLForm params(request);

        std::string query = params.get("query", "");
        const char* pos = query.c_str();
        const char* end = "";
        ParserQuery parser(end, true);

        String message;

        const ASTPtr &res = tryParseQuery(parser, pos, pos + query.size(), message, true, "", false, 0);
        std::string str;
        if (res) {
            std::ostringstream stream;
            formatAST(*res, stream);
            str = stream.str();
        }else {
            str = "ERROR";
        }

            const char * data = str.c_str();
            response.sendBuffer(data, strlen(data));

    }
    catch (...)
    {
        tryLogCurrentException("OnlyParseHandler");

        try
        {
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_INTERNAL_SERVER_ERROR);

            if (!response.sent())
            {
                /// We have not sent anything yet and we don't even know if we need to compress response.
                response.send() << getCurrentExceptionMessage(false) << std::endl;
            }
        }
        catch (...)
        {
            LOG_ERROR((&Logger::get("OnlyParseHandler")), "Cannot send exception to client");
        }
    }
}


}
