/**	@file: avl_tree.h
	@author Gustavo Couto
	@author gcouto@fanshaweonline.ca
	@date 2013-03-01
	@version 0.0.7
	@note Developed for C++ 11
	@brief Simple test utilizing the custom AVL map.
	*/

#include <iostream>
#include <string>
#include "avl_tree.h"

int main( ) {
   using namespace std;
   avl_tree <int, int>::iterator m1_pIter, m2_pIter;

   avl_tree <int, int> m1, m2;
   typedef pair <int, int> Int_Pair;

   m1.insert ( Int_Pair ( 1, 10 ) );
   m1.insert ( Int_Pair ( 2, 20 ) );
   m1.insert ( Int_Pair ( 3, 30 ) );
   m1.insert ( Int_Pair ( 4, 40 ) );

   cout << "The original key values of m1 =";
   for ( m1_pIter = m1.begin( ); m1_pIter != m1.end( ); m1_pIter++ )
      cout << " " << m1_pIter -> first;
   cout << "." << endl;

   cout << "The original mapped values of m1 =";
   for ( m1_pIter = m1.begin( ); m1_pIter != m1.end( ); m1_pIter++ )
      cout << " " << m1_pIter -> second;
   cout << "." << endl;

   pair< avl_tree<int,int>::iterator, bool > pr;
   pr = m1.insert ( Int_Pair ( 1, 10 ) );

   if( pr.second == true ) {
      cout << "The element 10 was inserted in m1 successfully." << endl;
   }
   else {
      cout << "Key number 1 already exists in m1\n"
           << "with an associated value of ( (pr.first) -> second ) = " 
           << ( pr.first ) -> second 
           << "." << endl;
   }

   // The hint version of insert
   m1.insert( --m1.end( ), Int_Pair ( 5, 50 ) );

   cout << "After the insertions, the key values of m1 =";
   for ( m1_pIter = m1.begin( ); m1_pIter != m1.end( ); m1_pIter++ )
      cout << " " << m1_pIter -> first;
   cout << "," << endl;

   cout << "and the mapped values of m1 =";
   for ( m1_pIter = m1.begin( ); m1_pIter != m1.end( ); m1_pIter++ )
      cout << " " << m1_pIter -> second;
   cout << "." << endl;

   m2.insert ( Int_Pair ( 10, 100 ) );

   // The templatized version inserting a range
   m2.insert( ++m1.begin( ), --m1.end( ) );

   cout << "After the insertions, the key values of m2 =";
   for ( m2_pIter = m2.begin( ); m2_pIter != m2.end( ); m2_pIter++ )
      cout << " " << m2_pIter -> first;
   cout << "," << endl;

   cout << "and the mapped values of m2 =";
   for ( m2_pIter = m2.begin( ); m2_pIter != m2.end( ); m2_pIter++ )
      cout << " " << m2_pIter -> second;
   cout << "." << endl;

    // The templatized versions move constructing elements
    avl_tree<int, string> m3;
	avl_tree<int, string> m4;
    pair<int, string> is1(1, "a"), is2(2, "b");

    m3.insert(is1);
    cout << "After the move insertion, m3 contains:" << endl
      << " " << m3.begin()->first
      << " => " << m3.begin()->second
      << endl;

    m4.insert(m4.begin(), is2);
    cout << "After the move insertion, m4 contains:" << endl
      << " " << m4.begin()->first
      << " => " << m4.begin()->second
      << endl;
	int temp;
	cin >> temp;
}
