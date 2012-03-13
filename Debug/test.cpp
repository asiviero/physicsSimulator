//#include <boost/lambda/lambda.hpp>
#include <iostream>
using namespace std;
#include <iterator>
#include <algorithm>
#include <boost/thread.hpp>
#include <pthread.h>
void hello() {
	cout << "hello!" << endl;
}


int main()
{
  /*  using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " " );*/
        cout << "ok" << endl;
        boost::thread teste(&hello);
        
        teste.join();
        return 1;
}

