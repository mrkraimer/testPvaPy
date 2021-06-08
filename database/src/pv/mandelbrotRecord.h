/*
 * Copyright information and license terms for this software can be
 * found in the file LICENSE that is included with the distribution
 */

/**
 * @author mrk
 * @date 2013.04.02
 */
#ifndef MANDELBROTRECORD_H
#define MANDELBROTRECORD_H


#include <pv/pvDatabase.h>
#include <pv/timeStamp.h>
#include <pv/pvTimeStamp.h>

#include <shareLib.h>


namespace epics { namespace testPython {


class MandelbrotRecord;
typedef std::tr1::shared_ptr<MandelbrotRecord> MandelbrotRecordPtr;

/**
 * @brief A PVRecord that implements a hello service accessed via a channelPutGet request.
 *
 */
class epicsShareClass MandelbrotRecord :
    public epics::pvDatabase::PVRecord
{
public:
    POINTER_DEFINITIONS(MandelbrotRecord);
    /**
     * @brief Create an instance of MandelbrotRecord.
     *
     * @param recordName The name of the record.
     * @return The new instance.
     */
    static MandelbrotRecordPtr create(
        std::string const & recordName);
    /**
     *  @brief Implement hello semantics.
     */
    virtual void process();
    virtual ~MandelbrotRecord() {}
    virtual bool init() {return false;}
    void createImage();
private:
    MandelbrotRecord(std::string const & recordName,
        epics::pvData::PVStructurePtr const & pvStructure);     
    void expzCalc(double z[],int expz);
};


}}

#endif  /* MANDELBROTRECORD_H */
