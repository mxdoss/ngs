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

#ifndef _hpp_ngs_itf_error_msg_
#define _hpp_ngs_itf_error_msg_

#ifndef _h_ngs_itf_defs_
#include <ngs/itf/defs.h>
#endif

#include <exception>
#include <string>

namespace ngs
{

    /*----------------------------------------------------------------------
     * ErrorMsg
     *  a generic NGS error class
     *  holds a message describing what happened
     */
    class   ErrorMsg : public :: std :: exception
    {
    public:

        /* what ( for C++ )
         *  what went wrong
         */
        const char * what () const
            throw ();

        /* toMessage ( for Java )
         *  returns the detailed message
         */
        const :: std :: string & toMessage () const
            throw ();

        /* toString ( for Java )
         *  returns a short description
         */
        const :: std :: string & toString () const
            throw ();

        /* constructors
         *  various means of constructing
         */        
        ErrorMsg ()
            throw ();
        ErrorMsg ( const :: std :: string & message )
            throw ();

    public:

        // C++ support

        ErrorMsg ( const ErrorMsg & obj )
            throw ();
        ErrorMsg & operator = ( const ErrorMsg & obj )
            throw ();

        virtual ~ ErrorMsg ()
            throw ();

    private:

        :: std :: string msg;
    };

} // namespace ngs

#endif // _hpp_ngs_itf_error_msg_
