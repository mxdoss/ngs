/*===========================================================================
*
*                            PUBLIC DOMAIN NOTICE
*               National Center for Biotechnology Information
*
*  This software/database is a "United States Government Work" under the
*  terms of the United States Copyright Act.  It was written as part of
*  the author's official duties as a United States Government employee and
*  thus cannot be copyrighted.  This software/database is freely available
*  to the public for use. The National Library of Medicine and the U.S.
*  Government have not placed any restriction on its use or reproduction.
*
*  Although all reasonable efforts have been taken to ensure the accuracy
*  and reliability of the software and data, the NLM and the U.S.
*  Government do not and cannot warrant the performance or results that
*  may be obtained by using this software or data. The NLM and the U.S.
*  Government disclaim all warranties, express or implied, including
*  warranties of performance, merchantability or fitness for any particular
*  purpose.
*
*  Please cite the author in any work or product based on this material.
*
* ===========================================================================
*
*/

#include "py_ReadGroupItf.h"
#include "py_ErrorMsg.hpp"

#include <ngs/itf/ReadGroupItf.hpp>

PY_RES_TYPE PY_NGS_ReadGroupGetName ( void* pRef, void** pRet, void** ppNGSStrError )
{
    PY_RES_TYPE ret = PY_RES_ERROR; // TODO: use xt_* codes
    try
    {
        void* res = CheckedCast< ngs::ReadGroupItf* >(pRef) -> getName ();
        assert (pRet != NULL);
        *pRet = (void*) res;
        ret = PY_RES_OK;
    }
    catch ( ngs::ErrorMsg & x )
    {
        ret = ExceptionHandler ( x, ppNGSStrError );
    }
    catch ( std::exception & x )
    {
        ret = ExceptionHandler ( x, ppNGSStrError );
    }
    catch ( ... )
    {
        ret = ExceptionHandler ( ppNGSStrError );
    }

    return ret;
}


#if READ_GROUP_SUPPORTS_READS
    GEN_PY_FUNC_GET_BY_PARAMS1   ( ReadGroup, Read, ngs::ReadItf*, char const*, readId )
    GEN_PY_FUNC_GET_BY_PARAMS1   ( ReadGroup, Reads, ngs::ReadItf*, uint32_t, categories )
#endif
PY_RES_TYPE PY_NGS_ReadGroupGetStatistics ( void* pRef, void** pRet, void** ppNGSStrError )
{
    PY_RES_TYPE ret = PY_RES_ERROR; // TODO: use xt_* codes
    try
    {
        ngs::StatisticsItf* res = CheckedCast< ngs::ReadGroupItf* >(pRef) -> getStatistics ();
        assert (pRet != NULL);
        *pRet = (void*) res;
        ret = PY_RES_OK;
    }
    catch ( ngs::ErrorMsg & x )
    {
        ret = ExceptionHandler ( x, ppNGSStrError );
    }
    catch ( std::exception & x )
    {
        ret = ExceptionHandler ( x, ppNGSStrError );
    }
    catch ( ... )
    {
        ret = ExceptionHandler ( ppNGSStrError );
    }

    return ret;
}

