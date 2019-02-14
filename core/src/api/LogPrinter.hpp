// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from logger.djinni

#ifndef DJINNI_GENERATED_LOGPRINTER_HPP
#define DJINNI_GENERATED_LOGPRINTER_HPP

#include <memory>
#include <string>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER)
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

class ExecutionContext;

/**
 * Class representing a printer of errors, warnings, infos ... (at runtime).
 * Printed logs are stored in path set by PathResolver::resolveLogFilePath.
 */
class LogPrinter {
public:
    virtual ~LogPrinter() {}

    /**
     * Print different encountered errors.
     * @param message, string
     */
    virtual void printError(const std::string & message) = 0;

    /**
     * Print useful information messages.
     * @param message, string
     */
    virtual void printInfo(const std::string & message) = 0;

    /**
     * Print debug messages.
     * @param message string
     */
    virtual void printDebug(const std::string & message) = 0;

    /**
     * Print warning messages.
     * @param message, string
     */
    virtual void printWarning(const std::string & message) = 0;

    /**
     * Print messages from APDU comand interpretation loop.
     * @param message, string
     */
    virtual void printApdu(const std::string & message) = 0;

    /**
     * Print critical errors causing a core dump or error from which recovery is impossible.
     * @param message, string
     */
    virtual void printCriticalError(const std::string & message) = 0;

    /**
     * Get context in which printer is executed (print).
     * @return ExecutionContext object
     */
    virtual std::shared_ptr<ExecutionContext> getContext() = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_LOGPRINTER_HPP
