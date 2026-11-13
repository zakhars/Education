#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer()
{
   return "";
}

class TimeServer
{
public:
    string GetCurrentTime()
    {
    	try
    	{
    		string time = AskTimeServer();
    		LastFetchedTime = time;
    	}
    	catch (const system_error&)
		{
		}
		return LastFetchedTime;
    }

private:
    string LastFetchedTime = "00:00:00";
};

int main_04_16()
{
    TimeServer ts;
    try
    {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (exception& e)
    {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
