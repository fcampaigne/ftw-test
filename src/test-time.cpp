#define BOOST_TEST_MODULE ftw test
#include <boost/test/unit_test.hpp>

#include "ftwTime.h"
//date time
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace ftw;
using namespace std;

BOOST_AUTO_TEST_CASE( time_test )
{
	// current Precision
	cout << "msg-recision:" << Time::MsgPrecision << ":decimal-places" << endl;
	cout << "hi-res-recision:" << Time::HighResPrecision << ":decimal-places" << endl;
	BOOST_CHECK_CLOSE( Time::getMsgSeconds(), Time::getMsgSeconds(), 0.0001 );
	BOOST_CHECK_CLOSE( Time::getHighResSeconds(), Time::getHighResSeconds(), 0.0001 );
	
	// message time constructors
	Time::MsgTimePoint msgTime1 = Time::getMsgTimePoint();
	Time::MsgTimePoint msgTime2 = msgTime1;
	Time::MsgTimePoint msgTime3(msgTime2);	
	cout <<  "msg-count-since-epoch:" << msgTime1.time_since_epoch().count() << endl;
	BOOST_CHECK_EQUAL(msgTime1.time_since_epoch().count(), msgTime2.time_since_epoch().count());
	BOOST_CHECK_EQUAL(msgTime1.time_since_epoch().count(), msgTime3.time_since_epoch().count());

	// hi res time constructors
	Time::HighResTimePoint hrTime1 = Time::getHighResTimePoint();
	Time::HighResTimePoint hrTime2 = hrTime1;
	Time::HighResTimePoint hrTime3(hrTime2);	
	cout <<  "hi-res-count-since-epoch:" << hrTime1.time_since_epoch().count() << endl;
	BOOST_CHECK_EQUAL(hrTime1.time_since_epoch().count(), hrTime2.time_since_epoch().count());
	BOOST_CHECK_EQUAL(hrTime1.time_since_epoch().count(), hrTime3.time_since_epoch().count());
	
	// the following date is in ISO 8601 extended format (CCYY-MM-DD)
	string s("2001-10-09"); //2001-October-09
	boost::gregorian::date d(boost::gregorian::from_simple_string(s));
	BOOST_CHECK_EQUAL(to_simple_string(d), "2001-Oct-09");
	
	
/*
     const_string cs0( "" );                                                 // 1 //
     BOOST_CHECK_EQUAL( cs0.length(), (size_t)0 );
     BOOST_CHECK( cs0.is_empty() );

     const_string cs01( NULL );                                              // 2 //
     BOOST_CHECK_EQUAL( cs01.length(), (size_t)0 );
     BOOST_CHECK( cs01.is_empty() );

     const_string cs1( "test_string" );                                      // 3 //
     BOOST_CHECK_EQUAL( std::strcmp( cs1.data(), "test_string" ), 0 );
     BOOST_CHECK_EQUAL( cs1.length(), std::strlen("test_string") );

     std::string s( "test_string" );                                         // 4 //
     const_string cs2( s );
     BOOST_CHECK_EQUAL( std::strcmp( cs2.data(), "test_string" ), 0 );

     const_string cs3( cs1 );                                                // 5 //
     BOOST_CHECK_EQUAL( std::strcmp( cs1.data(), "test_string" ), 0 );

     const_string cs4( "test_string", 4 );                                   // 6 //
     BOOST_CHECK_EQUAL( std::strncmp( cs4.data(), "test", cs4.length() ), 0 );

     const_string cs5( s.data(), s.data() + s.length() );                    // 7 //
     BOOST_CHECK_EQUAL( std::strncmp( cs5.data(), "test_string", cs5.length() ), 0 );

     const_string cs_array[] = { "str1", "str2" };                           // 8 //
     BOOST_CHECK_EQUAL( cs_array[0], "str1" );
     BOOST_CHECK_EQUAL( cs_array[1], "str2" );
     */
}
