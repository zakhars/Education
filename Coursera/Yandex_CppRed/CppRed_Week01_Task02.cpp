#include "test_runner.h"
#include <sstream>
#include <string>
using namespace std;

class Logger {
public:
    explicit Logger(ostream& output_stream) : os(output_stream) { }

    void SetLogLine(bool value) { log_line = value; }
    void SetLogFile(bool value) { log_file = value; }

    bool LogLine() { return log_line; }
    bool LogFile() { return log_file; }

    void Log(const string& message) 
    {
        if (log_file && !log_line)
        {
            os << " ";
        }
        os << message << endl;
    }
    
    void LogFileName(const string& filename) { os << filename; }
    void LogLineNumber(int line) { os << (log_file ? ":" : "Line ") << line << " "; }

private:
    ostream & os;
    bool log_line = false;
    bool log_file = false;
};

#define LOG(logger, message) \
   if (logger.LogFile())  \
   { \
       logger.LogFileName(__FILE__); \
   } \
   if (logger.LogLine()) \
   { \
       logger.LogLineNumber(__LINE__); \
   } \
   logger.Log((message));


void TestLog() {
    /* ��� ��������� ����-������ � ���� ������ ��� ����� ����������� ����������
    * ������ ����� � ��������� �������� (��. ���������� expected ����). ����
    * �� ��������� �����-�� ��� ���� ������� TestLog, �� ��� ������ ����� ��������,
    * � ��� ���� �������� ������. ��� ��������.
    *
    * ����� ����� ��������, �� ���������� ����������� ������ #line
    * (http://en.cppreference.com/w/cpp/preprocessor/line), ������� ���������
    * �������������� ����� ������, � ����� ��� �����. ��������� ���, ������
    * ����� ������ ������� TestLog ����� ����������� ���������� �� ����, �����
    * ��� �� ��������� ����� ���*/
#line 1 "logger.cpp"
    
    ostringstream logs;
    Logger l(logs);
    LOG(l, "hello");

    l.SetLogFile(true);
    LOG(l, "hello");

    l.SetLogLine(true);
    LOG(l, "hello");

    l.SetLogFile(false);
    LOG(l, "hello");

    string expected = "hello\n";
    expected += "logger.cpp hello\n";
    expected += "logger.cpp:10 hello\n";
    expected += "Line 13 hello\n";
    ASSERT_EQUAL(logs.str(), expected);
}

int main_cppr_w1_t2() {
    TestRunner tr;
    RUN_TEST(tr, TestLog);
    return 0;
}


// Teacher's solution
namespace ts
{
    #include <string>
    #include <ostream>
    using namespace std;

    class Logger {
    public:
        explicit Logger(ostream& output_stream) : os(output_stream) {
        }

        void SetLogLine(bool value) { log_line = value; }
        void SetLogFile(bool value) { log_file = value; }

        void Log(const string& message);

        void SetFile(const string& filename) {
            file = filename;
        }

        void SetLine(int line_number) {
            line = line_number;
        }

    private:
        ostream & os;
        bool log_line = false;
        bool log_file = false;
        string file;
        int line;
    };

    void Logger::Log(const string& message) {
        if (log_file && log_line) {
            os << file << ':' << line << ' ';
        }
        else if (log_file) {
            os << file << ' ';
        }
        else if (log_line) {
            os << "Line " << line << ' ';
        }
        os << message << '\n';
    }

#define LOG1(logger, message) \
  logger.SetFile(__FILE__);  \
  logger.SetLine(__LINE__);  \
  logger.Log(message);
} // ts